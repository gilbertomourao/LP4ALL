/**
 * Questão 2 - Prova 3
 * Disciplina: Linguagem de Programação
 *
 * Data: 22/12/2020
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Cabeçalho das funções
 */
void limpabuffer();
char **createmat(unsigned *, unsigned *);
void destroymat(char **, unsigned);
void readmat(char **, unsigned, unsigned);
void printmat(char **, unsigned, unsigned);
void transforma(char **, unsigned, unsigned);

int main()
{
	unsigned rows, cols;

	char **mat = createmat(&rows, &cols);

	/*Leitura da matriz via stdin*/
	readmat(mat, rows, cols);

	/*Imprime a matriz na tela*/
	printmat(mat, rows, cols);

	/*Transforma a matriz de acordo com o enunciado*/
	transforma(mat, rows, cols);

	/*Imprime a matriz resultante na tela*/
	printmat(mat, rows, cols);

	/**
	 * Ainda que não seja necessário nesse caso, destrói a matriz. O sistema operacional 
	 * faria isso por você.
	 */
	destroymat(mat, rows);

	return 0;
}

/**
 * Funções
 */

/**
 * Função que limpa o buffer
 */
void limpabuffer()
{
	int ch;

	while((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Função que cria uma matriz de rows linhas e cols colunas.
 *
 * Ex: 
 *
 * char **mat = createmat(10,7);
 *
 * Cria uma matriz de 10 linhas e 7 colunas.
 */
char **createmat(unsigned *rows, unsigned *cols)
{
	printf("Insira a quantidade de linhas da matriz: ");
	scanf("%u", rows);
	limpabuffer();

	while (*rows == 0 || *rows > 1000)
	{
		printf("WARNING: Em createmat. Numero de linhas invalido. Por favor, insira um numero maior do que 0 ate 1000.\n");
		printf("Insira a quantidade de linhas da matriz: ");
		scanf("%u", rows);
		limpabuffer();
	}

	printf("Insira a quantidade de colunas da matriz: ");
	scanf("%u", cols);
	limpabuffer();

	while (*cols == 0 || *cols > 1000)
	{
		printf("WARNING: Em createmat. Numero de colunas invalido. Por favor, insira um numero maior do que 0 ate 1000.\n");
		printf("Insira a quantidade de colunas da matriz: ");
		scanf(" %u", cols);
		limpabuffer();
	}

	char **mat;

	/**
	 * Primeiro, cria um vetor de rows posições. Cada posição guardará um endereço para
	 * um novo vetor, por isso sizeof(char *) e não sizeof(char).
	 */
	mat = malloc(*rows * sizeof(char *));
	if (mat == NULL)
	{
		printf("ERRO: Em createmat. Alocacao de memoria falhou! Verificar a variavel mat.\n");
		exit(EXIT_FAILURE);
	}

	/**
	 * Em cada posição, cria um vetor de cols posições, resultando em uma matriz de 
	 * rows linhas e cols colunas.
	 */
	unsigned i;
	for (i = 0; i < *rows; i++)
	{
		*(mat + i) = malloc(*cols * sizeof(char));
		if (*(mat + i) == NULL)
		{
			printf("ERRO: Em createmat. Alocacao de memoria falhou! Verificar a variavel mat[%d].\n", i);
			exit(EXIT_FAILURE);
		}		
	}

	return mat;
}

/**
 * Função que destrói a matriz criada dinamicamente
 */
void destroymat(char **mat, unsigned rows)
{
	unsigned i;

	/*dealloc cada linha*/
	for (i = 0; i < rows; i++)
		free(*(mat + i));

	/*dealloc mat*/
	free(mat);
}

/**
 * Função que lê a matriz via stdin
 */
void readmat(char **mat, unsigned rows, unsigned cols)
{
	printf("\n~ Leitura da matriz\n\n");

	unsigned i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("Insira o caractere na posicao [%u][%u]: ", i, j);
			*(*(mat+i)+j) = getchar(); /*equivalente a mat[i][j] = getchar();*/
			if (*(*(mat+i)+j) == '\n')
			{
				*(*(mat+i)+j) = ' '; /* Facilita a visualização */
				continue;
			}
			limpabuffer();
		}
	}
}

/**
 * Função que imprime a matriz
 */
void printmat(char **mat, unsigned rows, unsigned cols)
{
	printf("\n~ Matriz\n\n");

	unsigned i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%c ", *(*(mat+i) + j) );
		}
		putchar('\n');
	}

	putchar('\n');
}

/**
 * Função que transforma a matriz
 *
 * char minusculo -> char maiusculo
 * char maiusculo -> char minusculo
 */
void transforma(char **mat, unsigned rows, unsigned cols)
{
	unsigned i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (*(*(mat+i)+j) >= 'a' && *(*(mat+i)+j) <= 'z')
				*(*(mat+i)+j) += 'A' - 'a'; /*minuscula -> maiuscula*/
			else 
				if (*(*(mat+i)+j) >= 'A' && *(*(mat+i)+j) <= 'Z')
					*(*(mat+i)+j) += 'a' - 'A'; /*maiuscula -> minuscula*/
		}
	}
}