//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 3 - Trocar diagonais principal e secundaria de uma matriz
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*Funções Usadas*/
void ReadDimensions (int *L, int *C);
void RecebeMatriz (char mat[][MAX], int *L, int *C);
void TrocaDiagonais (char mat[][MAX], int *L, int *C);
void ExibirMatriz (char mat[][MAX], int *L, int *C);

int main()
{
    char Matriz[MAX][MAX];
    int linha, coluna;

    ReadDimensions(&linha, &coluna);
    RecebeMatriz(Matriz, &linha, &coluna);
    printf("Matriz Original:\n");
    ExibirMatriz(Matriz, &linha, &coluna);
    TrocaDiagonais(Matriz, &linha, &coluna);
    printf("\nMatriz ap%cs a troca de diagonais:\n",162);
    ExibirMatriz(Matriz, &linha, &coluna);
    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Troca Diagonais *******\n", 135);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0 || *L>MAX) { //Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0 || *C>MAX) { //Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co de coluna inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*C);
    }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char mat[][MAX], int *L, int *C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;
	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            mat[i][j] ='*';
    printf("********* Bem Vindo ao Troca Diagonais *******\n");
	printf("\nPreencha a matriz com qualquer car%ccter:", 160);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida
            scanf(" %c", &mat[i][j]); // Recebe um caracter
            system("CLS"); // Limpa a tela para exibir tudo com o caracter recebido acima

            printf("********* Bem Vindo ao Troca Diagonais *******\n");
            printf("\nPreencha os espacos com qualquer car%ccter:", 160);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caracter recebido nessa iteração
        }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

void TrocaDiagonais (char mat[][MAX], int *L, int *C) {
   int i,j,k=0;
   char auxP[MAX], auxS[MAX];
    // Varrendo apenas diagonal principal
    for(i=0,j=0; i<*L && j<*C;i++,j++)
        auxP[k++]=mat[i][j]; // Passa diagonal principal para string auxiliar
    k=0;
    // Varrendo apenas diagonal secundaria
    for(i=0, j=*C-1; i<*L && j>=0; i++,j--)
        auxS[k++]=mat[i][j]; // Passa diagonal secundaria para string auxiliar
    k=0;
    // Passando diagonal secundaria para diagonal principal
    for(i=0,j=0; i<*L && j<*C;i++,j++)
        mat[i][j]=auxS[k++];
    k=0;
    // Passando diagonal principal para diagonal secundaria
    for(i=0, j=*C-1; i<*L && j>=0; i++,j--)
        mat[i][j]=auxP[k++];
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMatriz (char mat[][MAX], int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%c", mat[i][j]);
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

