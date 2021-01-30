#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void PrintaTracado(int C); //Estetico Apenas

int main()
{
    void PrintaMatriz(char Matriz[][MAX], int L, int C);

    char mat1[MAX][MAX], mat2[MAX][MAX];
    int linha, coluna;
    int i,j,k;

    printf ("Linha:");
    scanf("%i",&linha);
    printf ("\n\nColuna:");
    scanf("%i",&coluna);

    for(i=0; i<linha; i++){ //Lendo a Matriz Original
        for(j=0; j<coluna; j++){
            printf("[%i][%i] = ", i+1, j+1);
            fflush(stdin);
            scanf("%c", &mat1[i][j]);
            system("cls");
        }
    }
    system("pause");
    system("cls");

    for(i=0; i<linha; i++){
        mat1[i][coluna]='\0';
    }

    printf("Matriz original:\n");
    PrintaMatriz(mat1,linha,coluna);

    /*Fazendo a transposta*/
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            mat2[j][i]= mat1[i][j];
        }
    }
    for(i=0; i<coluna; i++){
        mat2[i][linha]='\0';
    }
    printf("Matriz transposta:\n");
    PrintaMatriz(mat2,coluna,linha);
    return 0;
}

/*Exibe matriz para o usuario*/
void PrintaMatriz(char Matriz[][MAX], int L, int C){
    int i,j;
    PrintaTracado(C);
    for(i=0; i<L; i++){ //Exibindo a matriz
         printf ("%s\n",Matriz[i]);
    }
    PrintaTracado(C);
    printf ("\n\n");
}
void PrintaTracado(int C){
    int i;
    for(i=0; i<C; i++)
        printf("----");
     printf("\n");
}
