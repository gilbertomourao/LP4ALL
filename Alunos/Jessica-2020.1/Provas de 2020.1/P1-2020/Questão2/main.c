#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void ReadDimensions (int *L, int *C);
void RecebeMatriz (char mat[][MAX], int *L, int *C);

void ExibirMatriz (char mat[][MAX], int *L, int *C);
void OrganizaLinhas (char mat[][MAX], int *L, int *C);

int main()
{
    char Matriz[MAX][MAX];
    int linha, coluna;

    ReadDimensions (&linha, &coluna);
    RecebeMatriz (Matriz, &linha, &coluna);
    //EXIBE MATRIZ ORIGINAL E MATRIZ COM LINHAS ORGANIZADAS
    printf("------------------------------\n");
    printf("\tMatriz Original\n");
    printf("------------------------------\n");
    ExibirMatriz(Matriz, &linha, &coluna);

    OrganizaLinhas(Matriz, &linha, &coluna);
    printf("------------------------------\n");
    printf("    Matriz Organizada\n");
    printf("------------------------------\n");
    ExibirMatriz(Matriz, &linha, &coluna);

    return 0;
}
/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Ornaizador de Linhas *******\n", 135);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0 || *L>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0 || *C>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de coluna inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*C);
    }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char mat[][MAX], int *L, int *C) { // Matriz recebida -  numero de linha - numero de coluna
    int i,j;
	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            mat[i][j] ='*';
    printf("********* Bem Vindo ao Ornaizador de Linhas *******\n", 135);
	printf("\nPreencha a matriz com qualquer caracter:");
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos
	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); //Informa a posição
            scanf(" %c", &mat[i][j]); // Receb caracter
            system("CLS"); //Limpa a tela para exibir tudo com o caracter recebido acima

            printf("********* Bem Vindo ao Ornaizador de Linhas *******\n", 135);
            printf("\nPreencha a matriz com qualquer caracter:");
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
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

/*ORGANIZA TODAS AS LINHAS DA MATRIZ*/
void OrganizaLinhas (char mat[][MAX], int *L, int *C) {
	int i,j,k;
	char aux;
	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++)
            for(k=j+1; k<*C; k++)
                if (mat[i][j]>mat[i][k]) { //Se o caractere na posicao [j] for maior (tabela ASCII) que da posicao [j+1]
                    aux=mat[i][j];  //Faz-se a troca de lugares dos caracteres em [j] e [j+1]
                    mat[i][j]=mat[i][k];
                    mat[i][k]=aux;
                }
}


