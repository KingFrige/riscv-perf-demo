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

```bash
$CHIPYARD/sims/vcs/simv-chipyard-StcBoomConfig-debug perfMonCnt.riscv +permissive +fsdbfile=test.fsdb +max-cycles=10000000 +permissive-off
```
