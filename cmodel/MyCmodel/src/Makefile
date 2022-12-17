src: CPU/* HEXParser/* memory/* main.cpp 
build: src
	g++ CPU/* HEXParser/* memory/* main.cpp  -o model
run: build
	./model ../test/test.hex
clean:
	rm -f emu