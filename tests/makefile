test.out: ../headers/output.o test.o
	gcc ../headers/output.o test.o -o test.out
	rm test.o

test.o: test.c
	gcc -c test.c

../headers/output.o: ../headers/output.h
	gcc -c ../headers/output.h -o ../headers/output.o

