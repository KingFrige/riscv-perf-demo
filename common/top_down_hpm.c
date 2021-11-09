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

  SET_PERFCNT(12,  8, 2); //
  SET_PERFCNT(13,  9, 2);
  SET_PERFCNT(14, 10, 2);
  SET_PERFCNT(15, 11, 2); //
  SET_PERFCNT(16, 12, 2);
  SET_PERFCNT(17, 13, 2);
  SET_PERFCNT(18, 14, 2);
  SET_PERFCNT(19, 15, 2);
  SET_PERFCNT(20, 16, 2); //
  SET_PERFCNT(21, 17, 2);
  SET_PERFCNT(22, 22, 2); //
  SET_PERFCNT(23, 23, 2);
  SET_PERFCNT(24, 24, 2); //

  SET_PERFCNT(25, 14, 1);
  SET_PERFCNT(26, 15, 1);
  SET_PERFCNT(27, 16, 1);

  SET_PERFCNT(28, 10, 6); // issueSlotsEmpty
  SET_PERFCNT(29, 18, 4); // fp retired
  SET_PERFCNT(30, 16, 7);
  SET_PERFCNT(31, 13, 7);

  return 0;
}

int topDownCntGet(){
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instret:%d\n", (int)(instret));
  printf("cycles:%d\n", (int)(cycles));

  SHOW_PERFCNT("slotsIssed:%d\n", 3);
  SHOW_PERFCNT("fetchBubbles:%d\n", 4);
  SHOW_PERFCNT("branchRetired:%d\n", 5);

  SHOW_PERFCNT("recoveryCycles:%d\n", 6);
  SHOW_PERFCNT("fetchNoDeliveredCycles:%d\n", 7);
  SHOW_PERFCNT("brMispredRetired:%d\n", 8);
  SHOW_PERFCNT("machineClears:%d\n", 9);
  SHOW_PERFCNT("memStallsAnyLoad:%d\n", 10);
  SHOW_PERFCNT("memStallsStores:%d\n", 11);

  SHOW_PERFCNT("uopsDeliveredLe0:%d\n", 12);
  SHOW_PERFCNT("uopsDeliveredLe1:%d\n", 13);
  SHOW_PERFCNT("uopsDeliveredLe2:%d\n", 14);
  SHOW_PERFCNT("exeport0Utilization:%d\n", 15);
  SHOW_PERFCNT("exeport1Utilization:%d\n", 16);
  SHOW_PERFCNT("exeport2Utilization:%d\n", 17);
  SHOW_PERFCNT("exeport3Utilization:%d\n", 18);
  SHOW_PERFCNT("exeport4Utilization:%d\n", 19);
  SHOW_PERFCNT("uopsExecutedGe1:%d\n",  20);
  SHOW_PERFCNT("uopsExecutedGe2:%d\n",  21);
  SHOW_PERFCNT("noOpsExecutedCycles:%d\n", 22);
  SHOW_PERFCNT("fewOpsExecutedCycles:%d\n", 23);
  SHOW_PERFCNT("arithDivider_active:%d\n", 24);

  SHOW_PERFCNT("memStallsL1Miss:%d\n", 25);
  SHOW_PERFCNT("memStallsL2Miss:%d\n", 26);
  SHOW_PERFCNT("memStallsL3Miss:%d\n", 27);

  SHOW_PERFCNT("issueSlotsEmpty:%d\n", 28);
  SHOW_PERFCNT("fpRetired:%d\n", 29);
  SHOW_PERFCNT("iTLBMiss:%d\n", 30);
  SHOW_PERFCNT("iCacheMiss:%d\n", 31);

  printf("branchResteers:%d\n", 0);
  printf("memLatency:%d\n", 0);

  return 0;
}

