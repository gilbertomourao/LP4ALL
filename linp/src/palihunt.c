#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../include/linp.h"

#define VALID_CHAR(ch) ((tolower(ch) >= 'a' && tolower(ch) <= 'z') || (ch >= '1' && ch <= '9') )

/**
 * strpal
 *
 * Verifica se a string passada como parâmetro é um palíndromo. 
 * Retorna 1 se for, 0 caso contrário.
 * 
 */
static int strpal(char *string)
{
	unsigned tamanho = 0, i = 0, j;

	/**
	 * Obtém o tamanho da string. Apenas um exercício de lógica para não 
	 * usar strlen o tempo inteiro.
	 */
	while(*(string + i++))
		tamanho++;

	if (tamanho == 1)
		return 0; /*A string deve ter pelo menos dois caracteres*/
	else 
		/**
		 * Lógica para verificar se a string é um palíndromo.
		 *
		 * Exemplos de palíndromos:
		 *
		 * arara, ovo, ana, Roma me tem amor, Mega bobagem, etc.
		 *
		 * Outros exemplos em https://www.normaculta.com.br/palindromo-exemplos-de-palavras-e-frases/
		 */
		for (i = 0,j = tamanho-1; i < j; i++, j--)
			if (tolower(*(string+i)) != tolower(*(string+j)))
				return 0; /*Não é um palíndromo!*/
	return 1; /*É um palíndromo*/	
}

/**
 * get_lowmat
 *
 * Função que obtém a matriz auxiliar. É necessária pois 
 * na matriz principal as ocorrências serão substituídas 
 * pelo caractere fornecido pelo usuário.
 * 
 */
static void get_auxmat(Linp_Matrix *source, char **dest)
{
	int i, j;

	for (i = 0;i < source->rows;i++)
	{
		for (j = 0;j < source->cols;j++)
		{
			dest[i][j] = source->mat[i][j];
		}
	}
}

/**
 * palisearch
 *
 * Procura por um palíndromo na direção passada como parâmetro para a função.
 *
 * 0, 1 -- linhas
 * 1, 0 -- colunas
 * 1, 1 -- diagonais no sentido da principal
 * 1,-1 -- diagonais no sentido da secundária
 */
static void palisearch(Linp_Matrix *array, char **aux_array, 
					   int pos_i, int pos_j, int step_i, int step_j,
					   int *end_i, int *end_j,
					   char *string, char *palindrome)
{
	int i, j, s;
	int init_i, init_j;

	/**
	 * Linhas
	 *
	 * próximo caractere na posição [i][j+1]
	 */
	if (step_i == 0 && step_j == 1)
	{
		init_i = pos_i;
		init_j = pos_j+1;
	}

	/**
	 * Colunas
	 * 
	 * próximo caractere na posição [i+1][j]
	 */
	if (step_i == 1 && step_j == 0)
	{
		init_i = pos_i+1;
		init_j = pos_j;
	}

	/**
	 * Diagonais P
	 *
	 * próximo caractere na posição [i+1][j+1]
	 */
	if (step_i == 1 && step_j == 1)
	{
		init_i = pos_i+1;
		init_j = pos_j+1;
	}

	/**
	 * Diagonais S
	 *
	 * próximo caractere na posição [i+1][j-1]
	 */
	if (step_i == 1 && step_j == -1)
	{
		init_i = pos_i+1;
		init_j = pos_j-1;
	}

	/*Inicializa palindrome e s*/
	palindrome[0] = '\0';
	s = 0;

	/*Verifica se o caractere atual é alfanumérico*/
	if (VALID_CHAR(aux_array[pos_i][pos_j]))
	{
		/*Adiciona o caractere à primeira posição da string*/
		string[s++] = aux_array[pos_i][pos_j];
		/**
		 * Inicializa o laço for com a próxima posição que depende
		 * da direção da procura, como definida anteriormente. A 
		 * condição de parada não será sempre i < linhas e j < colunas 
		 * pois no sentido da diagonal secundária, j diminui (diagonal para baixo) 
		 * e a condição de parada torna-se i < linhas e j >= 0. Fazer um desenho 
		 * pode ajudar na compreensão.
		 *
		 * Exemplo de procura:
		 * _ = qualquer caractere não alfanumérico (ex: +, @, &)
		 * 
		 * a_Ra__rA_x
		 *
		 *  Loop   string        palindrome
		 *    1      a_              \0
		 *    2     a_R              \0
		 *    3     a_Ra             aRa
		 *    4     a_Ra_            aRa
		 *    5     a_Ra__           aRa
		 *    6     a_Ra__r          aRa
		 *    7     a_Ra__rA         aRarA
		 *    8     a_Ra__rA_        aRarA
		 *    9     a_Ra__rA_x       aRarA
		 *
		 * Termina o loop com palindrome = aRarA e com a posição final, nesse caso 
		 * as coordenadas do caractere 'A'. Quando procurar a partir da próxima 
		 * posição encontrará Rar, que será armazenado em palindrome, e a posição final 
		 * que nesse caso são as coordenadas de 'r', o último caractere. Veja o comentário 
		 * abaixo para saber a utilidade da posição final.
		 */
		for (i = init_i, j = init_j; i < array->rows && 
								    ((step_j == -1) ? j >= 0 : j < array->cols);
								    i += step_i, j += step_j)
		{
			/*Se o caractere atual é válido, ele é adicionado a string.*/
			if (VALID_CHAR(aux_array[i][j]))
				string[s++] = aux_array[i][j];
			string[s] = '\0'; /*Finaliza string*/

			/**
			 * Verifica se string é um palíndromo. Se for, armazena em palindrome 
			 * e salva a posição final (end_i e end_j). Essa posição final é útil 
			 * para verificar se o palíndromo encontrado é na verdade um palíndromo 
			 * dentro de outro palíndromo. Por exemplo:
			 *
			 * aRarA --> possui os palíndromos aRa, Rar e arA. Não faz sentido 
			 * identificar esses palíndromos e sim apenas o principal, aRarA. 
			 *
			 * (EDIT)
			 *
			 * Considere o palíndromo abcdcba. Observe que ele possui como "subpalíndromos"
			 * bcdcb e cdc. Qualquer palíndromo, quando suficientemente grande, possuirá, 
			 * obviamente, "subpalíndromos". É por isso que para nós não faz sentido 
			 * destacá-los e sim apenas o palíndromo principal. 
			 */
			if (strpal(string))
			{
				strcpy(palindrome, string);
				if (VALID_CHAR(aux_array[i][j]))
				{
					*end_i = i;
					*end_j = j;
				}
			}
		}
	}
}

/**
 * huntrow
 *
 * Busca por palíndromos nas linhas da matriz. 
 * 
 */
static void huntrow(Linp_Matrix *array, char **aux_array, char *string, char *palindrome, int print_cond, const char c)
{
	int i, j, k, l;
	int end_i, end_j, last_end;

	for (i = 0; i < array->rows; i++) 
	{
		last_end = 0; /*Inicializa last_end na primeira posição, j = 0*/
		for (j=0; j < array->cols; j++)
		{
			if (VALID_CHAR(aux_array[i][j]))
			{
				palisearch(array, aux_array, i, j, 0, 1, &end_i, &end_j, string, palindrome);

				/*Verifica se é um palíndromo e se for verifica se ele é válido (não é um subpalíndromo)*/
				if (palindrome[0] && end_j > last_end)
				{
					if (print_cond)
						printf("O palindromo %s aparece na linha %d entre [%d][%d] e [%d][%d].\n",palindrome,i,i,j,i,end_j);

					/*Faz a substituição pelo caractere fornecido*/
					for (k = j,l = 0;k <= end_j;k++,l++)
						if (aux_array[i][k] == palindrome[l])
							array->mat[i][k] = c;
						else l--;

					/*Salva a posição final do palíndromo*/
					last_end = end_j;
				}
			}
		}	
	}

	if (print_cond)
		putchar('\n');
}

/**
 * huntcol
 *
 * Busca por palíndromos nas colunas da matriz. 
 * 
 */
static void huntcol(Linp_Matrix *array, char **aux_array, char *string, char *palindrome, int print_cond, const char c)
{
	int i, j, k, l;
	int end_i, end_j, last_end;

	for (j=0;j<array->cols;j++)
	{
		last_end = 0; /*Inicializa last_end na primeira posição, i = 0*/
		for (i=0;i<array->rows;i++)
		{ 
			if (VALID_CHAR(aux_array[i][j]))
			{
				palisearch(array, aux_array, i, j, 1, 0, &end_i, &end_j, string, palindrome);

				/*Verifica se é um palíndromo e se for verifica se ele é válido (não é um subpalíndromo)*/
				if (palindrome[0] && end_i > last_end)
				{
					if (print_cond)
						printf("O palindromo %s aparece na coluna %d entre [%d][%d] e [%d][%d].\n",palindrome,j,i,j,end_i,j);
					
					/*Faz a substituição pelo caractere fornecido*/
					for (k = i,l = 0;k <= end_i;k++,l++)
						if (aux_array[k][j] == string[l])
							array->mat[k][j] = c;
						else l--; 

					/*Salva a posição final do palíndromo*/
					last_end = end_i;
				}
			}
		}
	}

	if (print_cond)
    	putchar('\n');
}

/**
 * huntdiP
 *
 * Busca por palíndromos nas diagonais no sentido da principal
 * 
 */
static void huntdiP(Linp_Matrix *array, char **aux_array, char *string, char *palindrome, int print_cond, const char c)
{
	int i, j, k, l;
	int kaux, laux, maux; /*para string e substituição na matriz principal*/
	int end_i, end_j, last_end_i, last_end_j;

	for (j=0;j<array->cols;j++)
	{
		for (i=array->rows-1;i>=0;i--)
		{
			if (j>0) i = 0; /*evita repetições*/
			/*Inicializa last_end na primeira posição da diagonal P, [0][0]*/
			last_end_i = last_end_j = 0; 
			for (k = i,l = j; k < array->rows && l < array->cols; k++, l++)
			{ 
				if (VALID_CHAR(aux_array[k][l]))
				{
					palisearch(array, aux_array, k, l, 1, 1, &end_i, &end_j, string, palindrome);

					/*Verifica se é um palíndromo e se for verifica se ele é válido (não é um subpalíndromo)*/
					if (palindrome[0] && end_i > last_end_i && end_j > last_end_j)
					{
						if (print_cond)
							printf("O palindromo %s aparece na diagonal P entre [%d][%d] e [%d][%d].\n",palindrome,k,l,end_i,end_j);
						
						/*Faz a substituição pelo caractere fornecido*/
						for (kaux = k,laux = l,maux = 0; kaux <= end_i && laux <= end_j ; kaux++, laux++, maux++)
							if (aux_array[kaux][laux] == string[maux])
								array->mat[kaux][laux] = c;
							else maux--;

						/*Salva a posição final do palíndromo*/
						last_end_i = end_i;
						last_end_j = end_j;
					}
				}
			}
		}
	}

	if (print_cond)
		putchar('\n');
}

/**
 * huntdiS
 *
 * Busca por palíndromos nas diagonais no sentido da secundária
 * 
 */
static void huntdiS(Linp_Matrix *array, char **aux_array, char *string, char *palindrome, int print_cond, const char c)
{
	int i, j, k, l;
	int kaux, laux, maux; /*para string e substituição na matriz principal*/
	int end_i, end_j, last_end_i, last_end_j;

	for (i=0;i<array->rows;i++)
	{
		for (j=0;j<array->cols;j++)
		{
			if (i>0) j = array->cols-1; /*evita repetições*/
			/*Inicializa last_end na primeira posição da diagonal S, [0][cols-1]*/
			last_end_i = 0;
			last_end_j = array->cols-1;
			for (k = i,l = j; k < array->rows && l >= 0; k++, l--)
			{ 
				if (VALID_CHAR(aux_array[k][l]))
				{
					palisearch(array, aux_array, k, l, 1, -1, &end_i, &end_j, string, palindrome);

					/*Verifica se é um palíndromo e se for verifica se ele é válido (não é um subpalíndromo)*/
					if (palindrome[0] && end_i > last_end_i && end_j < last_end_j)
					{
						if (print_cond)
							printf("O palindromo %s aparece na diagonal S entre [%d][%d] e [%d][%d].\n",palindrome,k,l,end_i,end_j);
						
						/*Faz a substituição pelo caractere fornecido*/
						for (kaux = k,laux = l,maux = 0; kaux <= end_i && laux >= end_j ; kaux++, laux--, maux++)
							if (aux_array[kaux][laux] == string[maux])
								array->mat[kaux][laux] = c;
							else maux--;

						/*Salva a posição final do palíndromo*/
						last_end_i = end_i;
						last_end_j = end_j;
					}
				}
			}
		}
	}

	if (print_cond)
		putchar('\n');
}

/**
 * palihunt
 *
 * Busca por palíndromos na matriz. 
 *
 * Caso print seja "true", imprime na tela as posições onde encontrou os palíndromos.
 * Caso seja "false", apenas procura por palíndromos sem imprimir nada.
 * O parâmetro search permite que o usuário indique se quer buscar por palíndromos 
 * somente nas linhas, somente nas colunas, somente nas diagonais P, somente nas diagonais S 
 * ou em todas as direções. 
 * 
 */
void linp__palihunt(Linp_Matrix *array, char *print, char *search, const char c)
{
	char **aux_array;
	char *string, *palindrome;
	/*Tamanho máximo da string de varredura. Será o valor da maior dimensão da matriz.*/
	unsigned string_length = (array->rows > array->cols) ? array->rows : array->cols;

	int i; /*iterator*/

	/**
	 * Memory allocation
	 */
	
	/* 2d array */
	aux_array = malloc(array->rows * sizeof(char *));

	if (aux_array == NULL)
	{
		printf("ERROR: In palihunt. Memory allocation failed.\n Variable: aux_array\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < array->rows; i++)
	{
		aux_array[i] = malloc(array->cols * sizeof(char));
		if (aux_array[i] == NULL)
		{
			printf("ERROR: In palihunt. Memory allocation failed.\n Variable: aux_array[i]");
			exit(EXIT_FAILURE);
		}
	}

	/* string */
	string = malloc(string_length * sizeof(char));

	if (string == NULL)
	{
		printf("ERROR: In palihunt. Memory allocation failed.\n Variable: string\n");
		exit(EXIT_FAILURE);
	}

	/* palindrome */
	palindrome = malloc(string_length * sizeof(char));

	if (palindrome == NULL)
	{
		printf("ERROR: In palihunt. Memory allocation failed.\n Variable: palindrome\n");
		exit(EXIT_FAILURE);
	}

	/*Verifica a validade dos parâmetros print e search*/
	int print_true = strcmp(print, "print");
	int print_false = strcmp(print, "don't print");
	int search_valid = 0;

	if (print_true && print_false)
	{
		printf("ERROR: In palihunt. The parameter print can only accept the strings \"print\" or \"don't print\".\n");
		exit(EXIT_FAILURE);
	}

	int print_cond = !print_true;

	get_auxmat(array, aux_array);

	if (!strcmp(search, "rows"))
	{
		huntrow(array, aux_array, string, palindrome, print_cond, c);
		search_valid = 1;
	}

	if (!strcmp(search, "cols"))
	{
		huntcol(array, aux_array, string, palindrome, print_cond, c);
		search_valid = 1;
	}

	if (!strcmp(search, "diagP"))
	{
		huntdiP(array, aux_array, string, palindrome, print_cond, c);
		search_valid = 1;
	}

	if (!strcmp(search, "diagS"))
	{
		huntdiS(array, aux_array, string, palindrome, print_cond, c);
		search_valid = 1;
	}

	if (!strcmp(search, "all"))
	{
		huntrow(array, aux_array, string, palindrome, print_cond, c);
		huntcol(array, aux_array, string, palindrome, print_cond, c);
		huntdiP(array, aux_array, string, palindrome, print_cond, c);
		huntdiS(array, aux_array, string, palindrome, print_cond, c);
		search_valid = 1;
	}

	free(string);
	free(palindrome);

	for (i = 0; i < array->rows; i++)
	{
		free(aux_array[i]);
	}

	free(aux_array);

	if (!search_valid)
	{
		printf("ERROR: In palihunt. The parameter search can only accept the strings ""rows"", ""cols"", ""diagP"" and ""diagS"".\n");
		exit(EXIT_FAILURE);
	}
}