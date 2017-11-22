main: main.o ADTList.o LinkedList.o Object.o Person.o Employee.o
	g++ main.o ADTList.o LinkedList.o Object.o Person.o Employee.o -o main

main.o: main.cpp ADTList.h LinkedList.h Object.h
	g++ -c main.cpp

ADTList.o: ADTList.h Object.h ADTList.cpp
	g++ -c ADTList.cpp

LinkedList.o: LinkedList.h ADTList.h Object.h LinkedList.cpp
	g++ -c LinkedList.cpp

Object.o: Object.h Object.cpp
	g++ -c Object.cpp

Person.o: Person.h Object.h Person.cpp
	g++ -c Person.cpp

Employee.o: Employee.h Person.h Employee.cpp
	g++ -c Employee.cpp

clean:
	rm *.o

cleanall:	clean
	rm list
