#include <stdlib.h>
#include <stdio.h>

#include "pre_processing.h"
#include "sha256.h"

char *sha256(const char *input)
{
  PreProcessedInput *pre_processed = pre_process(input);

  free(pre_processed->b_input);
  free(pre_processed);

  return "sha256";
}
