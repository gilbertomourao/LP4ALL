#include <stdio.h>
#include <linp/linp.h>

/*Verifica se é alfanumérico*/
#define VALID_CHAR(ch) ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))

int main()
{
	Linp_Matrix grid;

	lp.readmat(&grid, "matriz_P1.txt");

	lp.dispmat(&grid, "Matriz de Entrada");

	/*Turma A*/

	int i, j, k;
	char aux; /*Para realizar a troca*/

	for (i = 0; i < grid.rows; i++)
	{
		for (j = 0; j < grid.cols; j++)
		{
			if (!VALID_CHAR(grid.mat[i][j]))
				continue;
			for (k = j+1; k < grid.cols; k++)
			{
				if (!VALID_CHAR(grid.mat[i][k]))
					continue;
				if(grid.mat[i][j] > grid.mat[i][k])
				{
					aux = grid.mat[i][j];
					grid.mat[i][j] = grid.mat[i][k];
					grid.mat[i][k] = aux;
				}
			}
		}
	}

	lp.dispmat(&grid, "Matriz com linhas ordenadas");

	return 0;
}