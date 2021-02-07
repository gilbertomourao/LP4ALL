#include <stdio.h>
#include <linp.h>

/*Verifica se é alfanumérico*/
#define VALID_CHAR(ch) ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))

int main()
{
	Linp_Mat *grid = lp.criarmat(100,100);

	lp.lerarquivo(grid, "matriz_P1.txt");
	lp.dispmat(grid, "Matriz de Entrada");

	/*Turma A*/

	int i, j, k;
	char aux; /*Para realizar a troca*/

	for (j = 0; j < grid->cols; j++)
	{
		for (i = 0; i < grid->rows; i++)
		{
			if (!VALID_CHAR(grid->data[i][j]))
				continue;
			for (k = i+1; k < grid->rows; k++)
			{
				if (!VALID_CHAR(grid->data[k][j]))
					continue;
				if(grid->data[i][j] > grid->data[k][j])
				{
					aux = grid->data[i][j];
					grid->data[i][j] = grid->data[k][j];
					grid->data[k][j] = aux;
				}
			}
		}
	}

	lp.dispmat(grid, "Matriz com colunas ordenadas");

	lp.destruirmat(grid);

	return 0;
}
