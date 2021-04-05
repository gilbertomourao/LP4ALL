/**
 * Solução da primeira questão da P1 de 2020.1
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

/* Tamanho máximo dos arrays */
#define MAX 100

int main()
{
	char palavra[MAX];
	char resposta[MAX];

	printf("Insira uma string: ");
	gets(palavra);

	printf("String inserida: %s\n", palavra);

	int i; /* iterador */

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

	/*A algoritmo para detecção de palíndromos dentro de um intervalo [ii, io].
	 *
	 * Variáveis reservadas: straux, inicio, fim, ii, io, ik
	 * 
	 * Criei como um bloco com as variáveis straux, inicio, fim, ii, io e ik 
	 * reservadas para facilitar a integração com outros algoritmos. Na prática, 
	 * isso seria feito facilmente através de uma função.
	 */
	char straux[MAX];
	int inicio = 0, fim = 0;
	int ii, io, ik; /* iteradores */

	for (ii = 0; palavra[ii] != '\0'; ii++)
	{
		if (VALID_CHAR(palavra[ii]))
		{
			/* Início do algoritmo */
			straux[0] = TOLOWER(palavra[ii]);

			for (io = ii + 1, ik = 1; palavra[io] != '\0'; io++, ik++)
			{
				if (VALID_CHAR(palavra[io]))
				{
					straux[ik] = TOLOWER(palavra[io]);
				} 
				else
					ik--;

				straux[ik+1] = '\0';
				/* puts(aux); */

				/* Verifica se a string auxiliar é um palíndromo */
				unsigned tamanho_aux = ik+1;

				int ii2, io2;
				int thays = 1;

				for (ii2 = 0, io2 = tamanho_aux-1; ii2 < io2 && thays; ii2++, io2--)
				{
					if (straux[ii2] != straux[io2])
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
					if (io > fim && palavra[io] != ' ')
					{
						inicio = ii;
						fim = io;

						int i_resp;
						for (i_resp = inicio; i_resp <= fim; i_resp++)
						{
							resposta[i_resp] = palavra[i_resp];
						}
					}
				}
			}
		}
	}
	/**
	 * Fim do algoritmo de busca por palíndromos
	 */

	puts(resposta);

	return 0;
}