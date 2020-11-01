#include <stdio.h>
#include <linp/linp.h>

int main()
{
	Linp_Matrix grid;

	lp.readmat(&grid, "matriz_P1.txt");

	lp.dispmat(&grid, "Matriz de Entrada");

	lp.palihunt(&grid, "true", "rows", '*');
	/**
	 * Para a turma b, basta substituir rows por cols no terceiro argumento
	 */

	lp.dispmat(&grid, "Matriz com Palindromos Identificados");

	return 0;
}