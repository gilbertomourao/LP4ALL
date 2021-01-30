#include <stdio.h>
#include <stdlib.h>

/*49.	Fazer um programa que receba do usuário a quantidade N de números a ser digitada.
Em seguida, o programa deve alocar dinamicamente um vetor de N inteiros, receber N números
do usuário e armazenar no vetor, e mostrar o maior valor do vetor, o menor valor do vetor e
a média dos valores.*/

//Funções usadas
void ReadDimension(int *D);
void AlocaVetor(int **vet, int D);
void DesalocaVetor(int *vet);
int *MaiorVetor(int *vet, int *D);
int *MenorVetor(int *vet, int *D);
float MediaVetor(int *vet, int *D);
void PrintVetor(int *vet, int *D);
void LerVetor(int *vet, int *D);

int main()
{
    int *vetor, tam;
    ReadDimension(&tam);
    AlocaVetor(&vetor, tam);
    LerVetor(vetor, &tam);
    PrintVetor(vetor, &tam);

    printf("O maior membro do vetor %c %i\n", 130, *(MaiorVetor(vetor, &tam)));
    printf("O menor membro do vetor %c %i\n", 130, *(MenorVetor(vetor, &tam)));
    printf("A m%cdia do vetor %c %f\n", 130, 130, MediaVetor(vetor, &tam));

    DesalocaVetor(vetor);

    return 0;
}

void ReadDimension (int *D) {
    printf ("Insira quantos membros deseja que o vetor tenha: ");
    scanf("%i", D);
    system("pause");
    system("cls");
}

void AlocaVetor(int **vet, int D) {
    *vet =  (int *)malloc(D* sizeof(int));
    if (vet==NULL) {
        printf ("Erro: Em AlocaMatriz.\nAloca%c%co de mem%cria falhou.\nVerificar a vari%cvel vet na linha 29.\n", 135, 198, 162,160);
        exit(0);
    }
}

void DesalocaVetor (int *vet) {
    free(vet);
}

int *MaiorVetor(int *vet, int *D) {
    int i,*m=vet;
    for (i=1; i<*D; i++)
        if ( *m < *(vet+i) )
            m = (vet+i);
    return m;
}

int *MenorVetor(int *vet, int *D) {
    int i,*m=vet;
    for (i=1; i<*D; i++)
        if ( *m > *(vet+i) )
            m = (vet+i);
    return m;
}

float MediaVetor(int *vet, int *D) {
    int i;
    float med=0;
    for (i=0; i<*D; i++)
        med += *(vet+i);

    return (med/i);
}

void LerVetor(int *vet, int *D) {
    int i;
    printf("Preenchendo o vetor:\n");
    for (i = 0; i < *D; i++) {
        printf("Posi%c%co [%i]: ", 135, 198, i);
        scanf(" %i", (vet + i));
    }
    system("pause");
    system("cls");
}

void PrintVetor(int *vet, int *D) {
    int i;
    printf("\t---- Vetor ----\n\n");
    for (i = 0; i < *D; i++)
        printf("----");
    printf("\n|");
    for (i = 0; i < *D; i++)
        printf(" %i |", *(vet+i));
    printf("\n");
    for (i = 0; i < *D; i++)
        printf("----");
    printf("\n\n");
}
