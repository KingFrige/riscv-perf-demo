
default:build-perf

hello:
	riscv64-unknown-elf-gcc -o hello hello.c
	spike /home/tools/devkit/chipyard-toolchain/riscv64-unknown-elf/bin/pk hello

build-hello:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0  hello.c common/syscalls.c common/top_down_hpm.c common/crt.S -o hello.riscv

build-perf:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0 perfMonCnt.c common/syscalls.c common/top_down_hpm.c common/crt.S -o perfMonCnt.riscv
	riscv64-unknown-elf-objdump -d perfMonCnt.riscv > perfMonCnt.asm

build-insnInfo:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0 insnInfoCnt.c common/syscalls.c common/insn_info.c common/crt.S -o insnInfoCnt.riscv
	riscv64-unknown-elf-objdump -d insnInfoCnt.riscv > insnInfoCnt.asm

clean:
	rm  -rf hello  *.riscv  *.o
