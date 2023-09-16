test.out: ../bin/output.o ../bin/arrfill.o ../bin/test.o
	gcc ../bin/arrfill.o ../bin/output.o ../bin/test.o -o test.out

../bin/test.o: test.c
	gcc -c test.c -o ../bin/test.o

../bin/output.o: ../includes/output.h ../source/output.c
	gcc -c ../source/output.c -o ../bin/output.o

../bin/arrfill.o: ../includes/arrfill.h ../source/arrfill.c
	gcc -c ../source/arrfill.c -o ../bin/arrfill.o
