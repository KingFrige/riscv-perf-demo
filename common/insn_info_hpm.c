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
  write_csr(scounteren, -1);
  write_csr(mcounteren, -1);

  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 5); // int load
  SET_PERFCNT( 4,  9, 5); // int store
  SET_PERFCNT( 5, 10, 5); // int amo
  SET_PERFCNT( 6, 11, 5); // int system
  SET_PERFCNT( 7, 12, 5); // int arith
  SET_PERFCNT( 8, 13, 5); // int branch
  SET_PERFCNT( 9, 14, 5); // int jal
  SET_PERFCNT(10, 15, 5); // int jalr
  SET_PERFCNT(11, 16, 5); // int mul
  SET_PERFCNT(12, 17, 5); // int div
  SET_PERFCNT(13, 18, 5); // fp
  SET_PERFCNT(14, 19, 5); // fp load
  SET_PERFCNT(15, 20, 5); // fp store
  SET_PERFCNT(16, 21, 5); // fp add
  SET_PERFCNT(17, 22, 5); // fp mul
  SET_PERFCNT(18, 23, 5); // fp mul-add
  SET_PERFCNT(19, 24, 5); // fp div
  SET_PERFCNT(20, 25, 5); // fp other

  SET_PERFCNT(21,  8, 6); // exception
  SET_PERFCNT(22,  9, 6); // f1 clear
  SET_PERFCNT(23, 10, 6); // f2 clear

  SET_PERFCNT(24, 10, 0); // br retired
  SET_PERFCNT(25, 11, 0); // br retired and taken
  SET_PERFCNT(26, 12, 0); // br retired and not taken

  SET_PERFCNT(27, 19, 1); // br target misp
  SET_PERFCNT(28, 20, 1); // br dir misp
  SET_PERFCNT(29, 21, 1); // taken conditional misp
  SET_PERFCNT(30, 22, 1); // not taken conditional misp
  SET_PERFCNT(31, 12, 1); // flush

  return 0;
}

int insnInfoCntGet(){
  long instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instret:%ld\n", (long)(instret));
  printf("cycles:%ld\n",  (long)(cycles));

  SHOW_PERFCNT("intLoad:%ld\n", 3)
  SHOW_PERFCNT("intStore:%ld\n", 4)
  SHOW_PERFCNT("intAmo:%ld\n", 5)
  SHOW_PERFCNT("intSystem:%ld\n", 6)
  SHOW_PERFCNT("intArith:%ld\n", 7)
  SHOW_PERFCNT("intBr:%ld\n", 8)
  SHOW_PERFCNT("intJal:%ld\n", 9)
  SHOW_PERFCNT("intJalr:%ld\n", 10)
  SHOW_PERFCNT("intMul:%ld\n", 11)
  SHOW_PERFCNT("intDiv:%ld\n", 12)
  SHOW_PERFCNT("fp:%ld\n", 13);
  SHOW_PERFCNT("fpLoad:%ld\n", 14);
  SHOW_PERFCNT("fpStore:%ld\n", 15);
  SHOW_PERFCNT("fpAdd:%ld\n", 16);
  SHOW_PERFCNT("fpMul:%ld\n", 17);
  SHOW_PERFCNT("fpMadd:%ld\n", 18);
  SHOW_PERFCNT("fpDiv:%ld\n", 19);
  SHOW_PERFCNT("fpOther:%ld\n", 20);

  SHOW_PERFCNT("exception:%ld\n", 21);
  SHOW_PERFCNT("f1Clear:%ld\n", 22);
  SHOW_PERFCNT("f2Clear:%ld\n", 23);

  SHOW_PERFCNT("brRetire:%ld\n", 24)
  SHOW_PERFCNT("brTaken:%ld\n", 25)
  SHOW_PERFCNT("brNotaken:%ld\n", 26)

  SHOW_PERFCNT("brMispTarget:%ld\n", 27);
  SHOW_PERFCNT("brMispDir:%ld\n", 28);
  SHOW_PERFCNT("takenCondMisp:%ld\n", 29);
  SHOW_PERFCNT("notakenCondMisp:%ld\n", 30);
  SHOW_PERFCNT("flush:%ld\n", 31);

  return 0;
}

