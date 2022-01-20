#include <stdint.h>

#define INT_BITS 32

uint32_t left_rotate(uint32_t number, uint8_t rotate)
{
  return (number << rotate) | (number >> (INT_BITS - rotate));
}

uint32_t right_rotate(uint32_t number, uint8_t rotate)
{
  return (number >> rotate) | (number << (INT_BITS - rotate));
}
