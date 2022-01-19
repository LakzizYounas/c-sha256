#include <stdlib.h>
#include <stdio.h>

#include "print_bin.h"
#include "pre_processing.h"
#include "sha256.h"

char *sha256(const char *input) {
  uint8_t *b_input = pre_process(input);

  print_bin_arr(b_input);
  free(b_input);

  return "sha256";
}
