#include <stdio.h>
#include <math.h> /* função pow */

#define SIZE 100

int main()
{
	int vec[SIZE];
	unsigned numero;

	do
	{
		printf("Insira um numero de ate 4 digitos: ");

		while (scanf("%u", &numero) != 1)
		{
			printf("Valor invalido!!! Insira um unsigned: ");
			/* Limpa o buffer */
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF); /*END OF FILE*/
		} 

		printf("Numero inserido: %u\n", numero);
	} while (numero / 10000 > 0);

	/**
	 * Captura os dígitos do número
	 */
	
	unsigned divi = 1;
	unsigned digitos = 1;

	while (numero / divi > 10)
	{
		divi = divi * 10;
		digitos++;
	}

	printf("Numero de digitos: %u\n", digitos);

	int i; /* iterador */
	unsigned accum = 0; /* accumulator */

	for (i = digitos - 1; i >= 0; i--)
	{
		vec[i] = numero / pow(10, i) - accum;
		accum = accum * 10 + vec[i] * 10;
		printf("%d\n", vec[i]);
	}

	/**
	 * Agora temos um vetor de tamanho = digitos que 
	 * contém todos os digitos do número.
	 */
	int j; /* o i eu já criei */

	for (i = 0, j = digitos - 1; i < j; i++, j--)
	{
		if (vec[i] != vec[j])
		{
			printf("\nNao e um palindromo!!!\n");
			return -1;
		}
	}

	printf("\nE um palindromo!!!\n");

	return 0;
}