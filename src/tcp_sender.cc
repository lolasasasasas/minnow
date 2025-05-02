#include "tcp_sender.hh"
#include "byte_stream.hh"
#include "debug.hh"
#include "tcp_config.hh"
#include "tcp_sender_message.hh"
#include <algorithm>
#include <cstdint>
#include <optional>
#include <iostream>
using namespace std;

// This function is for testing only; don't add extra state to support it.
uint64_t TCPSender::sequence_numbers_in_flight() const
{return _outstanding_bytes;
}

// This function is for testing only; don't add extra state to support it.
uint64_t TCPSender::consecutive_retransmissions() const
{
  debug( "unimplemented consecutive_retransmissions() called" );
  return consecutive_retransmission;
}
void TCPSender::push( const TransmitFunction& transmit )
{
  TCPSenderMessage msg;
  if(input_.has_error())
  {msg.FIN=false;
    msg.RST=true;
    msg.seqno=isn_+1;
    msg.SYN=false;
transmit(msg);
return;

  }
  while ( _outstanding_bytes <= receive_.window_size ) {
    
    msg.SYN = false;
    msg.FIN = false; // 显式初始化
    msg.RST = false;
    msg.payload = "";

    // SYN 逻辑保持不变
    if ( !_isSent_ISN ) {
      _isSent_ISN = true;
      msg.SYN = true;
      msg.seqno = isn_;
    } else {
      msg.seqno = Wrap32::wrap( next_seq, isn_ );
    }

    // 窗口计算保持不变
    size_t available_window = (receive_.window_size == 0) ? 1 : receive_.window_size;
    if(msg.SYN){available_window--;}
    size_t len = min(
      min( available_window - _outstanding_bytes, TCPConfig::MAX_PAYLOAD_SIZE ),
      input_.reader().peek().size()
    );
   
   
    // 读取数据逻辑保持不变
    read( input_.reader(), len, msg.payload );

    /******************** 仅修改 FIN 逻辑部分 ********************/
    if ( input_.writer().is_closed() && !_isSent_FIN ) {
      // 新增条件：只在读取完所有数据时添加 FIN
      if ( input_.reader().peek().empty() ) { // 数据已全部读取
        const size_t total_needed = msg.sequence_length() + _outstanding_bytes + 1;
        if ( total_needed <= available_window ) {
          msg.FIN = true;
          _isSent_FIN = true;
        }
      }
    }
    /***********************************************************/
    
    if ( msg.sequence_length() == 0 )
      break;
    else {
      _outstanding_collections.push_back( msg );
      _outstanding_bytes += msg.sequence_length();
    }

    if ( !timer_running_ ) {
      timer_running_ = true;
      timer_remaining_ms_ = current_RTO_ms_;
    }
    transmit( msg );
    
    next_seq += msg.sequence_length();
  }
}

TCPSenderMessage TCPSender::make_empty_message() const
{TCPSenderMessage msg;
  // 设置序列号：将 next_seq（流索引）转换为绝对序列号
  
msg.payload = "";
msg.FIN = false;
msg.RST=false;
msg.SYN=false;
if (input_.reader().has_error())
{msg.RST=true;}
else
{msg.RST= false;}
  msg.seqno = Wrap32::wrap( next_seq, isn_ );
  return msg;
  debug( "unimplemented make_empty_message() called" );
  
}

void TCPSender::receive( const TCPReceiverMessage& msg )
{
  receive_=msg;
  if (!msg.ackno.has_value() && msg.window_size == 0) {
    input_.set_error(); // 调用错误处理方法
    return;      // 直接返回不再处理后续逻辑
}
  if ( receive_.window_size == 0 )
  { receive_.window_size = 1;
  _primitive_window_size = msg.window_size;
  }
  if ( msg.ackno.has_value() == true ) { // ackno有值才需要删除确认的段
    // 确认ackno的有效性,传回来的ackno不能越过现在已经发出去的最新的seqno
    if ( msg.ackno.value().unwrap( isn_, next_seq) > next_seq)
      return;
    // 删除任何现在已经完全确认的段
    while ( _outstanding_bytes != 0 // 保证不会访问到空的outstanding集合
            && _outstanding_collections.front().seqno.unwrap( isn_, next_seq )
                   + _outstanding_collections.front().sequence_length()
                 <= msg.ackno.value().unwrap( isn_, next_seq ) ) {
      // 当ackno越过集合中某个元素的右边界时，删除这个元素
      _outstanding_bytes -= _outstanding_collections.front().sequence_length();
      _outstanding_collections.pop_front();
      // 有未完成的段被确认时，(即outstanding集合发生pop)才会设置RTO
      // outstanding集合为空(全部未完成的段都完全确认)，则停止计时，重置计时器;否则(当仍有没确认的段时)重启计时器，继续计时
      if ( _outstanding_bytes == 0 )
        timer_running_ = false;
      else {
        timer_running_= true;
      }
      consecutive_retransmission = 0;
      // RTO设置
      current_RTO_ms_=initial_RTO_ms_;
      timer_remaining_ms_ = current_RTO_ms_;
    }
  }
 
}

void TCPSender::tick(uint64_t ms_since_last_tick, const TransmitFunction& transmit) {
  if (timer_running_) {
      if (ms_since_last_tick >= timer_remaining_ms_) {
          timer_remaining_ms_ = 0;
      } else {
          timer_remaining_ms_ -= ms_since_last_tick;
      }
  }
  cout<<_primitive_window_size<<"primhhhhhhhhhhhhhhhhhhhh"<<endl;
cout<<current_RTO_ms_<<"current_RTO_ms_  "<<timer_remaining_ms_<<"timer_remaining_ms_  "<< ms_since_last_tick<<"ms_since_last_tick "<<endl;
  if (timer_remaining_ms_ == 0 && !_outstanding_collections.empty()) {
      // 重传最早的段
      transmit(_outstanding_collections.front());
      
      if(_primitive_window_size>0)
      {current_RTO_ms_ *= 2; }// 指数退避
      consecutive_retransmission++;
      // 重启定时器
      timer_remaining_ms_ = current_RTO_ms_;
      timer_running_ = true;
  }

  if (_outstanding_collections.empty()) {
      timer_running_ = false;
  }


  debug("tick({}, ...) called", ms_since_last_tick);
}
