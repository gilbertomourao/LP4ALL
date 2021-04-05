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
	char mat[MAX][MAX];
	char mat_resp[MAX][MAX];
	int L, C;
	int erro;

	do 
	{
		printf("Insira o numero de linhas: ");
		erro = scanf("%d", &L);
		fflush(stdin); /* Limpa o buffer */
	} while(L <= 0 || L > MAX || !erro);

	do 
	{
		printf("Insira o numero de colunas: ");
		erro = scanf("%d", &C);
		fflush(stdin); /* Limpa o buffer */
	} while(C <= 0 || C > MAX || !erro);

	/**
	 * Leitura da matriz
	 */
	int i, j;

	for (i = 0; i < L; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("Insira o elemento [%d][%d]: ", i, j);
			scanf("%c", &mat[i][j]);
			fflush(stdin); 
			/* Preenche a matriz resposta */
			mat_resp[i][j] = '*';
		}
	}

	/**
	 * Imprime a matriz fornecida
	 */
	printf("\n================================================\n"
		   "                 Matriz Original                    " 
		   "\n================================================\n");
	for (i = 0; i < L; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%c ", mat[i][j]);
		}
		putchar('\n');
	}

	printf("\n================================================\n"
		   "              Palindromos Identificados             " 
		   "\n================================================\n");
	
	/**
	 * Código anterior: string_palindromo
	 */

	for (i = 0; i < L; i++)
	{
		/*A algoritmo para detecção de palíndromos dentro de um intervalo [ii, io].
		 *
		 * Variáveis reservadas: straux, inicio, fim, ii, io, ik
		 * 
		 * Criei como um bloco com as variáveis straux, inicio, fim, ii, io e ik 
		 * reservadas para facilitar a integração com outros algoritmos. Na prática, 
		 * isso seria feito facilmente através de uma função.
		 */
		char straux[MAX];
		char palindromo[MAX]; /* Para imprimir o palindromo identificado */
		int inicio = 0, fim = 0;
		int ii, io, ik; /* iteradores */

		for (ii = 0; mat[i][ii] != '\0'; ii++)
		{
			if (VALID_CHAR(mat[i][ii]))
			{
				/* Início do algoritmo */
				straux[0] = TOLOWER(mat[i][ii]);
				int flag = 0;

				for (io = ii + 1, ik = 1; mat[i][io] != '\0'; io++, ik++)
				{
					if (VALID_CHAR(mat[i][io]))
					{
						straux[ik] = TOLOWER(mat[i][io]);
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

					if (thays != 0 && io > fim && mat[i][io] != ' ')
					{
						/*Significa que é um palíndromo válido*/
						flag = 1;
						/**
						 * Poderia verificar Arara_ --> Arara
						 */
						
						inicio = ii;
						fim = io;

						int i_resp;
						for (i_resp = inicio; i_resp <= fim; i_resp++)
						{
							mat_resp[i][i_resp] = mat[i][i_resp];
							palindromo[i_resp - inicio] = mat[i][i_resp];
						}
						palindromo[i_resp - inicio] = '\0';
						
					}
				}

				/* Verifica se identificou um palíndromo após o laço */
				if (flag)
				{
					printf("Palindromo %s identificado entre [%d][%d] e [%d][%d].\n", palindromo, i, inicio, i, fim);
				}
			}
		}
		/**
		 * Fim do algoritmo de busca por palíndromos
		 */
	}

	/**
	 * Imprime a matriz resposta
	 */
	printf("\n================================================\n"
		   "                 Matriz Resposta                    " 
		   "\n================================================\n");
	for (i = 0; i < L; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%c ", mat_resp[i][j]);
		}
		putchar('\n');
	}

	return 0;
}