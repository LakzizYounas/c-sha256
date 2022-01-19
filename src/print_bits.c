#include <stdint.h>
#include <stdio.h>

void print_bits(size_t const size, void const *const ptr)
{
  unsigned char *b = (unsigned char *)ptr;
  uint8_t byte;
  int i, j;

  for (i = size - 1; i >= 0; i--)
  {
    for (j = 7; j >= 0; j--)
    {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  printf("\n");
}

void print_bits_arr(uint8_t *arr, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    print_bits(sizeof(arr[i]), &(arr[i]));
  }
}
