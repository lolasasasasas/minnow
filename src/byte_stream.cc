#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  if (is_closed_) // 如果字节流已关闭，则不允许写入
  {
      set_error(); // 标记错误
      return;
  }

  // 计算当前可用容量
  uint64_t available_capacity = capacity_ - buffer_.size();
  if (available_capacity == 0) 
  {
      return;
  }

  uint64_t bytes_to_push = std::min(data.size(), available_capacity);


  for (size_t i = 0; i < bytes_to_push; ++i)
  {
      buffer_.push_back(data[i]);
  }

  
  bytes_pushed_ += bytes_to_push;
   // Your code here.
}

void Writer::close()
{
  is_closed_ = true; // Your code here.
}

bool Writer::is_closed() const
{

  /* code */


  return {is_closed_}; // Your code here.
}

uint64_t Writer::available_capacity() const
{
  
  return {}; // Your code here.
}

uint64_t Writer::bytes_pushed() const
{
  return {}; // Your code here.
}

string_view Reader::peek() const
{
  return {}; // Your code here.
}

void Reader::pop( uint64_t len )
{
  (void)len; // Your code here.
}

bool Reader::is_finished() const
{
  return {}; // Your code here.
}

uint64_t Reader::bytes_buffered() const
{
  return {}; // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return {}; // Your code here.
}

