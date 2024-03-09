1of1.s: 1of1.c
	clang-17 --target=riscv32 -march=rv32g -mabi=ilp32d -mno-relax 1of1.c -S -o 1of1.s

1of1.o: 1of1.s
	clang-17 --target=riscv32 -march=rv32g -mabi=ilp32d -mno-relax 1of1.s -c -o 1of1.o

b2b.s: b2b.c
	clang-17 --target=riscv32 -march=rv32g -mabi=ilp32d -mno-relax b2b.c -S -o b2b.s

b2b.o: b2b.s
	clang-17 --target=riscv32 -march=rv32g -mabi=ilp32d -mno-relax b2b.s -c -o b2b.o

final.x: 1of1.o b2b.o
	ld.lld 1of1.o b2b.o -o final.x
