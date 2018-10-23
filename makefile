all: sieve.o main.o
	gcc -o test main.o sieve.o

sieve.o: sieve.c sieve.h
	gcc -c sieve.c

main.o: main.c sieve.h
	gcc -c main.c

run:
	./test

clean:
	rm *.o
