#include <stdio.h>
#include <linp.h>

#define MAX_SIZE 100

int main()
{
	lp.start(); /* Inicializa um bloco LINP */

	Linp_Mat *matriz = lp.criarmat(MAX_SIZE, MAX_SIZE);
	Linp_Mat *dst = lp.criarmat(MAX_SIZE, MAX_SIZE);
	Linp_Word **palindromos = NULL;

	lp.lerarquivo(matriz, "matriz_q1_P1.txt");

	lp.dispmat(matriz, "Matriz original");

	lp.procpali(matriz, dst, &palindromos, "C", "", true, 3);

	/* Mantém apenas o primeiro palíndromo identificado em cada coluna */
	Linp_Word *varre = palindromos[0];
	int coluna_atual = varre->x0;
	int cont = 0; /* contador de excesso de palíndromos */
	int pali_y1, pali_x0;
	int i, j;

	/* conta quantos palíndromos procpali identificou por coluna */
	while (varre->next)
	{
		varre = varre->next;
		if (varre->x0 == coluna_atual)
		{
			/* Já identifica como coluna com mais de um palíndromo */
			cont++;
			/* Salva a posição do último palíndromo identificado no for, primeiro na lista */
			pali_y1 = varre->y1;
			pali_x0 = varre->x0;
		}
		else
		{
			/* Está em outra coluna */
			coluna_atual = varre->x0;

			/* Se cont não for nulo, há mais de um palíndromo na coluna*/
			if (cont)
			{
				/* Elimina todos os outros palíndromos da coluna */
				for (i = pali_y1 + 1; i < dst->rows; i++)
				{
					dst->data[i][pali_x0] = (char) 250;
				}
			}
		}
	}

	/* A questão pede para substituir as não ocorrências por '*' */
	for (i = 0; i < dst->rows; i++)
	{
		for (j = 0; j < dst->cols; j++)
		{
			dst->data[i][j] = (dst->data[i][j] == (char) 250) ? '*' : dst->data[i][j];
		}
	}

	lp.dispmat(dst, "Matriz de palindromos");

	lp.stop(); /* Finaliza o bloco LINP criado */

	return 0;
}