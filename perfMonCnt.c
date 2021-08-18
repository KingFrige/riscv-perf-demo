#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int main()
{

  size_t instret, cycles;
  instret = -read_csr(minstret);
  cycles  = -read_csr(mcycle);

  printf("Hello Boom!\n");

  instret += read_csr(minstret);
  cycles  += read_csr(mcycle);

  printf("C%d: %d instructions\n", (int)(instret));
  printf("C%d: %d cycles\n", (int)(cycles));
}
