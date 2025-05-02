#include "wrapping_integers.hh"
#include "debug.hh"

using namespace std;

Wrap32 Wrap32::wrap( uint64_t n, Wrap32 zero_point )
{
  // Your code here.
 
 
  return Wrap32{zero_point.raw_value_ + static_cast<uint32_t>(n)};
  debug( "unimplemented wrap( {}, {} ) called", n, zero_point.raw_value_ );
}

uint64_t Wrap32::unwrap( Wrap32 zero_point, uint64_t checkpoint ) const
{ 

  const uint32_t delta = raw_value_ - zero_point.raw_value_;
    const uint64_t base = static_cast<uint64_t>(delta);

    // 直接处理 checkpoint < base 的情况
    if (checkpoint < base) {
        return base;
    }

    // 计算 checkpoint 与 base 的差值（注意避免溢出）
    const uint64_t diff = checkpoint - base;
    // 计算需要增加的周期数（2^32 的倍数）
    const uint64_t cycles = (diff + (1ULL << 31)) >> 32;

    // 计算结果并处理可能的溢出
    return base + (cycles << 32);
  
  // Your code here.
  debug( "unimplemented unwrap( {}, {} ) called", zero_point.raw_value_, checkpoint );
  
}
