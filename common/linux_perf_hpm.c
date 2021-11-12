// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

int linuxPerfCntGet(){
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instructions:%d\n", (int)(instret));
  printf("cpu_cycle:%d\n", (int)(cycles));

  SHOW_PERFCNT("cache_references:%d\n", 3);
  SHOW_PERFCNT("branches:%d\n", 4);
  SHOW_PERFCNT("branch_misses:%d\n", 5);
  SHOW_PERFCNT("bus_cycles:%d\n", 6);

  SHOW_PERFCNT("l1_icache_loads:%d\n", 7);
  SHOW_PERFCNT("l1_icache_load_misses:%d\n", 8);
  SHOW_PERFCNT("l1_icache_prefetches:%d\n", 9);
  SHOW_PERFCNT("l1_icache_prefetche_misses:%d\n", 10);

  SHOW_PERFCNT("l1_dcache_loads:%d\n", 11);
  SHOW_PERFCNT("l1_dcache_load_misses:%d\n", 12);
  SHOW_PERFCNT("l1_dcache_stores:%d\n", 13);
  SHOW_PERFCNT("l1_dcache_store_misses:%d\n", 14);
  SHOW_PERFCNT("l1_dcache_prefetches:%d\n", 15);
  SHOW_PERFCNT("l1_dcache_prefetche_misses:%d\n", 16);

  SHOW_PERFCNT("l2_cache_loads:%d\n", 17);
  SHOW_PERFCNT("l2_cache_load_misses:%d\n", 18);
  SHOW_PERFCNT("l2_cache_stores:%d\n", 19);
  SHOW_PERFCNT("l2_cache_store_misses:%d\n", 20);
  SHOW_PERFCNT("l2_cache_prefetches:%d\n", 21);
  SHOW_PERFCNT("l2_cache_prefetche_misses:%d\n", 22);

  SHOW_PERFCNT("dtlb_loads:%d\n", 23);
  SHOW_PERFCNT("dtlb_load_misses:%d\n", 24);
  SHOW_PERFCNT("dtlb_stores:%d\n", 25);
  SHOW_PERFCNT("dtlb_store_misses:%d\n", 26);
  SHOW_PERFCNT("dtlb_prefetches:%d\n", 27);
  SHOW_PERFCNT("dtlb_prefetch_misses:%d\n", 28);

  SHOW_PERFCNT("itlb_loads:%d\n", 29);
  SHOW_PERFCNT("itlb_load_misses:%d\n", 30);

  SHOW_PERFCNT("branch_loads:%d\n", 31);
  // SHOW_PERFCNT("branch_load_misses:%d\n", 32);

  return 0;
}
