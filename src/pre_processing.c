#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "print_bits.h"

static uint8_t *string_to_uint8_array(const char *str, const uint64_t str_len)
{
  uint8_t *array = calloc(str_len + 1, sizeof(uint8_t));

  for (uint64_t i = 0; i < str_len; i++)
  {
    array[i] = str[i];
  }

  return array;
}

static uint8_t *append_1(uint8_t *b_input, const uint64_t str_len)
{
  uint8_t *array = realloc(b_input, (str_len + 1) * sizeof(uint8_t));

  array[str_len] = (uint8_t)128; // 128 binary is 10000000

  return array;
}

static uint8_t *pad_and_append_len(
    uint8_t *b_input,
    const uint64_t str_len,
    const uint64_t input_len)
{
  uint64_t new_len = str_len + (64 - (str_len % 64));
  uint8_t *array = realloc(b_input, (new_len + 1) * sizeof(uint8_t));

  // Padding
  for (uint64_t i = str_len; i < new_len - sizeof(uint64_t); i++)
  {
    array[i] = 0;
  }

  // Append input len
  for (uint8_t i = 0; i < 8; i++)
  {
    array[new_len - (sizeof(uint64_t) - i)] = input_len >> (56 - (i * 8));
  }

  return array;
}

const uint8_t *pre_process(const char *input)
{
  uint64_t input_len = strlen(input);
  uint8_t *b_input = string_to_uint8_array(input, input_len);

  b_input = append_1(b_input, input_len);
  uint64_t appened_len = input_len + sizeof(uint8_t);

  b_input = pad_and_append_len(b_input, appened_len, input_len);
  // appened_len = appened_len + (64 - (appened_len % 64));

  // print_bits_arr(b_input, appened_len);

  return b_input;
}
