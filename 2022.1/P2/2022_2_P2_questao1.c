#include <stdio.h>

/* MACROS */
#define MAX_SIZE 100

/* structs */
typedef struct Matriz
{
	int rows;
	int cols;
	int data[MAX_SIZE][MAX_SIZE];
} Matriz;

/* FUNCOES */
void ler_matriz(Matriz *mat)
{
	int rows, cols;

	/* Leitura de linhas */
	do 
	{
		printf("Digite a quantidade de linhas da matriz: ");
		scanf("%d", &rows);
		if (rows < 1 || rows > MAX_SIZE)
		{
			printf("Valor invalido!!! Digite um numero positivo e menor que %d!", MAX_SIZE);
		}
	} while (rows < 1 || rows > MAX_SIZE);

	/* Leitura de colunas */
	do 
	{
		printf("Digite a quantidade de colunas da matriz: ");
		scanf("%d", &cols);
		if (cols < 1 || cols > MAX_SIZE)
		{
			printf("Valor invalido!!! Digite um numero positivo e menor que %d!", MAX_SIZE);
		}
	} while (cols < 1 || cols > MAX_SIZE);

	mat->rows = rows;
	mat->cols = cols;

	/* cria a matriz */
	int i, j;

	for (i = 0; i < mat->rows; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			printf("Elemento na posicao [%d][%d]: ", i, j);
			scanf("%d", &mat->data[i][j]);
		}
	}
}

void imprime_matriz(Matriz *mat)
{
	int i, j;

	printf("\n~ Matriz %d x %d :\n", mat->rows, mat->cols);

	for (i = 0; i < mat->rows; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			printf("%d ", mat->data[i][j]);
		}
		putchar('\n');
	}
}

/* Janela que verifica se a posição atual é um máximo local*/
int windowLoc(Matriz *mat, int row, int col, int w_size)
{
	int i, j;
	int max_val = mat->data[row][col];

	for (i = row - w_size; i <= row + w_size && i < mat->rows; i++)
	{
		if (i < 0) continue;
		for (j = col - w_size; j <= col + w_size && j < mat->cols; j++)
		{
			if (j < 0) continue;
			if (mat->data[i][j] >= max_val && (i != row || j != col))
			{
				return 0; /* Não é um máximo local */
			}
		}
	}

	return 1; /* É um máximo local */
}

int *calcLocMax(Matriz *mat)
{
	int i, j, count = 0;
	/* variável estática para não ser perdida após a conclusão da função */
	static int max_vals[MAX_SIZE][3]; 

	for (i = 0; i < mat->rows; i++)
	{
		for (j = 0; j < mat->cols; j++)
		{
			/* Considera w_size = 1, pois foi pedido na questão */
			if (windowLoc(mat, i, j, 1))
			{
				max_vals[count][0] = mat->data[i][j];
				max_vals[count][1] = i;
				max_vals[count][2] = j;
				count++;
			}
		}
	}

	/* Identifica o fim de max_vals */
	max_vals[count][0] = -1;
	max_vals[count][1] = -1;
	max_vals[count][2] = -1;

	return max_vals[0];
}

/* Função que ordena os máximos locais encontrados*/
void recursive_sortMaxLoc(int *max_vals, int begin)
{
	int aux0, aux1, aux2;
	int count = begin;

	/* Fim da recursão */
	if (*(max_vals + (count+1)*3 + 1) == -1)
		return;

	while (*(max_vals + (count+1)*3 + 1) != -1)
	{
		int current = *(max_vals + count*3);
		int next = *(max_vals + (count+1)*3); /* ERRO CORRIGIDO: estava count*3 + 1 */

		if (current > next)
		{
			aux0 = *(max_vals + count*3);
			*(max_vals + count*3) = *(max_vals + (count+1)*3);
			*(max_vals + (count+1)*3) = aux0; 

			aux1 = *(max_vals + count*3 + 1);
			*(max_vals + count*3 + 1) = *(max_vals + (count+1)*3 + 1);
			*(max_vals + (count+1)*3 + 1) = aux1;

			aux2 = *(max_vals + count*3 + 2);
			*(max_vals + count*3 + 2) = *(max_vals + (count+1)*3 + 2);
			*(max_vals + (count+1)*3 + 2) = aux2;

		}

		count++;
	}

	recursive_sortMaxLoc(max_vals, begin + 1);
}

void sortMaxLoc(int *max_vals)
{
	/* chama a função recursiva começando com begin = 0 */
	recursive_sortMaxLoc(max_vals, 0);
}

/* Função que imprime os máximos locais identificados */
void imprimeMaxLoc(int *max_vals)
{
	int count = 0;

	printf("\n~ Maximos locais encontrados: ");

	while (*(max_vals + count*3 + 1) != -1)
	{
		printf("%d (%d,%d)", *(max_vals + count*3), *(max_vals + count*3 + 1), *(max_vals + count*3 + 2));
		count++;
		if (*(max_vals + count*3 + 1) != -1)
			printf(" - ");
	}
}

/* Função que obtém o máximo global */
int *getMaxGlob(int *max_vals)
{
	int count = 0;

	while (*(max_vals + count*3 + 1) != -1)
		count++;

	/* ERRO CORIGIDO: Condição if else adicionada para o caso de não haver máximo local */
	if (count)
		return (max_vals + (count - 1)*3);
	else 
		return NULL;
}

void imprimeMaxGlob(int *max_glob)
{
	/* ERRO CORIGIDO: Condição if else adicionada para o caso de não haver máximo global */
	if (max_glob)
		printf("\n~ Maximo global: %d (%d,%d)\n", max_glob[0], max_glob[1], max_glob[2]);
	else 
		printf("\n~ Maximo global nao existe.\n");
}

int main()
{
	Matriz mat;
	int *max_vals;
	int *max_glob;

	ler_matriz(&mat);

	max_vals = calcLocMax(&mat);

	sortMaxLoc(max_vals);

	imprimeMaxLoc(max_vals);

	max_glob = getMaxGlob(max_vals);

	imprimeMaxGlob(max_glob);

	imprime_matriz(&mat);

	return 0;
}