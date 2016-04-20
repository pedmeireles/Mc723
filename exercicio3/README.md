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
