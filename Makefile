
default:build-perf

hello:
	riscv64-unknown-elf-gcc -o hello hello.c
	spike /home/tools/devkit/chipyard-toolchain/riscv64-unknown-elf/bin/pk hello

build-hello:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0  hello.c common/syscalls.c common/crt.S -o hello.riscv

build-perf:
	riscv64-unknown-elf-gcc -O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds -I./common -DFLAGS_STR=\""-O2 -mcmodel=medany -static -std=gnu99 -fno-common -nostdlib -nostartfiles -lm -lgcc -T common/link.lds   "\" -DITERATIONS=0 perfMonCnt.c common/syscalls.c common/crt.S -o perfMonCnt.riscv

clean:
	rm  -rf hello  *.riscv  *.o