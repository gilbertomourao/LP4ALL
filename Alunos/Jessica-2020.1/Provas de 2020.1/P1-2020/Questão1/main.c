//     PROGRAMA: Questão 1 - Achar palavras palíndromos nas linhas da matriz e imprimir a posição inicial

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

/*Funções Usadas*/
void ReadDimensions (int *L, int *C);
void RecebeMatriz(char *mat, int *L, int *C);
void ExibirMatriz (char *mat, int *L, int *C);
void VarreLinhas(char *mat, int *L, int *C, int *casos);

int main()
{
    char Matriz[MAX][MAX];
    int linha, coluna, eventos=0;

    ReadDimensions(&linha, &coluna);

    RecebeMatriz(*Matriz, &linha, &coluna);

    VarreLinhas(*Matriz, &linha, &coluna, &eventos);

    ExibirMatriz(*Matriz, &linha, &coluna);

    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Ca%ca-Pal%cndromo *******\n", 135, 161);
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
void RecebeMatriz (char *mat, int *L, int *C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;

	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            *(mat+i*MAX+j) ='*';

    printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
	printf("\nPreencha a matriz com letras:", 163);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); //Informa a posição a ser recebida a letra
            fflush(stdin);
           *(mat+i*MAX+j)=getchar(); //Chama a função que recebe apenas numeros inteiros positivos do usuario
            system("CLS"); //Limpa a tela para exibir tudo com o numero recebido acima

            printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
            printf("\nPreencha os espacos com n%cmeros inteiros:", 163);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMatriz (char *mat, int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%c",*(mat+i*MAX+j));
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

/*CAÇA PALINDROMO NAS LINHAS*/
void VarreLinhas(char *mat, int *L, int *C, int *casos) {
    int i, j, k, m, n, confirma, aux=0;

	for(i=0; i<*L; i++) // Laço principal, controla a mudança das linhas da matriz
        for(j=0; j<*C; j++) // j define o ponto inicial da verificação do possivel palindromo (percorre toda linha)
            for(k=j+1; k<*C; k++) { // k define o ponto final da verificação do possivel palindromo (percorre toda linha)
                confirma=1;
                for(m=j,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if ( tolower(*(mat+i*MAX+m)) != tolower(*(mat+i*MAX+n)) ) { // Ignora case sensitive
                        confirma=0;
                        break;
                    }
                if (confirma && isalpha(*(mat+i*MAX+j)) && isalpha(*(mat+i*MAX+k))) { // Confirma se existe um palindromo na verificacao, evita ocorrencias com numeros e caracteres especiais
                    for(m=j+1; m<k; m++)
                        if ( !(isalpha(*(mat+i*MAX+m))) ) {
                            confirma=0;
                            break;
                        }
                    if(confirma){
                            (*(casos))++; // Soma as ocorrencias de um palindromo
                            printf("\n");
                            for(m=j; m<=k; m++) { // Imprime os palindromos achados
                                printf("%c", *(mat+i*MAX+m));
                            }
                            printf("   -   (%i,%i) - (%i,%i) \n", i, j, i, k); // Imprime as posições dos palindromos achados
                    }
                }
            }
 }


