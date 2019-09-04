CFLAGS = -g -Wall -ansi

linsolve: gendata.o linsolve.o checkresult.o main.o
	gcc $(CFLAGS) -o linsolve gendata.o linsolve.o checkresult.o main.o
gendata.o: gendata.c
	gcc $(CFLAGS) -c gendata.c
linsolve1.o: linsolve.c
	gcc $(CFLAGS) -c linsolve.c
checkresult.o: checkresult.c 
	gcc $(CFLAGS) -c checkresult.c
main.o: main.c gendata.c linsolve.c checkresult.c
	gcc $(CFLAGS) -c main.c gendata.c linsolve.c checkresult.c
clean: 
	rm *.o linsolve
