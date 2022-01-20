#include <stdlib.h>
#include <stdio.h>

#include "hash_values.h"
#include "pre_processing.h"
#include "chunk_split.h"
#include "message_schedule.h"
#include "compression.h"
#include "print_hex.h"
#include "sha256.h"

void sha256(const char *input)
{
  PreProcessedInput *pre_processed = pre_process(input);

  Chunk_Collection *chunk_collection = chunk_split(pre_processed);

  free(pre_processed->b_input);
  free(pre_processed);

  create_message_schedule(chunk_collection);

  Hashes *hashes = get_hashes();

  compression(hashes, chunk_collection);

  free(chunk_collection->chunks);
  free(chunk_collection);

  print_hex(hashes);

  free(hashes);
}
