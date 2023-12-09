CC=gcc
CFLAGS=-c -Wall -g

all: project

project: shell.o project.o
	$(CC) shell.o project.o -o project

shell.o: shell.c
	$(CC) $(CFLAGS) shell.c

project.o: project.c
	$(CC) $(CFLAGS) project.c

clean:
	/bin/rm -f project *.o *.gz

run:
	./project
