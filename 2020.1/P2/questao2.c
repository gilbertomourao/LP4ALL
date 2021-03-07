/** 
 * Questão 2 - solução não elegante
 *
 * Faria dessa maneira na época, quando ainda estava 
 * engatinhando em C.
 *
 * Obs: Não entendi direito, mas acho que o deslocamento 
 * para 'direita' em uma coluna seria para 'baixo' e para 
 * 'esquerda' seria para 'cima' (???).
 */

#include <stdio.h>

/* macros */
#define MAX_SIZE 100

void limpabuffer();
void lermatdim(int *, int *);
void lermat(int (*)[], int, int);
int lerdesloc();
char lerdir();
char lersent(int, int, int *);
void deslocar(int (*)[], int, int, int, char, char, int);
void printmat(int (*)[], int, int);

int main()
{
	int L, C; /* linhas e colunas da matriz */
	int mat[MAX_SIZE][MAX_SIZE];

	lermatdim(&L, &C);
	lermat(mat, L, C);

	printmat(mat, L, C);

	int desloc = lerdesloc();
	char dir = lerdir();
	int pos;
	char sentido = lersent(L, C, &pos);

	deslocar(mat, L, C, desloc, dir, sentido, pos);

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

int lerdesloc()
{
	int desloc;
	do
	{
		printf("Insira o valor do deslocamento (>= 0): ");
		scanf("%d", &desloc); limpabuffer();
	} while (desloc < 0);

	return desloc;
}

char lerdir()
{
	char dir;

	do
	{
		printf("Insira a direcao do deslocamento ('D' ou 'E'): ");
		scanf("%c", &dir); limpabuffer();
	} while (dir != 'D' && dir != 'E');

	return dir;
}

int condicao(char sentido, int pos, int linhas, int colunas)
{
	if (sentido == 'L')
		return pos < linhas && pos > 0;
	return pos < colunas && pos > 0;
}

char lersent(int linhas, int colunas, int *pos)
{
	char sentido;

	do
	{
		printf("Insira o sentido do deslocamento ('L' ou 'C'): ");
		scanf("%c", &sentido); limpabuffer();
	} while (sentido != 'L' && sentido != 'C');

	do
	{
		printf("Agora insira a %c que deseja deslocar: ", sentido);
		scanf("%d", pos); limpabuffer();
	} while (!condicao(sentido, *pos, linhas, colunas));

	return sentido;
}

/**
 * Funções auxiliares shiftright e shiftleft
 */
void shiftright(int *vec, int size, char sent)
{
	int i; /* iterador */
	int aux1, aux2 = vec[0];
	int step = (sent == 'L') ? 1 : MAX_SIZE;

	for (i = 1; i < size; i++)
	{
		aux1 = aux2;
		aux2 = vec[i * step];
		vec[i * step] = aux1;
	}

	/* com rotação */
	vec[0] = aux2;
}

void shiftleft(int *vec, int size, char sent)
{
	int i; /* iterador */
	int step = (sent == 'L') ? 1 : MAX_SIZE;
	int aux1, aux2 = vec[(size-1) * step];

	for (i = size-2; i >= 0; i--)
	{
		aux1 = aux2;
		aux2 = vec[i * step];
		vec[i * step] = aux1;
	}

	/* com rotação */
	vec[(size-1) * step] = aux2;
}

void deslocar(int (*mat)[MAX_SIZE], int linhas, int colunas, int desloc, char dir, char sent, int pos)
{
	int cont = 0;
	int *ptr = (sent == 'L') ? mat[pos] : &mat[0][pos];
	int size = (sent == 'L') ? colunas : linhas;

	while (cont < desloc)
	{
		if (dir == 'D')
			shiftright(ptr, size, sent);
		else 
			shiftleft(ptr, size, sent);
		++cont;
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