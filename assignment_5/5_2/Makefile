.PHONY: main test clean

main: main.o set.hpp
	g++ -std=c++17 main.o -o main.exe

main.o:
	g++ -std=c++17 -c main.cpp

test: test.o set.hpp
	g++ -std=c++17 test.o -o test.exe

test.o: 
	g++ -std=c++17 -c test.cpp

set.o:
	g++ --std=c++17 -c set.hpp