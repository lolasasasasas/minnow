#pragma once

#include "byte_stream.hh"

#include <cstdint>
#include <map>
#include <optional>

class Reassembler
{
public:
  // Construct Reassembler to write into given ByteStream.
  explicit Reassembler( ByteStream&& output ) : output_( std::move( output ) ) {}
  void insert( uint64_t first_index, std::string data, bool is_last_substring );

  // How many bytes are stored in the Reassembler itself?
  uint64_t count_bytes_pending() const;

  // Access output stream reader
  Reader& reader() { return output_.reader(); }
  const Reader& reader() const { return output_.reader(); }

  // Access output stream writer, but const-only (can't write from outside)
  const Writer& writer() const { return output_.writer(); }

private:
  ByteStream output_; // the Reassembler writes to this ByteStream

  std::map<uint64_t, std::string> buf_ {};
  uint64_t total_pending_ {};

  std::optional<uint64_t> end_index_ {};

  auto split( uint64_t pos ) noexcept;
};