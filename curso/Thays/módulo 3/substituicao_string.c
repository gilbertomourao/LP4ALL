/**
 * Algoritmo que recebe três strings do usuário:
 * string1, string2 e string3
 *
 * Busca pelas ocorrências de string2 em string1 
 * e substitui todas por string3. 
 *
 * Exemplo:
 *
 * string1: A frase que ana curte e uma tal de ana banana
 * string2: ana
 * string3: Impedancia
 *
 * resposta: A frase que Impedancia curte e uma tal de Impedancia bImpedanciaImpedancia
 */

#include <stdio.h>

/* Macro para ignorar case sensitive */
#define TOLOWER(ch) ((ch >= 'A' && ch <= 'Z') ? ch + 32 : ch)

/* Macro para identificar caracteres alfabéticos */
#define ALFABET(ch) (TOLOWER(ch) >= 'a' && TOLOWER(ch) <= 'z')

/* Macro para identificar se um caractere é válido.
 * Você pode alterar a condição. Por exemplo, se quiser 
 * detectar apenas caracteres alfabéticos, troque 
 * ch != ' ' por ALFABET(ch).
 */ 
#define VALID_CHAR(ch) (ch != ' ')

/* Tamanho máximo das strings */
#define MAX 100

int main()
{
	char string1[MAX], string2[MAX], string3[MAX];

	/* Leitura das strings */
	printf("Insira a string 1: ");
	gets(string1);
	printf("Insira a string 2: ");
	gets(string2);
	printf("Insira a string 3: ");
	gets(string3);
	
	/* Obtém a string2 auxiliar */
	char auxstring2[MAX];
	int i, j; /* iterador */

	for (i = 0, j = 0; string2[i]; i++)
	{
		if (ALFABET(string2[i]))
		{
			auxstring2[j] = TOLOWER(string2[i]);
			j++;
		}
	}
	auxstring2[j] = '\0'; /* Finaliza auxstring2 */
	/*
	puts(auxstring2);
	*/

	/* Procura por auxstring2 na string1 */
	char resposta[MAX]; /* string resposta */
	int ir = 0; /* iterador para a string resposta */
	unsigned cont = 0; /* identifica se a string2 ainda está em análise */ 

	for (i = 0; string1[i]; i++)
	{
		if (VALID_CHAR(string1[i]))
		{
			if (TOLOWER(string1[i]) == auxstring2[0])
			{
				/* Começa a busca */
				int k;
				for (j = i+1, k = 1; string1[j] && auxstring2[k]; j++, k++)
				{
					if (VALID_CHAR(string1[j]))
					{
						if (TOLOWER(string1[j]) != auxstring2[k])
						{
							break; /* Não encontrou a string2 na string1 nesta etapa */
						}
					}
					else 
					{
						k--;
					}
				}

				/* Verifica se encontrou a string2 */
				if (auxstring2[k] == '\0')
				{
					printf("Encontrou! Entre [%d] e [%d]\n", i, j-1);

					/* Controle */
					cont = 1;

					for (j = 0; string3[j]; j++)
					{
						resposta[ir] = string3[j];
						ir++;
					}
				}
				else /* Não encontrou */ 
				{
					if (!cont || !auxstring2[cont])
					{
						resposta[ir] = string1[i];
						ir++;
					}
					else
					{
						if (auxstring2[cont])
						{
							cont++;
						}
					}
				}
			}
			else
			{
				if (!cont || !auxstring2[cont])
				{
					resposta[ir] = string1[i];
					ir++;
				}
				else
				{
					if (auxstring2[cont])
					{
						cont++;
					}
				}
			}
		}
		else
		{
			if (!cont || !auxstring2[cont])
			{
				resposta[ir] = string1[i];
				ir++;
			}
		}
	}
	resposta[ir] = '\0'; /* Finaliza a string resposta */

	printf("String resposta: %s\n", resposta);

	return 0;
}