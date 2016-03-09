all: primoUpdateO3
primoUpdateO3: calc_primo.o main.o
	gcc -o primoUpdateO3 calc_primo.o main.o
	
calc_primo.o: calc_primo.c
	gcc -o calc_primo.o -c calc_primo.c -W -Wall -ansi -pedantic
main.o: main.c calc_primo.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
	rm -rf primoUpdateO3

