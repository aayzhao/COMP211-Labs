test.out: ../bin/output.o ../bin/arrfill.o ../bin/arraystruct.o ../bin/test.o
	gcc ../bin/arrfill.o ../bin/output.o ../bin/arraystruct.o ../bin/test.o -o test.out

../bin/test.o: test.c
	gcc -c test.c -o ../bin/test.o

../bin/output.o: ../includes/output.h ../source/output.c
	gcc -c ../source/output.c -o ../bin/output.o

../bin/arrfill.o: ../includes/arrfill.h ../source/arrfill.c
	gcc -c ../source/arrfill.c -o ../bin/arrfill.o

../bin/arraystruct.o: ../bin/arrfill.o ../includes/arraystruct.h ../source/arraystruct.c
	gcc -c ../source/arraystruct.c -o ../bin/arraystruct.o
