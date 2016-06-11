/* Mc723 - Laboratório de Projeto de Sistemas Computacionais
 * Exercício 4 : Plataformas e Periféricos.
 * Pedro Elias Lucas Ramos Meireles	Ra 148914
 * 2016s1
 * 
 * Aplicação: Implementação do MergeSort em Dualcore do Mips
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define STARTUP_ADDRESS 0x800000;
#define LOCK_ADDRESS (100*1024*1024);


volatile int procCounter = 0;
volatile int *lock = (int *) LOCK_ADDRESS;
volatile int vec[10] = {5, 1, 8, 9, 4, 7,2, 10, 3, 6};
volatile int workers = 2;

int longestChar(char *av[], int n){
	int i, max = 0;
	for(i = 0; i < n; i++){
		if(max < strlen(av[i + 2])){
			max = strlen(av[i + 2]);
		}
	}
	return max;
}

/*
	if(ac < 3){
		 printf("How to use: <program name> <size of vector> <list of terms of the vector>\n");
		 exit(0);
	}
		
	n = atoi(av[1]);
	sscanf(av[1], "%d", &n);
	if(ac != n + 2){
		printf("Put the wrong number of terms in the parameter list\n");
		exit(0);
	 }
	*/

//Metodo que realiza a intercalacao de dois vetores.
//Uma das minhas tentativas foi enviar o vetor do parâmetr main
void intercala (volatile int *vetor, int posicaoInicio, int posicaoFim, int metadeTamanho){
	
	//Inicializacao dos parametros necessarios na funcao intercala
	int i, j, k;
	int *vetorTemp;
	int ac = posicaoFim - posicaoInicio + 1;
	i = posicaoInicio;
	j = metadeTamanho + 1;
	k = 0;
	vetorTemp = (int *) malloc (sizeof(int) * ac);
	
	
	//Funcao intercala: ira enviar o menor termo dos dois subvetores para o apontador do vetor auxiliar.
	
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
                if (vetor[i] < vetor[j]) { 
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
    // copia vetor intercalado para o vetor original
    //Tanto o vetor de inteiros, quanto o vetor da entrada (copiar o vetor de entrada deu errado, e foi corrigido na main ())
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
} 


//Metodo MergeSort; Contem algoritmo de ordenacao seguindo o criterio de divisao e conquista empregado no mergeSort (intercalacao de dois subvetores ordenados).

void mergeSort(volatile int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades, e intercalacao das mesmas
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
	intercala(vetor, posicaoInicio, posicaoFim, metadeTamanho);
}

//AdquireLock(): Realiza o travamento de execução processador. 
void AdquireLock()
{
	while (*lock);
	
}
//ReleaseLock(): Libera o travamento de execução do processador.
void ReleaseLock()
 {
	*lock = 0;
  }
  
int f(int ac, char *av[]){
	int  n, i, half;
	int procNumber;
	int size;
	
	//Block of verifying entrance. 
	
	//Bloqueio do processador
	AdquireLock();
	
	procNumber = procCounter;
	procCounter ++;
	
	//Processo de leitura do parâmetro de entrada - é feito pelo primeiro processador.
	/*
	printf("Chegou até aqui %d\n", procNumber);
	if(procNumber == 0){
		
		scanf("%d", &n);
		
		//Copy the entrance of the program from char to integer.
		for(i = 0; i < n; i++){
			scanf("%d", &vec[i]);
		}
		
	}
	*/
	ReleaseLock();
	n = 10;
	half = n/2;
	/*
	 * Blocos de ordenação de um vetor.
	 * Processador 0: Ele ordenará a primeira metade do vetor.
	 * Processador 1: ele ordenará a segunda metade do vetor.
	 * O programa prossegue quando ambos decrementam workers, o zerando.*/
	//Ordenação da primeira metade do vetor. Feito pela primeira metade;
	if(procNumber == 1){
		mergeSort(vec, half+1, n);
	
		AdquireLock();
		workers --;
		
		printf("ultimo termo do vetor ordenado: %d\n", vec[n-1]);
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}
		printf("Work1 = %d\nProcessador atual: %d\n", workers, procNumber);
		
		ReleaseLock();
	}
	else{
		mergeSort(vec, 0, half);
		AdquireLock();
		workers --;
		
		printf("ultimo termo do vetor ordenado: %d\n", vec[n - 1]);
		printf("Work1 = %d\nProcessador atual: %d\n", workers, procNumber);
		
		ReleaseLock();
	}
	
	while(workers);
	/*
	 * Bloco de intercalação do vetor.
	 * O Processador 0 intercalará todo o vetorm e o imprimirá na saida local o vetor inteiro ordenado.*/
	if(procNumber == 0){
		AdquireLock();
		printf("%d chegou\n", workers);
		intercala(vec, 0, n, half);
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}
		printf("\n");	
		ReleaseLock();
		//free(vec);
	}
	return 0;
}

	/*
	//fim das verificacoes de qual processador eh
	//ambos tem que liberar memoria e acesso ao barramento.
	free(vec);
		
	}
		
	//Funcao do processador par: Ordenar a primeira metade do vetor, e depois escrever ela na entrada.
	if(procNumber == 0){
		
		
			
		//Vetor ordenado sendo impresso:
		printf("Impressao do vetor antes de ser ordenado\n");
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}
		printf("\n");
			
		//size = longestChar(av, n);
		size = 1;
		half = n/2;
			
		//Ordenação da primeira metade do vetor.
		mergeSort(av, size, vec, 0, half);
			
		//Vetor semi-ordenado sendo impresso:
		printf("Impressao do vetor apos ser ordenado\n");
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
			//itoa(vec[i], av[i+2], 10);
			sprintf(av[i+2], " %d ", vec[i]);
		}
		printf("\n");
	}
		
	/*Segundo processador: Realizara a ordenaçao da segunda metade do vetor, e também realizara
	 * a intercalação de todo o vetor. */
	/*
	else if(procNumber == 1){
	//Copy the entrance of the program from char to integer.
		vec = (int *) malloc(sizeof(int) * n);
		for(i = 0; i < n; i++){
			vec[i] = atoi(av[i + 2]);
		}
			
		//Vetor ordenado sendo impresso:
		printf("Impressao do vetor antes de ser ordenado\n");
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}
		printf("\n");
		
		size = longestChar(av, n);
		half = n/2;
			
		//Ordenação de todo o vetor;
		//Comeca com ordenacao da segunda metade, e depois intercala todo o vetor.
		mergeSort(av, size, vec, half+1, n);
		intercala(av, size, vec, 0, n, half );
		
		//Vetor totalmente ordenado sendo impresso:
		printf("Impressao do vetor apos ser ordenado\n");
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
			//sprintf(av[i+2], "%d", vec[i]); //nao eh necessario reescrever mais uma vez na entrada padrao
	/*	}
	printf("\n");	
	}
	//fim das verificacoes de qual processador eh
	//ambos tem que liberar memoria e acesso ao barramento.
	free(vec);
	ReleaseLock();
	return 0;

}  
*/
  
 int main( int ac, char *av[]){
	return f(ac, av);
}
