#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void PrintaTracado(int C); //Estetico Apenas

int main()
{
    char CPalavra[MAX][MAX];
    char aux [MAX][MAX];
    int linha, coluna;
    int i,j,k;

    void PreencheComEspacos(char Matriz[][MAX], int L, int C);
    void PrintaMatriz(char Matriz[][MAX], int L, int C);

    printf ("linha:");
    scanf("%i",&linha);
    printf ("\n\ncoluna:");
    scanf("%i",&coluna);

    for(i=0; i<linha; i++){ //Lendo a Matriz Original
        for(j=0; j<coluna; j++){
            printf("[%i][%i] = ", i+1, j+1);
            fflush(stdin);
            scanf("%c", &CPalavra[i][j]);
            system("cls");
        }
    }

    //Mostrando Matriz Original
    PrintaTracado(coluna);
    printf("MATRIZ ORIGINAL\n");
    PrintaTracado(coluna);
    PrintaMatriz(CPalavra,linha,coluna);

    //Varrendo  diagonal principal pra cima
    printf("DIAGONAL PRINCIPAL PRA CIMA:\n");
    printf("-----------------------------------------\n");
    for(k=0; k<coluna;k++){
        for(i=0; i<linha; i++){
            j=k+i;
            if(j<coluna){
                printf(" %c ", CPalavra[i][j]);
            }
        }
        printf ("\n");
    }
     printf ("\n\n\n");

    //Varrendo abaixo da diagonal principal
    printf("ABAIXO DA DIAGONAL PRINCIPAL:\n");
    printf("-----------------------------------------\n");
    for(k=1; k<linha; k++){
        for(j=0; j<coluna; j++){
            i=k+j;
            if(i<linha){
                printf(" %c ", CPalavra[i][j]);
            }
        }
        printf ("\n");
    }
    printf ("\n\n\n");

    //Varrendo totalmente no sentido da diagonal principal APENAS MATRIZES QUADRADAS
    printf("SENTIDO DA DIAGONAL PRINCIPAL:\n");
    printf("-----------------------------------------\n");
    for(k=0; k<linha; k++) {

        for(i=k, j=0; i<linha && j<coluna; i++, j++) {
            printf(" %c ", CPalavra[i][j]);
            if (i!=j)
                printf(" %c ", CPalavra[j][i]);
        }
        printf ("\n");
    }
    printf ("\n\n\n");

    //Varrendo totalmente no sentido da diagonal secundaria APENAS MATRIZES QUADRADAS
    printf("SENTIDO DA DIAGONAL SECUNDARIA:\n");
    printf("-----------------------------------------\n");
    for(k=0; k<linha; k++) {
        for(i=k, j=coluna-1; i<linha ; i++, j--) {
            printf(" %c ", CPalavra[i][j]);
            if (i+j != coluna-1)
                printf(" %c ", CPalavra[i-k][j-k]);
        }
        printf ("\n");
    }
    printf ("\n\n\n");

    //Varrendo  diagonal secundaria pra cima
    printf("DIAGONAL SECUNDARIA PRA CIMA:\n");
    printf("-----------------------------------------\n");
     for(k=coluna-1; k>=0;k--){
        for(i=0; i<linha; i++){
            j=k-i;
            if(j>=0){
                printf(" %c ", CPalavra[i][j]);
            }
        }
        printf ("\n");
    }
    printf ("\n\n\n");

    //Varrendo abaixo da diagonal secundaria
    printf("ABAIXO DA DIAGONAL SECUNDARIA:\n");
    printf("-----------------------------------------\n");
    for(k=0; k<linha; k++){
        for(i=1+k , j=coluna-1; i<linha; i++, j--){
                printf(" %c ", CPalavra[i][j]);
        }
        printf ("\n");
    }
    printf("\n\n\n");

     //Varrendo apenas diagonal principal
    printf("DIAGONAL PRINCIPAL:\n");
    printf("-----------------------------------------\n");
    for(i=0,j=0; i<linha && j<coluna;i++,j++){
        printf(" %c ", CPalavra[i][j]);
    }
     printf ("\n\n\n");

     //Varrendo acima diagonal principal
    printf("ACIMA DA DIAGONAL PRINCIPAL:\n");
    printf("-----------------------------------------\n");
    for(k=1; k<coluna;k++){
        for(i=0; i<linha; i++){
            j=k+i;
            if(j<coluna){
                printf(" %c ", CPalavra[i][j]);
            }
        }
        printf ("\n");
    }
     printf ("\n\n\n");

    //Varrendo apenas diagonal secundaria
    printf("DIAGONAL SECUNDARIA:\n");
    printf("-----------------------------------------\n");
    for(i=0, j=coluna-1; i<linha && j>=0;i++,j--){
        printf(" %c ", CPalavra[i][j]);
    }
     printf ("\n\n\n");

     //Varrendo acima diagonal principal
    printf("ACIMA DA DIAGONAL SECUNDARIA:\n");
    printf("-----------------------------------------\n");
    for(k=coluna-2; k>=0;k--){
        for(i=0; i<linha; i++){
            j=k-i;
            if(j>=0){
                printf(" %c ", CPalavra[i][j]);
            }
        }
        printf ("\n");
    }
    printf ("\n\n\n");


    system("pause");
    system("CLS");

    /*MOSTRANDO ORGANIZADO AGORA*/

    //Mostrando Matriz Original
    printf("MATRIZ ORIGINAL\n");
    PrintaMatriz(CPalavra,linha,coluna);

    //Mostrando diagonal principal
    PreencheComEspacos(aux,linha,coluna);
    for(i=0,j=0; i<linha && j<coluna;i++,j++){
        aux[i][j]=CPalavra[i][j];
    }
    printf("DIAGONAL PRINCIPAL\n");
    PrintaMatriz(aux,linha,coluna);

    //Mostrando diagonal secundaria
    PreencheComEspacos(aux,linha,coluna);
    for(i=0, j=coluna-1; i<linha && j>=0;i++,j--){
        aux[i][j]=CPalavra[i][j];
    }
    printf("DIAGONAL SECUNDARIA\n");
    PrintaMatriz(aux,linha,coluna);

    //Mostrando acima da diagonal principal
    PreencheComEspacos(aux,linha,coluna);
    for(k=1; k<coluna;k++){
        for(i=0; i<linha; i++){
            j=k+i;
            if(j<coluna){
                aux[i][j]=CPalavra[i][j];
            }
        }
    }
    printf("ACIMA DA DIAGONAL PRINCIPAL\n");
    PrintaMatriz(aux,linha,coluna);

     //Mostrando acima da diagonal secundaria
     PreencheComEspacos(aux,linha,coluna);
     for(k=coluna-2; k>=0;k--){
        for(i=0; i<linha; i++){
            j=k-i;
            if(j>=0){
                aux[i][j]=CPalavra[i][j];
            }
        }
    }
    printf("ACIMA DA DIAGONAL SECUNDARIA\n");
    PrintaMatriz(aux,linha,coluna);

    //Mostrando diagonal principal pra cima
    PreencheComEspacos(aux,linha,coluna);
    for(k=0; k<coluna;k++){
        for(i=0; i<linha; i++){
            j=k+i;
            if(j<coluna){
                aux[i][j]=CPalavra[i][j];
            }
        }
    }
    printf("DIAGONAL PRINCIPAL PARA CIMA\n");
    PrintaMatriz(aux,linha,coluna);

    //Mostrando abaixo da diagonal principal
    PreencheComEspacos(aux,linha,coluna);
    for(k=1; k<linha; k++){
        for(j=0; j<coluna; j++){
            i=k+j;
            if(i<linha){
                aux[i][j]=CPalavra[i][j];
            }
        }
    }
    printf("ABAIXO DA DIAGONAL PRINCIPAL\n");
    PrintaMatriz(aux,linha,coluna);

     //Mostrando secundaria principal pra cima
     PreencheComEspacos(aux,linha,coluna);
     for(k=coluna-1; k>=0;k--){
        for(i=0; i<linha; i++){
            j=k-i;
            if(j>=0){
                aux[i][j]=CPalavra[i][j];
            }
        }
    }
    printf("DIAGONAL SECUNDARIA PARA CIMA\n");
    PrintaMatriz(aux,linha,coluna);

    //Mostrando abaixo da diagonal secundaria
    PreencheComEspacos(aux,linha,coluna);
     for(k=0; k<linha; k++){
        for(i=1+k , j=coluna-1; i<linha; i++, j--){
               aux[i][j]=CPalavra[i][j];
        }
    }
    printf("ABAIXO DA DIAGONAL SECUNDARIA\n");
    PrintaMatriz(aux,linha,coluna);

    return 0;
}

void PreencheComEspacos(char Matriz[][MAX], int L, int C){
    int i,j;
    for(i=0; i<L; i++){ //Exibindo a matriz
        for(j=0; j<C; j++){
            Matriz[i][j]=' ';
        }
    }
}

void PrintaTracado(int C){
    int i;
    for(i=0; i<C; i++)
        printf("----");
     printf("\n");
}

void PrintaMatriz(char Matriz[][MAX], int L, int C){
    int i,j;

    PrintaTracado(C);
    for(i=0; i<L; i++){ //Exibindo a matriz
        for(j=0; j<C; j++){
            printf(" %c ", Matriz[i][j]);
        }
         printf ("\n");
    }
    PrintaTracado(C);
    printf ("\n\n");
}


