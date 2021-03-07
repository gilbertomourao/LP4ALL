/**
 * Algoritmo que diz se uma string é um palíndromo
 *
 * Arara
 *
 * Toda string é um vetor de caracteres terminado por um '\0'
 */

#include <stdio.h>

#define SIZE 100


int main()
{
	char palavra[SIZE];

	printf("Insira uma string: ");
	gets(palavra);

	printf("String inserida: %s\n", palavra);

	/*Verifica se a string inserida é um palíndromo*/
	unsigned tamanho = 0;

	while (palavra[tamanho] != '\0')
	{
		tamanho++;
	}

	printf("Tamanho da string: %u\n", tamanho);

	/**
	 * Agora que tamanho armazena o tamanho da string, nós temos 
	 * acesso ao último elemento: tamanho-1
	 */
	
	int i, j; /* iteradores */

	/**
	 * 01234
	 * arara
	 *
	 * tamanho = 5
	 *
	 * i = 0, j = 4
	 *
	 * compara: a com a
	 *
	 * i = 1, j = 3
	 *
	 * compara: r com r
	 *
	 * i = 2, j = 2
	 *
	 * i não é menor do que j
	 */
	
	/**
	 * 01234
	 * thays
	 *
	 * tamanho = 5
	 *
	 * i = 0, j = 4
	 *
	 * compara: t com s
	 *
	 * São diferentes, então imprime Não é um palíndromo.
	 */
	
	/**
	 * Sobre a função tolower
	 *
	 * tolower(A) --> a
	 * tolower(a) --> a
	 *
	 * Mas, isso não altera o caractere!
	 *
	 * string = Ana
	 *
	 * tolower(string[0]) --> a
	 */

	char aux_i, aux_j;

	for (i = 0, j = tamanho-1; i < j; i++, j--)
	{
		/* Se palavra[i] for maiúscula */
		if (palavra[i] >= 'A' && palavra[i] <= 'Z')
		{
			aux_i = palavra[i] + 'a' - 'A'; /* transforma maiúscula em minúscula */
		}
		else 
		{
			aux_i = palavra[i];
		}

		/* Se palavra[j] for maiúscula */
		if (palavra[j] >= 'A' && palavra[j] <= 'Z')
		{
			aux_j = palavra[j] + 'a' - 'A'; /* transforma maiúscula em minúscula */
		}
		else 
		{
			aux_j = palavra[j];
		}

		if (aux_i != aux_j)
		{
			printf("\nNao e um palindromo!!!\n");
			return -1;
		}
	}

	printf("\nE um palindromo!!!\n");
	
	return 0;
}