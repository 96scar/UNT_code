allfiles: bSearch.o bubble.o database.o db.o parse.o set.o stack.o
	gcc -o allfiles bSearch.o bubble.o database.o db.o parse.o set.o stack.o

bSearch.o: defs.h sortAndSearch.h
	gcc -c bSearch.c

bubble.o: defs.h 
	gcc -c bubble.c

database.o: defs.h parse.h
	gcc -c database.c

db.o: defs.h
	gcc -c db.c

parse.o: parse.h
	gcc -c parse.c

set.o: db.h set.h
	gcc -c set.c

stack.o: stack.h
	gcc -c stack.c

clean:
	rm allfiles bSearch.o bubble.o database.o db.o parse.o set.o stack.o

run: 
	./allfiles < data
