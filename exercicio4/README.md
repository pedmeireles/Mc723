#Exercício 4 - Plataformas e Periféricos
##MC723 - Laboratório de Projeto de Sistemas Computacionais . 
###Ra 148914, Pedro Elias Lucas Ramos Meireles. 1s2016

#### Atividade
Este experimento tem como objetivo executar uma aplicação em uma plataforma multicore, além de incluir novos periféricos para garantir integridade da execução de programas (neste caso, uma inclusão de um periférico de lock).

##### Periférico Basico
Nesta primeira parte, foram feitas modificações no código do arquivo ac_tlm_peripheral, para que fosse possivel manipular e armazenar valores escritos e lidos, sem que os dois processadores o façam simultaneamente.
Caso os dois processadores fossem aptos a subescrever um mesmo endereço de memória, eles acabariam gerando conflito de dados, e gerando resultados incorretos na execução das aplicações.
Além disso, deve-se tomar cuidado com os endereços de entrada, para que estas não ultrapassem o valor da pilha pre-determinada para os processadores.




##### Instanciação de um outro processador
Ao instanciar um outro processador identico ao primeiro, deve-se ter cuidado na hora de incluir as mesmas entradas em ambos os processadores, fazendo as devidas cópias de entrada para ambos os processadores antes de realizar a execução do programa. Estas cópias de dados foram feitas através de utilização de variaveis auxiliares, e as mudanças foram realizadas no main.cpp.

#### Aplicação (merge.c)
Para avaliar o desempenho da utilização de dois processadores Vs. o de um único, foi utilizado uma aplicação de ordenação de vetores utilizando o mergesort. 
A ideia básica, para a utilização de 2 processadores, é que cada um ordene uma das metades do vetor, e depois de concluida esta tarefa, um deles intercale os dois subvetores ordenados, para gerar o resultado final correto.
Ao observar o código comentado, é possivel notar que na execução de um unico core (isso é possivel avaliar alterando o define de NCORE de 2 para 1), a execução ocorre corretamente; 
Mas, ao fazer o NCORE valer 2, por algum motivo, ambos os processadores acreditam ser o primeiro processador (procNumber = 1), e eles ordenam somente uma das metades do vetor, gerando resultados incorretos.

O que eu aprendi gerando a aplicação merge.c: que o programador deve gerar vários cuidados para gerar um código de algoritmo correto. Perguntando por email para o PED Jorge e o Prof. Lucas Wanner, pude notar que os seguintes empecilhos são muito comuns ao utilizar o ArchC:
* Não se deve utilizar mallocs, visto que o simulador do ArchC compartilha dados com o processador original da maquina, e isto acarreta em conflitos de informação, e pode fazer com que a simulação dê errado.
* É necessário sempre realizar um AdquireLock e ReleaseLock quando se trabalha com leituras e escritas dentro do ambiente do simulador ArchC, pois elas são funções do tipo não reentrante, e elas entram na zona crítica do processamento.
* É aconselhado que as entradas do programa já estejam armazenadas dentro do código, ou computadas no início da execução, evitando a necessidade de entradas e escritas. 
* As variáveis globais são triviais para a comunicação de dados dentro de diferentes processadores, pois estes são os dados que se comunicam dentro deles.
* Variáveis do tipo Volatile são aquelas que necessitam que, sempre que sejam modificadas, sejam reescritas para dentro da memória secundária do processador. Isto garante que não fique armazenado dados na cache de um dos processadores, e faça com que o outro não enxergue mudanças em variáveis comuns aos dois. 
* A execução das funções não deve ser utilizada na main() do [programa].c .Isto se deve a alguma interação (a qual não sei explicar o por que ocorre), com que faz com que algumas (senão todas) as variaveis iniciadas na main() sejam comuns aos dois processadores. O melhor método é executar todo o programa em outra função, e chamar esta função na main(). Desta forma, todas as variaveis que são iniciadas nesta função deveriam não ser comuns a ambos os processadores (embora este seja o problema relatado de por quê eu não consigo executar o dualcore, e portanto, gero resultados incorretos na merge.c, mesmo o código sendo coerente com as principais dificuldades listadas anteriormente, incluindo chamar a execução do meu programa em outra função, como pode ser notado no próprio código).

Por conta disso, não consegui realizar a constatação da diferença de tempo de execução do merge.c no processador singlecore e dualcore, mesmo ciente de todas (ou a maioria das) dificuldades de utilizar um dualcore e gerar um programa de execução em paralelo.
