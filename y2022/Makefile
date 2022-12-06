CC=gcc
CFLAGS=-Wall -I.
DEPS=aoc.h utils.h
OBJ=aoc.o utils.o d01.o d02.o d03.o d04.o d06.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

aoc: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o aoc
