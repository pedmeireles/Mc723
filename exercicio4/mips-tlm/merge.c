/* Mc723 - Laboratório de Projeto de Sistemas Computacionais
 * Exercício 4 : Plataformas e Periféricos.
 * Pedro Elias Lucas Ramos Meireles	Ra 148914
 * 2016s1
 * 
 * Aplicação: Implementação do MergeSort em Dualcore do Mips
 * */

#include <stdio.h>
#include <stdlib.h>

//#define STARTUP_ADDRESS 0x800000;
#define LOCK_ADDRESS (100*1024*1024);
#define TAM 10
#define NCORES 2

volatile int procCounter = 0;
volatile int *lockG = (int *) LOCK_ADDRESS;
volatile int vec[TAM];
volatile int local = 0;
volatile int workers = 0;

void AdquireGLock() { while (*lockG); }
//ReleaseLock(): Libera o travamento de execução do processador.
void ReleaseGLock() {*lockG = 0; }

void AdquireLocLock(volatile int *lock)
{
	int i;
	AdquireGLock();
	while(*lock)
	{
		ReleaseGLock();
		for(i=0; i < 10; i++) {}
		AdquireGLock();
	}
	*lock = 1;
	ReleaseGLock();
}

void ReleaseLocLock(volatile int *lock)
{
	AdquireGLock();
	*lock = 0;
	ReleaseGLock();
}
//Metodo que realiza a intercalacao de dois vetores.

void intercala (volatile int *vetor, int posicaoInicio, int posicaoFim, int metadeTamanho){
	
	//Inicializacao dos parametros necessarios na funcao intercala
	int i, j, k;
	int vetorTemp[TAM];
	
	i = posicaoInicio;
	j = metadeTamanho + 1 ;
	k = 0;
	while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } 
            else {
                if (vetor[i] <= vetor[j]) { 
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
	
	//Funcao intercala: ira enviar o menor termo dos dois subvetores para o apontador do vetor auxiliar.
	
	
	for (i = posicaoInicio; i <= posicaoFim; i++)  
		vetor[i] = vetorTemp[i-posicaoInicio];
	}

//Metodo MergeSort; Contem algoritmo de ordenacao seguindo o criterio de divisao e conquista empregado no mergeSort (intercalacao de dois subvetores ordenados).

void mergeSort(volatile int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;

    if(posicaoInicio >= posicaoFim) return;

    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
  
	intercala(vetor, posicaoInicio, posicaoFim, metadeTamanho);

	
}
void g(){
int n, i, procNumber;
	
	//Inicialização do programa.
	/* 
	 * O processador 0 fara a leitura dos parâmetros(tamanho do vetor e seus respectivos termos), e o processador 1 irá confirmar a leitura */
	n = TAM;
	
	AdquireLocLock(&local);
	procNumber = procCounter;
	procCounter ++;
	
	if (procNumber >= NCORES)
	{
		ReleaseLocLock(&local);
		return ;
	}
	
	if(procNumber == 0){
		for(i = 0; i < n; i++){
			vec[i] = n - i;
			//workers ++;
		}

	}

	ReleaseLocLock(&local);
	//for(i = 0; i < TAM*TAM; i++);
	//Primeira espera : Os dois processadores tem que fazer a leitura e confirmar a leitura dos parâmetros de entrada.
	
	
	/* Bloco de ordenação::
	 * O processador 0 irá ordenar a primeira metade do vetor.
	 * O processador 1 irá ordenar a segunda metade do vetor. 
	 * Ambos irão novamente subescrever a variavel 'workers'.*/

/*
	AdquireLocLock(&local);
	/*
	procCounter --;
	procNumber = procCounter;
	
	
	printf("countN = %d\n", procNumber);
	printf("Work = %d\n", workers);
	ReleaseLocLock(&local);

*/
	//while (workers < 1);
	procNumber = procNumber;
	mergeSort(vec, n/NCORES*procNumber, n/(NCORES - procNumber) - 1);
	
	AdquireLocLock(&local);
	printf("Procnumber = %d\n", procNumber);
	workers ++;
	printf("Work = %d\n", workers);
	ReleaseLocLock(&local);

	//Segunda espera: ele irá encerrar quando ambos os processadores tiverem ordenado os dois subvetores que correspondem a todo o vetor.
	if(workers == NCORES )
	{
		intercala(vec, 0, n-1, (n-1)/2);
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}
		printf("\n");
		
	}
}

void f(){
	g();
}
 

int main(){
	f();
	return 0;
}
