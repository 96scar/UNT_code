project: project.o functions.o
	g++ project.o functions.o -o project

project.o: project.cpp header.h
	g++ -c project.cpp

functions.o: functions.cpp header.h
	g++ -c functions.cpp
	
run:
	./project
	
clean:
	rm project project.o functions.o