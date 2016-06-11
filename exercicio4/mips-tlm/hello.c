#include <stdio.h>
#include <stdlib.h>

//#define STARTUP_ADDRESS 0x800000;
#define LOCK_ADDRESS (100*1024*1024);


volatile int procCounter = 0;
volatile int *lock = (int *) LOCK_ADDRESS;


void RecursiveHello( int n, int procNumber)
{
	if (n) {
		printf("Hi from processor PowerPC %d!\n",
		procNumber);
	RecursiveHello(n - 1, procNumber);
	}
}
void AcquireLock()
{
	while (*lock);
}

void ReleaseLock()
 {
	*lock = 0;
  }
  
  
 int main( int ac, char *av[]){
 int i;
 int procNumber;

 AcquireLock();
 procNumber = procCounter;
 procCounter ++;
 ReleaseLock();

 if (procNumber % 2) {
	 for (i = 0; i < 100000; i ++);
	 }
 RecursiveHello(10, procNumber);
 
 exit(0);
 return 0;
}

