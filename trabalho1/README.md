#Projeto 1: Benchmarking.
##Parte 3: Avaliação de desempenho.
###Pedro Elias Lucas Ramos Meireles, Ra 148914.

O projeto 1: benchmarking, da disciplina Mc 723 (Laboratório de Projeto de Sistemas Computacionais) se deve a respeito de adquirir dados a respeito de partes de componentes de hardware, atravez de execução de programas selecionados para se tornarem um benchmark; analisar estes dados obtidos experimentalmente, expecíficos para cada máquina; e obter conclusões de qual computador tem melhores componentes eletrônicos em um grupo de testes. 

Para isso, na primeira parte, foi criado diferentes grupos (de 3 a 4 pessoas) que deveriam selecionar um programa que pudesse corresponder a uma análise de um ou mais componentes eletrônicos (como alocação dinâmica de memória, ou processamento de imagens, por exemplo); Como já foi expecificado no github, eu fiz parte do grupo 5, o qual selecionou o projeto de “ordenação”, o qual analisa o desempenho dos computadores em alocação de memória dinâmica, comparadores aritméticos e mudança de posição de um vetor na memória. Mais detalhes a respeito da execução deste programa se encontra no repositório registrado no site da disciplina, no projeto 1, parte 1.

Para a segunda parte, todos os membros de cada grupo foram realocados de maneira seletiva pelo professor da disciplina, para que os grupos tivessem a maior variedades de benchmarks diferentes para a realização do relatório, na parte 3. Fui alocado para o grupo F, onde estive presente com os alunos Pedro Vasconcellos, e o Pedro Grijó. Cada um de nós trouxe o projeto de benchmark realizado na etapa anterior, para que fizessemos registro dos dados de cada um dos programas dos outros integrantes do grupo. Eu, com o projeto “ordenação”; Pedro Vasconcellos, com o projeto “Gnuplot”, o qual cria um grafo com diversos nós e arestas, e analiza o tempo de processamento da máquina para instanciar este objeto computacional; E Pedro Grijó, com o projeto “Genetic”, o qual realiza projeções e analise de imagens, que no caso, foi realizado o processamento do quadro Monalisa. O detalhamento de como funciona cada um dos programas também se encontra na lista de repositórios  da parte 1. 
Todos os grupos fizeram a extração dos dados e registraram os mesmos no arquivo do google drive cujo link se encontra a seguir: <https://docs.google.com/spreadsheets/d/1c9JP7p0yYadZqwHrJEReNS8knAeSaMRDabaCDr-fwjg/edit#gid=0>

Para uma analise mais detalhista, em virtude de que não foi requerido de que coletassemos os dados de todos os benchmarks, a minha analise será restrita ao grupo o qual estive presente, tal qual também será restrita ás maquinas utilizadas pelos integrantes do grupo.  Para cada membro do grupo, foi utilizada o mesmo equipamento eletrônico, em todos os programas. Os dados de cada um dos computadores utilizado pelos membros do grupo F são:
<ul>
<li> <em>Pedro Meireles</em>: Intel® Core™ i5-4590 CPU @ 3.30GHz × 4;  Memory 8 GiB;  64-bit graph: Intel® Haswell Desktop , Gnome: Version 3.18.2; Disk 216.9 GB; Fedora 23 </li>
<li> <em>Pedro Grijó:</em>:Intel(R) Core(TM) i7-2670QM CPU @ 2.20GHz x4, 8GB DDR 1333Mhz ,Ubuntu 14.04LTS 32bits,HDD: SAMSUNG HN-M101MBB / 5400 RPM/ Sata III</li>
<li> <em>Pedro Vasconcellos</em>: Raspberry Pi, 900MHz quad-core ARM Cortex-A7 CPU, 1GB RAM, 32GB SD Card</li>
</ul>
Como cada um dos programas faz analises de diferentes componentes de hardware de cada um dos computadores, eles serão analisados individualmente, pelo desempenho comparativo de cada computador (ou seja, do melhor desempenho ao pior desempenho). Além disso, no final, será feita uma analise geral, verificando os padrões utilizados por cada computador (qual se manteve nos melhores desempenhos, e qual esteve no pior desempenho). Para esta análise, nos ateremos exclusivamente aos computadores descritos por cada membro do grupo F. 

<strong> 1. Benchmark Genetic: </strong>
Os tempos obtidos de cada um dos integrantes do grupo, através da extração devida dos dados, foram os seguintes:
#####tabela 1: dados coletados do benchmarck Genetic
| Nome do usuário    | Tempo(s) | Desvio padrão de tempo(s) | Performace de disco (MB/s) | Desvio padrão(MB/s) |
|--------------------|----------|---------------------------|----------------------------|---------------------|
| Pedro Meireles     | 48.8472  | 3.993094562               | 25.6797                    | 1.921797425         |
| Pedro Grijó        | 68.927   | 3.229                     | 56.627                     | 4.919               |
| Pedro Vasconcellos | 568.411  | 39.121                    | 10.3954                    | 0.682               |

Faremos duas analises comparativas para este benchmark: o tempo de execução do programa, e a performance do disco para a execução do programa.
Para o tempo de execução do programa, podemos ver que o computador que possui o menor tempo médio de execução de todos é o do Meireles, seguido do Grijó, e por último o do Vasconcellos, este levando aproximadamente 11 vezes mais do que a máquina com o menor tempo de execução. Levando isso em consideração, podemos supor que a máquina do Vasconcellos é a que possui o pior tempo de processamento, para um programa que exige processamento de imagem. Além disso, analisando o desvio padrão, podemos notar que a discrepância de tempos é muito pequena para os dois melhores tempos, mas relativamente alta para a máquina de pior desempenho. Mesmo o tempo de execução da mesma sendo muito maior do que as demais, se for feito uma comparação de proporção, calculando a razão entre o tempo médio pelo desvio padrão do tempo, para a máquina de pior desempenho (cuja razão equivale a aproximadamente 14.5), e a de melhor desempenho (cujo resultado equivale a aproximadamente 4.89), podemos ver que a discrepância de tempo da pior máquina, em relação ao tempo de execução, difere muito das outras máquinas executadas. 
Em relação a performance do disco, podemos ver que a máquina que possui a maior performance é a do Grijó, seguida do Meireles, e, novamente, por último, a do Vasconcellos. Isto sugere que, das três máquinas, definitivamente a pior para executar programas de processamento de imagem é a do Vasconcellos; No entanto, em imagens que possuem grandes dimensões, a máquina do Grijó possuirá uma performance melhor do que a do Meireles, visto que a performance do disco é aproximadamente 2 vezes maior; mas, para imagens menores, a do Meireles possui tendencia de executar mais rápido o programa, por ter o melhor tempo de processamento (além do fato de que o programa não se baseia somente em processamento de disco, incluindo fatores de processamento cujos dados só podem ser analisados pela performance de tempo, o qual a maquina do Meireles foi devidamente mais rápida do que a do Grijó).

<strong> 2. Benchmark Gnuplot: </strong>
Os tempos obtidos de cada um dos integrantes do grupo, através da extração devida dos dados, foram os seguintes:

#####tabela 2: dados coletados do benchmarck Gnuplot
| Nome do usuário    | Time elapsed (s) | cpu-clock (msec) | mem-stores             | bus-cycles     |
|--------------------|------------------|------------------|------------------------|----------------|
| Pedro Meireles     | 9.9518           | 9780.507075      | não foi possivel medir | 974, 385, 386    |
| Pedro Grijó        | 0.002921562      | 2.213035         | Não foi possível medir | 215,164        |
| Pedro Vasconcellos | 133.26618227     | 129662.762102    | Não foi possível medir | 58,343,431,876 |

Através da tabela acima, podemos concluir as seguintes informações a respeito de cada máquina utilizada:
Primeiramente, a máquina que teve o menor tempo de execução foi a máquina do Grijó, com um tempo assustadoramente pequeno de 0.002s. Além disso, ela também teve o menor tempo de clock do cpu, e o menor bus-cycles, o que induz que ela foi definitivamente a melhor em conseguir instanciar o grafo, do que todas as demais. Em comparação com a mais lenta, ela foi <em>66630 vezes</em> mais rápida em tempo de execução, aproximadamente.
Em segundo, a máquina intermediária foi a máquina do Meireles, a qual teve um tempo de execução de 3317 vezes mais lenta do que a mais rápida, mas no entanto 13 vezes mais rápida (em tempo de execução) do que a mais lenta de todas. Além disso, ela teve uma ordem de grandeza em relação ao bus-cycle bem intermédiario em relação as outras (a mais rápida teve ordem de grandeza de 10e5, enquanto a intermediária teve de 10e8, e a mais lenta teve de 10e10, onde a anotação (x)e(y) corresponde ao número x elevado ao número y), e o mesmo vale para o clock-cpu.
Por último, a máquina mais lenta corresponde, tal como na primeira parte, a do Vasconcellos, a qual também exige o maior valor de clock-cpu e bus-cycles, o que diz que ela foi a que mais dependeu de recursos físicos da máquina, para ainda assim, entregar o resultado no tempo de execução mais lento do que os demais. 


<strong> 3. Benchmark Ordenação: </strong>
Os tempos obtidos de cada um dos integrantes do grupo, através da extração devida dos dados, foram os seguintes:

#####tabela 3: dados coletados do benchmarck Ordenação
| Nome do usuário    | Média do pior caso, para o algoritmo mais lento. | Média do pior caso, para o algoritmo mais rápido | Média do caso médio, para o algoritmo mais lento. | Média do caso médio, para o algoritmo mais rápido | Média do melhor caso, para o algoritmo mais lento. | Média do melhor caso, para o algoritmo mais rápido. |
|--------------------|--------------------------------------------------|--------------------------------------------------|---------------------------------------------------|---------------------------------------------------|----------------------------------------------------|-----------------------------------------------------|
| Pedro Meireles     | Bubble Sort: 8.254946s                           | Quick Sort: 0.002482s                            | Bubble Sort: 5.760140s                            | Quick Sort: 0.002445s                             | Selection Sort: 5.645237s                          | Insertion Sort: 0.000240s                           |
| Pedro Grijó        | Bubblesort: 10.836368s                           | Quicksort: 0.002975s                             | Bubblesort: 7.277500s                             | Quicksort: 0.002971s                              | Selection Sort: 6.781425s                          | Insertion Sort: 0.000307s                           |
| Pedro Vasconcellos | Bubblesort: 192.888878s                          | Quicksort: 0.032364s                             | Bubblesort: 112.523956s                           | Quicksort: 0.031743s                              | Bubblesort: 86.418031s                             | Insertion Sort: 0.004234s                           |

A partir dos dados obtidos, podemos chegar as seguintes conclusões a respeito de cada máquina utilizada, para cada tipo de caso. 
* Para o pior caso: Todas as máquinas coencidiram para o método do melhor e pior algorítmo utilizados. Além disso, para o pior caso, tanto para o algorítmo mais lento para o mais rápido, a ordem das máquinas em execução de tempo foram o mesmo (Meireles, Grijó, e por último, Vasconcellos), embora a diferença de tempos entre a primeira e a segunda máquina foram pequenas (mas se tornam significativas para casos maiores do que os coletados neste benchmark), e da última máquina, gritantes.
* Para o caso médio: Todas as máquinas coencidiram para o método do melhor e pior algoritmo utilizados. Além disso, a ordem da máquina mais rápida para a mais lenta se manteve, e a mais lenta teve tempos mais distantes do que as duas primeiras máquinas.
* Para o melhor caso: A máquina do Vasconcellos diferiu para o algorítmo utilizado no algorítmo mais lento (ao inves de ser o selection sort, foi o bubble sort). Ainda assim, a ordem de tempo de execução se manteve, e o padrão da máquina mais lenta também ter os tempos mais discrepantes do que as demais, também. 

<strong> 4.Conclusão </strong>

Embora a máquina do Grijó tenha se destacado no segundo benchmark, a máquina que mais se manteve constante no desempenho como a mais confiável e segura para bons tempos de execução ainda assim foi a do Meireles, sendo a sugerida para a aplicação de tarefas complexas que exigem bons tempos de execução. 

A máquina menos confiavel de todas para a execução de tarefas é a máquina do Vasconcellos, por ter o pior tempo de execução em todos os programas de benchmark. O que sugere que a máquina do Vasconcellos não possui boas características de processamento e execução de programas, mas que provavelmente deve ter atribuído outras características físicas que a tornam viaveis para algumas aplicações (muito provavelmente, ela deve ser a máquina mais portátil das 3)