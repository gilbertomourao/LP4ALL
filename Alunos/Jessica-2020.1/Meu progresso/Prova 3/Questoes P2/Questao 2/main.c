//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 2
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funções Usadas*/
    void ReadDimensions (int *L, int *C);
    void AlocaMatriz (char **mat, int *L, int *C);
    void RecebeMatriz (char *mat, int *L, int *C);
    void ExibirMatriz (char *mat, int *L, int *C);

    void Desl_Linha_Coluna(char *Op); // Determina se será deslocado a linha (L) ou coluna (C)
    void LerDeslocamento (int *Vd, char *Op, int *L, int *C); // Lê o valor do deslocamento
    void Desl_Esquerda_Direita (char *D); // Determina se o deslocamento será para esquerda (E) ou para direita (D)

    void Desloca (char *mat, int *L, int *C, int *Vd, char *D, char *Op); // Desloca à esquerda (ou direita) na linha (ou coluna)
    void ExibeOpcoesSelecionadas (int *Vd, char *D, char *Op);
    void DesalocaMatriz (char *mat);

int main()
{
    char *Matriz;
    int linha, coluna;
    int ValorDoDeslocamento;
    char OpcaoDeslocamento, DirecaoDeslocamento;

    ReadDimensions(&linha, &coluna);
    AlocaMatriz(&Matriz, &linha, &coluna);
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
    DesalocaMatriz(Matriz);
    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Deslocador *******\n", 135);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0) { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0) { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co de coluna inv%clida, insira novamente:  ", 198, 160);
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
        printf ("Erro: Em função 'AlocaMatriz'.\nAloca%c%co de mem%cria falhou.\nVerificar a vari%cvel 'mat' na linha 74.\n", 135, 198, 162,160);
        exit(0);
    }
}

/*DESALOCA O ESPAÇO DE MEMÓRIA DA MATRIZ*/
void DesalocaMatriz (char *mat) {
    free(mat);
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char *mat, int *L, int *C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;
	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            *(mat+i*(*C)+j) ='*';
    printf("********* Bem Vindo ao Deslocador *******\n");
	printf("\nPreencha a matriz com qualquer car%ccter:", 160);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida
            scanf(" %c", (mat+i*(*C)+j)); // Recebe um caracter
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
void ExibirMatriz (char *mat, int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%c", *(mat+i*(*C)+j));
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

/*DETERIMIMA SE O DESLOCAMENTO SERÁ NA LINHA (L) OU NA COLUNA (C)*/
void Desl_Linha_Coluna(char *Op) {
    printf("\n------------------------------------------------");
    printf("\nEscolha a op%c%co de deslocamente desejada:\nDigite 'L' para linha ou 'C' para coluna.\n",135,198);
    printf("\n\nOp%c%co: ", 135, 198);
    fflush(stdin);
    scanf("%c", Op);
    while(*Op!='C' && *Op!='c' && *Op!='L' && *Op!='l') { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nOp%c%co inv%clida, tente novamente:  ", 135, 198, 160);
        fflush(stdin);
        scanf("%c", Op);
    }
}

/*LÊ O VALOR DE DESLOCAMENTO*/
void LerDeslocamento (int *Vd, char *Op, int *L, int *C) {
    printf("\n------------------------------------------------");
    printf("\nDigite o valor do deslocamento, por favor:  ");
    fflush(stdin);
    scanf("%i", Vd);
    if (*Op=='L' || *Op=='l')
        while(*Vd<=0 || *Vd>*C) { // Caso a dimenção recebida esteja fora dos parametros
            printf("\nDimens%co inv%clida, tente novamente:  ", 198, 160);
            fflush(stdin);
            scanf("%i", Vd);
        }
    else if (*Op=='C' || *Op=='c')
        while(*Vd<=0 || *Vd>*L) { // Caso a dimenção recebida esteja fora dos parametros
            printf("\nDimens%co inv%clida, tente novamente:  ", 198, 160);
            fflush(stdin);
            scanf("%i", Vd);
        }
}

/* DETERMINA SE DESLOCAMENTO SERÁ PARA ESQUERDA (E) OU PARA DIREITA (D)*/
void Desl_Esquerda_Direita (char *D) {
    printf("\n------------------------------------------------");
    printf("\nEscolha a op%c%co de dire%c%co desejada:\nDigite 'E' para esquerda ou 'D' para direita.\n",135,198,135,198);
    printf("\n\nOp%c%co: ", 135, 198);
    fflush(stdin);
    scanf("%c", D);
    while(*D!='E' && *D!='e' && *D!='D' && *D!='d') { //Caso a dimenção recebida esteja fora dos parametros
        printf("\nOp%c%co inv%clida, tente novamente:  ", 135, 198, 160);
        fflush(stdin);
        scanf("%c", D);
    }
    printf("\n------------------------------------------------\n");
}

void ExibeOpcoesSelecionadas (int *Vd, char *D, char *Op) {
    printf("\n--------------------------------------\n");
    if (*Op=='L' || *Op=='l')
        printf("| Op%c%co escolhida: Linha\n", 135, 198);
    else if (*Op=='C' || *Op=='c')
        printf("| Op%c%co escolhida: Coluna\n", 135, 198);
    if (*D=='D' || *D=='d')
        printf("| Dire%c%co escolhida:  Direita\n", 135, 198);
    else if (*D=='E' || *D=='e')
        printf("| Dire%c%co escolhida:  Esquerda\n", 135, 198);
    printf("| Valor do deslocamento: %i \n", *Vd);
    printf("--------------------------------------\n");
}

void Desloca (char *mat, int *L, int *C, int *Vd, char *D, char *Op) {
    int i,j,k;
    char temp;

    if (*Op=='L' || *Op=='l') { // Para deslocamento nas linhas

        if (*D=='D' || *D=='d') { // Para deslocamento para direita

            for(i=0; i<*L; i++)
                for (k=0; k<*Vd; k++) {
                    temp=*(mat+i*(*C)+(*C-1)); // Guarda o ultimo caractere da linha percorrida
                    for (j=(*C)-1; j>0; j--) // Realiza o deslocamento unitario dos membros para direita
                        *(mat+i*(*C)+j)=*(mat+i*(*C)+(j-1));
                    *(mat+i*(*C)+j)=temp; // Posiciona o ultimo caractere perdido no deslocamento na primeira posicao da linha
                }

        } else if (*D=='E' || *D=='e') { // Para deslocamento para esquerda

            for(i=0; i<*L; i++)
                for (k=0; k<*Vd; k++) {
                    temp=*(mat+i*(*C)); // Guarda o primeiro caractere da linha percorrida
                    for (j=0; j<*C-1; j++) // Realiza o deslocamento unitario dos membro para esquerda
                        *(mat+i*(*C)+j)=*(mat+i*(*C)+(j+1));
                    *(mat+i*(*C)+j)=temp; // Posiciona o primeiro caractere perdido no deslocamento na ultima posicao da linha
                }

        }

    } else if (*Op=='C' || *Op=='c') {  // Para deslocamento nas colunas

        if (*D=='D' || *D=='d') { // Para deslocamento para direita

            for(j=0; j<*C; j++)
                for (k=0; k<*Vd; k++) {
                    temp=*(mat+(*L-1)*(*C)+j); // Guarda o ultimo caractere da coluna percorrida
                    for (i=(*L)-1; i>0; i--) // Realiza o deslocamento unitario dos membros para direita
                        *(mat+i*(*C)+j)=*(mat+(i-1)*(*C)+j);
                    *(mat+i*(*C)+j)=temp; // Posiciona o ultimo caractere perdido no deslocamento na primeira posicao da coluna
                }

        } else if (*D=='E' || *D=='e') { // Para deslocamento para esquerda

            for(j=0; j<*C; j++)
                for (k=0; k<*Vd; k++) {
                    temp=*(mat+j); // Guarda o primeiro caractere da coluna percorrida
                    for (i=0; i<*L-1; i++) // Realiza o deslocamento unitario dos membro para esquerda
                        *(mat+i*(*C)+j)=*(mat+(i+1)*(*C)+j);
                    *(mat+i*(*C)+j)=temp; // Posiciona o primeiro caractere perdido no deslocamento na ultima posicao da coluna
                }
        }
    }
}
