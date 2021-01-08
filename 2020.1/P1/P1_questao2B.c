#include <stdio.h>
#include <linp/linp.h>

/*Verifica se é alfanumérico*/
#define VALID_CHAR(ch) ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))

int main()
{
	Linp_Matrix grid;

	lp.readmat(&grid, "matriz_P1.txt");

	lp.dispmat(&grid, "Matriz de Entrada");

	/*Turma B*/

	int i, j, k;
	char aux; /*Para realizar a troca*/

	for (j = 0; j < grid.cols; j++)
	{
		for (i = 0; i < grid.rows; i++)
		{
			if (!VALID_CHAR(grid.mat[i][j]))
				continue;
			for (k = i+1; k < grid.rows; k++)
			{
				if (!VALID_CHAR(grid.mat[k][j]))
					continue;
				if(grid.mat[i][j] > grid.mat[k][j])
				{
					aux = grid.mat[i][j];
					grid.mat[i][j] = grid.mat[k][j];
					grid.mat[k][j] = aux;
				}
			}
		}
	}

	lp.dispmat(&grid, "Matriz com colunas ordenadas");

	return 0;
}