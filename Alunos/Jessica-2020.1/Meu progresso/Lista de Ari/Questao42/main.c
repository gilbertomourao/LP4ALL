#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*42.	Faça um programa que receba como entradas uma lista de nomes em ordem aleatória e
ordene essa lista em ordem alfabética.*/
#define MAX 100
int main()
{
    char lista[MAX][MAX];
    char lista_aux [MAX][MAX];
    int membros;
    int i,j,k;
    char temp[MAX];

    /*Entrando com a quantidade membros da lista*/
    printf("Insira a quantidade de pessoas da lista, por favor: ");
    scanf("%i", &membros);
    system("pause");
    system("CLS");

    /*Entrando com os nomes dos membros na lista*/
    printf("-------------------------------------------------------\n");
    printf("\tDigite o nome de cada membro abaixo\n");
    printf("-------------------------------------------------------\n");

    for(i=0; i<membros; i++){
        printf("%i - ", i+1);
        fflush(stdin); //Foi necessario para resolver um erro CUIDADO
        gets(lista[i]);
        printf("\n");
    }
    system("pause");
    system("CLS");

    /*Oganizando a lista*/
    for(i=0; i<membros; i++) { //Ornaliza a lista de acordo com comparacoes na lista auxiliar
        for (j=i+1; j<membros; j++){
            k=strcmp(lista[i],lista[j]);
            if(k>0) { //Se string em i foi maior que string em i+1, troca de lugar
                strcpy(temp,lista[i]);
                strcpy(lista[i],lista[j]);
                strcpy(lista[j],temp);
            }
        }
    }

    /*Exibe lista ordenada*/
    printf("-------------------------------------------------------\n");
    printf("\tLista de Membros Ordenados\n");
    printf("-------------------------------------------------------\n");
    for(i=0; i<membros; i++){ //Mostrando resultado
        printf("%i - %s\n",i+1, lista[i]);
    }
    return 0;
}
