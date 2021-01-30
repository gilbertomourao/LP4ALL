#include <stdio.h>
#include <stdlib.h>

void preencheMat (int **mat, int *L, int *C);
void printMat (int **mat, int *L, int *C);

int main()
{
    int linha, coluna,i;
    int **matriz;

    printf("Entre com linha:");
    scanf("%i", &linha);
    printf("Entre com coluna:");
    scanf("%i", &coluna);
    printf("\n");

    //Alocando espaço pra matriz
    matriz = malloc(linha*sizeof(int*));
    for (i=0; i<linha; i++)
        *(matriz+i) = malloc(coluna*sizeof(int));

    if (matriz== NULL) {
        printf ("Error! memory not allocated.\n");
        exit(EXIT_FAILURE);

    }

    preencheMat(matriz, &linha, &coluna);
    printMat(matriz, &linha, &coluna);

    return 0;
}

void preencheMat (int **mat, int *L, int *C) {
    int i,j;

    for (i=0; i<*L; i++)
        for (j=0; j<*C; j++)
            *(*(mat+i)+j)=i+j;
}

void printMat (int **mat, int *L, int *C) {
    int i,j;

    for (i=0; i<*L; i++){
        for (j=0; j<*C; j++)
            printf(" %i ", *(*(mat+i)+j));
        printf("\n");
    }
}

void Clean (int **mat, int *L, int *C) {
    int i;
      for (i=0; i<*L; i++)
        free(*(mat+i));
      free(mat);
}
