#include <stdint.h>

typedef struct PreProcessedInput
{
  uint8_t *b_input;
  uint64_t b_input_len;
} PreProcessedInput;

PreProcessedInput *pre_process(const char *str);