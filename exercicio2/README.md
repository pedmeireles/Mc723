# Exercício 2 de Mc723: Configurações de cache
## 1º semestre de 2016. 
## Pedro Elias Lucas Ramos Meireles, Ra 148914.

O objetivo geral do exercício 2 é, através da utilização do software *dinero*, realizar traces de execução já coletados para definir qual a melhor configuração de caches para alguns dos programas. 
Vale ressaltar alguns pontos, antes de realizar a análise do relatório.
* Através da pesquisa realizada pela referência *[1]*, descrita no final do relatório, foi extraída a seguinte informação: 
" O cache L1 é sempre muito pequeno (de 32 a 128 KB) e oferece tempos de acesso muito baixos, equivalentes a apenas 3  ou 4 ciclos (o que em um processador de 3.0 GHz equivale a apenas 1 ou 1.33 nanossegundos). Entretanto, todo esse desempenho tem um custo, que é a necessidade de usar células com mais transístores, controladores mais sofisticados e mais trilhas de acesso, o que torna o cache L1 muito caro em termos de transístores usados.'
"O cache L2 por sua vez é baseado no uso de células mais lentas, com controladores mais simples e menos linhas de dados. Isso permite que o cache L2 seja sempre muito maior (de 256 KB a 2 MB), mas ele em compensação trabalha com  tempos de acesso mais altos, de tipicamente 10 a 15 ciclos"

Logo, para a extração dos dados, eu considerei as expecificações reais de uma cache L1, e para tanto, nenhum dos programas terá uma cache L1 maior do que 128 KB, mesmo que isso otimizasse ainda mais o miss rate da execução dos programas.
* Para otimizar o miss rate de uma cache, existe algumas técnicas que funcionam, dentre elas:

  - **Aumentar o tamanho da cache**: Aumentando o tamanho de uma cache, aumenta o número de informações que pode ser armazenada nela. No entando, existe um custo de manufatura para isso, e caches L1 tendem a ser muito caras para se extrapolar no tamanho delas. No cenário ao qual trabalhei, supus que estamos trabalhando com computadores e máquinas de consumo para usuários final, domésticos, e para isso, o custo de manufatura não deve extrapolar um custo exarcebado e inviável de se comercializar. Para tanto, o tamanho máximo de qualquer uma das caches L1 respeitará o limite de 128K.
  - **Aumentar o tamanho do bloco**: Aumentando o tamanho do bloco, para um determinado intervalo, fará com, que fato, o miss rate de execução dos programas caia, por é possivel pegar um número maior de blocos de informação da memória. Mas fazer isso acarreta numa diminuição do número diversificado de intervalos que é possivel obter de um programa (ou seja, isso diminui a altura da cache), e como consequencia, para tamanhos de blocos muito grandes, o miss rate irá aumentar abruptamente. Este fenómeno será estudado ao longo deste relatório.
  Para este relatório, não foi limitado o tamanho do bloco de nenhuma cache. A analise do tamanho do bloco será exclusivamente no ponto do grafico o qual se chega ao vale mínimo do miss rate. 
* __O estudo dos programas será feito individualmente__. Não será construido uma cache L1 global que otimize todos os tempos, mas sim uma cache específica que seja capaz de melhorar os programas individualmente. Fazer o estudo da melhor cache global pode ser ploblemático, devido ao fato de que o melhor método para fazer isso é através da aplicação da média geométrica (pois esta é a melhor média para realizar estudos de atributos similares, mas que possuem diferenças distintas), e além disso, houve medições o qual o miss rate foi zero. O que implica que haverá médias nulas, o que não contribui de nenhuma maneira para um estudo decente de estipulação de uma cache L1 de instrução e dados global. 
* O valor base do bloco da cache, para estudo da variação dos tamanhos da cache, foi 32b.
* O valor base utilizado para estudo da variação do tamanho do bloco será o melhor Demand miss Rate do respectivo programa e cache. Este dado será informado ao longo da explicação do programa, e também será fornecido nas tabelas. 

###Análise dos programas.

A seguir, será feito o estudo dos seguintes programas selecionados por mim:
1. Equake.f2b;
2. Lucas.m2b;
3. Swim.m2b
4. Gcc.f2b.

O estudo deles foi feito através do trace de execução e a utilização da ferramenta *dinero*. 
####Equake.f2b.
A seguir, será apresentado as seguintes tabelas, nas suas respectivas ordens:

Tabela 1: Variação do tamanho da cache L1 de instruções. Tamanho do bloco de instruções: 32b

| Size of Block (b) | Size of Memoryruction) (Kb) | Demand Miss Rate |
|---------------|----------------------------|------------------|
| 32            | 16                         | 0.0221           |
| 32            | 32                         | 0.0136           |
| 32            | 64                         | 0.0024           |
| 32            | 128                        | 0                |


 Tabela 2: Variação do tamanho da cache L1 de dados.  Tamanho do bloco de dados: 32b
 
| Size of Block (b) | Size of Memory (data) (Kb) | Demand Miss Rate (Data) |
|----------------------|---------------------------|-------------------------|
| 32                   | 16                        | 0.0077                  |
| 32                   | 32                        | 0.0033                  |
| 32                   | 64                        | 0.0023                  |
| 32                   | 128                       | 0.0021                  |

 Tabela 3: Variação do tamanho do bloco da cache L1 de dados. Tamanho da cache L1 de dados: 128Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|----------------|--------------------|-------------------|
| 32             | 128                | 0.0021            |
| 64             | 128                | 0.0023            |
| 128            | 128                | 0.0019            |
| 256            | 128                | 0.003             |
| 512            | 128                | 0.0043            |
| 1024           | 128                | 0.0047            |

Tabela 4: Variação do tamanho do bloco da cache L1 de instruções. Tamanho da cache L1 de instruções: 128Kb

| Size of Block (b) | Size of Memoryruction) (Kb) | Demand Miss Rate |
|---------------|----------------------------|------------------|
| 32            | 128                        | 0                |
| 64            | 128                        | 0                |
| 128           | 128                        | 0                |
| 256           | 128                        | 0                |
| 512           | 128                        | 0.0005           |
| 1024          | 128                        | 0.0005           |


A seguir, será ilustrado o gráfico de cada uma das tabelas, enumerado apropriadamente:

![alt text][grafico1]

![alt text][grafico2]

 ![alt text][grafico3]

 ![alt text][grafico4]

A partir destes gráficos, podemos concluir que a melhor configuração das caches L1 são:
* Cache L1 de instrução: 128Kb de tamanho total, e 256b de bloco;
* Cache L1 de dados: 128Kb de tamanho total, e 128b de bloco. Vale ressaltar que ocorreu uma anomalia no gráfico, pois ouve dois momentos o qual ele sofreu ascensão de demand miss rate, e o usual é que este tipo de ascensão só ocorre uma vez. Neste caso, foi selecionado o mínimo entre os dois vales (o menor deles).

####Lucas.m2b
A seguir, será apresentado as seguintes tabelas, nas suas respectivas ordens:

Tabela 5: Variação do tamanho da cache L1 de instruções. Tamanho do bloco de instruções: 32b

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 16                  | 0                 |
| 32                | 32                  | 0                 |
| 32                | 64                  | 0                 |
| 32                | 128                 | 0                 |


 Tabela 6: Variação do tamanho da cache L1 de dados.  Tamanho do bloco de dados: 32b
 
| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 16                  | 0.1588            |
| 32                | 32                  | 0.1549            |
| 32                | 64                  | 0.1529            |
| 32                | 128                 | 0.1519            |

 Tabela 7: Variação do tamanho do bloco da cache L1 de instruções. Tamanho da cache L1 de dados: 16Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate |
|-------------------|---------------------|------------------|
| 32                | 16                  | 0                |
| 64                | 16                  | 0                |
| 128               | 16                  | 0                |
| 256               | 16                  | 0                |
| 512               | 16                  | 0                |
| 1024              | 16                  | 0                |
| 2048              | 16                  | 0                |
| 4096              | 16                  | 0                |

 Tabela 8: Variação do tamanho do bloco da cache L1 de dados. Tamanho da cache L1 de instruções: 128Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 128                 | 0.1519            |
| 64                | 128                 | 0.0813            |
| 128               | 128                 | 0.0473            |
| 256               | 128                 | 0.0314            |
| 512               | 128                 | 0.2096            |
| 1024              | 128                 | 0.2292            |
| 2048              | 128                 | 0.2467            |
| 4096              | 128                 | 0.2773            |


A seguir, será ilustrado o gráfico de cada uma das tabelas, enumerado apropriadamente:

![alt text][grafico5]

![alt text][grafico6]

 ![alt text][grafico7]

 ![alt text][grafico8]

A partir destes gráficos, podemos concluir que a melhor configuração das caches L1 são:
* Cache L1 de instrução: 16Kb de tamanho total, e tamanho irrelevante do bloco (neste caso, atribuido o mesmo valor que na cache de dados, que foi de 256b);
* Cache L1 de dados: 128Kb de tamanho total, e 256b de bloco.


####Swim.m2b
A seguir, será apresentado as seguintes tabelas, nas suas respectivas ordens:

Tabela 9: Variação do tamanho da cache L1 de instruções. Tamanho do bloco de instruções: 32b

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 16                  | 0                 |
| 32                | 32                  | 0                 |
| 32                | 64                  | 0                 |
| 32                | 128                 | 0                 |


 Tabela 10: Variação do tamanho da cache L1 de dados.  Tamanho do bloco de dados: 32b
 
| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate |
|-------------------|---------------------|------------------|
| 32                | 16                  | 0.1812           |
| 32                | 32                  | 0.1808           |
| 32                | 64                  | 0.1805           |
| 32                | 128                 | 0.1476           |

Tabela 11: Variação do tamanho do bloco da cache L1 de instruções. Tamanho da cache L1 de dados: 16Kb

| Size of Block  (b) | Size of Memory (Kb) | Demand Miss Rate  |
|--------------------|---------------------|-------------------|
| 32                 | 16                  | 0                 |
| 64                 | 16                  | 0                 |
| 128                | 16                  | 0                 |
| 256                | 16                  | 0                 |
| 512                | 16                  | 0                 |
| 1024               | 16                  | 0                 |
| 2048               | 16                  | 0                 |

 Tabela 12: Variação do tamanho do bloco da cache L1 de dados. Tamanho da cache L1 de instruções: 128Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate |
|-------------------|---------------------|------------------|
| 32                | 128                 | 0.1476           |
| 64                | 128                 | 0.074            |
| 128               | 128                 | 0.0373           |
| 256               | 128                 | 0.019            |
| 512               | 128                 | 0.01             |
| 1024              | 128                 | 0.0708           |
| 2048              | 128                 | 0.1289           |


A seguir, será ilustrado o gráfico de cada uma das tabelas, enumerado apropriadamente:

![alt text][grafico9]

![alt text][grafico10]

 ![alt text][grafico11]

 ![alt text][grafico12]

A partir destes gráficos, podemos concluir que a melhor configuração das caches L1 são:
* Cache L1 de instrução: 16Kb de tamanho total, e tamanho irrelevante do bloco (neste caso, atribuido o mesmo valor que na cache de dados, que foi de 512);
* Cache L1 de dados: 128Kb de tamanho total, e 512b de bloco, onde se encontrou a ponta do vale.
 
####Gcc.f2b
A seguir, será apresentado as seguintes tabelas, nas suas respectivas ordens:

Tabela 13: Variação do tamanho da cache L1 de instruções. Tamanho do bloco de instruções: 32b

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 16                  | 0.0325            |
| 32                | 32                  | 0.0185            |
| 32                | 64                  | 0.0109            |
| 32                | 128                 | 0.0026            |

 Tabela 14: Variação do tamanho da cache L1 de dados.  Tamanho do bloco de dados: 32b
 
| Size of Block (b)   | Size of Memory (Kb) | Demand Miss Rate |
|---------------------|---------------------|------------------|
| 32                  | 16                  | 0.0435           |
| 32                  | 32                  | 0.0276           |
| 32                  | 64                  | 0.017            |
| 32                  | 128                 | 0.012            |

Tabela 15: Variação do tamanho do bloco da cache L1 de instruções. Tamanho da cache L1 de dados: 128Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate |
|-------------------|---------------------|------------------|
| 32                | 128                 | 0.0026           |
| 64                | 128                 | 0.0023           |
| 128               | 128                 | 0.0018           |
| 256               | 128                 | 0.0017           |
| 512               | 128                 | 0.0015           |
| 1024              | 128                 | 0.0016           |

 Tabela 16: Variação do tamanho do bloco da cache L1 de dados. Tamanho da cache L1 de instruções: 128Kb

| Size of Block (b) | Size of Memory (Kb) | Demand Miss Rate  |
|-------------------|---------------------|-------------------|
| 32                | 128                 | 0.012             |
| 64                | 128                 | 0.0102            |
| 128               | 128                 | 0.0095            |
| 256               | 128                 | 0.0102            |
| 512               | 128                 | 0.0137            |
| 1024              | 128                 | 0.0205            |

A seguir, será ilustrado o gráfico de cada uma das tabelas, enumerado apropriadamente:

![alt text][grafico13]

![alt text][grafico14]

 ![alt text][grafico15]

 ![alt text][grafico16]

A partir destes gráficos, podemos concluir que a melhor configuração das caches L1 são:
* Cache L1 de instrução: 128Kb de tamanho total, e tamanho do bloco 512b
* Cache L1 de dados: 128Kb de tamanho total, e 128b de bloco, onde se encontrou a ponta do vale.

####Observações finais

Para os programas terminados em .m2b, foi notado de que eles não precisam de uma cache de instruções muito grandes, devido ao fato de já estar no meio do fluxo de execução. Eles precisam de caches de dados mais otimizadas, por fazer buscas frequentes de dados ao longo da execução dos respectivos programas.

Para tanto, para estudar melhor as caches de instrução, melhor avaliar mais os pontos dos programas terminados em .f2b, pois estes exigem maior variação do fluxo de instruções dos programas, exigindo mais da cache L1 de instrução. 

A conclusão de qual a melhor configuração de cada cache se encontra ao final de cada análise dos programas.

O número de iterações utilizadas no *dinero* foi de 20 execuções. 


### Referencias

[[1]](http://www.hardware.com.br/dicas/entendendo-cache.html) : Descrição breve para melhor interpretação de caches.

[Wikipedia] (https://pt.wikipedia.org/wiki/Cache#Cache_L1) (2) : Explicações breves sobre cache L1

[grafico1]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico1.png
[grafico2]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico2.png
[grafico3]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico3.png
[grafico4]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico4.png
[grafico5]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico5.png
[grafico6]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico6.png
[grafico7]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico7.png
[grafico8]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico8.png
[grafico9]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico9.png
[grafico10]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico10.png
[grafico11]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico11.png
[grafico12]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico12.png
[grafico13]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico13.png
[grafico14]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico14.png
[grafico15]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico15.png
[grafico16]:https://github.com/pedmeireles/Mc723/blob/master/exercicio2/Gr%C3%A1ficos/Grafico16.png
