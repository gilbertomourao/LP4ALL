#include <stdio.h>
#include <math.h> /* função pow */

#define SIZE 100

int main()
{
	int vec[SIZE];
	unsigned numero;

	printf("Insira um numero inteiro positivo: ");

	while (scanf("%u", &numero) != 1)
	{
		printf("Valor invalido!!! Insira um unsigned: ");
		/* Limpa o buffer */
		char ch;
		while ((ch = getchar()) != '\n' && ch != EOF); /*END OF FILE*/
	} 

	printf("Numero inserido: %u\n", numero);

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

	for (i = 0; i < digitos; i++)
	{
		vec[i] = numero / pow(10, digitos-1-i) - accum;
		accum = accum * 10 + vec[i] * 10;
		printf("%d ", vec[i]);
	}
	putchar('\n');

	int aux[SIZE];

	int inicio = 0, fim = 0;

	int j, k;

	/**
	 * 1121
	 * 
	 * vec = 1211
	 *
	 * vet_inv = 1121
	 */

	for (i = 0; i < digitos; i++)
	{
		aux[0] = vec[i];
		for (j = i + 1, k = 1; j < digitos; j++, k++)
		{
			aux[k] = vec[j];
			/*puts(aux);*/

			/* Verifica se a string auxiliar é um palíndromo */
			unsigned tamanho_aux = k+1;

			int i2, j2;
			int thays = 1;

			/**
			 * Operador and
			 *
			 * 1 and 0 = 0
			 * Qualquer coisa and 0 = 0
			 */

			for (i2 = 0, j2 = tamanho_aux-1; i2 < j2 && thays; i2++, j2--)
			{
				if (aux[i2] != aux[j2])
				{
					/*printf("Nao e um palindromo!!!\n");*/
					thays = 0;
				}
			}

			if (thays != 0)
			{
				/*Significa que é um palíndromo válido*/
				/**
				 * Poderia verificar Arara_ --> Arara
				 */
				if (j > fim)
				{
					inicio = i;
					fim = j;

					printf("Palindromo ");
					int i3;
					for (i3 = inicio; i3 <= fim; i3++)
					{
						printf("%d ", vec[i3]);
					}

					printf("entre %d e %d\n", inicio, fim);
				}
			}
		}
	}

	return 0;
}