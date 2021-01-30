//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 2
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*Funções Usadas*/
void ReadDimensions (int *L, int *C);
void RecebeMatriz (char mat[][MAX], int *L, int *C);
void ExibirMatriz (char mat[][MAX], int *L, int *C);
void LerDeslocamento (int *Valor_D, char *Opcao, int *L, int *C); // Lê o valor do deslocamento
void Desl_Esquerda_Direita (char *Direcao); // Determina se o deslocamento será para esquerda (E) ou para direita (D)
void Desl_Linha_Coluna(char *Opcao); // Determina se será deslocado a linha (L) ou coluna (C)
void Desloca (char mat[][MAX], int *L, int *C, int *Valor_D, char *Direcao, char *Opcao); // Desloca à esquerda (ou direita) na linha (ou coluna)
void ExibeOpcoesSelecionadas (int *Valor_D, char *Direcao, char *Opcao);

int main()
{
    char Matriz[MAX][MAX];
    int linha, coluna;
    int ValorDoDeslocamento;
    char OpcaoDeslocamento, DirecaoDeslocamento;

    ReadDimensions(&linha, &coluna);
    RecebeMatriz(Matriz, &linha, &coluna);
    printf("Matriz Original:\n");
    ExibirMatriz(Matriz, &linha, &coluna);

    Desl_Linha_Coluna(&OpcaoDeslocamento); // Recebe a opção de deslocamento (coluna ou linha)
    LerDeslocamento(&ValorDoDeslocamento, &OpcaoDeslocamento, &linha, &coluna); // Recebe o valor do desl.
    Desl_Esquerda_Direita(&DirecaoDeslocamento); // Recebe sentido do deslocamento
    printf("\n\n");
    system("PAUSE"); // Pausa
    system("CLS"); // Limpa a tela

    printf("Matriz Original:\n");
    ExibirMatriz(Matriz, &linha, &coluna); // Exibe matriz antes do deslocamento
    ExibeOpcoesSelecionadas(&ValorDoDeslocamento,&DirecaoDeslocamento,&OpcaoDeslocamento);
    Desloca(Matriz, &linha, &coluna,&ValorDoDeslocamento,&DirecaoDeslocamento,&OpcaoDeslocamento);
    printf("\nMatriz com deslocamento:\n");
    ExibirMatriz(Matriz, &linha, &coluna); // Exibe matriz apos deslocamento
    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Deslocador *******\n", 135);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0 || *L>MAX) { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0 || *C>MAX) { // Caso a dimenção recebida esteja fora dos parametros
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
    printf("********* Bem Vindo ao Deslocador *******\n");
	printf("\nPreencha a matriz com qualquer car%ccter:", 160);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida
            scanf(" %c", &mat[i][j]); // Recebe um caracter
            system("CLS"); // Limpa a tela para exibir tudo com o caracter recebido acima

            printf("********* Bem Vindo ao Deslocador *******\n");
            printf("\nPreencha os espacos com qualquer car%ccter:", 160);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caracter recebido nessa iteração
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

/*DETERIMIMA SE O DESLOCAMENTO SERÁ NA LINHA (L) OU NA COLUNA (C)*/
void Desl_Linha_Coluna(char *Opcao) {
    printf("\n------------------------------------------------");
    printf("\nEscolha a op%c%co de deslocamente desejada:\nDigite 'L' para linha ou 'C' para coluna.\n",135,198);
    printf("\n\nOp%c%co: ", 135, 198);
    fflush(stdin);
    scanf("%c", &*Opcao);
    while(*Opcao!='C'&&*Opcao!='c'&&*Opcao!='L'&&*Opcao!='l') { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nOp%c%co inv%clida, tente novamente:  ", 135, 198, 160);
        fflush(stdin);
        scanf("%c", &*Opcao);
    }
}

/*LÊ O VALOR DE DESLOCAMENTO*/
void LerDeslocamento (int *Valor_D, char *Opcao, int *L, int *C) {
    printf("\n------------------------------------------------");
    printf("\nDigite o valor do deslocamento, por favor:  ");
    fflush(stdin);
    scanf("%i", &*Valor_D);
    if (*Opcao=='L' || *Opcao=='l')
        while(*Valor_D<=0 || *Valor_D>*C) { // Caso a dimenção recebida esteja fora dos parametros
            printf("\nDimens%co inv%clida, tente novamente:  ", 198, 160);
            fflush(stdin);
            scanf("%i", &*Valor_D);
        }
    else if (*Opcao=='C' || *Opcao=='c')
        while(*Valor_D<=0 || *Valor_D>*L) { // Caso a dimenção recebida esteja fora dos parametros
            printf("\nDimens%co inv%clida, tente novamente:  ", 198, 160);
            fflush(stdin);
            scanf("%i", &*Valor_D);
        }
}

/* DETERMINA SE DESLOCAMENTO SERÁ PARA ESQUERDA (E) OU PARA DIREITA (D)*/
void Desl_Esquerda_Direita (char *Direcao) {
    printf("\n------------------------------------------------");
    printf("\nEscolha a op%c%co de dire%c%co desejada:\nDigite 'E' para esquerda ou 'D' para direita.\n",135,198,135,198);
    printf("\n\nOp%c%co: ", 135, 198);
    fflush(stdin);
    scanf("%c", &*Direcao);
    while(*Direcao!='E'&&*Direcao!='e'&&*Direcao!='D'&&*Direcao!='d') { //Caso a dimenção recebida esteja fora dos parametros
        printf("\nOp%c%co inv%clida, tente novamente:  ", 135, 198, 160);
        fflush(stdin);
        scanf("%c", &*Direcao);
    }
    printf("\n------------------------------------------------\n");
}

void ExibeOpcoesSelecionadas (int *Valor_D, char *Direcao, char *Opcao) {
    printf("\n--------------------------------------\n");
    if (*Opcao=='L' || *Opcao=='l')
        printf("| Op%c%co escolhida: Linha\n", 135, 198);
    else if (*Opcao=='C' || *Opcao=='c')
        printf("| Op%c%co escolhida: Coluna\n", 135, 198);
    if (*Direcao=='D' || *Direcao=='d')
        printf("| Dire%c%co escolhida:  Direita\n", 135, 198);
    else if (*Direcao=='E' || *Direcao=='e')
        printf("| Dire%c%co escolhida:  Esquerda\n", 135, 198);
    printf("| Valor do deslocamento: %i \n", *Valor_D);
    printf("--------------------------------------\n");
}

void Desloca (char mat[][MAX], int *L, int *C, int *Valor_D, char *Direcao, char *Opcao) {
    int i,j,k,m;
    char aux1[MAX], aux2[MAX];

    if (*Opcao=='L' || *Opcao=='l') { // Para deslocamento nas linhas

        if (*Direcao=='D' || *Direcao=='d') { // Para deslocamento para direita
            k=((*C)-(*Valor_D));    // Delimita os elementos que vão 'desaparacer' (serem afastados saindo dos limites da linha) no delocamento
            for (i=0; i<*L; i++) {
                for (j=k, m=0; j<*C; j++, m++) // Armazena parte dos elementos numa string auxiliar
                    aux1[m]=mat[i][j];
                aux1[m]='\0';
                for(j=0, m=0; j<k; j++, m++) // Armazena outra parte dos elementos numa outra string auxiliar
                    aux2[m]=mat[i][j];
                aux2[m]='\0';
                strcat(aux1,aux2); // Concatena as strings auxiliares de modo a geral o deslocamento desejado
                for(j=0; aux1[j]!='\0'; j++) // Atribui string concatenada para linha da matriz
                    mat[i][j]=aux1[j];
            }
        }
        else if (*Direcao=='E' || *Direcao=='e') { // Para deslocamento para esquerda
            k=(*Valor_D);   // Faz um processo semelhando ao anterior
            for (i=0; i<*L; i++) {
                for (j=0, m=0; j<k; j++, m++)
                    aux1[m]=mat[i][j];
                aux1[m]='\0';
                for(j=k, m=0; j<*C; j++, m++)
                    aux2[m]=mat[i][j];
                aux2[m]='\0';
                strcat(aux2,aux1);
                for(j=0; aux2[j]!='\0'; j++)
                    mat[i][j]=aux2[j];
            }
        }
    }
    else if(*Opcao=='C' || *Opcao=='c') {  // Para deslocamento nas colunas

        if (*Direcao=='D' || *Direcao=='d') { // Para deslocamento para direita
            k=((*L)-(*Valor_D)); // Faz um processo semelhando ao anterior
            for (j=0; j<*C; j++) {
                for (i=k, m=0; i<*L; i++, m++)
                    aux1[m]=mat[i][j];
                aux1[m]='\0';
                for(i=0, m=0; i<k; i++, m++)
                    aux2[m]=mat[i][j];
                aux2[m]='\0';
                strcat(aux1,aux2);
                for(i=0; aux1[i]!='\0'; i++)
                    mat[i][j]=aux1[i];
            }
        }
        else if (*Direcao=='E' || *Direcao=='e') { // Para deslocamento para esquerda
            k=(*Valor_D); // Faz um processo semelhando ao anterior
            for (j=0; j<*C; j++) {
                for (i=0, m=0; i<k; i++, m++)
                    aux1[m]=mat[i][j];
                aux1[m]='\0';
                for(i=k, m=0; i<*L; i++, m++)
                    aux2[m]=mat[i][j];
                aux2[m]='\0';
                strcat(aux2,aux1);
                for(i=0; aux2[i]!='\0'; i++)
                    mat[i][j]=aux2[i];
            }
        }
    }
}
