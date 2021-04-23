/*  TERCEIRA AVALIA��O DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUEST�O 1 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200

// PROTOTIPOS
void Ler_matriz(int (*)[], int);  // FUN�AO PARA LER MATRIZ
void Conta_matriz(int (*)[], int, int (*)[], int *); // FUN�AO PARA CONTAR OCORRENCIAS DE CADA ELEMENTO
int Existe_mem(int (*)[], int, int); // FUN�AO AUXILIAR PARA VERIFICAR SE A CONTAGEM NAO ESTA SE REPETINDO
void Imprime_mem(int (*)[], int); // FUN�AO PARA IMPRIMIR OS RESULTADOS


void main ()
{
    int mat[MAX][MAX]; // MATRIZ INSERIDA
    int dim; // DIMENSAO DA MATRIZ: MATRIZ QUADRADA TEM NUMERO DE LINHAS E COLUNAS IGUAL
	int erro; // VARIAVEL QUE AUXILIA A VERIFICAR SE A DIMENSAO � V�LIDA
	int memoria[MAX*MAX][2]; // MATRIZ MEMORIA QUE ARMAZENA O ELEMENTO NA COLUNA 0 E A QUANTIDADE DE VEZES QUE ELE APARECE NA COLUNA 1
	int tam_mem=0; // TAMANHO DA MATRIZ

	do
    {   printf("INSIRA A DIMENSAO DA MATRIZ: "); // FOR�A O USUARIO A INSERIR UM NUMERO VALIDO PARA A DIMENSAO DA MATRIZ
        erro = scanf("%d", &dim);
        fflush(stdin);
    } while (dim <= 0 || dim > MAX || erro == 0);

    Ler_matriz(mat, dim);
	Conta_matriz(mat, dim, memoria, &tam_mem);
	Imprime_mem(memoria, tam_mem);

}

void Ler_matriz(int (*mat)[MAX], int dim)// LER A MATRIZ
{
    int i, j; // ITERADORES
    int erro; // VARIAVEL QUE AUXILIA A VERIFICAR SE O ELEMENTO � V�LIDO

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			do
			{
				printf("INSIRA O ELEMENTO INTEIRO DA POSICAO [%d][%d]: ", i, j);
				erro = scanf("%d", &mat[i][j]);
				fflush(stdin);
			} while (erro == 0);
		}
	}
}

void Conta_matriz(int (*mat)[MAX], int dim, int (*memoria)[2], int *tam_mem) // CONTA QUANTAS VEZES CADA ELEMENTO APARECE
{
	int i, j, iaux,jaux; // ITERADORES
	int cont_mem = 0; // CONTADOR PARA QUANTIDADE DE ELEMENTOS
	int cont = 0; // CONTADOR DE ELEMENTOS IGUAIS

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			if (!Existe_mem(memoria, cont_mem, mat[i][j])) // VERIFICA SE O ELEMENTO J� FOI CONTADO
			{
				for (iaux = 0; iaux < dim; iaux++)
				{
					for (jaux = 0; jaux < dim; jaux++)
					{
						if (mat[iaux][jaux] == mat[i][j]) // PERCORRE A MATRIZ E VAI FAZENDO A CONTAGEM DE OCORRENCIAS DE CADA ELEMENTO
                        {
                            cont++;
                        }
					}
				}

				memoria[cont_mem][1] = cont; // RECEBE QUANTIDADE DE VEZES QUE O ELEMENTO APARECEU
				memoria[cont_mem][0] = mat[i][j]; // RECEBE O NOVO ELEMENTO
				cont_mem++; // INCREMENTA POIS O NUMERO DE LINHAS DA MATRIZ MEMORIA � IGUAL AO NUM DE ELEMENTOS DA MATRIZ
				cont=0; // REINICIA O CONTADOR
			}
		}
	}

	*tam_mem = cont_mem; // O CONTEUDO DE tam_mem SER� IGUAL A QUANTIDADE DE VEZES QUE FOI ADICIONADO UM ELEMENTO NA MATRIZ MEMORIA
}
// FUN�AO SIMPLES SO PARA VERIFICAR SE "n" (ELEMENTO[i][j]) JA FOI CONTADO PARA NAO REPETIR NA MATRIZ MEMORIA
int Existe_mem(int (*memoria)[2], int tam_mem, int n)
{
	int i; // ITERADOR

	for (i = 0; i < tam_mem; i++)
	{
		if (n == memoria[i][0])
		{
			return 1; // JA FOI CONTADO
		}
	}

	return 0;
}

void Imprime_mem(int (*memoria)[2], int tam_mem)// IMPRIMIR RESULTADO
{
	int i; // ITERADOR

	for (i = 0; i < tam_mem; i++)
	{
		printf("%d - %d, ", memoria[i][0], memoria[i][1]); // IMPRIME O ELEMENTO E QUANTAS VEZES APARECEU
	}

    printf("\b\b \n"); // SO PARA APAGAR A VIRGULA E O ESPA�O DO ULTIMO ELEMENTO
}








