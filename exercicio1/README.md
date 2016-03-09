<h1>Relatório do exercício 1 de Mc 723A.</h1>
<h2>Pedro Elias Lucas Ramos Meireles,  ra 148914.</h2>
<h3>Parte 1: compilando o código primo.c</h3>

<p>Na parte inicial do exercício 1, iniciado em 04/03/2016, foi dado aos alunos um código em C chamado primo.c, o qual deveria ser analisado o tempo de execução e de compilação do mesmo, para cada tipo de compilação executada pelo mesmo. </p>

<p>Por questão de boa prática de execução de programas, tanto a compilação quanto a execução de cada um dos métodos de compilação do programa foram executados 5 vezes, e foi calculado a média aritmética de cada um. A seguir, será relatado as médias de compilação e execução de cada um deles:</p>

<ol>
	<li>Compilação sem otimização (gcc primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.085 s ; user = 0.034 s  ; system = 0.016 s. </li>
			<li>Tempo de execução: real = 0.400 s; user = 0.398s; system = 0.001 s. </li>
		</ul>
	</li>

	<li>Compilação com otimização O0 (gcc -O0  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.072 s ; user = 0.033 s ; system = 0.020 s.
			</li>
			<li>Tempo de execução: real = 0.401 s; user = 0.398 s; system = 0.002 s. </li>
		</ul>
	</li>

	<li>Compilação com otimização O1 (gcc -O1  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.076 s ; user = 0.036 s; system = 0.021 s.
			</li>
			<li>Tempo de execução: real = 0.399 s; user = 0.397 s; system = 0.001 s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização O2 (gcc -O2  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.088 s ; user = 0.42 ; system = 0.019 s.
			</li>
			<li>Tempo de execução: real = 0.398 s; user = 0.396 s; system = 0.001 s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização O3 (gcc -O3  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.080 s ; user = 0.044 s ; system = 0.017 s.
			</li>
			<li>Tempo de execução: real = 0.398 s; user = 0.396 s; system = 0.001 s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização -mtune=native (gcc -mtune=native  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.076 s ; user = 0.034 s ; system = 0.020 s.
			</li>
			<li>Tempo de execução: real = 0.400 s; user = 0.398 s; system = 0.001 s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização -mtune=generic (gcc -mtune=generic  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.071 s ; user = 0.033 s ; system = 0.021 s.
			</li>
			<li>Tempo de execução: real = 0.401 s; user = 0.399 s; system = 0.001 s. </li>
		</ul>
	</li>
	
	

</ol>

<p>Vale ressaltar alguns pontos importantes para esta primeira parte do relatório: </p>

<ul>
   <li>
      <p>A versão que teve o tempo de execução real mais rápido foi quando o código primo foi compilado em otimização -O3.  </p>
   </li>
   <li>
      <p>-mtune=native : ele compila o código para a versão que melhor execute no processador da máquina utilizada. Ele tem um custo de tempo de compilação um pouco maior, visto que ele tem que detectar qual o processador é o da máquina utilizada. Estranhamente, ele não melhorou tanto o tempo de execução do programa primo.c, a ponto de que este não foi o método de compilação mais eficiente para a execução do programa. </p>
     
   </li>
   <li>
      <p>-mtune=generic : Ele compila o programa para a versão que abrange o maior número de processadores utilizados atualmente, tornando o código o mais compativel a maioria dos processadores. Este método não gerou grandes otimizações de execução do programa, sendo superado pelo método de otimização de compilação -O3.  </p>
   </li>
</ul>

<h3>Parte 2: Partindo o programa primo.c em duas </h3>
<p>Nesta parte do exercício, o enunciado requere que o código primo.c seja separado pelos códigos main.c (que só contém a função main do primo.c) e o código calc_primo.c (que contem a função que verifica se um número é primo ou não).</p>
<p>Para esta parte, eu criei um Makefile que consiste em criar um programa nomeado <em>primo</em>, o qual será compilado pela melhor versão de otimização feita na Parte 1 do experimento (no caso, -O3).Além disso, foi necessário criar um arquivo calc_primo.h, que contem o cabeçalho da função primo(int n), para conseguir linkar ambos os códigos fonte.</p>
<p>A seguir, segue os tempos de compilação e execução do código.</p>
<ul>
   <li> Tempo de compilação: real = 0.055 s ; user = 0.019 s ; system = 0.011 s. </li>
	<li>Tempo de execução: real = 0.400 s; user = 0.399 s; system = 0.001 s. </li>

</ul>
<p>A partir dessas informações, podemos concluir que o tempo de compilação melhorou drasticamente, enquanto que o tempo de execução decresceu levemente. </p>


<h3>Parte 3: Alterando levemente o código primo.c</h3>

<p>Para esta parte, foi requisitado de que fosse feita uma pequena alteração do código primo.c para que ele contasse todos os primos no intervalo 1 até a entrada n (que deveria ser inserida por linha de comando).</p>

<p>Essas alteração leve, sem que alterasse o código que confirma se um número é primo, somente alterando a função main do programa. </p>

<p>Compilando esta nova versão do programa, tanto para um arquivo fonte para dois arquivos fontes, testando para uma entrada <strong>n = 100000</strong>, chegamos as seguintes informações:</p>
<ol>
<li>Programa compilado para um código fonte, sem otimização:
		<ul>
			<li>Tempo de compilação: real = 0.093 s, user = 0.031 s, system =0.017 s . </li>
			<li>Tempo de execução: real = 1.733 s, user = 1.731s, system =0.001 s </li>
		</ul>
	
	</li>
	<li>Programa compilado para um código fonte, com otimização -O3:
		<ul>
			<li>Tempo de compilação: real = 0.097 s, user = 0.018 s, system =0.017 s . </li>
			<li>Tempo de execução: real = 1.726 s, user = 1.724 s, system =0.001 s </li>
		</ul>
	
	</li>
<li>Programa compilado para dois códigos fontes, sem otimização:
		<ul>
			<li>Tempo de compilação: real = 0.051 s, user = 0.031 s, system =0.010 s . </li>
			<li>Tempo de execução: real = 1.738 s, user = 1.736s, system =0.002 s </li>
		</ul>
	
	</li>
	<li>Programa compilado para dois códigos fontes, com otimização -O3:
		<ul>
			<li>Tempo de compilação: real = 0.053 s, user = 0.019 s, system =0.009 s . </li>
			<li>Tempo de execução: real = 1.734 s, user = 1.731 s, system =0.002 s </li>
		</ul>
	</li>
</ol>

<p>A partir dessa informação, podemos notar que foi confirmado que usar dois códigos fontes melhora o tempo de compilação do programa, mas que isso faz com que o programa fique levemente mais lento no mesmo. Além disso, a otimização -O3 acelerou o tempo de execução em ambas as circinstancias, para o mesmo número de códigos fontes.</p>



<h4>Referências: </h4>
<ul>
     <li><p>Esse é um <a href = "http://sdf.org/~riley/blog/2014/10/30/march-mtune/" title ="-march -mtune, What's the Difference?" > link</a> para descrição breve de quando usar -mtune e -march.</p> 
   </li>
   <li> <p>Esse é um <a href = "https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html" title = "Options That Control Optimization" > link</a> para descrição de cada otimização -O. </p>
   </li>
</ul>
