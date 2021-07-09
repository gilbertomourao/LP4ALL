/**
 * Solução da questão 1 da prova 3 com LINP
 */

#include <linp.h>
#include <string.h> /* Para strlen() */
#include <stdio.h>

#define MAX_SIZE 100

void invstr(char *);
void substitui(Linp_Mat *, char *, Linp_Word *);

int main()
{
	lp.start();

	Linp_Mat *str1 = lp.criarmat(1, MAX_SIZE);
	Linp_Mat *dst = lp.criarmat(1, MAX_SIZE);
	char str2[MAX_SIZE];

	lp.input("String 1: ", "%s", str1->data[0], MAX_SIZE);
	lp.input("String 2: ", "%s", str2, MAX_SIZE);

	/**
	 * Antes de usar a função procstr, o valor de cols 
	 * da Linp_Mat str1 deve ser corrigido para o tamanho 
	 * da string lida. Alterar o membro cols de Linp_Mat 
	 * não afeta a função destruirmat.
	 */
	unsigned i;
	for (i = 0; str1->data[0][i] != '\0'; i++);
	str1->cols = i;
	dst->cols = i;

	/* Procura str2 em str1 sem ignorar qualquer 
	 * caractere e sem ignorar case sensitive. Também 
	 * não procura str2 invertida. 
	 * dst irá armazenar str1 com as ocorrências de 
	 * str2 destacadas.
	 */
	Linp_Word **palavras;
	lp.procstr(str1, dst, &palavras, str2, "-L", "", false);

	lp.dispmat(dst, "Ocorrencias: ");

	invstr(str2);
	substitui(dst, str2, palavras[0]);

	lp.dispmat(dst, "Resposta: ");

	/**
	 * Se quiser imprimir do modo convencional, 
	 * utilizando a função printf, declare um ponteiro 
	 * para um char e aponte para dst. 
	 *
	 * Antes, insira um '\0' na última posição de dst.
	 */
	dst->data[0][dst->cols] = '\0';
	char *ptr = dst->data[0];
	printf("String resposta: %s\n", ptr);

	/* Libera a memória previamente alocada */
	lp.stop();

	return 0;
}

/**
 * Função que inverte a string str passada como
 * parâmetro.
 */
void invstr(char *str)
{
	char aux;
	unsigned i;
	unsigned j = strlen(str);

	for (i = 0, j = j - 1; i < j; i++, j--)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
	}
}

/**
 * Função que substitui as ocorrências pela 
 * string invertida
 */
void substitui(Linp_Mat *str1, char *strinv, Linp_Word *palavras)
{
	unsigned i, j;
	Linp_Word *temp = palavras;
	while(temp)
	{
		for (j = temp->x0; j <= temp->x1; j++)
			str1->data[0][j] = strinv[j - temp->x0];
		temp = temp->next;
	}

	/* O professor pediu para substituir por '*', nesse caso... */
	for (i = 0; i < str1->cols; i++)
	{
		if (str1->data[0][i] == (char) 250)
			str1->data[0][i] = '*';
	}
}