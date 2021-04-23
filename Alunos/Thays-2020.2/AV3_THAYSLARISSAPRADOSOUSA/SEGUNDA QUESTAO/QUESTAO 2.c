/*  TERCEIRA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 2 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200

// PROTOTIPOS
void Ler_Mat(int (*)[], int);
void Sum_C (int (*)[], int, int *);
void Produto_L (int (*)[], int, int *);
void Sum_Mat (int (*)[], int, int *);
void Sum_Principal (int (*)[], int, int *);
void Sum_Secundaria (int (*)[], int, int *);
void Resultado(int *);

void main ()
{
    int mat[MAX][MAX]; // MATRIZ INSERIDA
    int dim; // DIMENSAO DA MATRIZ: MATRIZ QUADRADA TEM NUMERO DE LINHAS E COLUNAS IGUAL
    int erro; // VARIAVEL QUE AUXILIA A VERIFICAR SE A DIMENSAO É VÁLIDA
    int sum_coluna=0; // SOMA DA PRIMEIRA COLUNA
    int prod_linha=1; // PRODUTO DA PRIMEIRA LINHA
    int sum_total=0; // SOMA TOTAL
    int sum_principal=0; // SOMA DIAGONAL PRINCIPAL
    int sum_secundaria=0; // SOMA DIAGONAL SECUNDARIA

    do
    {   printf("INSIRA A DIMENSAO DA MATRIZ: "); // FORÇA O USUARIO A INSERIR UM NUMERO VALIDO DE LINHAS
        erro = scanf("%d", &dim);
        fflush(stdin);
    } while (dim <= 0 || dim > MAX || erro == 0);

    Ler_Mat(mat,dim);
    Sum_C(mat,dim, &sum_coluna);
    Resultado(&sum_coluna);
    printf("\n");
    Produto_L(mat,dim,&prod_linha);
    Resultado(&prod_linha);
    printf("\n");
    Sum_Mat(mat,dim,&sum_total);
    Resultado(&sum_total);
    printf("\n");
    Sum_Principal(mat,dim,&sum_principal);
    Resultado(&sum_principal);
    printf("\n");
    Sum_Secundaria(mat,dim,&sum_secundaria);
    Resultado(&sum_secundaria);

}

void Ler_Mat(int (*mat)[MAX], int dim) // LER MATRIZ
{
   int i, j; // ITERADORES
	int erro; // VARIAVEL QUE AUXILIA A VERIFICAR SE O ELEMENTO É VÁLIDO

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

void Sum_C (int (*mat)[MAX], int dim, int *sum_coluna) // SOMA DOS ELEMENTOS DA PRIMEIRA COLUNA
{
    int i; // ITERADOR PARA VARRER AS LINHAS DA PRIMEIRA COLUNA DA MATRIZ
    printf("b)");
    for (i = 0; i < dim; i++)
	{
	    *sum_coluna = *sum_coluna + mat[i][0];

	}
}

void Produto_L (int (*mat)[MAX], int dim, int *prod_linha) // PRODUTO DOS ELEMENTOS DA PRIMEIRA LINHA
{
    int j; // ITERADOR PARA VARRER AS COLUNAS DA PRIMEIRA LINHA DA MATRIZ
    printf("c)");
    for (j = 0; j < dim; j++)
	{
	    *prod_linha = (*prod_linha) * mat[0][j];

	}
}

void Sum_Mat(int (*mat)[MAX], int dim, int *sum_total) // SOMA DE TODOS OS ELEMENTOS DA MATRIZ
{
    int i,j; // ITERADORES PARA VARRER A MATRIZ
    printf("d)");
    for (i = 0; i < dim; i++)
	{
	    for (j=0; j< dim; j++)
        {
            *sum_total = *sum_total + mat[i][j];
        }
	}

}

void Sum_Principal(int (*mat)[MAX], int dim, int *sum_principal) // SOMA DOS ELEMENTOS DA DIAGONAL PRINCIPAL
{
    int i,j; // ITERADORES PARA VARRER A MATRIZ
    printf("e)");
    for (i = 0; i < dim; i++)
	{
	    for (j=0; j< dim; j++)
        {
            if (i==j) // i==j É A CONDIÇAO DA DIAGONAL PRINCIPAL
            {
                *sum_principal = *sum_principal + mat[i][j];
            }
        }
	}
}

void Sum_Secundaria(int (*mat)[MAX], int dim, int *sum_secundaria) // SOMA DOS ELEMENTOS DA DIAGONAL SECUNDARIA
{
    int i; // ITERADOR PARA VARRER A MATRIZ
    printf("f)");
    for (i = 0; i < dim; i++) // mat[i][dim-i-1] É A CONDIÇAO DA DIAGONAL SECUNDARIA
	{
            *sum_secundaria = *sum_secundaria + mat[i][dim-i-1];
	}

}

void Resultado (int *result) // IMPRIME OS RESULTADOS
{
    printf ("%d", *result);
}

