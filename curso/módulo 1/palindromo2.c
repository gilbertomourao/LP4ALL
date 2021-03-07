/**
 * Verifica se existem palíndromos dentro de uma
 * string
 */

#include <stdio.h>

#define SIZE 100

int main()
{
	char palavra[SIZE];
	char resposta[SIZE];

	printf("Insira uma string: ");
	gets(palavra);

	printf("String inserida: %s\n", palavra);

	char aux[SIZE];
	int i, j, k; /* iterador */

	/* Inicializa a string resposta */
	for (i = 0; palavra[i] != '\0'; i++)
	{
		resposta[i] = '*';
	}
	resposta[i] = '\0';
	/**
	 * palavra = idjcoishcois
	 * resposta = ************
	 */

	int inicio = 0, fim = 0;

	for (i = 0; palavra[i] != '\0'; i++)
	{
		if (palavra[i] >= 'A' && palavra[i] <= 'Z')
			aux[0] = palavra[i] + 'a' - 'A'; /* Inicializa a string auxiliar */
		else 
		{
			if (palavra[i] != ' ')
				aux[0] = palavra[i];
		}
		for (j = i + 1, k = 1; palavra[j] != '\0'; j++, k++)
		{
			if (palavra[j] >= 'A' && palavra[j] <= 'Z')
				aux[k] = palavra[j] + 'a' - 'A'; /* Inicializa a string auxiliar */
			else 
			{
				if (palavra[j] != ' ')
					aux[k] = palavra[j];
			}
			aux[k+1] = '\0';
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
				if (j > fim && palavra[j] != ' ')
				{
					inicio = i;
					fim = j;

					int i_resp;
					for (i_resp = inicio; i_resp <= fim; i_resp++)
					{
						resposta[i_resp] = palavra[i_resp];
					}
				}
			}
		}
	}

	puts(resposta);

	return 0;
}