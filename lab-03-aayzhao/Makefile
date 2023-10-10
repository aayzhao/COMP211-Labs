CC=gcc
CFLAGS=-c -Wall -Werror -g

all: test

test: bit_utils.o test.o
	${CC} bit_utils.o test.o -o test

bit_utils.o: bit_utils.c bit_utils.h
	$(CC) $(CFLAGS) bit_utils.c

test.o: test.c
	$(CC) $(CFLAGS) test.c

run: test
	./test

clean:
	rm -f test *.o
