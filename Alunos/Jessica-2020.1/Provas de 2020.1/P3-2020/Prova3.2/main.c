//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 2 - Transformar maiúscula em minúscula e vice-versa e imprimir a matriz resultante.
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Funcoes Usadas*/
    void AlocaMatriz (char **mat, int *L, int *C);
    void DesalocaMatriz (char *mat);
    void ReadDimensions (int *L, int *C);
    void PrintMatriz (char *mat, int *L, int *C);
    void RecebeMatriz (char *mat, int *L, int *C);
    void Transformar (char *mat, int  *L, int *C);

int main()
{
    char *Matriz;
    int linha, coluna;

    ReadDimensions(&linha, &coluna);
    AlocaMatriz(&Matriz, &linha, &coluna);
    RecebeMatriz(Matriz, &linha, &coluna);

    printf("------ Matriz original ------");
    PrintMatriz(Matriz, &linha, &coluna);
    Transformar(Matriz, &linha, &coluna);
    printf("------ Matriz convertida ------");
    PrintMatriz(Matriz, &linha, &coluna);
    DesalocaMatriz(Matriz);
    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ********* \n", 135, 161);
    printf("\nDigite a dimens%co da linha:  ", 198);
    scanf("%i", &*L);
    while(*L<=0) { // Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de linha inv%clida!\nInsira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0) { // Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de coluna inv%clida!\nInsira novamente:  ", 198, 160);
        scanf(" %i", &*C);
    }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*ALOCA ESPAÇO DE MEMÓRIA PARA A MATRIZ*/
void AlocaMatriz (char **mat, int *L, int *C) {
    *mat = (char *)malloc((*L) * (*C) * sizeof(char));
    if (mat==NULL) {
        printf ("Erro: Em fun%cão 'AlocaMatriz'.\nAloca%c%co de mem%cria falhou.\n", 135,135, 198, 162);
        exit(0);
    }
}

/*DESALOCA O ESPAÇO DE MEMÓRIA DA MATRIZ*/
void DesalocaMatriz (char *mat) {
    free(mat);
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void PrintMatriz (char *mat, int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%c",*(mat+i*(*C)+j));
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char *mat, int *L, int *C) { // Matriz - numero de linha - numero de coluna
    int i,j;
	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            *(mat+i*(*C)+j) ='*';

    printf("********* Formando Matriz ********* \n", 135, 161);
	printf("\nPreencha a matriz:");
    PrintMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida a letra
            scanf(" %c", (mat+i*(*C)+j)); // Chama a função que recebe apenas numeros inteiros positivos do usuario
            system("CLS"); // Limpa a tela para exibir tudo com o numero recebido acima

            printf("********* Formando Matriz ********* \n", 135, 161);
            printf("\nPreencha a matriz:");
            PrintMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); // Pausa
    system("CLS"); // Limpa a tela
}

 /*CONVERTE AS LETRAS MAIUSCULAR EM MINUSCULAR E VIRSE E VERSA*/
void Transformar (char *mat, int  *L, int *C) {
    int i, j;
	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            if (*(mat+i*(*C)+j)>='A' && *(mat+i*(*C)+j)<='Z') //Se o caractere for maiusculo
                *(mat+i*(*C)+j) = tolower(*(mat+i*(*C)+j)); //Converte caractere para minusculo na matriz auxiliar
            else //Se o caractere for minusculo
                *(mat+i*(*C)+j) = toupper(*(mat+i*(*C)+j)); //Converte caractere para maiusculo na matriz auxiliar
        }
}
