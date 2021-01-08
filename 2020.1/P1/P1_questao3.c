#include <stdio.h>
#include <linp/linp.h>

int main()
{
	Linp_Matrix grid;

	lp.readmat(&grid, "matriz_P1.txt");

	lp.dispmat(&grid, "Matriz de Entrada");

	int i, j;

	for (i = 0; i < grid.rows; i++)
	{
		for (j = 0; j < grid.cols; j++)
		{
			if (grid.mat[i][j] >= 'A' && grid.mat[i][j] <= 'Z')
				grid.mat[i][j] += 'a' - 'A';
			else
				if (grid.mat[i][j] >= 'a' && grid.mat[i][j] <= 'z')
					grid.mat[i][j] += 'A' - 'a';			
		}
	}

	lp.dispmat(&grid, "Matriz com maiuscula <-> minuscula");

	return 0;
}