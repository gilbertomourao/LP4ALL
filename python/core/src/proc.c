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
#include <ctype.h> /* tolower() */
#include <string.h>
/* #include <stdbool.h> */

/**
 * Macro que define se um caractere é alfabético.
 * ALFABET(ch) = 1 se ch for alfabético, 0 caso contrário.
 */
#define ALFABET(ch) (tolower(ch) >= 'a' && tolower(ch) <= 'z')

/**
 * Macro que define se um caractere é alfanumérito. 
 * ALFANUM(ch) = 1 se ch for alfanumérito, 0 caso contrário.
 */
#define ALFANUM(ch) (ALFABET(ch) || (ch >= '0' && ch <= '9'))

/**
 * Caractere retornado como lower char se ign_cs for = true.
 * Caso contrário, retorna o próprio caractere.
 */
static char getch_cs(char ch, bool ign_cs)
{
	return (ign_cs) ? tolower(ch) : ch;
}

#define GETC(ch) getch_cs(ch, ign_cs)

/**
 * Verifica se o caracter ch já existe em list e 
 * retorna 1 caso verdadeiro e 0 caso contrário.
 */
static int list_repetido(char *list, char ch)
{
	unsigned i;
	for (i = 0; list[i]; i++)
		if (list[i] == ch)
			return 1;

	return 0;
}

/**
 * Verifica se o caracter ch deve ser ignorado.
 */
static int ignorac(char *list, char ch)
{
	if (list[0] == (char) 254)
		return !ALFABET(ch);

	if (list[0] == (char) 255)
		return !ALFANUM(ch);

	return list_repetido(list, ch);
}

/**
 * Lista de caracteres que deverão ser ignorados de acordo 
 * com o parâmetro ign_chars passado para a função proc.
 */
static char *list_ign(char *ign_chars, bool ign_cs)
{
	unsigned list_len = strlen(ign_chars); /* comprimento máximo da lista */
	char *list = malloc(list_len * sizeof(char));

	if (list == NULL)
	{
		printf("ERRO: Em proc. Na funcao list_ign. Nao foi possivel alocar memoria para a variavel list.\n");
		exit(EXIT_FAILURE);
	}

	/**
	 * Ignora todos os caracteres não alfabéticos e utiliza o caractere
	 * (char) 254 para identificar essa condição.
	 */
	if (!strcmp(ign_chars, "!alfabet"))
	{
		list[0] = (char) 254;
		list[1] = '\0';
		return list;
	}

	/* Ignora todos os caracteres não alfanuméricos e utiliza o caractere 
	 * NBSP para identificar essa condição.
	 */
	if (!strcmp(ign_chars, "!alfanum"))
	{	
		list[0] = (char) 255; /* NBSP */
		list[1] = '\0';
		return list;
	}

	unsigned i, j;
	list[0] = '\0'; /* Inicializa list */
	for (i = 0, j = 0; i < list_len; i++, j++)
	{
		/* Verifica se é um caractere repetido */
		if (list_repetido(list, GETC(ign_chars[i])))
		{
			list[j--] = '\0';
		}
		else
		{
			list[j] = GETC(ign_chars[i]);
		}
		list[j+1] = '\0'; /* Finaliza list */
	}

	return list;
}

/**
 * Obtém a string auxiliar sem os caracteres a serem ignorados 
 * e ignorando ou não case sensitive.
 */
static char *straux(char *string, char *list_ign, bool ign_cs)
{
	char *aux = malloc(strlen(string) * sizeof(char));

	if (aux == NULL)
	{
		printf("ERRO: Em proc. Na funcao straux. Nao foi possivel alocar memoria para a variavel aux.\n");
		exit(EXIT_FAILURE);
	}	

	unsigned i, j;
	for (i = 0, j = 0; string[i]; i++, j++)
	{
		char ch = GETC(string[i]);
		if (ignorac(list_ign, ch))
		{
			j--;
		}
		else 
		{
			aux[j] = ch;
		}
	}
	aux[j] = '\0'; /* Finaliza a string auxiliar */

	return aux;
}

/**
 * strequiv
 *
 * Verifica se as strings passadas como parâmetros são iguais 
 * ou simétricas (como "ari" e "ira").
 * Retorna 1 se forem, 0 caso contrário.
 *
 * size é o tamanho de str2 ou strlen(str2). Utiliza-lo como 
 * parâmetro evita que toda vez que strproc for invocada o 
 * tamanho de str2 seja calculado, o que aumentaria o número 
 * de instruções de forma desnecessária.
 */
static int strequiv(char *str1, char *str2, unsigned size, bool ign_cs, bool ign_inv)
{
	unsigned i, cont = 0, cont_inv = 0;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		cont += GETC(str1[i]) == str2[i]; /*contador para igualdade*/
		if (!ign_inv)
			cont_inv += GETC(str1[i]) == str2[size - 1 - i]; /*contador para simetria*/
	}

	/**
	 * Verifica se encontrou a string
	 *
	 * Se str1 = str2, então cont = size e str2[cont] = str1[cont] = '\0'.
	 * Se str1 e str2 forem simétricas, cont_inv = size e str2[cont_inv] = str1[cont_inv] = '\0'
	 * Se str1 < str2, então cont < size e cont_inv < size, logo str2[cont] != '\0'.
	 * Se str1 > str2, então mesmo que cont = size, str1[cont] != '\0'.
	 * 
	 */

	if (str1[cont] == '\0' && str2[cont] == '\0')
		return 1;
	if (str1[cont_inv] == '\0' && str2[cont_inv] == '\0')
		return -1;

	return 0;
}

/**
 * strpal
 *
 * Verifica se a string passada como parâmetro é um palíndromo. 
 * Retorna 1 se for, 0 caso contrário.
 * 
 */
static int strpal(char *string, unsigned string_len, bool ign_cs)
{
	unsigned i = 0, j;

	if (string_len == 1)
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
		for (i = 0,j = string_len-1; i < j; i++, j--)
			if (GETC(string[i]) != GETC(string[j]))
				return 0; /*Não é um palíndromo!*/
	return 1; /*É um palíndromo*/	
}

/**
 * strlogic
 *
 * Caso str2 for uma string válida, verifica se str1 e str2 
 * são equivalentes. 
 * Caso str2 = NULL, verifica se str1 é um palíndromo.
 */
static int strlogic(char *str1, char *str2, unsigned size, bool ign_cs, bool ign_inv)
{
	if (str2)
		return strequiv(str1, str2, size, ign_cs, ign_inv);
	else 
		return strpal(str1, size, ign_cs);
}

/**
 * strproc
 *
 * Procura pela string passada como parâmetro na direção passada para a função.
 *
 * 0, 1 -- linhas
 * 1, 0 -- colunas
 * 1, 1 -- diagonais no sentido da principal
 * 1,-1 -- diagonais no sentido da secundária
 */
static bool strproc(Linp_Mat *array, char *list_ign, bool ign_cs, bool ign_inv,  
				    int pos_i, int pos_j, int step_i, int step_j,
				    int *end_i, int *end_j,
				    char *string1, char *string2, unsigned str2len,
				    char *string3, int *sentido)
{
	int i, j, init_i = 0, init_j = 0;
	bool flag = false;
	int aux_sentido;

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

	unsigned s = 0;
	/*Verifica se o caractere atual é válido*/
	if (!ignorac(list_ign, array->data[pos_i][pos_j]))
	{
		/*Adiciona o caractere à primeira posição da string1*/
		string1[s++] = array->data[pos_i][pos_j];
		/**
		 * Inicializa o laço for com a próxima posição que depende
		 * da direção da procura, como definida anteriormente. A 
		 * condição de parada não será sempre i < linhas e j < colunas 
		 * pois no sentido da diagonal secundária, j diminui (diagonal para baixo) 
		 * e a condição de parada torna-se i < linhas e j >= 0. Fazer um desenho 
		 * pode ajudar na compreensão.
		 *
		 * Exemplo de procura com palíndromo:
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
		 * posição encontrará Rar, que será identificado como palindrome, e a posição final 
		 * que nesse caso são as coordenadas de 'r', o último caractere. Veja o comentário 
		 * abaixo para saber a utilidade da posição final.
		 */
		for (i = init_i, j = init_j; i < array->rows && 
								    ((step_j == -1) ? j >= 0 : j < array->cols);
								    i += step_i, j += step_j)
		{
			/*Se o caractere atual é válido, ele é adicionado a string1.*/
			if (!ignorac(list_ign, array->data[i][j]))
				string1[s++] = array->data[i][j];
			string1[s] = '\0'; /*Finaliza string1*/

			/* Se string2 == NULL, busca por palíndromos */
			/* e size = tamanho da string atual */
			unsigned size = (string2) ? str2len : s;
			/**
			 * Lógica para strings:
			 *
			 * Apenas armazena a posição final (end_i e end_j).
			 * 
			 * Lógica para palíndromos:
			 * 
			 * Verifica se string é um palíndromo. Se for, salva a posição final 
			 * (end_i e end_j). Essa posição final é útil para verificar se o 
			 * palíndromo encontrado é na verdade um palíndromo dentro de outro 
			 * palíndromo. Por exemplo:
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
			/* sentido = 1 se string1 = string2 ou se string1 for um palindromo */
			/* sentido = -1 se string1 e string2 forem simétricas */
			/* sentido = 0 caso contrário */
			aux_sentido = strlogic(string1, string2, size, ign_cs, ign_inv);
			if (aux_sentido)
			{
				if (!ignorac(list_ign, array->data[i][j]))
				{
					*end_i = i;
					*end_j = j;
				}
				strcpy(string3, string1);
				*sentido = aux_sentido;
				flag = true;
			}
		}
	}

	return flag;
}

/**
 * invstr
 *
 * Inverse a string passada como parâmetro. 
 * É necessária pois algumas strings são 
 * encontradas no sentido oposto (direita->esquerda) 
 * ou (baixo->cima).
 */
static void invstr(char *string)
{
	char aux;
	unsigned len = strlen(string);
	unsigned i, j;

	for (i = 0, j = len-1; i < j;i++, j--)
	{
		aux = string[i];
		string[i] = string[j];
		string[j] = aux;
	}
}

/**
 * insere_pos 
 *
 * Insere a "linha" (x0,y0)-->(x1,y1) na lista L
 */
static Linp_Word *insere_word(Linp_Word *L, 
					   		  unsigned x0, unsigned x1, unsigned y0, unsigned y1, 
					   		  char *string, int sentido)
{
	Linp_Word *novo;

	novo = malloc(sizeof(Linp_Word));

	if (novo == NULL)
	{
		printf("ERRO: Em proc. Na funcao insere_word. Nao foi possivel alocar memoria para a variavel novo.\n");
		exit(EXIT_FAILURE);
	}

	if (sentido == 1) /* string direita */
	{
		novo->x0 = x0;
		novo->x1 = x1;
		novo->y0 = y0;
		novo->y1 = y1;
	}
	if (sentido == -1) /* string invertida */
	{
		novo->x0 = x1;
		novo->x1 = x0;
		novo->y0 = y1;
		novo->y1 = y0;
		invstr(string);
	}

	/* Aloca memória para word */
	unsigned size = strlen(string) + 1;

	novo->word = malloc(size * sizeof(char));

	if (novo->word == NULL)
	{
		printf("ERRO: Em proc. Na funcao insere_word. Nao foi possivel alocar memoria para a variavel novo->word.\n");
		exit(EXIT_FAILURE);
	}

	/* Copia string para word */
	strcpy(novo->word, string);

	novo->next = L;

	return novo;
}

/**
 * Busca pela string ou por palíndromos nas linhas do array
 */
static void proclin(Linp_Mat *array, 
					Linp_Word **pos, 
					char *list_ign, bool ign_cs, bool ign_inv, 
					char *string1, char *string2, unsigned str2len, 
					char *string3)
{
	int i, j;
	int end_i, end_j, last_end;
	int sentido;

	for (i = 0; i < array->rows; i++)
	{
		last_end = 0; /*Inicializa last_end na primeira posição, j = 0*/
		for (j = 0; j < array->cols; j++)
		{
			/* Verifica se encontrou a string ou um palíndromo
             * e, caso seja um palíndromo, verifica se não é um 
             * subpalíndromo.
			 */
			if (strproc(array, list_ign, ign_cs, ign_inv,  
					i, j, 0, 1, &end_i, &end_j, 
					string1, string2, str2len, string3, &sentido) && end_j > last_end)
			{
				*pos = insere_word(*pos, j, end_j, i, end_i, string3, sentido);

				/*Salva a posição final para a lógica do palíndromo*/
				last_end = end_j;
			}
		}
	}
}

/**
 * Busca pela string ou por palíndromos nas colunas do array
 */
static void proccol(Linp_Mat *array, 
					Linp_Word **pos, 
					char *list_ign, bool ign_cs, bool ign_inv, 
					char *string1, char *string2, unsigned str2len, 
					char *string3)
{
	int i, j;
	int end_i, end_j, last_end;
	int sentido;

	for (j = 0; j < array->cols; j++)
	{
		last_end = 0; /*Inicializa last_end na primeira posição, i = 0*/
		for (i = 0; i < array->rows; i++)
		{
			/* Verifica se encontrou a string ou um palíndromo
             * e, caso seja um palíndromo, verifica se não é um 
             * subpalíndromo.
			 */
			if (strproc(array, list_ign, ign_cs, ign_inv, 
					i, j, 1, 0, &end_i, &end_j, 
					string1, string2, str2len, string3, &sentido) && end_i > last_end)
			{
				*pos = insere_word(*pos, j, end_j, i, end_i, string3, sentido);

				/*Salva a posição final para a lógica do palíndromo*/
				last_end = end_j;
			}
		}
	}
}

/**
 * Busca pela string ou por palíndromos nas diagonais P do array
 */
static void procdiP(Linp_Mat *array, 
					Linp_Word **pos, 
					char *list_ign, bool ign_cs, bool ign_inv, 
					char *string1, char *string2, unsigned str2len, 
					char *string3)
{
	int i, j, k, l;
	int end_i, end_j, last_end_i, last_end_j;
	int sentido;

	for (j = 0; j < array->cols; j++)
	{
		for (i = array->rows-1; i>=0; i--)
		{
			if (j>0) i = 0; /*evita repetições*/
			/*Inicializa last_end na primeira posição da diagonal P, [0][0]*/
			last_end_i = last_end_j = 0; 
			for (k = i,l = j; k < array->rows && l < array->cols; k++, l++)
			{
				/* Verifica se encontrou a string ou um palíndromo
	             * e, caso seja um palíndromo, verifica se não é um 
	             * subpalíndromo.
				 */
				if (strproc(array, list_ign, ign_cs, ign_inv, 
						k, l, 1, 1, &end_i, &end_j, 
						string1, string2, str2len, string3, &sentido) && end_i > last_end_i && end_j > last_end_j)
				{
					*pos = insere_word(*pos, l, end_j, k, end_i, string3, sentido);

					/*Salva a posição final para a lógica do palíndromo*/
					last_end_i = end_i;
					last_end_j = end_j;
				}
			}
		}
	}
}

/**
 * Busca pela string ou por palíndromos nas diagonais S do array
 */
static void procdiS(Linp_Mat *array, 
					Linp_Word **pos, 
					char *list_ign, bool ign_cs, bool ign_inv, 
					char *string1, char *string2, unsigned str2len, 
					char *string3)
{
	int i, j, k, l;
	int end_i, end_j, last_end_i, last_end_j;
	int sentido;

	for (i = 0; i < array->rows; i++)
	{
		for (j = 0; j < array->cols; j++)
		{
			if (i > 0) j = array->cols-1; /*evita repetições*/
			/*Inicializa last_end na primeira posição da diagonal S, [0][cols-1]*/
			last_end_i = 0;
			last_end_j = array->cols-1;
			for (k = i,l = j; k < array->rows && l >= 0; k++, l--)
			{
				/* Verifica se encontrou a string ou um palíndromo
	             * e, caso seja um palíndromo, verifica se não é um 
	             * subpalíndromo.
				 */
				if (strproc(array, list_ign, ign_cs, ign_inv, 
						k, l, 1, -1, &end_i, &end_j, 
						string1, string2, str2len, string3, &sentido) && end_i > last_end_i && end_j < last_end_j)
				{
					*pos = insere_word(*pos, l, end_j, k, end_i, string3, sentido);

					/*Salva a posição final para a lógica do palíndromo*/
					last_end_i = end_i;
					last_end_j = end_j;
				}
			}
		}
	}
}

/**
 * Cria um array de listas encadeadas
 */
static Linp_Word **pos_array(unsigned size)
{
	Linp_Word **aux;

	aux = malloc((size + 1) * sizeof(Linp_Word *));
	if (aux == NULL)
	{
		printf("ERRO: Em proc. Na funcao pos_array. Nao foi possivel alocar memoria para a variavel *aux.\n");
		exit(EXIT_FAILURE);
	}

	/* Inicializa as listas */
	unsigned i;
	for (i = 0; i < size; i++)
	{
		aux[i] = NULL;
	}
	aux[size] = NULL; /* Indica o término do array de listas word */

	/* Adiciona o bloco de memória alocada para o heap atual */
	Words *new;

	new = malloc(sizeof(Words));
	if (new == NULL)
	{
		printf("ERRO: Em proc. Na funcao pos_array. Nao foi possivel adicionar o novo array de words ao heap.\n");
		exit(EXIT_FAILURE);
	}

	new->word_add = aux;
	new->next = heap->w;
	heap->w = new;

	return aux;
}

/**
 * EDIT: proc não é mais visível. Utilize procstr ou procpali.
 * 
 * void proc(Linp_Mat *, Linp_Word ***, char *, const char *, const char *, bool);
 *
 * (Linp_Word ***) -> armazenará o array de listas encadeadas que contém a localização dos (char *).
 * em (Linp_Mat *) após a conclusão da função.
 * (char *) -> se == NULL, procura por palíndromos em (Linp_Mat *).
 * (const char *) -> "linhas" -- procura apenas nas linhas.
 * 			   		 "colunas" -- procura apenas nas colunas.
 * 			      	 "diagP" -- procura apenas nas diagonais no sentido da principal.
 * 			         "diagS" -- procura apenas nas diagonais no sentido da secundária.
 * 			         "todas" -- procura em todas as direções acima.
 * (const char *) -> se == NULL, não ignora nenhum caractere.
 * 					 "!alfanum" -- ignora todos os caracteres não alfanuméricos.
 * 			   		 " @&*" -- ignora os caracteres ' ', '@', '&' e '*'.
 * 			      	 obs: o usuário pode fornecer qualquer lista de caracteres.
 * (bool) -> se == true, ignora case sensitive.
 *
 * Ex: 
 *
 * Linp_Mat *grid = lp.criarmat(1000,1000);
 * Linp_Word **posicoes;
 * char string[100];
 * 
 * lp.lerarquivo(grid, "arquivo.txt");
 * input("~Insira uma string: ", "%s", string, 100);
 *
 * lp.proc(grid, posicoes, string, "todas", "!alfanum", 1);
 *
 * Linp_Word **palindromos;
 *
 * lp.proc(grid, palindromos, NULL, "todas", "!alfanum", 1);
 * 
 */
static void kernelproc(Linp_Mat *array, Linp_Word ***pos, char *string, char *dir, char *ign_chars, bool ign_cs)
{
	/**
	 * Prepara a lista de caracteres a serem ignorados, a string 
	 * auxiliar de busca e a string de varredura.
	 */
	char *ignorar = list_ign(ign_chars, ign_cs); /* Lista com os caracteres a serem ignorados por proc*/
	char *string_aux = NULL; /* string auxiliar, leva em conta os parâmetros ign_chars e ign_cs */
	unsigned strauxlen = 0;
	if (string)
	{
		string_aux = straux(string, ignorar, ign_cs);
		strauxlen = strlen(string_aux);
	}

	/*Tamanho máximo da string de varredura. Será o valor da maior dimensão da matriz.*/
	unsigned string1_length = (array->rows > array->cols) ? array->rows : array->cols;
	char *string1 = malloc((1 + string1_length) * sizeof(char));

	if (string1 == NULL)
	{
		printf("ERRO: Em proc. Na funcao linp__proc. Nao foi possivel alocar memoria para a variavel string1.\n");
		exit(EXIT_FAILURE);
	}

	/* String que armazenará a palavra encontrada */
	char *string3 = malloc((1 + string1_length) * sizeof(char));

	if (string3 == NULL)
	{
		printf("ERRO: Em proc. Na funcao linp__proc. Nao foi possivel alocar memoria para a variavel string3.\n");
		exit(EXIT_FAILURE);
	}

	/**
	 * Verifica a direção da procura e aloca memória para pos
	 */
	bool ign_inv = dir[0] == '-';
	unsigned size = strlen(dir) - ign_inv;

	*pos = pos_array(size);

	char *ptr = (ign_inv) ? dir+1 : dir;
	unsigned i;

	for (i = 0; ptr[i]; i++)
	{
		switch(ptr[i])
		{
			case 'L':
			{
				proclin(array, &pos[0][i], ignorar, ign_cs, ign_inv, string1, string_aux, strauxlen, string3);
				break;
			}
			case 'C':
			{
				proccol(array, &pos[0][i], ignorar, ign_cs, ign_inv, string1, string_aux, strauxlen, string3);
				break;
			}
			case 'P':
			{
				procdiP(array, &pos[0][i], ignorar, ign_cs, ign_inv, string1, string_aux, strauxlen, string3);
				break;
			}
			case 'S':
			{
				procdiS(array, &pos[0][i], ignorar, ign_cs, ign_inv, string1, string_aux, strauxlen, string3);
				break;
			}
			default:
				break;
		}
	}

	/* Libera a memória previamente alocada */
	free(ignorar);
	free(string_aux);
	free(string1);
	free(string3);
}

/**
 * Verifica se a direção passada é válida
 */
static void validdir(char *ptr)
{
	if (strcmp(ptr, "L") && 
		strcmp(ptr, "C") && 
		strcmp(ptr, "P") && 
		strcmp(ptr, "S") && 
		strcmp(ptr, "LC") && 
		strcmp(ptr, "LP") && 
		strcmp(ptr, "LS") && 
		strcmp(ptr, "CP") && 
		strcmp(ptr, "CS") && 
		strcmp(ptr, "PS") && 
		strcmp(ptr, "LCP") && 
		strcmp(ptr, "LCS") && 
		strcmp(ptr, "LPS") && 
		strcmp(ptr, "CPS") && 
		strcmp(ptr, "LCPS") ) 
	{
		printf("ERRO: Em proc. Argumento invalido para dir. Este parametro aceita somente "
			   "as strings abaixo.\n\n"
			   "\"L\": procura nas linhas\n"
			   "\"C\": procura nas colunas\n"
			   "\"P\": procura na direcao da diagonal principal\n"
			   "\"S\": procura na direcao da diagonal secundaria\n"
			   "\"LC\": procura nas direcoes L e C\n"
			   "\"LP\": procura nas direcoes L e P\n"
			   "\"LS\": procura nas direcoes L e S\n"
			   "\"CP\": procura nas direcoes C e P\n"
			   "\"CS\": procura nas direcoes C e S\n"
			   "\"PS\": procura nas direcoes P e S\n"
			   "\"LCP\": procura nas direcoes L, C e P\n"
			   "\"LCS\": procura nas direcoes L, C e S\n"
			   "\"LPS\": procura nas direcoes L, P e S\n"
			   "\"CPS\": procura nas direcoes C, P e S\n"
			   "\"LCPS\": procura nas direcoes L, C, P e S\n\n"
			   "O usuario pode inserir o caractere '-' antes da direcao para indicar que "
			   "nao deseja procurar na sentido oposto (string invertida). Por exemplo:\n\n"
			   "\"-LCPS\": procura nas direcoes L, C, P e S, mas nao procura a string invertida.\n\n"
			   "O caractere '-' nao tem qualquer efeito se o usuario estiver procurando por palindromos.\n\n"
			   "Veja a documentacao para mais detalhes.\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * procstr e procpali
 *
 * Funções criadas com o objetivo de tornar o acesso à função proc 
 * mais amigável. procstr e procpali buscam uma string e palíndromos, 
 * respectivamente, e destacam as ocorrências no array.
 */

/**
 * Destaca as ocorrencias nas linhas
 */
static void destacalinhas(Linp_Mat *src, Linp_Mat *dst, Linp_Word *posicoes)
{
	int i, j;
	int flag = posicoes->x0 < posicoes->x1;
	int init_j = flag ? posicoes->x0 : posicoes->x1;
	int end_j = flag ? posicoes->x1 : posicoes->x0;

	for (i = posicoes->y0, j = init_j; j <= end_j; j++)
	{
		dst->data[i][j] = src->data[i][j];
	}
}

/**
 * Destaca as ocorrencias nas colunas
 */
static void destacacolunas(Linp_Mat *src, Linp_Mat *dst, Linp_Word *posicoes)
{
	int i, j;
	int flag = posicoes->y0 < posicoes->y1;
	int init_i = flag ? posicoes->y0 : posicoes->y1;
	int end_i = flag ? posicoes->y1 : posicoes->y0;

	for (i = init_i, j = posicoes->x0; i <= end_i; i++)
	{
		dst->data[i][j] = src->data[i][j];
	}
}

/**
 * Destaca as ocorrencias nas diagP
 */
static void destacadiagP(Linp_Mat *src, Linp_Mat *dst, Linp_Word *posicoes)
{
	int i, j;
	int flag = posicoes->x0 < posicoes->x1;
	int init_i = flag ? posicoes->y0 : posicoes->y1;
	int end_i = flag ? posicoes->y1 : posicoes->y0;
	int init_j = flag ? posicoes->x0 : posicoes->x1;
	int end_j = flag ? posicoes->x1 : posicoes->x0;

	for (i = init_i, j = init_j; 
		 i <= end_i && j <= end_j; 
		 i++, j++)
	{
		dst->data[i][j] = src->data[i][j];
	}
}

/**
 * Destaca as ocorrencias nas diagS
 */
static void destacadiagS(Linp_Mat *src, Linp_Mat *dst, Linp_Word *posicoes)
{
	int i, j;
	int flag = posicoes->x0 > posicoes->x1;
	int init_i = flag ? posicoes->y0 : posicoes->y1;
	int end_i = flag ? posicoes->y1 : posicoes->y0;
	int init_j = flag ? posicoes->x0 : posicoes->x1;
	int end_j = flag ? posicoes->x1 : posicoes->x0;

	for (i = init_i, j = init_j; 
		 i <= end_i && j >= end_j; 
		 i++, j--)
	{
		dst->data[i][j] = src->data[i][j];
	}
}

/**
 * Função que destaca as ocorrências de string em src
 * através de dst.
 */
static void proc(Linp_Mat *src, Linp_Mat *dst, Linp_Word ***words, 
				 char *string, char *dir, char *ign_chars, bool ign_cs)
{
	/* Verifica se está dentro de um bloco LINP */
	if (words && heap_count == 0)
	{
		printf("ERRO: Em proc. Esta funcao so pode alocar memoria para words dentro de um bloco LINP.\n");
		exit(EXIT_FAILURE);
	}

	char *ptr = (dir[0] == '-') ? dir+1 : dir;
	validdir(ptr);

	/* Procura pelas ocorrências */
	Linp_Word **posicoes;

	kernelproc(src, &posicoes, string, dir, ign_chars, ign_cs);

	if (dst)
	{
		/* Inicializa dst */
		dst->rows = src->rows;
		dst->cols = src->cols;
		int i, j;
		for (i = 0; i < dst->rows; i++)
			for (j = 0; j < dst->cols; j++)
				dst->data[i][j] = (char) 250;

		for (i = 0; ptr[i]; i++)
		{
			Linp_Word *varre = posicoes[i];

			switch(ptr[i])
			{
				case 'L':
				{
					while (varre)
					{
						destacalinhas(src, dst, varre);
						varre = varre->next;
					}
					break;
				}
				case 'C':
				{
					while (varre)
					{
						destacacolunas(src, dst, varre);
						varre = varre->next;
					}
					break;
				}
				case 'P':
				{
					while (varre)
					{
						destacadiagP(src, dst, varre);
						varre = varre->next;
					}
					break;
				}
				case 'S':
				{
					while (varre)
					{
						destacadiagS(src, dst, varre);
						varre = varre->next;
					}
					break;
				}
				default:
					break;
			}
		}
	}

	/* Libera a memória previamente alocada */
	if (words == NULL)
	{
		linp__destruirword(posicoes);
		heap->w = heap->w->next;
	}
	else 
	{
		/**
		 * É responsabilidade do usuário liberar a memória alocada 
		 * para posicoes, para onde words aponta.
		 */
		*words = posicoes;
	}
}

/*********************************************************************
 * 						   Top Level Functions						 *
 *********************************************************************
 */

/**
 * procstr
 *
 * Função que destaca as ocorrências de str em src.
 */
static void linp__procstr(Linp_Mat *src, Linp_Mat *dst, Linp_Word ***words, 
				   		  char *string, char *dir, char *ign_chars, bool ign_cs)
{
	char error_msg[351] = "\0";
	bool error_flag = false;
	/* Verifica se src é válido */
	if (src == NULL)
	{
		strcat(error_msg, "ERRO: Em procstr. O parametro src nao pode ser NULL.\n");
		error_flag = true;
	}
	/* Verifica se a string é válida */
	if (string == NULL)
	{
		strcat(error_msg, "ERRO: Em procstr. O parametro string nao pode ser NULL. Se deseja "
			   			  "procurar por palindromos, utilize a funcao procpali.\n");
		error_flag = true;
	}
	/* Verifica se dir é válida */
	if (dir == NULL)
	{
		strcat(error_msg, "ERRO: Em procstr. O parametro dir nao pode ser NULL. Valores aceitos: " 
			   			  "\"linhas\", \"colunas\", \"diagP\", \"diagS\" e \"todas\".\n");
		error_flag = true;
	}
	/* Verifica se ign_chars é válida */
	if (ign_chars == NULL)
	{
		strcat(error_msg, "ERRO: Em procstr. O parametro ign_chars nao pode ser NULL.\n");
		error_flag = true;
	}

	if (error_flag)
	{
		puts(error_msg);
		exit(EXIT_FAILURE);
	}

	proc(src, dst, words, string, dir, ign_chars, ign_cs);
}

/**
 * procpali
 *
 * Função que destaca os palíndromos em src.
 */
static void linp__procpali(Linp_Mat *src, Linp_Mat *dst, Linp_Word ***words,
				    	   char *dir, char *ign_chars, bool ign_cs)
{
	char error_msg[235] = "\0";
	bool error_flag = false;

	/* Verifica se src é válido */
	if (src == NULL)
	{
		strcat(error_msg, "ERRO: Em procpali. O parametro src nao pode ser NULL.\n");
		error_flag = true;
	}
	/* Verifica se dir é válida */
	if (dir == NULL)
	{
		strcat(error_msg, "ERRO: Em procpali. O parametro dir nao pode ser NULL. Valores aceitos: " 
			 			  "\"linhas\", \"colunas\", \"diagP\", \"diagS\" e \"todas\".\n");
		error_flag = true;
	}
	/* Verifica se ign_chars é válida */
	if (ign_chars == NULL)
	{
		strcat(error_msg, "ERRO: Em procpali. O parametro ign_chars nao pode ser NULL.\n");
		error_flag = true;
	}

	if (error_flag)
	{
		puts(error_msg);
		exit(EXIT_FAILURE);
	}

	/* Chama proc com string = NULL para procurar por palíndromos */
	proc(src, dst, words, NULL, dir, ign_chars, ign_cs);
}
