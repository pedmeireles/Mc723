<h1>Relatório do exercício 1 de Mc 723A.</h1>
<h2>Pedro Elias Lucas Ramos Meireles,  ra 148914.</h2>
<h3>Parte 1: compilando o código primo.c</h3>

<p>Na parte inicial do exercício 1, iniciado em 04/03/2016, foi dado aos alunos um código em C chamado primo.c, o qual deveria ser analisado o tempo de execução e de compilação do mesmo, para cada tipo de compilação executada pelo mesmo. </p>

<p>Por questão de boa prática de execução de programas, tanto a compilação quanto a execução de cada um dos métodos de compilação do programa foram executados 5 vezes, e foi calculado a média aritmética de cada um. A seguir, será relatado as médias de compilação e execução de cada um deles:</p>

<ol>
	<li>Compilação sem otimização (gcc primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.085 s ; user = 0.034 s  ; system = 0.016 s.
			</li>
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
			<li>Tempo de compilação: real = 0.z s ; user = 0.x s; system = 0.c s.
			</li>
			<li>Tempo de execução: real = 0.x s; user = 0.z s; system = 0.v s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização O2 (gcc -O2  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.x s ; user = 0.x ; system = 0.x s.
			</li>
			<li>Tempo de execução: real = 0.x s; user = 0.x s; system = 0.x s. </li>
		</ul>
	</li>
	
	<li>Compilação com otimização O3 (gcc -O3  primo.c -o primo):
		<ul>
			<li>Tempo de compilação: real = 0.x s ; user = 0.x s ; system = 0.x s.
			</li>
			<li>Tempo de execução: real = 0.x s; user = 0.x s; system = 0.x s. </li>
		</ul>
	</li>

</ol>
