CC = gcc
CFLAGS = -I/mnt/learncli/workdir/COMP211-Labs/includes
TAR = sept21
#../bin/%.o: ../source/%.c ../includes/%.h
#	$(CC) -c -o $@ ../source/%.c

$(TAR).out: ../bin/output.o ../bin/arrfill.o ../bin/arraystruct.o ../bin/algo.o ../bin/$(TAR).o
	$(CC) ../bin/arrfill.o ../bin/output.o ../bin/arraystruct.o ../bin/algo.o ../bin/$(TAR).o -o $(TAR).out

../bin/$(TAR).o: $(TAR).c
	$(CC) -c $(TAR).c -o ../bin/$(TAR).o

../bin/output.o: ../includes/output.h ../source/output.c
	$(CC) -c ../source/output.c -o ../bin/output.o

../bin/arrfill.o: ../includes/arrfill.h ../source/arrfill.c
	$(CC) -c ../source/arrfill.c -o ../bin/arrfill.o

../bin/arraystruct.o: ../includes/arrfill.h ../includes/arraystruct.h ../source/arraystruct.c
	$(CC) -c ../source/arraystruct.c -o ../bin/arraystruct.o

../bin/algo.o: ../includes/algo.h ../source/algo.c
	$(CC) -c ../source/algo.c -o ../bin/algo.o
