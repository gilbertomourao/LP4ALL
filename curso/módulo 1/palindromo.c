/**
 * Verifica se uma string é um palíndromo ignorando espaço
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

	/* String auxiliar */
	char aux[SIZE];

	int i; /* iterador */
	int j = 0;

	for (i = 0; palavra[i] != '\0'; i++)
	{
		if (palavra[i] >= 'A' && palavra[i] <= 'Z')
		{
			aux[j] = palavra[i] + 'a' - 'A';
			j++;
		}
		else 
		{
			if (palavra[i] != ' ')
			{
				aux[j] = palavra[i];
				j++;
			}
		}
	}
	aux[j] = '\0'; /* Finalizo a string auxiliar */

	printf("\nString auxiliar: %s\n", aux);

	/* Verifica se é um palíndromo */
	unsigned tamanho_aux = j;

	printf("Tamanho da string auxiliar = %u\n", tamanho_aux);

	/* Verifica se é um palíndromo */
	for (i = 0, j = tamanho_aux-1; i < j; i++, j--)
	{
		if (aux[i] != aux[j])
		{
			printf("\nNao e um palindromo!!!\n");
			return -1;
		}
	}

	printf("\nE um palindromo!!!\n");

	return 0;
}