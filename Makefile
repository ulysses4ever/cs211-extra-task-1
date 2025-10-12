all: main.o extra-task-1.o
	g++ main.o extra-task-1.o -o extra-task

main.o: main.cpp extra-task-1.h
	g++ -c main.cpp -o main.o

extra-task-1.o: extra-task-1.cpp extra-task-1.h
	g++ -c extra-task-1.cpp -o extra-task-1.o
