/**
 * Caça-Palíndromos ignorando espaço (faz mais sentido do que não ignorar)
 */

#include <stdio.h>
#include <linp.h>

int main()
{
	Linp_Mat *src = lp.criarmat(100,100);
	Linp_Mat *dst = lp.criarmat(100,100);
	Linp_Word **palindromos;

	lp.lerarquivo(src, "matriz_P1.txt");
	lp.dispmat(src, "Matriz de Entrada");

	/**
	 * Ver código fonte da função procpali em linp/src/proc.c
	 */
	lp.procpali(src, dst, &palindromos, "linhas", " ", true);
	/**
	 * Para a turma b, basta substituir linhas por colunas no quarto argumento
	 */

	lp.dispmat(dst, "Matriz com Palindromos Identificados");

	Linp_Word *varre = palindromos[0];
	while (varre)
	{
		printf("Palindromo encontrado: %s, entre [%u][%u] e [%u][%u]\n", varre->word, 
			   varre->y0, varre->x0, varre->y1, varre->x1);
		varre = varre->next;
	}

	/**
	 * Libera a memória previamente alocada
	 */
	lp.destruirmat(src);
	lp.destruirmat(dst);
	lp.destruirword(palindromos, 1);

	return 0;
}