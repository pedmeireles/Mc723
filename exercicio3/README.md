#Exercício 3 - Contagem de Ciclos.
##MC723 - Laboratório de Projeto de Sistemas Computacionais . 
###Ra 148914, Pedro Elias Lucas Ramos Meireles. 1s2016

#### Introdução
Este exercício tem como importancia aprender a manusear as ferramentas do ambiente de simulação usado na disciplina (o ArchC), e 
a partir dele, executar simulações do mips para realizar a medida do desempenho dele a partir do CPI médio dos programas.

Relembrando, CPI corresponde ao ciclo por instrução de um determinado comando do processador. Normalmente, os comandos mais
rápidos para os mais lentos vem de operadores lógicos e aritméticos (dos aritméticos, temos os comandos de comparação e de
operação), seguidos por comandos de jump e de branch (os quais saltam instruções do processador), e os mais lentos são operações
de acesso a memória (load e store de informações da memória).

Após configurar o ambiente para que ele possa executar as simulações, foi realizado as duas etapas recomendadas: a primeira
corresponde a analise do programa do hello world e do hello world modificado, ambos estarão inclusos os códigos fontes 
para análise posterior do relatório, e para não necessitar copiar aqui o mesmo. 
A segunda parte corresponde a execução de 3 programas e a análise do CPI médio de cada um dos programas. 
Os programas correspondentes ao término do meu RA são:
* patricia (small)
* rijndael coder (small)
* gsm coder (large).

#### Parte 1: hello world! Contando instruções.
Fazendo pequenas alterações no arquivo mips1_isa.cpp, para que ele tivesse um contador global para cada tipo de operação de adição, foi possivel analisar o tipo de operação de adição preferido pelo compilador gcc ao ler o código em C, para o comportamento do mips.

A seguir, será impresso a saída para cada um dos hello worlds distintos. O hello.c corresponde ao hello world convencional, o qual realiza um printf da mensagem. O hello1.c corresponde a criação de uma string que corresponde a mensagem, e para criar mais operações de adição, foi feito de modo que a mensagem fosse impressa char a char, percorrendo o vetor e imprimindo a mensagem desta maneira.

* ./mips.x --load=hello.mips
  - Número total de add: 0
  - Número total de addu: 176
  - Número total de addi: 1
  - Número total de addiu: 299
  - **Número total de add's**: 476

* ./mips.x --load=hello.mips
  - Número total de add: 0
  - Número total de addu: 259
  - Número total de addi: 1
  - Número total de addiu: 347
  - **Número total de add's**: 607

Assim sendo, podemos notar alguns detalhes interessantes:
* A diferença entre o add e o addu é que o add faz a soma com overflow, e o addu faz uma soma sem sinal, ou seja, sem overflow;
* O comportamento do addu quando somamos número com sinal negativo é na verdade tornar o número ainda maior do que ele é (para um número unsigned, o bit mais significativo ainda tem significado numérico, enquanto que para um número signed, o bit mais significativo consta como uma flag que verifica se o número é positivo (valor 0) ou negativo (valor 1).
* Como as operações nunca ocorreriam overflow, a ponto de que o sinal era irrelevante para a operação, nao tendo nenhuma subtração ao longo da execução, o compilador interpretou os inteiros como unsigneds, e não fez nenhuma chamada de add no programa, fazendo preferência com o addu. A mesma lógica de prioridade pode ser aplicada para o addiu, visto que ele foi o tipo de operação de soma que variou para os imediatos. 

####Parte 2: Avaliando o desempenho.

Novamente, fazendo alteração no mips1_isa.cpp, para cada método de instrução, para que:
* Incrementasse uma variavel global para o número total de instruções;
* Incrementasse uma variavel das 3 variáveis globais, respectiva ao tipo de instrução que ela corresponde. Os tipos que ela poderia corresponder são:
  - Controle: corresponde as instruções de jump/branch;
  - Memória: corresponde as instruções de acesso de memória (load/store);
  - Outrem: corresponde as outras instruções;
* Incrementasse com o respectivo peso (dependendo do tipo de instrução) uma variável global que corresponde ao número de ciclos total do programa.
* Mesmo com estas alterações, isto não impediu com que eu utilizasse a opção -s para seguir as estatísticas da simulação (caso tivesse erro de implementação nas partes acima).

Executando os três programas listados anteriormente, cheguei as seguintes conclusões:
* O programa Rijndael (small) tem CPI´s de 3.644 e 4.611, respectivamente, Possuindo um total de instruções respectivos de 43383735 e 3291, respectivamente;
* O programa gsm (Large) tem CPI´s de 3.3 e 3.05, respectivamente, possuindo um total de instruções respectivos a 1467203038 e 572250930, para cada CPI, respectivamente.
* O programa patricia (small) tem CPI de 4.448, possuindo um total de 178978837 instruções.
* O programa Rijndael tem 2 partes:o Encode (primeiro CPI) e o Decode (segundo CPI).
* O programa gsm tem 2 partes: o gsm toast (primeiro CPI) e o untoast (segundo CPI).
* Os dados detalhados da saída de cada comando do programa, tal a tabela que calcula o resultado final da soma dos ciclos, e do CPI médio resultante, se encontra no diretório Dados (o único arquivo lá dentro corresponde as planilhas dos 3 programas). 

A partir destes dados, podemos concluir que o programa que executaria mais rápido, se tivesse o mesmo número de instruções em comparação com os outros, é o programa gsm (large), visto que ele tem o menor CPI. Além disso, o programa que tem m menor número de instruções é o Rijndael (o segundo programa, correspondente ao decode), o que indica que ele também tem o menor número de ciclos da máquina (o que significa que ele executa mais rápidamente do que os outros). 

O CPI corresponde ao número médio de ciclos por instrução; se multiplicado pelo número de instruções, ele dará aproximadamente o número de ciclos da instrução; Quanto maior o número de ciclos de uma instrução, mais tempo ele leva para executar na máquina (pois ele exige mais ciclos de clock).
