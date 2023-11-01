CC=gcc
CFLAGS=-c -Wall -Werror -g

all: lab04

lab04: bit_utils.o instructions.o lab04.o
	${CC} $^ -o lab04

bit_utils.o: bit_utils.c bit_utils.h
	$(CC) $(CFLAGS) bit_utils.c

instructions.o: instructions.c instructions.h bit_utils.h
	$(CC) $(CFLAGS) instructions.c

lab04.o: lab04.c instructions.h
	$(CC) $(CFLAGS) lab04.c

run: lab04
	./lab04

clean:
	rm -f lab04 *.o

