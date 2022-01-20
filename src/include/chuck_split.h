#pragma once

#include <stdlib.h>
#include "pre_processing.h"

typedef struct Chunk
{
  uint32_t data[64];
} Chunk;

typedef struct Chunk_Collection
{
  size_t chunks_len;
  Chunk *chunks;
} Chunk_Collection;

Chunk_Collection *chunk_split(PreProcessedInput *pre_processed);
