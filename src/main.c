#include <stdio.h>

#include "sha256.h"

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    sha256(argv[1]);
  }
  return (0);
}
