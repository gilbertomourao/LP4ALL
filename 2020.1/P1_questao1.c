#include <stdio.h>
#include <linp/linp.h>

int main()
{
	Linp_Matrix grid;

	lp.readmat(&grid, "matriz_P1.txt");

	lp.dispmat(&grid, "Matriz de Entrada");

	/**
	 * Ver código fonte da função palihunt em linp/src/palihunt.c
	 */
	lp.palihunt(&grid, "print", "rows", '*');
	/**
	 * Para a turma b, basta substituir rows por cols no terceiro argumento
	 */

	lp.dispmat(&grid, "Matriz com Palindromos Identificados");

	return 0;
}