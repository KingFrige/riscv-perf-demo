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

  SET_PERFCNT( 3,  8, 4); // int load
  SET_PERFCNT( 4,  9, 4); // int store
  SET_PERFCNT( 5, 10, 4); // int amo
  SET_PERFCNT( 6, 11, 4); // int system
  SET_PERFCNT( 7, 12, 4); // int arith
  SET_PERFCNT( 8, 13, 4); // int branch
  SET_PERFCNT( 9, 14, 4); // int jal
  SET_PERFCNT(10, 15, 4); // int jalr
  SET_PERFCNT(11, 16, 4); // int mul
  SET_PERFCNT(12, 17, 4); // int div
  SET_PERFCNT(13, 18, 4); // fp
  SET_PERFCNT(14, 19, 4); // fp load
  SET_PERFCNT(15, 20, 4); // fp store
  SET_PERFCNT(16, 21, 4); // fp add
  SET_PERFCNT(17, 22, 4); // fp mul
  SET_PERFCNT(18, 23, 4); // fp mul-add
  SET_PERFCNT(19, 24, 4); // fp div
  SET_PERFCNT(20, 25, 4); // fp other

  SET_PERFCNT(21,  8, 5); // exception
  SET_PERFCNT(22,  9, 5); // f1 clear
  SET_PERFCNT(23, 10, 5); // f2 clear

  SET_PERFCNT(24, 10, 0); // br retired
  SET_PERFCNT(25, 11, 0); // br retired and taken
  SET_PERFCNT(26, 12, 0); // br retired and not taken

  SET_PERFCNT(27, 20, 1); // br target misp
  SET_PERFCNT(28, 21, 1); // br dir misp
  SET_PERFCNT(29, 22, 1); // taken conditional misp
  SET_PERFCNT(30, 23, 1); // not taken conditional misp
  SET_PERFCNT(31, 11, 1); // flush

  return 0;
}

int insnInfoCntGet(){
  size_t instret, cycles;

  instret = read_csr(minstret);
  cycles = read_csr(mcycle);

  printf("instret:%d\n", (int)(instret));
  printf("cycles:%d\n", (int)(cycles));

  SHOW_PERFCNT("intLoad:%d\n", 3)
  SHOW_PERFCNT("intStore:%d\n", 4)
  SHOW_PERFCNT("intAmo:%d\n", 5)
  SHOW_PERFCNT("intSystem:%d\n", 6)
  SHOW_PERFCNT("intArith:%d\n", 7)
  SHOW_PERFCNT("intBr:%d\n", 8)
  SHOW_PERFCNT("intJal:%d\n", 9)
  SHOW_PERFCNT("intJalr:%d\n", 10)
  SHOW_PERFCNT("intMul:%d\n", 11)
  SHOW_PERFCNT("intDiv:%d\n", 12)
  SHOW_PERFCNT("fp:%d\n", 13);
  SHOW_PERFCNT("fpLoad:%d\n", 14);
  SHOW_PERFCNT("fpStore:%d\n", 15);
  SHOW_PERFCNT("fpAdd:%d\n", 16);
  SHOW_PERFCNT("fpMul:%d\n", 17);
  SHOW_PERFCNT("fpMadd:%d\n", 18);
  SHOW_PERFCNT("fpDiv:%d\n", 19);
  SHOW_PERFCNT("fpOther:%d\n", 20);

  SHOW_PERFCNT("exception:%d\n", 21);
  SHOW_PERFCNT("f1Clear:%d\n", 22);
  SHOW_PERFCNT("f2Clear:%d\n", 23);

  SHOW_PERFCNT("brRetire:%d\n", 24)
  SHOW_PERFCNT("brTaken:%d\n", 25)
  SHOW_PERFCNT("brNotaken:%d\n", 26)

  SHOW_PERFCNT("brMispTarget:%d\n", 27);
  SHOW_PERFCNT("brMispDir:%d\n", 28);
  SHOW_PERFCNT("takenCondMisp:%d\n", 29);
  SHOW_PERFCNT("notakenCondMisp:%d\n", 30);
  SHOW_PERFCNT("flush:%d\n", 31);

  return 0;
}

