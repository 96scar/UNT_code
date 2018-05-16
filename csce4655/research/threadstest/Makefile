TASKS = 119

both:
	gcc -lpthread pthreads_test.c -o gcc_pthreads_test -lm
	clang -pthread pthreads_test.c -o clang_pthreads_test -lm

run_both: 	
	time ./gcc_pthreads_test parallel $(TASKS) > output_gcc
	time ./clang_pthreads_test parallel $(TASKS) > output_clang	
	
gcc_pthreads_test: 
	gcc -lpthread pthreads_test.c -o gcc_pthreads_test -lm

run_gcc: 
	time ./gcc_pthreads_test parallel $(TASKS) > output_gcc

clang_pthreads_test:
	clang -pthread pthreads_test.c -o clang_pthreads_test -lm

run_clang:	
	time ./clang_pthreads_test parallel $(TASKS) > output_clang

clean:
	rm gcc_pthreads_test clang_pthreads_test output_gcc output_clang
