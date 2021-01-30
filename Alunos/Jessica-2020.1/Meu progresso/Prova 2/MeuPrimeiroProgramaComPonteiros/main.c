#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100


/*Faça um programa que, dado um inteiro n e uma matriz de ordem m x n, cujos elementos são
todos inteiros positivos, imprime uma tabela onde os elementos são listados em ordem decrescente,
acompanhados da indicação de linha e coluna a que pertencem. Havendo repetições de elementos
na matriz, a ordem é irrelevante. Utilize obrigatoriamente a função da parte (a).*/

/*Funções Usadas*/

void ReadDimensions (int *L, int *C);
void ReadNumber(int *numero);
void ExibirMatriz(int *mat, int *L, int *C);
void RecebeMatriz(int *mat, int *mat_aux, int *L, int *C);
void Maior (int *mat, int *L, int *C, int *elemento, int *lin, int *col);

int main()
{
    int linha, coluna;
    int Matriz[MAX][MAX], Matriz_aux[MAX][MAX];
    int ElementoMaior=-1; // Qualquer valor positivo
    int Lin, Col;

    ReadDimensions(&linha, &coluna);
    RecebeMatriz(*Matriz, *Matriz_aux, &linha, &coluna);

    printf("*********Bem Vindo ao Ca%cador de Maior Membro*******\n\n", 135);
    printf ("Elemento Linha Coluna\n") ;

    while (1) {
        Maior(*Matriz_aux, &linha, &coluna, &ElementoMaior, &Lin, &Col);
        if (ElementoMaior > 0) {
            printf("    %d      %d      %d \n", ElementoMaior, Lin, Col) ;
            Matriz_aux[Lin][Col]=(-1); //Demarca para ser desconsiderado na próxima iteração
        } else
            break;
    }
    printf ("\nMatriz analisada:") ;
    ExibirMatriz(*Matriz, &linha, &coluna);

    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("*********Bem Vindo ao Ca%cador de Maior Membro*******\n", 135);

    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf(" %i", &*L);
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

/*LER APENAS NUMEROS NUMA VARIAVEL INTEIRA*/
void ReadNumber(int *numero) {
    char ch; //Capta cada caractere digitado
    char digitado[2]; //Junta todos os digitos digitados
    int i=0;
    while (1) {
            fflush(stdin); //Limpa o buffer
            ch = getch(); //Captura o caractere digitado pelo usuario;
            if (isdigit(ch) && i<1) { // Se for um numero
                digitado[i]=ch; //É direcionado para string de numeros
                i++; //Passqa para proxima posição
                printf("%c", ch); //Exibe o numero digitado na tela
            } else if (ch==8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
                i--;
                printf("\b \b"); //Apaga o caractere anterior
            } else if (ch==13 && i) {  // Quando o ENTER for digitado e tiver caractere
                digitado[i] = '\0'; //Finaliza a string
                break; // Termina o loop
            }
        }
        *numero = atoi(digitado); // Converte a string em inteiros e passa para pomteiro
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz(int *mat, int *mat_aux, int *L, int *C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;

	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            *(mat+i*MAX+j) =0;

    printf("*********Bem Vindo ao Ca%cador de Maior Membro*******\n", 135);
	printf("\nPreencha os espacos com n%cmeros inteiros:", 163);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); //Informa a posição a ser recebida a letra
            ReadNumber(mat+i*MAX+j); //Chama a função que recebe apenas numeros inteiros positivos do usuario
            *(mat_aux+i*MAX+j)=*(mat+i*MAX+j); //Preenche matriz auxiliar
            system("CLS"); //Limpa a tela para exibir tudo com o numero recebido acima

            printf("*********Bem Vindo ao Ca%cador de Maior Membro*******\n", 135);
            printf("\nPreencha os espacos com n%cmeros inteiros:", 163);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMatriz(int *mat, int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%i",*(mat+i*MAX+j));
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

void Maior (int *mat, int *L, int *C, int *elemento, int *lin, int *col) {
    int i,j;

    *elemento=*(mat);
    *lin = 0;
    *col = 0;

    for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++) {
            if (*(mat+i*MAX+j) > *elemento) {
                *elemento = *(mat+i*MAX+j);
                *lin=i;
                *col=j;
            }
        }
}



