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
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instructions:%d\n", (int)(instret));
  printf("cpu_cycle:%d\n", (int)(cycles));

  SHOW_PERFCNT("cache_references:%d\n", 3);

  return 0;
}
