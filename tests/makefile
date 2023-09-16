test.out: ../bin/output.o ../bin/arrfill.o test.o
	gcc ../bin/arrfill.o ../bin/output.o test.o -o test.out
	rm test.o

test.o: test.c
	gcc -c test.c

../bin/output.o: ../includes/output.h ../source/output.c
	gcc -c ../source/output.c -o ../bin/output.o

../bin/arrfill.o: ../includes/arrfill.h ../source/arrfill.c
	gcc -c ../source/arrfill.c -o ../bin/arrfill.o
