generate:
	@cd test && \
		riscv64-unknown-elf-gcc test.c -o test.o -Ttext 0x80000000 -march=rv32i -mabi=ilp32 &&  \
		riscv64-unknown-elf-objdump -S -d test.o -M no-aliases > test.S && \
		python3 elf2hex.py --bit-width 32 --infile test.o --outfile test.hex


build: clean
	@mkdir build
	@cd build && cmake ../src && make
	
run: build
	@./build/model test/test.hex config/SingleCycle.yaml
clean:
	@rm -rf build