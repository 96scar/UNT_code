sum: main.o definitions.o
	gcc -o sum main.o definitions.o

main.o: main.c prototype.h structure.h
	gcc -c main.c

definitions.o: definitions.c prototype.h structure.h
	gcc -c definitions.c
