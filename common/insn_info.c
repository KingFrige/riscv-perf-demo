// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <sys/signal.h>
#include "util.h"
#include "hpm.h"

#define SET_PERFCNT(mhpmcnt, eventid, enventclass) \
  write_csr(mhpmcounter ## mhpmcnt, 0); \
  write_csr(mhpmevent ## mhpmcnt, HPM_EVENTID_ ## eventid|HPM_EVENTCLASS_ ## enventclass);

#define SHOW_PERFCNT(fmt, mhpmcnt) \
  printf(fmt, (int)(read_csr(mhpmcounter ## mhpmcnt)));

int insnInfoCntSet(){
  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 3); // int load
  SET_PERFCNT( 4,  9, 3); // int store
  SET_PERFCNT( 5, 10, 3); // int amo
  SET_PERFCNT( 6, 11, 3); // int system
  SET_PERFCNT( 7, 12, 3); // int arith
  SET_PERFCNT( 8, 13, 3); // int branch
  SET_PERFCNT( 9, 14, 3); // int jal
  SET_PERFCNT(10, 15, 3); // int jalr
  SET_PERFCNT(11, 16, 3); // int mul
  SET_PERFCNT(12, 17, 3); // int div
  SET_PERFCNT(13, 18, 3); // int br taken
  SET_PERFCNT(14, 19, 3); // int br not taken
  SET_PERFCNT(15, 20, 3); // fp
  SET_PERFCNT(16, 21, 3); // fp load
  SET_PERFCNT(17, 22, 3); // fp store
  SET_PERFCNT(18, 23, 3); // fp add
  SET_PERFCNT(19, 24, 3); // fp mul
  SET_PERFCNT(20, 25, 3); // fp mul-add
  SET_PERFCNT(21, 26, 3); // fp div
  SET_PERFCNT(22, 27, 3); // fp other

  SET_PERFCNT(23,  8, 4); // exception
  SET_PERFCNT(24,  9, 4); // br target misp
  SET_PERFCNT(25, 10, 4); // br dir misp
  SET_PERFCNT(26, 11, 4); // taken conditional misp
  SET_PERFCNT(27, 12, 4); // not taken conditional misp
  SET_PERFCNT(28, 13, 4); // f1 clear
  SET_PERFCNT(29, 14, 4); // f2 clear
  SET_PERFCNT(30, 17, 4); // flush

  return 0;
}

int insnInfoCntGet(){
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("minstret:%d\n", (int)(instret));
  printf("mcycle:%d\n", (int)(cycles));

  SHOW_PERFCNT("int_load:%d\n", 3)
  SHOW_PERFCNT("int_store:%d\n", 4)
  SHOW_PERFCNT("int_amo:%d\n", 5)
  SHOW_PERFCNT("int_system:%d\n", 6)
  SHOW_PERFCNT("int_arith:%d\n", 7)
  SHOW_PERFCNT("int_br:%d\n", 8)
  SHOW_PERFCNT("int_jal:%d\n", 9)
  SHOW_PERFCNT("int_jalr:%d\n", 10)
  SHOW_PERFCNT("int_mul:%d\n", 11)
  SHOW_PERFCNT("int_div:%d\n", 12)
  SHOW_PERFCNT("br_taken:%d\n", 13)
  SHOW_PERFCNT("br_ntaken:%d\n", 14)
  SHOW_PERFCNT("fp_load:%d\n", 15);
  SHOW_PERFCNT("fp_load:%d\n", 16);
  SHOW_PERFCNT("fp_store:%d\n", 17);
  SHOW_PERFCNT("fp_add:%d\n", 18);
  SHOW_PERFCNT("fp_mul:%d\n", 19);
  SHOW_PERFCNT("fp_madd:%d\n", 20);
  SHOW_PERFCNT("fp_div:%d\n", 21);
  SHOW_PERFCNT("fp_other:%d\n", 22);

  SHOW_PERFCNT("exception:%d\n", 23);
  SHOW_PERFCNT("br_misp_target:%d\n", 24);
  SHOW_PERFCNT("br_misp_dir:%d\n", 25);
  SHOW_PERFCNT("taken_cond_misp:%d\n", 26);
  SHOW_PERFCNT("ntaken_cond_misp:%d\n", 27);
  SHOW_PERFCNT("f1_clear:%d\n", 28);
  SHOW_PERFCNT("f2_clear:%d\n", 29);
  SHOW_PERFCNT("flush:%d\n", 30);

  return 0;
}

