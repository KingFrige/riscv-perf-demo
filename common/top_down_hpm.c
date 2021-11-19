// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

int topDownCntSet(){
  write_csr(scounteren, -1);
  write_csr(mcounteren, -1);

  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 0);
  SET_PERFCNT( 4,  9, 0);
  SET_PERFCNT( 5, 10, 0);

  SET_PERFCNT( 6,  8, 1);
  SET_PERFCNT( 7,  9, 1);
  SET_PERFCNT( 8, 10, 1);
  SET_PERFCNT( 9, 11, 1);
  SET_PERFCNT(10, 12, 1);
  SET_PERFCNT(11, 13, 1);
  SET_PERFCNT(12, 14, 1);
  SET_PERFCNT(13, 15, 1);
  SET_PERFCNT(14, 16, 1);

  SET_PERFCNT(15, 13, 2); //
  SET_PERFCNT(16, 14, 2);
  SET_PERFCNT(17, 15, 2);
  SET_PERFCNT(18, 16, 2);
  SET_PERFCNT(19, 17, 2);
  SET_PERFCNT(20, 24, 2); //
  SET_PERFCNT(21, 25, 2);
  SET_PERFCNT(22, 26, 2); //

  SET_PERFCNT(29, 23, 1);
  SET_PERFCNT(30, 17, 1);
  SET_PERFCNT(31, 18, 5);

  return 0;
}

int topDownCntGet(){
  long instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instret:%ld\n", (long)(instret));
  printf("cycles:%ld\n",  (long)(cycles));

  SHOW_PERFCNT("slotsIssed:%ld\n", 3);
  SHOW_PERFCNT("fetchBubbles:%ld\n", 4);
  SHOW_PERFCNT("branchRetired:%ld\n", 5);

  SHOW_PERFCNT("badResteers:%ld\n", 6);
  SHOW_PERFCNT("recoveryCycles:%ld\n", 7);
  SHOW_PERFCNT("unknowBanchCycles:%ld\n", 8);
  SHOW_PERFCNT("brMispredRetired:%ld\n", 9);
  SHOW_PERFCNT("machineClears:%ld\n", 10);
  SHOW_PERFCNT("iCacheStallCycles:%ld\n", 11);
  SHOW_PERFCNT("iTLBStallCycles:%ld\n", 12);
  SHOW_PERFCNT("memStallsAnyLoad:%ld\n", 13);
  SHOW_PERFCNT("memStallsStores:%ld\n", 14);

  SHOW_PERFCNT("exeport0Utilization:%ld\n", 15);
  SHOW_PERFCNT("exeport1Utilization:%ld\n", 16);
  SHOW_PERFCNT("exeport2Utilization:%ld\n", 17);
  SHOW_PERFCNT("exeport3Utilization:%ld\n", 18);
  SHOW_PERFCNT("exeport4Utilization:%ld\n", 19);
  SHOW_PERFCNT("noOpsExecutedCycles:%ld\n", 20);
  SHOW_PERFCNT("fewOpsExecutedCycles:%ld\n", 21);
  SHOW_PERFCNT("arithDivider_active:%ld\n", 22);

  SHOW_PERFCNT("robStallCycles:%ld\n", 29);
  SHOW_PERFCNT("memStallsL1Miss:%ld\n", 30);
  SHOW_PERFCNT("fpRetired:%ld\n", 31);

  printf("memLatency:%ld\n", 0);
  printf("memStallsL2Miss:%ld\n", 0);
  printf("memStallsL3Miss:%ld\n", 0);

  return 0;
}

