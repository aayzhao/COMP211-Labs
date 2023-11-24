CC=gcc
CFLAGS=-c -Wall -Werror -g

all: lab06

lab06: task.o sim.o lab06.o
	$(CC) task.o sim.o lab06.o -o lab06 -lm

task.o: task.c
	$(CC) $(CFLAGS) task.c
	
sim.o: sim.c
	$(CC) $(CFLAGS) sim.c

lab06.o: lab06.c
	$(CC) $(CFLAGS) lab06.c

run: lab06
	./lab06

clean:
	/bin/rm -f lab06 *.o 

