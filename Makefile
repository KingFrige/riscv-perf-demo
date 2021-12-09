
all:build-perf build-insnInfo build-init build-tma build-info

hello:
	riscv64-unknown-elf-gcc -o hello hello.c
	spike /home/tools/devkit/chipyard-toolchain/riscv64-unknown-elf/bin/pk hello

build-hello:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0  hello.c common/syscalls.c common/top_down_hpm.c common/crt.S -o hello.riscv

build-perf:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0 perfMonCnt.c common/syscalls.c common/top_down_hpm.c common/crt.S -o perfMonCnt_tma.riscv
	riscv64-unknown-elf-objdump -d perfMonCnt_tma.riscv > perfMonCnt_tma.asm

build-insnInfo:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0 insnInfoCnt.c common/syscalls.c common/insn_info_hpm.c common/crt.S -o insnInfoCnt_info.riscv
	riscv64-unknown-elf-objdump -d insnInfoCnt_info.riscv > insnInfoCnt_info.asm

build-init:
	make -C benchmarks

build-tma:
	make -C benchmarks_tma

build-info:
	make -C benchmarks_info

clean:
	rm  -rf hello  *.riscv  *.o *.asm
	make -C benchmarks clean
	make -C benchmarks_tma clean
	make -C benchmarks_info clean
