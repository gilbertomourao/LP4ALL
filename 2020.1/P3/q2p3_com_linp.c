/**
 * Solução da questão 2 da prova 3 com LINP
 */

#include <linp.h>

void transforma(Linp_Mat *);

int main()
{
	lp.start();

	Linp_Mat *mat = lp.criarmat(100, 100);

	lp.lerarquivo(mat, "matriz.txt");

	lp.dispmat(mat, "Matriz Original");
	transforma(mat);
	lp.dispmat(mat, "Matriz Transformada");

	lp.stop();

	return 0;
}

void transforma(Linp_Mat *mat)
{
	unsigned i, j;
	for (i = 0; i < mat->rows; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			if (mat->data[i][j] >= 'A' && mat->data[i][j] <= 'Z')
				mat->data[i][j] += 'a' - 'A';
			else 
				if (mat->data[i][j] >= 'a' && mat->data[i][j] <= 'z')
					mat->data[i][j] += 'A' - 'a';
		}
	}
}