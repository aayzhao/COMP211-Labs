CC = gcc
#CFLAGS = -I/mnt/learncli/workdir/COMP211-Labs/includes
TA ?= sept21
BIN = ../bin/
INC = ../includes/
SRC = ../source/

#../bin/%.o: ../source/%.c ../includes/%.h
#	$(CC) -c -o $@ ../source/%.c

$(TA).out: $(BIN)output.o $(BIN)arrfill.o $(BIN)arraystruct.o $(BIN)algo.o $(BIN)$(TA).o
	$(CC) $(BIN)arrfill.o $(BIN)output.o $(BIN)arraystruct.o $(BIN)algo.o $(BIN)$(TA).o -o $@

$(BIN)$(TA).o: $(TA).c
	$(CC) -c $(TA).c -o $@

$(BIN)output.o: $(INC)output.h $(SRC)output.c
	$(CC) -c $(SRC)output.c -o $@

$(BIN)arrfill.o: $(INC)arrfill.h $(SRC)arrfill.c
	$(CC) -c $(SRC)arrfill.c -o $@

$(BIN)arraystruct.o: $(INC)arrfill.h $(SRC)arrfill.c $(INC)arraystruct.h $(SRC)arraystruct.c
	$(CC) -c $(SRC)arraystruct.c -o $@

$(BIN)algo.o: $(INC)algo.h $(SRC)algo.c
	$(CC) -c $(SRC)algo.c -o $@
