<h1>Relatório do exercício 1 de Mc 723A.</h1>
<h2>Pedro Elias Lucas Ramos Meireles,  ra 148914.</h2>
<h3>Parte 1: compilando o código primo.c</h3>

<p>Na parte inicial do exercício 1, iniciado em 04/03/2016, foi dado aos alunos um código em C chamado primo.c, o qual deveria ser analisado o tempo de execução e de compilação do mesmo, para cada tipo de compilação executada pelo mesmo. </p>

<p>Por questão de boa prática de execução de programas, tanto a compilação quanto a execução de cada um dos métodos de compilação do programa foram executados 5 vezes, e foi calculado a média aritmética de cada um. A seguir, será relatado as médias de compilação e execução de cada um deles:</p>

<ol>
	<li>Compilação sem otimização (gcc primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.065 s.</li>
			<li>Tempo de execução: real = 0.384 s.</li>
		</ul>
	</li>

	<li>Compilação com otimização O0 (gcc -O0  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.055s.
			</li>
			<li>Tempo de execução: real = 0.350 s. 
			</li>
		</ul>
	</li>

	<li>Compilação com otimização O1 (gcc -O1  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.060 s.
			</li>
			<li>Tempo de execução: real = 0.318 s; 
			</li>
		</ul>
	</li>
	
	<li>Compilação com otimização O2 (gcc -O2  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.059 s.
			</li>
			<li>Tempo de execução: real = 0.310 s. 
			</li>
		</ul>
	</li>
	
	<li>Compilação com otimização O3 (gcc -O3  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.054s.
			</li>
			<li>Tempo de execução: real = 0.302 s. 
			</li>
		</ul>
	</li>
	
	<li>Compilação com otimização -mtune=native (gcc -mtune=native  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.062 s.
			</li>
			<li>Tempo de execução: real = 0.354 s. 
			</li>
		</ul>
	</li>
	
	<li>Compilação com otimização -mtune=generic (gcc -mtune=generic  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.092 s.
			</li>
			<li>Tempo de execução: real = 0.359 s. 
			</li>
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

<h3>Parte 2: Partindo o programa primo.c</h3>
<p>Nesta parte do exercício, o enunciado requere que o código primo.c seja separado pelos códigos main.c (que só contém a função main do primo.c) e o código calc_primo.c (que contem a função que verifica se um número é primo ou não).</p>
<p>Para esta parte, eu criei um Makefile que consiste em criar um programa nomeado <em>primo</em>, o qual será compilado pela melhor versão de otimização feita na Parte 1 do experimento (no caso, -O3). Também foi necessário criar um calc_primo.h, que consiste em um header que referencia a função primo(int n).</p>
<p>A seguir, segue os tempos de compilação e execução do código.</p>
<ul>
   <li> Tempo de compilação: real = 0.038 s . 
   </li>
	<li>Tempo de execução: real = 0.372 s. </li>

</ul>
<p>A partir dessas informações, podemos concluir que o tempo de compilação piorou drasticamente, enquanto que o tempo de execução real se manteve constante. </p>


<h4>Referências: </h4>
<ul>
     <li><p>Esse é um <a href = "http://sdf.org/~riley/blog/2014/10/30/march-mtune/" title ="-march -mtune, What's the Difference?" > link</a> para descrição breve de quando usar -mtune e -march.</p> 
   </li>
   <li> <p>Esse é um <a href = "https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html" title = "Options That Control Optimization" > link</a> para descrição de cada otimização -O. </p>
   </li>
</ul>
