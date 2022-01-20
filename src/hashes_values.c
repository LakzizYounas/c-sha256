#include <stdlib.h>
#include "hash_values.h"

Hashes *get_hashes(void)
{
  Hashes *hashes = malloc(sizeof(Hashes));

  *hashes = (Hashes){
      .h0 = 0x6a09e667,
      .h1 = 0xbb67ae85,
      .h2 = 0x3c6ef372,
      .h3 = 0xa54ff53a,
      .h4 = 0x510e527f,
      .h5 = 0x9b05688c,
      .h6 = 0x1f83d9ab,
      .h7 = 0x5be0cd19,
  };

  return hashes;
}

uint32_t *get_round_hashes(void)
{
  uint32_t *round_hashes = calloc(sizeof(uint32_t), 65);

  round_hashes[0] = 0x428a2f98;
  round_hashes[1] = 0x71374491;
  round_hashes[2] = 0xb5c0fbcf;
  round_hashes[3] = 0xe9b5dba5;
  round_hashes[4] = 0x3956c25b;
  round_hashes[5] = 0x59f111f1;
  round_hashes[6] = 0x923f82a4;
  round_hashes[7] = 0xab1c5ed5;
  round_hashes[8] = 0xd807aa98;
  round_hashes[9] = 0x12835b01;
  round_hashes[10] = 0x243185be;
  round_hashes[11] = 0x550c7dc3;
  round_hashes[12] = 0x72be5d74;
  round_hashes[13] = 0x80deb1fe;
  round_hashes[14] = 0x9bdc06a7;
  round_hashes[15] = 0xc19bf174;
  round_hashes[16] = 0xe49b69c1;
  round_hashes[17] = 0xefbe4786;
  round_hashes[18] = 0x0fc19dc6;
  round_hashes[19] = 0x240ca1cc;
  round_hashes[20] = 0x2de92c6f;
  round_hashes[21] = 0x4a7484aa;
  round_hashes[22] = 0x5cb0a9dc;
  round_hashes[23] = 0x76f988da;
  round_hashes[24] = 0x983e5152;
  round_hashes[25] = 0xa831c66d;
  round_hashes[26] = 0xb00327c8;
  round_hashes[27] = 0xbf597fc7;
  round_hashes[28] = 0xc6e00bf3;
  round_hashes[29] = 0xd5a79147;
  round_hashes[30] = 0x06ca6351;
  round_hashes[31] = 0x14292967;
  round_hashes[32] = 0x27b70a85;
  round_hashes[33] = 0x2e1b2138;
  round_hashes[34] = 0x4d2c6dfc;
  round_hashes[35] = 0x53380d13;
  round_hashes[36] = 0x650a7354;
  round_hashes[37] = 0x766a0abb;
  round_hashes[38] = 0x81c2c92e;
  round_hashes[39] = 0x92722c85;
  round_hashes[40] = 0xa2bfe8a1;
  round_hashes[41] = 0xa81a664b;
  round_hashes[42] = 0xc24b8b70;
  round_hashes[43] = 0xc76c51a3;
  round_hashes[44] = 0xd192e819;
  round_hashes[45] = 0xd6990624;
  round_hashes[46] = 0xf40e3585;
  round_hashes[47] = 0x106aa070;
  round_hashes[48] = 0x19a4c116;
  round_hashes[49] = 0x1e376c08;
  round_hashes[50] = 0x2748774c;
  round_hashes[51] = 0x34b0bcb5;
  round_hashes[52] = 0x391c0cb3;
  round_hashes[53] = 0x4ed8aa4a;
  round_hashes[54] = 0x5b9cca4f;
  round_hashes[55] = 0x682e6ff3;
  round_hashes[56] = 0x748f82ee;
  round_hashes[57] = 0x78a5636f;
  round_hashes[58] = 0x84c87814;
  round_hashes[59] = 0x8cc70208;
  round_hashes[60] = 0x90befffa;
  round_hashes[61] = 0xa4506ceb;
  round_hashes[62] = 0xbef9a3f7;
  round_hashes[63] = 0xc67178f2;

  return round_hashes;
}