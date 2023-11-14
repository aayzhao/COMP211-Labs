CC=gcc
CFLAGS=-c -Wall -g #-std=c11

all: lab05

lab05: memory.o cache.o bit_utils.o lab05.o
	$(CC) memory.o cache.o bit_utils.o lab05.o -o lab05 -lm

memory.o: memory.c
	$(CC) $(CFLAGS) memory.c

cache.o: cache.c
	$(CC) $(CFLAGS) cache.c
	
bit_utils.o: bit_utils.c
	$(CC) $(CFLAGS) bit_utils.c

lab05.o: lab05.c
	$(CC) $(CFLAGS) lab05.c

clean:
	/bin/rm -f lab05 *.o *.gz

run: lab05 memory.txt
	./lab05 memory.txt

