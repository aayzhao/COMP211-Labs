CC = gcc
CFLAGS = -I/mnt/learncli/workdir/COMP211-Labs/includes

#../bin/%.o: ../source/%.c ../includes/%.h
#	$(CC) -c -o $@ ../source/%.c

test.out: ../bin/output.o ../bin/arrfill.o ../bin/arraystruct.o ../bin/algo.o ../bin/test.o
	$(CC) ../bin/arrfill.o ../bin/output.o ../bin/arraystruct.o ../bin/algo.o ../bin/test.o -o test.out

../bin/test.o: test.c
	$(CC) -c test.c -o ../bin/test.o

../bin/output.o: ../includes/output.h ../source/output.c
	$(CC) -c ../source/output.c -o ../bin/output.o

../bin/arrfill.o: ../includes/arrfill.h ../source/arrfill.c
	$(CC) -c ../source/arrfill.c -o ../bin/arrfill.o

../bin/arraystruct.o: ../bin/arrfill.o ../includes/arraystruct.h ../source/arraystruct.c
	$(CC) -c ../source/arraystruct.c -o ../bin/arraystruct.o

../bin/algo.o: ../includes/algo.h ../source/algo.c
	$(CC) -c ../source/algo.c -o ../bin/algo.o
