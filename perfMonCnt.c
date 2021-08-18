#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "hpm.h"

int main()
{

  size_t instret, cycles;
  size_t slotsIssed, fetchBubbles, recoveryCycles;
  size_t brMispredRetired, machineClears, fetchLatencyCycles, opsExecutedCycles;
  size_t memStallsAnyLoad, memStallsStores;

  instret = -read_csr(minstret);
  cycles  = -read_csr(mcycle);
  printf("C0: %d instructions\n", (int)(instret));
  printf("C0: %d cycles\n", (int)(cycles));

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

  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");
  printf("Hello Boom!\n");

  instret += read_csr(minstret);
  cycles  += read_csr(mcycle);

  slotsIssed = read_csr(mhpmcounter3);
  fetchBubbles = read_csr(mhpmcounter4);

  recoveryCycles = read_csr(mhpmcounter5);
  brMispredRetired = read_csr(mhpmcounter6);
  machineClears = read_csr(mhpmcounter7);
  fetchLatencyCycles = read_csr(mhpmcounter8);
  opsExecutedCycles = read_csr(mhpmcounter9);
  memStallsAnyLoad = read_csr(mhpmcounter10);
  memStallsStores = read_csr(mhpmcounter11);

  printf("C0: %d instructions\n", (int)(instret));
  printf("C0: %d cycles\n", (int)(cycles));

  printf("C0: %d slotsIssed\n", (int)(slotsIssed));
  printf("C0: %d fetchBubbles\n", (int)(fetchBubbles));

  printf("C0: %d recoveryCycles\n", (int)(recoveryCycles));
  printf("C0: %d brMispredRetired\n", (int)(brMispredRetired));
  printf("C0: %d machineClears\n", (int)(machineClears));
  printf("C0: %d fetchLatencyCycles\n", (int)(fetchLatencyCycles));
  printf("C0: %d opsExecutedCycles\n", (int)(opsExecutedCycles));
  printf("C0: %d memStallsAnyLoad\n", (int)(memStallsAnyLoad));
  printf("C0: %d memStallsStores\n", (int)(memStallsStores));
}
