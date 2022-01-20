#pragma once

#include <stdint.h>

#include <stdint.h>

typedef struct Hashes
{
  uint32_t h0;
  uint32_t h1;
  uint32_t h2;
  uint32_t h3;
  uint32_t h4;
  uint32_t h5;
  uint32_t h6;
  uint32_t h7;
} Hashes;

Hashes *get_hashes(void);
uint32_t *get_round_hashes(void);
