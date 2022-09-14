.PHONY: all clean test open

all: use

use: main.o functions.o test.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

test: functions.o test.o
	g++ -Wall -Wextra -c -D TEST main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

clean:
	rm test.o main.o functions.o start

open: main.cpp functions.cpp test.cpp functions.h test.h tests.txt makefile
	code main.cpp functions.cpp test.cpp functions.h test.h tests.txt makefile

main.o: main.cpp
	g++ -Wall -Wextra -c main.cpp -o main.o

functions.o: functions.cpp
	g++ -Wall -Wextra -c functions.cpp -o functions.o

test.o: test.cpp
	g++ -Wall -Wextra -c test.cpp -o test.o





