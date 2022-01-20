#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "pre_processing.h"
#include "print_bits.h"

static void string_to_uint8_array(
    PreProcessedInput *pre_processed,
    const char *str,
    const uint64_t str_len)
{
  pre_processed->b_input = calloc(str_len + 1, sizeof(uint8_t));

  for (uint64_t i = 0; i < str_len; i++)
  {
    pre_processed->b_input[i] = str[i];
  }

  pre_processed->b_input_len = str_len;
}

static void append_1(PreProcessedInput *pre_processed)
{
  pre_processed->b_input = realloc(
      pre_processed->b_input,
      (pre_processed->b_input_len + 1) * sizeof(uint8_t));

  pre_processed->b_input[pre_processed->b_input_len] = (uint8_t)128; // 128 binary is 10000000
  pre_processed->b_input_len += sizeof(uint8_t);
}

static void pad_and_append_len(
    PreProcessedInput *pre_processed,
    const uint64_t input_len)
{
  uint64_t new_len =
      pre_processed->b_input_len + (64 - (pre_processed->b_input_len % 64));

  pre_processed->b_input =
      realloc(pre_processed->b_input, (new_len + 1) * sizeof(uint8_t));

  // Padding
  for (
      uint64_t i = pre_processed->b_input_len;
      i < new_len - sizeof(uint64_t);
      i++)
  {
    pre_processed->b_input[i] = 0;
  }

  // Append input len
  for (uint8_t i = 0; i < 8; i++)
  {
    pre_processed->b_input[new_len - (sizeof(uint64_t) - i)] =
        (input_len * 8) >> (56 - (i * 8));
  }

  pre_processed->b_input_len = new_len;
}

PreProcessedInput *pre_process(const char *input)
{
  uint64_t init_len = strlen(input);
  PreProcessedInput *pre_processed = malloc(sizeof(PreProcessedInput));

  string_to_uint8_array(pre_processed, input, init_len);
  append_1(pre_processed);
  pad_and_append_len(pre_processed, init_len);

  // print_8bits_arr(pre_processed->b_input, pre_processed->b_input_len);

  return pre_processed;
}
