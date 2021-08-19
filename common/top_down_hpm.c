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
  write_csr(mhpmevent5, HPM_EVENTID_8|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter6, 0);
  write_csr(mhpmevent6, HPM_EVENTID_9|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter7, 0);
  write_csr(mhpmevent7, HPM_EVENTID_10|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter8, 0);
  write_csr(mhpmevent8, HPM_EVENTID_11|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter9, 0);
  write_csr(mhpmevent9, HPM_EVENTID_12|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter10, 0);
  write_csr(mhpmevent10, HPM_EVENTID_13|HPM_EVENTCLASS_1);
  write_csr(mhpmcounter11, 0);
  write_csr(mhpmevent11, HPM_EVENTID_14|HPM_EVENTCLASS_1);

  return 0;
}

int topDownCntGet(){
  size_t instret, cycles;
  size_t slotsIssed, fetchBubbles, recoveryCycles;
  size_t brMispredRetired, machineClears, fetchNoDeliveredCycles, opsExecutedCycles;
  size_t memStallsAnyLoad, memStallsStores;

  instret= read_csr(minstret);
  cycles= read_csr(mcycle);

  slotsIssed = read_csr(mhpmcounter3);
  fetchBubbles = read_csr(mhpmcounter4);

  recoveryCycles = read_csr(mhpmcounter5);
  fetchNoDeliveredCycles = read_csr(mhpmcounter6);
  brMispredRetired = read_csr(mhpmcounter7);
  machineClears = read_csr(mhpmcounter8);
  opsExecutedCycles = read_csr(mhpmcounter9);
  memStallsAnyLoad = read_csr(mhpmcounter10);
  memStallsStores = read_csr(mhpmcounter11);

  printf("instructions:%d\n", (int)(instret));
  printf("cycles:%d\n", (int)(cycles));
  printf("slotsIssed:%d\n", (int)(slotsIssed));
  printf("fetchBubbles:%d\n", (int)(fetchBubbles));
  printf("recoveryCycles:%d\n", (int)(recoveryCycles));
  printf("fetchNoDeliveredCycles:%d\n", (int)(fetchNoDeliveredCycles));
  printf("brMispredRetired:%d\n", (int)(brMispredRetired));
  printf("machineClears:%d\n", (int)(machineClears));
  printf("opsExecutedCycles:%d\n", (int)(opsExecutedCycles));
  printf("memStallsAnyLoad:%d\n", (int)(memStallsAnyLoad));
  printf("memStallsStores:%d\n", (int)(memStallsStores));

  return 0;
}

