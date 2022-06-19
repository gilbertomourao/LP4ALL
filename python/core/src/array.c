/**
 * LINP - Biblioteca da disciplina Linguagem de Programação - EE, UFMA
 *
 * Autor: Gilberto José Guimarães de Sousa Mourão
 *
 * A biblioteca LINP tem como objetivo principal ajudar os alunos que 
 * estão cursando ou irão cursar a disciplina linguagem de programação. 
 * Aqui estão algumas funções cobradas ao longo dos anos em provas 
 * e em atividades. Sugiro que, caso não consiga desenvolver a sua 
 * própria função, utilize LINP como referência para estudar um determinado 
 * algoritmo. 
 *
 * Outra utilidade de LINP está no fato dela poder ser utilizada como 
 * comparação. As funções aqui presentes foram testadas em diversos 
 * casos e são confiáveis. É interessante ler a documentação de cada 
 * função para ter mais detalhes.
 *
 * A distribuição desta biblioteca é livre, podendo ser utilizada por 
 * qualquer pessoa, desde que seja citado o nome do autor e dos seus 
 * colaboradores. Os alunos que estão cursando a disciplina linguagem 
 * de programação e os que já foram aprovados podem contribuir com LINP 
 * desenvolvendo novas funções e/ou otimizando as já existentes. Para tal, 
 * siga as regras do github ou envie mensagem para um dos colaboradores 
 * do repositório.
 */

#include "../include/linp.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * criarmat
 *
 * Cria uma matriz através de alocação dinâmica. 
 */
static Linp_Mat *linp__criarmat(unsigned rows, unsigned cols)
{
	/* Verifica se está dentro de um bloco LINP */
	if (heap_count == 0)
	{
		printf("ERRO: Em criarmat. Esta funcao so pode ser invocada dentro de um bloco LINP.\n");
		exit(EXIT_FAILURE);
	}

	unsigned i;
	Linp_Mat *mat = malloc(sizeof(Linp_Mat));
	if (mat == NULL)
	{
		printf("ERRO: Em criarmat. Nao foi possivel alocar memoria para a variavel mat.\n");
		exit(EXIT_FAILURE);
	}

	mat->data = malloc(rows * sizeof(char *));
	if (mat->data == NULL)
	{
		printf("ERRO: Em criarmat. Nao foi possivel alocar memoria para a variavel data.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < rows; i++)
	{
		mat->data[i] = malloc(cols * sizeof(char));
		if (mat->data[i] == NULL)
		{
			printf("ERRO: Em criarmat. Nao foi possivel alocar memoria para a variavel data[%u].\n", i);
			exit(EXIT_FAILURE);
		}		
	}

	mat->rows = rows;
	mat->cols = cols;

	/* Adiciona o bloco de memória alocada para o heap atual */
	Arrays *new;

	new = malloc(sizeof(Arrays));
	if (new == NULL)
	{
		printf("ERRO: Em criarmat. Nao foi possivel adicionar o novo array ao heap.\n");
		exit(EXIT_FAILURE);
	}

	new->arr_add = mat;
	new->next = heap->arr;
	heap->arr = new;

	return mat;
}

/**
 * lerarquivo
 *
 * Lê um arquivo (geralmente txt) e copia o seu conteúdo 
 * para array, uma matriz. É importante atentar para a 
 * formatação do arquivo. 
 *
 * Considere _ = '\n'
 * 
 * Exemplo de arquivo bem formatado:
 * 
 * abcde_
 * efghd_
 * defef_
 * 
 */
static void linp__lerarquivo(Linp_Mat *array, char *text_file)
{
	int i, j, flag = 1, cols = 0;
	bool eol = false;
	char ch; /*consome caracteres*/
	unsigned i_limit = array->rows, j_limit = array->cols;
	FILE *file;

	file = fopen(text_file,"r");

	if (!file)
		exit(EXIT_FAILURE);

	for (i = 0;flag!=EOF && i < array->rows;i++)
	{
		eol = false;
		for (j = 0;!eol && j < array->cols;j++)
		{
			flag = fscanf(file,"%c",&array->data[i][j]); 

			if (!flag || flag == EOF) 
			{
				eol = true;
				break;
			}

			if (array->data[i][j] == '\n')
			{
				eol = true;
				j--;
			}
		}

		if (j > cols) cols = j;

		while (!eol)
		{
			fscanf(file,"%c",&ch);
			if (ch == '\n') eol = true;
		}
	}

	array->cols = cols;
	array->rows = i;

	fclose(file);

	/*some warnings*/
	if (array->rows == i_limit || array->cols == j_limit)
	{
		printf("\nWARNING: Reached the limit of LINP Linp_Matrix read function. ");
		printf("The Linp_Matrix on the text file may not have been properly read.\n");
	}
}

/**
 * criararquivo
 *
 * Cria um arquivo com o conteúdo de array.
 */
static void linp__criararquivo(Linp_Mat *array, char *text_file)
{
	FILE *file;

	file = fopen(text_file, "w"); /* cria o arquivo para escrita (write) */

	unsigned i, j;

	for (i = 0; i < array->rows; i++)
	{
		for (j = 0; j < array->cols; j++)
		{
			fputc(array->data[i][j], file); /* Insere o caracter na posição [i][j] no arquivo */
		}
		fputc('\n', file);
	}

	fclose(file); /* fecha o arquivo */
}

/**
 * dispmat
 *
 * Imprime a matriz na tela. 
 */
static void linp__dispmat(Linp_Mat *array, char *str)
{
	int i, j;

	printf("\n~$ %s\n\n",str);

	for (i = 0;i < array->rows;i++)
	{
		for (j = 0;j < array->cols;j++)
			printf("%c ", array->data[i][j]);

		putchar('\n');
	}

	putchar('\n');
}

/**
 * stringToMat
 * 
 * Transfora uma string em uma linp_Matrix. 
 */
static void linp__wordToMat(Linp_Mat *array, Linp_Word *string)
{
	int i, j, cols = 0, strpos = 0;
	bool eol = false;
	char ch, flag = ' ';
	unsigned i_limit = array->rows, j_limit = array->cols;

	for (i = 0; flag!='\0' && i < array->rows;i++)
	{
		eol = false;
		for (j = 0;!eol && j < array->cols;j++)
		{
			flag = array->data[i][j] = string->word[strpos++]; 

			if (flag == '\n' || flag == '\0') 
			{
				eol = true;
				break;
			}

			if (array->data[i][j] == '\n')
			{
				eol = true;
				j--;
			}
		}

		if (j > cols) cols = j;

		while (!eol)
		{
			ch = string->word[strpos++];
			if (ch == '\n') eol = true;
		}
	}

	array->cols = cols;
	array->rows = i;

	/*some warnings*/
	if (array->rows == i_limit || array->cols == j_limit)
	{
		printf("\nWARNING: Reached the limit of LINP Linp_Matrix read function. ");
		printf("The Linp_Matrix on the string may not have been properly read.\n");
	}
}

/**
 * matToString
 * 
 * Transfora uma linp_Matrix em uma string. 
 */
static Linp_Word **linp__matToWord(Linp_Mat *array)
{
	unsigned i, j, strpos = 0;

	/*Cria um array de words para garantir que o word seja incluido no heap de linp*/

	Linp_Word **string_array;
	unsigned size = 1;

	string_array = malloc((size + 1) * sizeof(Linp_Word *));
	if (string_array == NULL)
	{
		printf("ERRO: Em array. Na funcao matToString. Nao foi possivel alocar memoria para a variavel *string_array.\n");
		exit(EXIT_FAILURE);
	}

	/* Inicializa as listas */
	for (i = 0; i < size; i++)
	{
		string_array[i] = malloc(sizeof(Linp_Word));

		if (string_array[i] == NULL)
		{
			printf("ERRO: Em array. Na funcao matToString. Nao foi possivel alocar memoria para a variavel string_array[%u].\n", i);
			exit(EXIT_FAILURE);
		}

	}
	string_array[size] = NULL; /* Indica o término do array de listas word */

	/* Adiciona o bloco de memória alocada para o heap atual */
	Words *new;

	new = malloc(sizeof(Words));
	if (new == NULL)
	{
		printf("ERRO: Em proc. Na funcao pos_array. Nao foi possivel adicionar o novo array de words ao heap.\n");
		exit(EXIT_FAILURE);
	}

	new->word_add = string_array;
	new->next = heap->w;
	heap->w = new;

	/* A string criada deve ter rows*(cols+1) + 1 espaços, incluindo o '\0'*/
	Linp_Word *string = string_array[0];
	string->word = malloc((array->rows*(array->cols + 1) + 1)*sizeof(char));

	if (string->word == NULL)
	{
		printf("ERRO: Em array. Na funcao matToString. Nao foi possivel alocar memoria para a variavel string.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < array->rows; i++)
	{
		for (j = 0; j < array->cols; j++)
		{
			string->word[strpos++] = array->data[i][j];
		}
		string->word[strpos++] = '\n';
	}
	string->word[strpos] = '\0';

	return string_array;
}