#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

void MostrarMatriz1 (char *mat, int *L, int *C);
void MostrarMatriz2 (char mat[][MAX], int *L, int *C);
void MostrarVetor1 (char *vet, int *C);
void MostrarVetor2 (char *vet, int *C);

void ReceberMatriz1 (char *mat, int *L, int *C);
void ReceberMatriz2 (char mat[][MAX], int *L, int *C);
void ReceberVetor1 (char *vet, int *C);
void ReceberVetor2 (char *vet, int *C);

int main()
{
    char matriz[MAX][MAX];

    char vetor[MAX];

    int coluna=3, linha=3;
    //Forma 1:
    printf("Forma 1 de receber e mostrar matriz:\n\n");
    ReceberMatriz1 (*matriz, &linha, &coluna);
    MostrarMatriz1 (*matriz, &linha, &coluna);
    //Forma 2:
    printf("Forma 2 de receber e mostrar matriz:\n\n");
    ReceberMatriz2 (matriz, &linha, &coluna);
    MostrarMatriz2 (matriz, &linha, &coluna);


    //Forma 1:
    printf("Forma 1 de receber e mostrar vetor:\n\n");
    ReceberVetor1 (vetor, &coluna);
    MostrarVetor1 (vetor, &coluna);
    //Forma 2:
    printf("Forma 2 de receber e mostrar vetor:\n\n");
    ReceberVetor2 (vetor, &coluna);
    MostrarVetor2 (vetor, &coluna);

    return 0;
}

void MostrarMatriz1 (char *mat, int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		for (int j=0; j<*C; j++)
			printf(" %c ",*(mat+i*MAX+j));
		printf("\n");
    }
    putchar('\n');
    system("pause");
    system("cls");
}

void ReceberMatriz1 (char *mat, int *L, int *C) {
	for (int i=0; i<*L; i++) {
		for (int j=0; j<*C; j++) {
            printf("[%i][%i] = ", i,j);
            fflush(stdin);
			*(mat+i*MAX+j)=getchar();
		}
    }
    putchar('\n');
}

void MostrarMatriz2 (char mat[][MAX], int *L, int *C) {
    putchar('\n');
    for (int i=0; i<*L; i++) {
        for(int j=0; j<*C; j++)
            printf(" %c ", mat[i][j]);
        printf("\n");
    }
    putchar('\n');
    system("pause");
    system("cls");
}

void ReceberMatriz2 (char mat[][MAX], int *L, int *C) {
    putchar('\n');
    for (int i=0; i<*L; i++) {
        for(int j=0; j<*C; j++) {
            printf("[%i][%i] = ", i,j);
            scanf(" %c", &mat[i][j]);
        }
    }
    putchar('\n');
}


void MostrarVetor1 (char *vet, int *C) {
    putchar('\n');
    for (int j=0; j<*C; j++)
        printf(" %c ",*(vet+j));
    putchar('\n');
    system("pause");
    system("cls");
}

void ReceberVetor1 (char *vet, int *C) {
    putchar('\n');
    for (int j=0; j<*C; j++) {
        fflush(stdin);
        *(vet+j)=getchar();
    }
    putchar('\n');
}

void MostrarVetor2 (char *vet, int *C) {
    putchar('\n');
    for (int j=0; j<*C; j++)
        printf(" %c ",vet[j]);
    putchar('\n');
    system("pause");
    system("cls");
}

void ReceberVetor2 (char *vet, int *C) {
    putchar('\n');
    for (int j=0; j<*C; j++)
        scanf(" %c", &vet[j]);
    putchar('\n');
}
