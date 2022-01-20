#include <stdio.h>
#include <stdlib.h>

#include "pre_processing.h"
#include "chunk_split.h"

Chunk_Collection *chunk_split(PreProcessedInput *pre_processed)
{
  Chunk_Collection *chunk_collection = calloc(sizeof(Chunk_Collection), 1);

  size_t chunks_len = pre_processed->b_input_len / 64;
  Chunk *chunks = calloc(sizeof(Chunk), chunks_len);

  for (size_t chunk_i = 0, process_i = 0; chunk_i < chunks_len; chunk_i++)
  {
    for (size_t row_i = 0; row_i < 16; row_i++)
    {
      chunks[chunk_i].data[row_i] |= pre_processed->b_input[process_i++] << 24;
      chunks[chunk_i].data[row_i] |= pre_processed->b_input[process_i++] << 16;
      chunks[chunk_i].data[row_i] |= pre_processed->b_input[process_i++] << 8;
      chunks[chunk_i].data[row_i] |= pre_processed->b_input[process_i++] << 0;
    }
  }

  chunk_collection->chunks = chunks;
  chunk_collection->chunks_len = chunks_len;

  return chunk_collection;
}
