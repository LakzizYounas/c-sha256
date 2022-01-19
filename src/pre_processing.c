#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "print_bin.h"

static uint8_t *string_to_uint8_array(const char *str, const size_t str_len)
{
  uint8_t *array = calloc(str_len + 1, sizeof(uint8_t));

  for (size_t i = 0; i < str_len; i++)
  {
    array[i] = str[i];
  }

  return array;
}

static uint8_t *append_1(uint8_t *b_input, const size_t str_len)
{
  uint8_t *array = realloc(b_input, (str_len + 1) * sizeof(uint8_t));

  array[str_len] = (uint8_t)128;
  array[str_len + 1] = 0;

  return array;
}

const uint8_t *pre_process(const char *input)
{
  size_t cur_len = strlen(input);
  uint8_t *b_input = string_to_uint8_array(input, cur_len);

  b_input = append_1(b_input, input_len);
  cur_len += sizeof(uint8_t);

  return b_input;
}
