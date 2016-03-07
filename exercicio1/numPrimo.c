#include <stdio.h>

int primo(int n)
{
  int i;

  for(i = 2; i < n; i ++)
    if (n % i == 0)
      return 0;
  
  return 1;
}

int main()
{
	int n;
	int i = 1;
	int counter = 0;
	printf("insira um numero inteiro\n");
	scanf("%d", &n);
	

	
	for(i = 2; i <= n; i++){
		printf("iteração atual: %d", i);
		if(primo(i)){
			counter++;
		}
		printf("  numeros primos presentes no intervalo: %d\n", counter);
	}
	
	printf("Existem %d numeros primos entre 1 e %d\n", counter, n);
}
