CC = gcc
#CFLAGS = -I/mnt/learncli/workdir/COMP211-Labs/includes
TA ?= test
BIN = ../bin/
INC = ../includes/
SRC = ../source/
#FLAGS = -Werror -Wall

#../bin/%.o: ../source/%.c ../includes/%.h
#	$(CC) -c -o $@ ../source/%.c

$(TA).out: $(BIN)binops.o $(BIN)output.o $(BIN)arraystruct.o $(BIN)algo.o $(BIN)$(TA).o
	$(CC) $(BIN)binops.o $(BIN)output.o $(BIN)arraystruct.o $(BIN)algo.o $(BIN)$(TA).o -o $@

$(BIN)$(TA).o: $(TA).c
	$(CC) -c $(TA).c -o $@

$(BIN)output.o: $(INC)output.h $(SRC)output.c
	$(CC) -c $(SRC)output.c -o $@

#$(BIN)arrfill.o: $(INC)arrfill.h $(SRC)arrfill.c
#	$(CC) -c $(SRC)arrfill.c -o $@

$(BIN)arraystruct.o: $(INC)algo.h $(SRC)algo.c $(INC)arraystruct.h $(SRC)arraystruct.c
	$(CC) -c $(SRC)arraystruct.c -o $@

$(BIN)algo.o: $(INC)algo.h $(SRC)algo.c
	$(CC) -c $(SRC)algo.c -o $@

$(BIN)binops.o: $(INC)binops.h $(SRC)binops.c
	$(CC) -c $(SRC)binops.c -o $@
