#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "hpm.h"

extern int topDownCntSet();
extern int topDownCntGet();

int main()
{
  topDownCntSet();

  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");

  topDownCntGet();
}
