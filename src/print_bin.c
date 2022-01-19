#include <stdint.h>
#include <stdio.h>

void print_bin(uint8_t b) {
  for (int i = 7; i >= 0; --i) {
    putchar((b & (1 << i)) ? '1' : '0');
  }
}

void print_bin_arr(uint8_t *arr) {
  for (size_t i = 0; arr[i]; i++) {
    print_bin(arr[i]);
    printf("\n");
  }
}
