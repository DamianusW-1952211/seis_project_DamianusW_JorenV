.DEFAULT_GOAL := all

CC=g++

clean:
	rm -rf *.o
	rm -rf *.out

compile:
	$(CC) -std=c++17 -o main main.cpp

clear:
	clear

run:
	./main

all: clean compile clear run
