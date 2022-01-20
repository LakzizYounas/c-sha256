#include "print_bits.h"
#include "bit_rotate.h"
#include "compression.h"

void compression(Hashes *hashes, Chunk_Collection *chunk_collec)
{
  for (size_t chunk_i = 0; chunk_i < chunk_collec->chunks_len; chunk_i++)
  {
    uint32_t a = hashes->h0,
             b = hashes->h1,
             c = hashes->h2,
             d = hashes->h3,
             e = hashes->h4,
             f = hashes->h5,
             g = hashes->h6,
             h = hashes->h7;

    for (size_t i = 0; i < 64; i++)
    {
      uint32_t s1 = (right_rotate(e, 6)) ^ (right_rotate(e, 11)) ^ (right_rotate(e, 25));
      uint32_t ch = (e & f) ^ ((~e) & g);
      uint32_t temp1 = h + s1 + ch + ROUND_CONSTANTS[i] + chunk_collec->chunks[chunk_i].data[i];
      uint32_t s0 = (right_rotate(a, 2)) ^ (right_rotate(a, 13)) ^ (right_rotate(a, 22));
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp2 = s0 + maj;

      h = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }
    hashes->h0 += a;
    hashes->h1 += b;
    hashes->h2 += c;
    hashes->h3 += d;
    hashes->h4 += e;
    hashes->h5 += f;
    hashes->h6 += g;
    hashes->h7 += h;
  }
}
