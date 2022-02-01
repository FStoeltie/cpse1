.PHONY: main test clean

main: main.o set.o
	g++ -std=c++17 set.o main.o -o main.exe

main.o:
	g++ -std=c++17 -c main.cpp

test: test.o set.o
	g++ -std=c++17 set.o test.o -o test.exe

test.o: 
	g++ -std=c++17 -c test.cpp

set.o:
	g++ --std=c++17 -c set.cpp