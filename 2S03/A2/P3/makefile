CFLAGS = -g -Wall -ansi

sinc: sinc.o main.o
	gcc $(CFLAGS) -o sinc sinc.o main.o -lm
sinc.o: sinc.c
	gcc $(CFLAGS) -c sinc.c -o sinc.o -lm
main.o: main.c
	gcc $(CFLAGS) -c main.c -lm
clean: 
	rm *.o sinc
