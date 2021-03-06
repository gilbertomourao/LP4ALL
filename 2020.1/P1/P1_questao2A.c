#include <stdio.h>
#include <linp.h>

/*Verifica se é alfanumérico*/
#define VALID_CHAR(ch) ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))

int main()
{
	lp.start();

	Linp_Mat *grid = lp.criarmat(100,100);

	lp.lerarquivo(grid, "matriz_P1.txt");
	lp.dispmat(grid, "Matriz de Entrada");

	/*Turma A*/

	int i, j, k;
	char aux; /*Para realizar a troca*/

	for (i = 0; i < grid->rows; i++)
	{
		for (j = 0; j < grid->cols; j++)
		{
			if (!VALID_CHAR(grid->data[i][j]))
				continue;
			for (k = j+1; k < grid->cols; k++)
			{
				if (!VALID_CHAR(grid->data[i][k]))
					continue;
				if(grid->data[i][j] > grid->data[i][k])
				{
					aux = grid->data[i][j];
					grid->data[i][j] = grid->data[i][k];
					grid->data[i][k] = aux;
				}
			}
		}
	}

	lp.dispmat(grid, "Matriz com linhas ordenadas");

	lp.stop();

	return 0;
}