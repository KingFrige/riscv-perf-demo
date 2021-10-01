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

  SET_PERFCNT(14,  8, 2);
  SET_PERFCNT(15,  9, 2);
  SET_PERFCNT(16, 10, 2);
  SET_PERFCNT(17, 11, 2);
  SET_PERFCNT(18, 12, 2); //
  SET_PERFCNT(19, 13, 2);
  SET_PERFCNT(20, 14, 2);
  SET_PERFCNT(21, 15, 2);
  SET_PERFCNT(22, 16, 2);
  SET_PERFCNT(23, 17, 2); //
  SET_PERFCNT(24, 18, 2);

  SET_PERFCNT(25, 16, 1);
  SET_PERFCNT(26, 17, 1);
  SET_PERFCNT(27, 18, 1);
  SET_PERFCNT(28, 19, 1);

  return 0;
}

int topDownCntGet(){
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("minstret:%d\n", (int)(instret));
  printf("mcycle:%d\n", (int)(cycles));

  SHOW_PERFCNT("slotsIssed:%d\n", 3);
  SHOW_PERFCNT("fetchBubbles:%d\n", 4);
  SHOW_PERFCNT("branchRetired:%d\n", 5);

  SHOW_PERFCNT("recoveryCycles:%d\n", 6);
  SHOW_PERFCNT("fetchNoDeliveredCycles:%d\n", 7);
  SHOW_PERFCNT("brMispredRetired:%d\n", 8);
  SHOW_PERFCNT("machineClears:%d\n", 9);
  SHOW_PERFCNT("noneOpsExecutedCycles:%d\n", 10);
  SHOW_PERFCNT("opsExecutedCycles:%d\n", 11);
  SHOW_PERFCNT("memStallsAnyLoad:%d\n", 12);
  SHOW_PERFCNT("memStallsStores:%d\n", 13);

  SHOW_PERFCNT("exeport0Utilization:%d\n", 14);
  SHOW_PERFCNT("exeport1Utilization:%d\n", 15);
  SHOW_PERFCNT("exeport2Utilization:%d\n", 16);
  SHOW_PERFCNT("exeport3Utilization:%d\n", 17);
  SHOW_PERFCNT("exeport4Utilization:%d\n", 18);
  SHOW_PERFCNT("opsExeGt0:%d\n", 19);
  SHOW_PERFCNT("opsExeGt1:%d\n", 20);
  SHOW_PERFCNT("opsExeGt2:%d\n", 21);
  SHOW_PERFCNT("opsExeGt3:%d\n", 22);
  SHOW_PERFCNT("opsExeGt4:%d\n", 23);
  SHOW_PERFCNT("arithDivider_active:%d\n", 24);

  SHOW_PERFCNT("memStallsL1Miss:%d\n", 25);
  SHOW_PERFCNT("memStallsL2Miss:%d\n", 26);
  SHOW_PERFCNT("memStallsL3Miss:%d\n", 27);
  SHOW_PERFCNT("memLatency:%d\n", 28);

  return 0;
}

