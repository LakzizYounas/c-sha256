#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_values.h"

static char *binary_to_hex(const char *inStr)
{
  char hex[] = "0123456789ABCDEF";
  char *out = calloc(sizeof(char), 256);
  size_t len = strlen(inStr) / 4;

  for (size_t out_i = 0; len > 0; len--, out_i++)
  {
    uint8_t current = 0;

    for (size_t i = 0; i < 4; ++i)
    {
      current = (current << 1) + (*inStr - '0');
      inStr++;
    }
    out[out_i] = hex[current];
  }

  return out;
}

static void uint32_to_string(uint32_t nb, char *buf)
{
  char byte[33] = {0};

  for (int8_t i = 31, j = 0; i >= 0; i--, j++)
  {
    byte[i] = ((nb >> j) & 1) == 0 ? '0' : '1';
  }
  strcat(buf, byte);
}

void print_hex(Hashes *hashes)
{
  char binary[257] = {0};

  uint32_to_string(hashes->h0, binary);
  uint32_to_string(hashes->h1, binary);
  uint32_to_string(hashes->h2, binary);
  uint32_to_string(hashes->h3, binary);
  uint32_to_string(hashes->h4, binary);
  uint32_to_string(hashes->h5, binary);
  uint32_to_string(hashes->h6, binary);
  uint32_to_string(hashes->h7, binary);

  char *out = binary_to_hex(binary);
  printf("%s\n", out);
  free(out);
}
