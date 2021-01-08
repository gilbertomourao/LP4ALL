/**
 * Questão 1 - Prova 3
 * Disciplina: Linguagem de Programação
 *
 * Data: 22/12/2020
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

/**
 * Macro que identifica se um caractere é alfanumérico
 */
#define VALID_CHAR(ch) ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9'))

/**
 * Struct que armazena as posições inicial e final de uma string
 */
typedef struct substring
{
	unsigned init;
	unsigned end;
} Subpos;

/**
 * Cabeçalho de funções
 */
char *createstr(unsigned);
Subpos *createpos(unsigned);
void readstr(char *, unsigned);
void printstr(char *);
void procstr(char *, char *, Subpos *, unsigned *);
void invstr(char *);
void insertstr(char *, char *, Subpos *, unsigned *);

int main()
{
	char *string1 = createstr(SIZE);
	char *string2 = createstr(SIZE);
	Subpos *pos = createpos(SIZE); /*para guardar as posições das ocorrências da string2 na string1*/

	printf("Insira a primeira string: ");
	readstr(string1, SIZE);

	printf("Insira a segunda string: ");
	readstr(string2, SIZE);

	/*Procura as ocorrencias da string2 na string1*/
	unsigned ocorrencias;
	procstr(string2, string1, pos, &ocorrencias);

	/*Inverte a string2*/
	invstr(string2);

	/*Substitui a string2 invertida nas ocorrencias da string2 original na string1*/
	insertstr(string2, string1, pos, &ocorrencias);

	/*Imprime o resultado*/
	printf("String resultante: ");
	printstr(string1);

	/* Chamar free no final da main não é necessário. O SO já faz isso. */
	free(string1);
	free(string2);
	free(pos);

	return 0;
}

/**
 * Funções
 */

/**
 * Função que cria um vetor de caracteres utilizando alocação dinâmica.
 * Para liberar a memória, basta utilizar a função free(vetor), onde vetor
 * é um vetor de caracteres, como segue.
 *
 * char *vetor = createstr(100);
 *
 * seu código
 * 
 * free(vetor);
 */
char *createstr(unsigned max_str_len)
{
	char *string;

	/*Não é bom fazer cast em malloc, pode esconder alguns bugs, caso ocorram*/
	string = malloc(max_str_len * sizeof(char)); 

	/*Verifica se tudo ocorreu normalmente*/
	if (string == NULL)
	{
		printf("ERRO: Em createstr. Alocacao de memoria falhou! Verificar a variavel string.\n");
		exit(EXIT_FAILURE);
	}

	return string;
}

Subpos *createpos(unsigned max_pos_len)
{
	Subpos *pos;

	pos = malloc(max_pos_len * sizeof(Subpos));

	/*Verifica se tudo ocorreu normalmente*/
	if (pos == NULL)
	{
		printf("ERRO: Em createpos. Alocacao de memoria falhou! Verificar a variavel pos.\n");
		exit(EXIT_FAILURE);
	}

	return pos;
}

/**
 * Função que lê uma string de stdin (teclado).
 */
void readstr(char *string, unsigned buffer_size)
{
	/**
	 * Lê string utilizando fgets, diretamente de stdin (teclado).
	 * Impede que uma string com tamanho > buffer_size seja lida, 
	 * evitando que região de memória não alocada pelo sistema 
	 * operacional seja acessada. 
	 */
	fgets(string, buffer_size, stdin);

	/* 
	 * Incrementa o iterador "i" até encontrar um '\n' ou chegar 
	 * ao '\0'.
	 */
	unsigned i;
	for (i = 0; *(string+i) != '\0' && *(string+i) != '\n'; i++);

	/**
	 * Caso tenha encontrado '\n', remove inserindo um '\0' no lugar.
	 */
	if (*(string+i) == '\n')
		*(string+i) = '\0';
	else
	{
		/**
		 * Encontrou o '\0', ou seja, fgets não encontrou espaço para inserir
		 * um '\n' antes do '\0'. Isso significa que antes do ENTER do usuário, 
		 * mais caracteres foram inseridos via stdin do que o permitido, ou seja, 
		 * num_de_caracteres > buffer_size. O while abaixo limpa o buffer, consumindo 
		 * esse excesso de caracteres.
		 */
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
	}

	/**
	 * Verifica se a string informada é válida, ou seja, se possui
	 * apenas caracteres alfanuméricos.
	 *
	 * Caso não seja, chama novamente a função readstr.
	 */
	for (i = 0; *(string+i) != '\0'; i++)
	{
		if (!VALID_CHAR(*(string +i)))
		{
			printf("ERRO: Em readstr. Apenas caracteres alfanumericos sao permitidos! Insira uma nova string.\nNova tentativa: ");
			readstr(string, buffer_size);
		}
	}
}

/**
 * Função que imprime a string na tela
 */
void printstr(char *string)
{
	/*Não vejo isso como algo útil*/
	puts(string);
}


/**
 * Função que procura a string2 na string1
 */
void procstr(char *string2, char *string1, Subpos *pos, unsigned *ocorrencias)
{
	unsigned i, j, flag;
	Subpos *aux_pos = pos; /* auxiliar para varrer pos */

	*ocorrencias = 0; /* reseta ocorrencias */

	for (i = 0; *(string1 + i) != '\0'; i++)
	{
		j = 0;
		if (*(string1 + i) == *(string2 + j))
		{
			flag = 1;
			unsigned i_aux;
			for (i_aux = i+1, j = 1; flag && *(string1 + i_aux) && *(string2 + j); i_aux++, j++)
			{
				flag = (*(string1 + i_aux) == *(string2 + j)) && 
						*(string1 + i_aux) && 
						*(string2 + j);
			}

			/**
			 * Se sair do for com flag = 1 e *(string2+j) = '\0', encontrou a string2 na string1 
			 * entre i e i_aux-1
			 */
			if (flag && !*(string2+j))
			{
				aux_pos->init = i;
				(aux_pos++)->end = i_aux-1;

				*ocorrencias += 1; /* Incrementa ocorrencias */
			}
		}
	}
}

/**
 * Função que inverte a string
 */
void invstr(char *string)
{
	char aux; 
	unsigned i, j, len = 0;

	/*Adquire o tamanho da string*/
	for (i = 0; *(string+i) != '\0'; i++)
		len++;

	for (i = 0, j = len-1; i < j; i++, j--)
	{
		aux = *(string+i);
		*(string+i) = *(string+j);
		*(string+j) = aux;
	}
}


/**
 * Função que insere a string2 na string1 entre as posições dadas por pos.
 */
void insertstr(char *string2, char *string1, Subpos *pos, unsigned *ocorrencias)
{
	unsigned i, j, k;
	Subpos *pos_aux; /*Para facilitar a leitura do código*/

	/* Primeiro substitui todos os caracteres por '*' */
	for (i = 0; *(string1 + i); i++)
		*(string1 + i) = '*';

	/* Depois, insere a string2 invertida entre as posições indicadas */
	for (i = 0; i < *ocorrencias; i++)
	{
		pos_aux = pos + i;
		for (j = pos_aux->init, k = 0; j <= pos_aux->end; j++, k++)
		{
			*(string1 + j) = *(string2 + k);
		}
	}
}