#include <stdio.h>

#include "sha256.h"

int main()
{
  sha256("hello world");
  // const char *output = sha256("hello world");
  // printf("output: [%s]\n", output);
  return (0);
}