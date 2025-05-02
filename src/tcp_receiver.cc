#include "tcp_receiver.hh"
#include "byte_stream.hh"
#include "debug.hh"
#include "tcp_receiver_message.hh"
#include "tcp_sender_message.hh"
#include "wrapping_integers.hh"
#include <cmath>
#include <cstdint>

#include <iostream>
using namespace std;

void TCPReceiver::receive( TCPSenderMessage message )
{if(message.RST)
  {
    reassembler_.reader().set_error();
  }
  if ( message.SYN ) { // 处理SYN标志
    if ( !isn_set_ ) {
      isn_set_ = true;
      zero_point_ = message.seqno; // 设置ISN为SYN的序列号
      checkpoint = 0;
    }
  }
  if ( !isn_set_ ) { // 未收到SYN前忽略数据
    return;
  }

  // 计算绝对序列号并处理SYN占用的序列号
  uint64_t absolute_seqno = message.seqno.unwrap( zero_point_, checkpoint );
  uint64_t stream_index = absolute_seqno - 1 + ( message.SYN ? 1 : 0 );

  // 插入数据到Reassembler，考虑FIN标志
  reassembler_.insert( stream_index, message.payload, message.FIN );
  checkpoint = stream_index; // 更新checkpoint以便下一次unwrap
  debug( "unimplemented receive() called" );
  (void)message;
}

TCPReceiverMessage TCPReceiver::send() const
{
  // Your code here.
  TCPReceiverMessage msg;
  if(writer().has_error())
  {
    msg.RST=true;
  }
  msg.window_size=(writer().available_capacity()<=65535?writer().available_capacity():65535);
  if ( isn_set_ ) {
    // ackno = 已组装的字节数 + 1（SYN占一个序号） + FIN是否已接收
    uint64_t ackno = writer().bytes_pushed() + 1;
    if ( writer().is_closed()) { // 如果流已结束，加上FIN的序号
      ackno += 1;
    }
    std::cout<<ackno<<"   "<<std::endl;
    msg.ackno = Wrap32::wrap( ackno, zero_point_ );
  } else {
    msg.ackno = std::nullopt; // 未收到SYN时返回nullopt
  }
  



 
  
  debug( "unimplemented send() called" );
  return msg;
}
