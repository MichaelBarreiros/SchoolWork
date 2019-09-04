CFLAGS = -g -Wall -ansi -O3

linsolve: timing.o gendata.o linsolve.o checkresult.o main.o
	gcc $(CFLAGS) -o linsolve timing.o gendata.o linsolve.o checkresult.o main.o
timing.o: timing.c
	gcc $(CFLAGS) -c timing.c
gendata.o: gendata.c
	gcc $(CFLAGS) -c gendata.c
linsolve.o: linsolve.c
	gcc $(CFLAGS) -c linsolve.c
checkresult.o: checkresult.c
	gcc $(CFLAGS) -c checkresult.c
main.o: main.c timing.c gendata.c linsolve.c checkresult.c
	gcc $(CFLAGS) -c main.c timing.c gendata.c linsolve.c checkresult.c
clean: 
	rm *.o linsolve
