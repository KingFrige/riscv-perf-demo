// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

int linuxPerfCntSet(){
  write_csr(scounteren, -1);
  write_csr(mcounteren, -1);

  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 0);
  SET_PERFCNT( 4,  9, 0);
  SET_PERFCNT( 5, 10, 0);
  SET_PERFCNT( 6, 11, 0);

  SET_PERFCNT( 7, 12, 0);
  SET_PERFCNT( 8, 13, 1);
  SET_PERFCNT( 9, 14, 1);
  SET_PERFCNT(10, 15, 1);
  SET_PERFCNT(11, 16, 1);
  SET_PERFCNT(12, 17, 8);

  SET_PERFCNT(13, 19, 8);
  SET_PERFCNT(14, 20, 8);
  SET_PERFCNT(15, 21, 8);
  SET_PERFCNT(16, 22, 8);

  SET_PERFCNT(17, 23, 8);
  SET_PERFCNT(18, 24, 8);
  SET_PERFCNT(19, 25, 8);
  SET_PERFCNT(20, 26, 8);
  SET_PERFCNT(21, 27, 8);
  SET_PERFCNT(22, 28, 8);

  SET_PERFCNT(23, 29, 8);
  SET_PERFCNT(24, 30, 8);
  SET_PERFCNT(25, 31, 8);
  SET_PERFCNT(26, 32, 8);
  SET_PERFCNT(27, 33, 8);
  SET_PERFCNT(28, 34, 8);
  SET_PERFCNT(29, 35, 8);
  SET_PERFCNT(30, 36, 8);

  return 0;
}

int linuxPerfCntGet(){
  long instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instructions:%ld\n", (long)(instret));
  printf("cpu_cycle:%ld\n",    (long)(cycles));

  SHOW_PERFCNT("l1_icache_loads:%ld\n", 3);
  SHOW_PERFCNT("l1_icache_load_misses:%ld\n", 4);
  SHOW_PERFCNT("l1_icache_prefetches:%ld\n", 5);
  SHOW_PERFCNT("l1_icache_prefetch_misses:%ld\n", 6);

  SHOW_PERFCNT("l1_dcache_loads:%ld\n", 7);
  SHOW_PERFCNT("l1_dcache_load_misses:%ld\n", 8);
  SHOW_PERFCNT("l1_dcache_stores:%ld\n", 9);
  SHOW_PERFCNT("l1_dcache_store_misses:%ld\n", 10);
  SHOW_PERFCNT("l1_dcache_prefetches:%ld\n", 11);
  SHOW_PERFCNT("l1_dcache_prefetch_misses:%ld\n", 12);

  SHOW_PERFCNT("itlb_loads:%ld\n", 13);
  SHOW_PERFCNT("itlb_load_misses:%ld\n", 14);
  SHOW_PERFCNT("itlb_prefetches:%ld\n", 15);
  SHOW_PERFCNT("itlb_prefetch_misses:%ld\n", 16);

  SHOW_PERFCNT("dtlb_loads:%ld\n", 17);
  SHOW_PERFCNT("dtlb_load_misses:%ld\n", 18);
  SHOW_PERFCNT("dtlb_stores:%ld\n", 19);
  SHOW_PERFCNT("dtlb_store_misses:%ld\n", 20);
  SHOW_PERFCNT("dtlb_prefetches:%ld\n", 21);
  SHOW_PERFCNT("dtlb_prefetch_misses:%ld\n", 22);

  SHOW_PERFCNT("cache_references:%ld\n", 23); // llc references -> hit
  SHOW_PERFCNT("cache_misses:%ld\n", 24);     // llc misses
  SHOW_PERFCNT("llc_cache_loads:%ld\n", 25);
  SHOW_PERFCNT("llc_cache_load_misses:%ld\n", 26);
  SHOW_PERFCNT("llc_cache_stores:%ld\n", 27);
  SHOW_PERFCNT("llc_cache_store_misses:%ld\n", 28);
  SHOW_PERFCNT("llc_cache_prefetches:%ld\n", 29);
  SHOW_PERFCNT("llc_cache_prefetch_misses:%ld\n", 30);

  // SHOW_PERFCNT("bus_cycles:%ld\n", 31);
  // SHOW_PERFCNT("branches:%ld\n", 29);
  // SHOW_PERFCNT("branch_misses:%ld\n", 30);
  // SHOW_PERFCNT("branch_loads:%ld\n", 31);
  // SHOW_PERFCNT("branch_load_misses:%ld\n", 32);

  return 0;
}
