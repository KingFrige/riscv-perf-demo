// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

int cpiStackCntGet(){
  long instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instructions:%ld\n", (long)(instret));
  printf("cpu_cycle:%ld\n",    (long)(cycles));

  SHOW_PERFCNT("cache_references:%ld\n", 3);

  return 0;
}
