#include <stdlib.h>
#include <stdio.h>

#include "hash_values.h"
#include "pre_processing.h"
#include "chuck_split.h"
#include "message_schedule.h"
#include "sha256.h"

char *sha256(const char *input)
{
  PreProcessedInput *pre_processed = pre_process(input);

  Chunk_Collection *chunk_collection = chunk_split(pre_processed);

  free(pre_processed->b_input);
  free(pre_processed);

  create_message_schedule(chunk_collection);

  Hashes *hashes = get_hashes();

  free(chunk_collection->chunks);

  return "sha256";
}
