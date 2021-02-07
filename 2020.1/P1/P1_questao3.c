#include <stdio.h>
#include <linp.h>

int main()
{
	Linp_Mat *grid = lp.criarmat(100,100);

	lp.lerarquivo(grid, "matriz_P1.txt");
	lp.dispmat(grid, "Matriz de Entrada");

	int i, j;

	for (i = 0; i < grid->rows; i++)
	{
		for (j = 0; j < grid->cols; j++)
		{
			if (grid->data[i][j] >= 'A' && grid->data[i][j] <= 'Z')
				grid->data[i][j] += 'a' - 'A';
			else
				if (grid->data[i][j] >= 'a' && grid->data[i][j] <= 'z')
					grid->data[i][j] += 'A' - 'a';			
		}
	}

	lp.dispmat(grid, "Matriz com maiuscula <-> minuscula");

	lp.destruirmat(grid);

	return 0;
}