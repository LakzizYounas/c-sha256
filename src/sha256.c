#include <stdlib.h>
#include <stdio.h>

#include "pre_processing.h"
#include "chuck_split.h"
#include "sha256.h"

char *sha256(const char *input)
{
  PreProcessedInput *pre_processed = pre_process(input);
  Chunk *chunks = chunk_split(pre_processed);

  free(pre_processed->b_input);
  free(pre_processed);

  free(chunks);

  return "sha256";
}
