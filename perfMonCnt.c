#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "hpm.h"

#pragma GCC optimize ("unroll-loops")

typedef float t;

static const int RBM = 4, RBN = 5, RBK = 6;
static const int CBM = 24, CBN = 25, CBK = 24;

extern int topDownCntSet();
extern int topDownCntGet();

int main()
{
  topDownCntSet();

  const int R = 8;
  int m, n, p;
  uint64_t s = 0xdeadbeefU;

  m = CBM;
  n = CBN;
  p = CBK;

  t a[m*p];
  t b[p*n];
  t c[m*n];

  for (size_t i = 0; i < m; i++)
    for (size_t j = 0; j < p; j++)
      a[i*p+j] = (t)(s = lfsr(s));
  for (size_t i = 0; i < p; i++)
    for (size_t j = 0; j < n; j++)
      b[i*n+j] = (t)(s = lfsr(s));
  memset(c, 0, m*n*sizeof(c[0]));

  printf("Hello Boom!\n");

  topDownCntGet();
}
