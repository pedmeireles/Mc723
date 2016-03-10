all: primosNumb13
primosNumb13: calc_primo.o main.o
	gcc -O3 -fopenmp calc_primo.o main.o  -o primosNumb13
	
calc_primo.o: calc_primo.c
	gcc -o calc_primo.o -c calc_primo.c -W -Wall -ansi -pedantic
main.o: main.c calc_primo.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o

