#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    int andares;
    int auxiliar;
    char matriz[MAX][MAX];
    int i, j;

    printf("Quantos andares voce deseja que sua piramide tenha:");
    scanf(" %i", &andares);
    while(andares<=0){
        printf("A quantidade de andares solicitada é invalida, tente novamente:");
        fflush(stdin);
        scanf("%i", &andares);
    }

    /*Piramide simples*/
    printf("\n\n-------------------------------------\n");
    printf("Piramide Simples\n");
    printf("-------------------------------------\n");
    for(i=1; i<=andares; i++){
        auxiliar=i;
        while(auxiliar>0){
            printf("*");
            --auxiliar;
        }
        printf("\n");
    }

    printf("\n\n");

    /*Piramide Tabulada*/
    printf("\n\n-------------------------------------\n");
    printf("Piramide Tabulada\n");
    printf("-------------------------------------\n");

    for(i=1; i<=andares; i++){

        auxiliar=0;

        for(j=1; j<=andares-i; j++) { //gerando espaços decrescentes
            matriz[i-1][auxiliar++] = ' ';
        }

        for(j=1; j<=2*i-1; j++) {  // gerando asteriscos de quantidades impares crescentes
            matriz[i-1][auxiliar++] = '*';
        }

        for(j=1; j<=andares-i; j++) { //gerando espaços decrescentes
            matriz[i-1][auxiliar++] = ' ';
        }

        matriz[i-1][auxiliar]='\0';
    }

    for(i=0; i<andares; i++){
        for(j=0; matriz[i][j]!='\0'; j++){
            printf("%c", matriz[i][j]);
        }
         printf("\n");
    }
       printf("\n\n");

    for(i=1; i<=andares ; i++) { //modo simples

        for(j=1; j<=andares-i; j++){ //gerando espaços decrescentes
            printf(" ");
        }

        for(j=1; j<=2*i-1; j++) { // gerando asteriscos de quantidades impares crescentes
            printf("*");
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}
