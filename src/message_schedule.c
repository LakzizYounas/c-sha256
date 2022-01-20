#include <stdio.h>

#include "print_bits.h"
#include "bit_rotate.h"
#include "chunk_split.h"

void create_message_schedule(Chunk_Collection *chunk_collec)
{
  for (size_t i = 0; i < chunk_collec->chunks_len; i++)
  {
    for (size_t j = 16; j < 64; j++)
    {
      uint32_t s0 =
          right_rotate(chunk_collec->chunks[i].data[j - 15], 7) ^
          right_rotate(chunk_collec->chunks[i].data[j - 15], 18) ^
          (chunk_collec->chunks[i].data[j - 15] >> 3);
      uint32_t s1 =
          right_rotate(chunk_collec->chunks[i].data[j - 2], 17) ^
          right_rotate(chunk_collec->chunks[i].data[j - 2], 19) ^
          (chunk_collec->chunks[i].data[j - 2] >> 10);

      chunk_collec->chunks[i].data[j] =
          chunk_collec->chunks[i].data[j - 16] +
          s0 +
          chunk_collec->chunks[i].data[j - 7] +
          s1;
    }
    // print_32bits_arr(chunk_collec->chunks[i].data, 64);
  }
}
