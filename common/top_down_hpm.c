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

  write_csr(mhpmcounter3, 0);
  write_csr(mhpmevent3, HPM_EVENTID_8|HPM_EVENTCLASS_0);
  write_csr(mhpmcounter4, 0);
  write_csr(mhpmevent4, HPM_EVENTID_9|HPM_EVENTCLASS_0);

  write_csr(mhpmcounter5, 0);
  write_csr(mhpmevent5, HPM_EVENTID_10|HPM_EVENTCLASS_0);
  write_csr(mhpmcounter6, 0);
  write_csr(mhpmevent6, HPM_EVENTID_11|HPM_EVENTCLASS_0);
  write_csr(mhpmcounter7, 0);
  write_csr(mhpmevent7, HPM_EVENTID_12|HPM_EVENTCLASS_0);


  write_csr(mhpmcounter8, 0);
  write_csr(mhpmevent8, HPM_EVENTID_8|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter9, 0);
  write_csr(mhpmevent9, HPM_EVENTID_9|HPM_EVENTCLASS_1);

  write_csr(mhpmcounter10, 0);
  write_csr(mhpmevent10, HPM_EVENTID_10|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter11, 0);
  write_csr(mhpmevent11, HPM_EVENTID_11|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter12, 0);
  write_csr(mhpmevent12, HPM_EVENTID_12|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter13, 0);
  write_csr(mhpmevent13, HPM_EVENTID_13|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter14, 0);
  write_csr(mhpmevent14, HPM_EVENTID_14|HPM_EVENTCLASS_1);

  write_csr(mhpmcounter15, 0);
  write_csr(mhpmevent15, HPM_EVENTID_15|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter16, 0);
  write_csr(mhpmevent16, HPM_EVENTID_16|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter17, 0);
  write_csr(mhpmevent17, HPM_EVENTID_17|HPM_EVENTCLASS_1);

  write_csr(mhpmcounter18, 0);
  write_csr(mhpmevent18, HPM_EVENTID_18|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter19, 0);
  write_csr(mhpmevent19, HPM_EVENTID_19|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter20, 0);
  write_csr(mhpmevent20, HPM_EVENTID_20|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter21, 0);
  write_csr(mhpmevent21, HPM_EVENTID_21|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter22, 0);
  write_csr(mhpmevent22, HPM_EVENTID_22|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter23, 0);
  write_csr(mhpmevent23, HPM_EVENTID_23|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter24, 0);
  write_csr(mhpmevent24, HPM_EVENTID_24|HPM_EVENTCLASS_1);

  write_csr(mhpmcounter25, 0);
  write_csr(mhpmevent25, HPM_EVENTID_25|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter26, 0);
  write_csr(mhpmevent26, HPM_EVENTID_26|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter27, 0);
  write_csr(mhpmevent27, HPM_EVENTID_27|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter28, 0);
  write_csr(mhpmevent28, HPM_EVENTID_28|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter29, 0);
  write_csr(mhpmevent29, HPM_EVENTID_29|HPM_EVENTCLASS_1);

  return 0;
}

int topDownCntGet(){
  size_t instret, cycles;
  size_t slotsIssed, fetchBubbles, recoveryCycles;
  size_t brMispredRetired, machineClears, fetchNoDeliveredCycles, opsExecutedCycles;
  size_t memStallsAnyLoad, memStallsStores;

  size_t branchRetired, fpRetired, vectorRetired, iTLBMiss;
  size_t iCacheMiss, branchResteers, renameExecutionStall;
  size_t issueExecutionStall, robExecutionStall, memStallsL1Miss, memStallsL2Miss, memStallsL3Miss;
  size_t exeport0Utilization, exeport1Utilization, exeport2Utilization, exeport3Utilization, exeport4Utilization;
  size_t memLatency;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  slotsIssed = read_csr(mhpmcounter3);
  fetchBubbles = read_csr(mhpmcounter4);

  branchRetired = read_csr(mhpmcounter5);
  fpRetired = read_csr(mhpmcounter6);
  vectorRetired = read_csr(mhpmcounter7);

  recoveryCycles = read_csr(mhpmcounter8);
  fetchNoDeliveredCycles = read_csr(mhpmcounter9);
  brMispredRetired = read_csr(mhpmcounter10);
  machineClears = read_csr(mhpmcounter11);
  opsExecutedCycles = read_csr(mhpmcounter12);
  memStallsAnyLoad = read_csr(mhpmcounter13);
  memStallsStores = read_csr(mhpmcounter14);

  iTLBMiss = read_csr(mhpmcounter15);
  iCacheMiss = read_csr(mhpmcounter16);
  branchResteers = read_csr(mhpmcounter17);

  renameExecutionStall = read_csr(mhpmcounter18);
  issueExecutionStall = read_csr(mhpmcounter19);
  robExecutionStall = read_csr(mhpmcounter20);
  exeport0Utilization = read_csr(mhpmcounter21);
  exeport1Utilization = read_csr(mhpmcounter22);
  exeport2Utilization = read_csr(mhpmcounter23);
  exeport3Utilization = read_csr(mhpmcounter24);
  exeport4Utilization = read_csr(mhpmcounter25);

  memStallsL1Miss = read_csr(mhpmcounter26);
  memStallsL2Miss = read_csr(mhpmcounter27);
  memStallsL3Miss = read_csr(mhpmcounter28);
  memLatency = read_csr(mhpmcounter29);

  printf("minstret:%d\n", (int)(instret));
  printf("mcycle:%d\n", (int)(cycles));

  printf("slotsIssed:%d\n", (int)(slotsIssed));
  printf("fetchBubbles:%d\n", (int)(fetchBubbles));
  printf("branchRetired:%d\n", (int)(branchRetired));
  printf("fpRetired:%d\n", (int)(fpRetired));
  printf("vectorRetired:%d\n", (int)(vectorRetired));

  printf("recoveryCycles:%d\n", (int)(recoveryCycles));
  printf("fetchNoDeliveredCycles:%d\n", (int)(fetchNoDeliveredCycles));
  printf("brMispredRetired:%d\n", (int)(brMispredRetired));
  printf("machineClears:%d\n", (int)(machineClears));
  printf("opsExecutedCycles:%d\n", (int)(opsExecutedCycles));
  printf("memStallsAnyLoad:%d\n", (int)(memStallsAnyLoad));
  printf("memStallsStores:%d\n", (int)(memStallsStores));

  printf("iTLBMiss:%d\n", (int)(iTLBMiss));
  printf("iCacheMiss:%d\n", (int)(iCacheMiss));
  printf("branchResteers:%d\n", (int)(branchResteers));

  printf("renameExecutionStall:%d\n", (int)(renameExecutionStall));
  printf("issueExecutionStall:%d\n", (int)(issueExecutionStall));
  printf("robExecutionStall:%d\n", (int)(robExecutionStall));
  printf("exeport0Utilization:%d\n", (int)(exeport0Utilization));
  printf("exeport1Utilization:%d\n", (int)(exeport1Utilization));
  printf("exeport2Utilization:%d\n", (int)(exeport2Utilization));
  printf("exeport3Utilization:%d\n", (int)(exeport3Utilization));
  printf("exeport4Utilization:%d\n", (int)(exeport4Utilization));

  printf("memStallsL1Miss:%d\n", (int)(memStallsL1Miss));
  printf("memStallsL2Miss:%d\n", (int)(memStallsL2Miss));
  printf("memStallsL3Miss:%d\n", (int)(memStallsL3Miss));
  printf("memLatency:%d\n", (int)(memLatency));

  return 0;
}

