#pragma once

#include "pre_processing.h"

typedef struct Chunk
{
  uint32_t data[64];
} Chunk;

Chunk *chunk_split(PreProcessedInput *pre_processed);
