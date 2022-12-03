CC=gcc
CFLAGS=-I.
DEPS=aoc.h d01.h
OBJ=aoc.o d01.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

aoc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
