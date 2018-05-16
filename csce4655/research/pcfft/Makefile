all:
	gcc -lpthread pcfft.c complex.c main.c -o gcc_test
	clang -pthread pcfft.c complex.c main.c -o clang_test

run:
	./gcc_test
	./clang_test

run_gcc: 
	./gcc_test

run_clang: 
	./clang_test

clean:
	rm gcc_test clang_test
