README
============


build
-----------

```bash
module load chipyard

make
```

run
----------

- sim

```bash
$CHIPYARD/sims/vcs/simv-chipyard-StcBoomConfig-debug perfMonCnt.riscv +permissive +fsdbfile=test.fsdb +max-cycles=10000000 +permissive-off
```

- spike

```
$ cd benchmarks
$ make
$ spike mm.riscv
```


reference 
-------------

[riscv-tests](https://github.com/riscv-software-src/riscv-tests)
