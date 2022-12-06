CC=gcc
CFLAGS=-I.
DEPS=aoc.h utils.h
OBJ=aoc.o utils.o d01.o d02.o d03.o d06.o

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

aoc: $(OBJ)
	$(CC) -Wall -o $@ $^ $(CFLAGS)
