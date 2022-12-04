CC=gcc
CFLAGS=-I.
DEPS=aoc.h utils.h
OBJ=aoc.o utils.o d01.o d02.o d03.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

aoc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
