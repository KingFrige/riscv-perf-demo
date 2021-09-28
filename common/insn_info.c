// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

int insnInfoCntSet(){
  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  write_csr(mhpmcounter3, 0);
  write_csr(mhpmevent3, HPM_EVENTID_8|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter4, 0);
  write_csr(mhpmevent4, HPM_EVENTID_9|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter5, 0);
  write_csr(mhpmevent5, HPM_EVENTID_10|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter6, 0);
  write_csr(mhpmevent6, HPM_EVENTID_11|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter7, 0);
  write_csr(mhpmevent7, HPM_EVENTID_12|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter8, 0);
  write_csr(mhpmevent8, HPM_EVENTID_13|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter9, 0);
  write_csr(mhpmevent9, HPM_EVENTID_14|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter10, 0);
  write_csr(mhpmevent10, HPM_EVENTID_15|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter11, 0);
  write_csr(mhpmevent11, HPM_EVENTID_16|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter12, 0);
  write_csr(mhpmevent12, HPM_EVENTID_17|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter13, 0);
  write_csr(mhpmevent13, HPM_EVENTID_18|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter14, 0);
  write_csr(mhpmevent14, HPM_EVENTID_19|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter15, 0);
  write_csr(mhpmevent15, HPM_EVENTID_20|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter16, 0);
  write_csr(mhpmevent16, HPM_EVENTID_21|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter17, 0);
  write_csr(mhpmevent17, HPM_EVENTID_22|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter18, 0);
  write_csr(mhpmevent18, HPM_EVENTID_23|HPM_EVENTCLASS_2);
  write_csr(mhpmcounter19, 0);
  write_csr(mhpmevent19, HPM_EVENTID_24|HPM_EVENTCLASS_2);

  return 0;
}

int insnInfoCntGet(){
  size_t instret, cycles;
  size_t int_load, int_store, int_amo, int_system, int_arith, int_br, int_jal, int_jalr;
  size_t int_mul, int_div;
  size_t fp_load, fp_store, fp_add, fp_mul, fp_madd, fp_div, fp_other;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  int_load   = read_csr(mhpmcounter3);
  int_store  = read_csr(mhpmcounter4);
  int_amo    = read_csr(mhpmcounter5);
  int_system = read_csr(mhpmcounter6);
  int_arith  = read_csr(mhpmcounter7);
  int_br     = read_csr(mhpmcounter8);
  int_jal    = read_csr(mhpmcounter9);
  int_jalr   = read_csr(mhpmcounter10);
  int_mul    = read_csr(mhpmcounter11);
  int_div    = read_csr(mhpmcounter12);
  fp_load    = read_csr(mhpmcounter13);
  fp_store   = read_csr(mhpmcounter14);
  fp_add     = read_csr(mhpmcounter15);
  fp_mul     = read_csr(mhpmcounter16);
  fp_madd    = read_csr(mhpmcounter17);
  fp_div     = read_csr(mhpmcounter18);
  fp_other   = read_csr(mhpmcounter19);

  printf("minstret:%d\n", (int)(instret));
  printf("mcycle:%d\n", (int)(cycles));

  printf("int_load:%d\n",  (int)(int_load));
  printf("int_store:%d\n", (int)(int_store));
  printf("int_amo:%d\n",   (int)(int_amo));
  printf("int_system:%d\n", (int)(int_system));
  printf("int_arith:%d\n", (int)(int_arith));
  printf("int_br:%d\n", (int)(int_br));
  printf("int_jal:%d\n", (int)(int_jal));
  printf("int_jalr:%d\n", (int)(int_jalr));
  printf("int_mul:%d\n", (int)(int_mul));
  printf("int_div:%d\n", (int)(int_div));
  printf("fp_load:%d\n", (int)(fp_load));
  printf("fp_store:%d\n", (int)(fp_store));
  printf("fp_add:%d\n", (int)(fp_add));
  printf("fp_mul:%d\n", (int)(fp_mul));
  printf("fp_madd:%d\n", (int)(fp_madd));
  printf("fp_div:%d\n", (int)(fp_div));
  printf("fp_other:%d\n", (int)(fp_other));

  return 0;
}

