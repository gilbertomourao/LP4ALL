/**
 * Questão 3 - solução não elegante
 */

#include <stdio.h>

#define MAX_SIZE 100

void limpabuffer();
void lermatdim(int *, int *);
void lermat(int (*)[], int, int);
void printmat(int (*)[], int, int);
void trocardiag(int (*)[], int, int);

int main()
{
	int L, C; /* linhas e colunas da matriz */
	int mat[MAX_SIZE][MAX_SIZE];

	lermatdim(&L, &C);
	lermat(mat, L, C);
	printmat(mat, L, C);
	trocardiag(mat, L, C);
	printmat(mat, L, C);

	return 0;
}

void limpabuffer()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void lermatdim(int *linhas, int *colunas)
{
	do
	{
		printf("Linhas (numero inteiro positivo): ");
		scanf("%d", linhas); limpabuffer();
	} while (*linhas <= 0);

	do
	{
		printf("Colunas (numero inteiro positivo): ");
		scanf("%d", colunas); limpabuffer();
	} while (*colunas <= 0);
}

void lermat(int (*mat)[MAX_SIZE], int linhas, int colunas)
{
	int i, j;

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]); limpabuffer();
		}
	}
}

void printmat(int (*mat)[MAX_SIZE], int linhas, int colunas)
{
	int i, j;

	printf("\n~Matriz\n\n");

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');
}

void trocardiag(int (*mat)[MAX_SIZE], int linhas, int colunas)
{
	int i, j;
	int aux;

	for (i = 0, j = colunas-1; i < linhas; i++, j--)
	{
		aux = mat[i][i];
		mat[i][i] = mat[i][j];
		mat[i][j] = aux;
	}
}