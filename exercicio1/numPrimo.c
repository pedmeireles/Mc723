#include <stdio.h>
#include <stdlib.h>
int primo(int n)
{
  int i;

  for(i = 3; i < n; i = i + 2)
    if (n % i == 0)
      return 0;
  
  return 1;
}

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Nao foi inserido nenhum numero na linha de comando\n");
		return 0;
	}
	
	int n;
	n = atoi(argv[1]);
	int i = 1;
	int counter = 0;

	if( n >= 2){
	   counter++;
	}
	for(i = 3; i <= n; i = i + 2){
		if(primo(i)){
			counter++;
			}
		}
	
	printf("Existem %d numeros primos entre 1 e %d\n", counter, n);
}
