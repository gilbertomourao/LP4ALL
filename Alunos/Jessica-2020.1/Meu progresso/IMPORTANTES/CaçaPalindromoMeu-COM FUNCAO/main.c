#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

/*Funcoes Usadas*/
    int ReadNumbers(void);
    char ReadLetter(void);
    void TransformarMatrizMinuscula(char mat[][MAX], int L);
    void ExibirMatriz(char mat[][MAX], int L, int C);

    int ReadLinha (void);
    int ReadColuna (void);
    void RecebeMatriz(char mat[][MAX], char mat_final[][MAX], int L, int C);

    int VarreLinhas(char mat[][MAX], char mat_final[][MAX], int L, int C);
    int VarreColunas(char mat[][MAX], char mat_final[][MAX], int L, int C);
    int VarreDiagonaisP(char mat[][MAX], char mat_final[][MAX], int L, int C);
    int VarreDiagonaisS(char mat[][MAX], char mat_final[][MAX], int L, int C);



int main()
{
    int linha, coluna, l, c, dp, ds, ocorrencias;
    char Matriz[MAX][MAX];
    char Matriz_final[MAX][MAX];

    //Recebe as dimensoes da matriz
    printf("Bem vindo ao CA%cA-PALINDROMOS DA JESS s2!\n\n", 128);
    linha = ReadLinha();
    coluna = ReadColuna();

    printf("\n\n");
    system("PAUSE");
    system("CLS");

    //Recebe a matriz de letras
    printf("           CA%cA-PALINDROMOS DA JESS s2", 128);
    RecebeMatriz(Matriz, Matriz_final, linha, coluna);

    //Procura a palavra
    printf("Palindromos encontrados na matriz:\n\n");
    l = VarreLinhas (Matriz, Matriz_final, linha,coluna);
    c = VarreColunas (Matriz, Matriz_final, linha, coluna);
    dp = VarreDiagonaisP (Matriz, Matriz_final, linha, coluna);
    ds = VarreDiagonaisS (Matriz, Matriz_final, linha, coluna);
    printf("\n\n");
    ocorrencias = l+c+dp+ds;

     //Exibe os resultados das procura
    if (ocorrencias==1) {
        printf("CA%cA-PALINDROMOS DA JESS s2\n", 128);
        ExibirMatriz(Matriz_final,linha,coluna);
        printf("Foi encontrado %i caso da palindromo.\n\n\n",ocorrencias);
    } else if (ocorrencias>1){
        printf("CA%cA-PALINDROMOS DA JESS s2\n", 128);
        ExibirMatriz(Matriz_final,linha,coluna);
        printf("Foram encontrados %i casos da palindromo.\n\n\n",ocorrencias);
    } else
        printf("N%co houve nenhuma ocorrencia de palindromo.\n\n\n",198);

    return 0;
}

/*LENDO A DIMENSÃO DA LINHA DA MATRIZ DE CARACTERES*/
int ReadLinha (void) {
    int L;
    printf("Digite a dimens%co da linha, por favor:  ", 198);
    L = ReadNumbers();
    while(L<=0 || L>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimens%co de linha inv%clida, insira novamente:  ", 198,160);
        L = ReadNumbers();
    }
    return L;
}

/*LENDO A DIMENSÃO DA COLUNA DA MATRIZ DE CARACTERES*/
int ReadColuna (void) {
    int C;
    printf("\n\nDigite a dimensão da coluna, por favor:  ");
    C = ReadNumbers();
    while(C<=0 || C>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimensão de coluna invalida, insira novamente: ");
        C = ReadNumbers();
    }
    return C;
}

/*LER APENAS NUMEROS NUMA VARIAVEL INTEIRA*/
int ReadNumbers(void) {
    char ch; //Capta cada caractere digitado
    char digitado[50]; //Junta todos os digitos digitados
    int i=0;
    int numero; //Recebe o numero final
    do{
            fflush(stdin); //Limpa o buffer
            ch = getch( ); //Captura o caractere digitado pelo usuario;

            if (isdigit(ch) != 0) { // Se for um numero
                digitado[i]=ch; //É direcionado para string de numeros
                i++; //Passqa para proxima posição
                printf("%c", ch); //Exibe o numero digitado na tela

            } else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
                digitado[i] = '\0';
                i--;
                printf("\b \b"); //Apaga o caractere anterior
            }
        } while(ch != 13); // Quando o ENTER for digitado, termina o loop

        digitado[i] = '\0'; //Finaliza a string finalmente
        numero = atoi(digitado); // Converte a string em inteiros e passa para variavel numero

        return numero; // Retorna o numero inteiro
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz(char mat[][MAX], char mat_final[][MAX], int L, int C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;

	for (i=0; i<L; i++) // Preenhe toda matriz com asteriscos primeiramente
        for(j=0; j<C; j++)
            mat[i][j]='*';

	for (i=0; i<L; i++) //Finaliza a toda a matriz com \0
        mat[i][C] = '\0';

	printf("Recebendo a matriz");
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<L; i++)
        for(j=0; mat[i][j] != '\0'; j++) {
            printf("Matriz [%i][%i]: ", i+1, j+1); //Informa a posição a ser recebida a letra
            mat[i][j] = ReadLetter(); //Chama a função que recebe apenas caracteres alfabeticos do usuario
            mat_final[i][j]=mat[i][j]; //Gera a matriz auxiliar
            system("CLS"); //Limpa a tela para exibir tudo com o caractere recebido acima

            printf("Recebendo a matriz");
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }

    printf("\n\n");
    system("PAUSE"); //Pausa o sistema
    system("CLS"); //Limpa a tela

    TransformarMatrizMinuscula(mat, L); //Converte as duas matrizes para letras minusculas
    TransformarMatrizMinuscula(mat_final, L);
}

/*CONVERTE TODA MATRIZ EM LETRAS MINUSCULAS*/
void TransformarMatrizMinuscula(char mat[][MAX], int L){
     int i, j;
     for (i=0; i<L; i++)
        for(j=0; mat[i][j] != '\0'; j++) {
            if(mat[i][j]>='A' && mat[i][j]<='Z')
                mat[i][j]=tolower(mat[i][j]);
        }
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMatriz(char mat[][MAX], int L, int C) {
    int k, z, i;
    printf("\n");
    for(i=0; i<C; i++) //Estetico apenas
        printf("---");
     printf("\n");

    for (k=0; k<L; k++) { //Laço principal das linhas
        for(z=0; mat[k][z] != '\0'; z++) { //Laço secundario das colunas
            printf(" %c ", mat[k][z]); //Exibe cada caractere
        }
        printf("\n"); //Pula a linha
    }

    for(i=0; i<C; i++) //Estetico apenas
        printf("---");
    printf ("\n\n");
}

/*LER APENAS UMA LETRA*/
char ReadLetter(void) {
	char ch; //Capta cada caractere digitado
	char digitado[2]; //Junta letra e enter
	int i = 0;

	while (1) {
		fflush(stdin); //Limpa o buffer
		ch = _getch(); //Captura o caractere digitado pelo usuario;

		if (isalpha(ch) != 0  && i < 1) { // Se for uma letra e estiver dentro do tamanho
			digitado[i] = ch; // É direcionado para string auxilar
			i++; //Passa para proxima posição
			printf("%c", ch); //Exibe letra ou numero digitado na tela

		}
		else if (ch == 8 && i==1) { //Se o Blackspace for digitado e tiver letra para apagar na posição 0 da string
			i--;
			digitado[i] = '\0';
			printf("\b \b"); //Apaga o caractere anterior

		} else if (ch==13 && i==1) // Quando o ENTER for digitado e tiver letra na posição 0 da string, termina o loop
            break;
	}
	digitado[i] = '\0'; //Finaliza a string

    return digitado[0];
}

 /*CAÇA PALINDROMO NAS LINHAS*/
 int VarreLinhas(char mat[][MAX], char mat_final[][MAX], int L, int C) {
    int i, j, k, m, n, confirma, aux=0;

	for(i=0; i<L; i++) // Laço principal, controla a mudança das linhas da matriz

        for(j=0; j<C; j++) { // j define o ponto inicial da verificação do possivel palindromo (percorre toda linha)
            for(k=j+1; k<C; k++) { // k define o ponto final da verificação do possivel palindromo (percorre toda linha)
                confirma=1;
                for(m=j,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if (mat[i][m]!=mat[i][n]) {
                        confirma=0;
                        break;
                    }
                if(confirma && isalpha(mat[i][j]) && isalpha(mat[i][k])) { // Confirma se existe um palindromo na verificacao, evita ocorrencias com numeros e caracteres especiais
                    aux++; // Soma as ocorrencias de um palindromo
                    printf("\n");
                    for(m=j; m<=k; m++) { // Demarca com letras maiusculas os palindromos achados
                       mat_final[i][m] = toupper(mat[i][m]);
                       printf("%c", mat[i][m]);
                    }
                    printf("\n");
                }
            }
        }
    return aux;
 }

/*CAÇA PALINDROMO NAS COLUNAS*/
int VarreColunas(char mat[][MAX], char mat_final[][MAX], int L, int C) {
    int i, j, k, m, n, i_inicio, i_final, confirma, aux=0;

	for(j=0; j<C; j++) // Laço principal, controla a mudança das colunas da matriz

        for(i=0; i<L; i++) { // i define o ponto inicial da verificação do palindromo (percorre toda coluna)
            for(k=i+1; k<L; k++) { // k define o ponto final da verificação do palindromo (percorre toda coluna)
                confirma=1;
                for(m=i,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if (mat[m][j]!=mat[n][j]) {
                        confirma=0;
                        break;
                    }
                if(confirma && isalpha(mat[i][j]) && isalpha(mat[k][j])) { //Confirma se existe um palindromo na verificacao, evita ocorrencias com numeros e caracteres especiais
                    aux++; // Soma as ocorrencias de um palindromo
                    printf("\n");
                    for(m=i; m<=k; m++){  // Demarca com letras maiusculas os palindromos achados
                        mat_final[m][j] = toupper(mat[m][j]);
                        printf("%c", mat[m][j]);
                    }
                    printf("\n");
                }
            }
        }
    return aux;
}

/*CAÇA PALINDROMO NAS DIAGONAIS PRINCIPAIS*/
int VarreDiagonaisP(char mat[][MAX], char mat_final[][MAX], int L, int C) {
    int i, j, k, m, n, confirma, aux=0;
    int a,b,c,d; // a-> I_inicial | b-> J_inicial | c-> I_final | d-> J_final - Variam esses valores

    //Sentido da diagonal principal para cima
    for (k=0; k<C;k++)
        for (i=0; i<L; i++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            j=k+i;
            if (j<C) { //Lógica de percorrer diagonais

                for(m=i+1, n=j+1; m<L && n<C; m++, n++) { //Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo

                    confirma=1;

                    for (a=i, b=j, c=m, d=n; a<c && b<d; a++, b++, c--, d--) {
                        if(mat[a][b]!=mat[c][d]) {
                            confirma=0;
                            break;
                        }
                    }

                    if (confirma && isalpha(mat[i][j]) && isalpha(mat[m][n])) {
                        aux++; // Soma as ocorrencias de um palindromo
                        printf("\n");
                        for(a=i, b=j; a<=m && b<=n; a++,b++){  // Demarca com letras maiusculas os palindromos achados
                        mat_final[a][b] = toupper(mat[a][b]);
                        printf("%c", mat[a][b]);
                        }
                        printf("\n");
                    }
                }
            }
        }

    //Sentido abaixo da diagonal principal
    for(k=1; k<L; k++)
        for(j=0; j<C; j++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            i=k+j;
            if (i<L) { //Lógica de percorrer diagonais

                for(m=i+1, n=j+1; m<L && n<C; m++, n++) { // Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo

                    confirma=1;

                    for (a=i, b=j, c=m, d=n; a<c && b<d; a++, b++, c--, d--) {
                        if(mat[a][b]!=mat[c][d]) {
                            confirma=0;
                            break;
                        }
                    }

                    if (confirma && isalpha(mat[i][j]) && isalpha(mat[m][n])){
                        aux++; // Soma as ocorrencias de um palindromo
                        printf("\n");
                        for(a=i, b=j; a<=m && b<=n; a++,b++) { // Demarca com letras maiusculas os palindromos achados
                        mat_final[a][b] = toupper(mat[a][b]);
                        printf("%c", mat[a][b]);
                        }
                        printf("\n");
                    }
                }
            }
        }

    return aux;
}

/*CAÇA PALINDROMO NAS DIAGONAIS SECUNDARIAS*/
int VarreDiagonaisS(char mat[][MAX], char mat_final[][MAX], int L, int C) {
    int i, j, k, m, n, confirma, aux=0;
    int a,b,c,d; // a-> I_inicial | b-> J_inicial | c-> I_final | d-> J_final - Variam esses valores

    //Sentido da diagonal secundária para cima
    for(k=C-1; k>=0;k--)

        for(i=0; i<L; i++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            j=k-i;
            if (j>=0) { //Lógica de percorrer diagonais

                for(m=i+1, n=j-1; m<L && n>=0; m++, n--) { //Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo

                    confirma=1;

                    for (a=i, b=j, c=m, d=n; a<c && b>d; a++, b--, c--, d++) {
                        if(mat[a][b]!=mat[c][d]) {
                            confirma=0;
                            break;
                        }
                    }

                    if (confirma && isalpha(mat[i][j]) && isalpha(mat[m][n])) {
                        aux++; // Soma as ocorrencias de um palindromo
                        printf("\n");
                        for(a=i, b=j; a<=m && b>=n; a++,b--){  // Demarca com letras maiusculas os palindromos achados
                        mat_final[a][b] = toupper(mat[a][b]);
                        printf("%c", mat[a][b]);
                        }
                        printf("\n");
                    }
                }
            }
        }

    //Sentido abaixo da diagonal secundaria
    for(k=0; k<L; k++)
        for(i=1+k , j=C-1; i<L; i++, j--) { // Lógica de percorrer diagonais - i e j guardam e definem as posições iniciais de um possivel palindromo

            for(m=i+1, n=j-1; m<L && n>=0; m++, n--) { // Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo

                confirma=1;

                for (a=i, b=j, c=m, d=n; a<c && b>d; a++, b--, c--, d++) {
                    if(mat[a][b]!=mat[c][d]) {
                        confirma=0;
                        break;
                    }
                }

                if (confirma && isalpha(mat[i][j]) && isalpha(mat[m][n])) {
                    aux++; // Soma as ocorrencias de um palindromo
                    printf("\n");
                    for(a=i, b=j; a<=m && b>=n; a++,b--){  // Demarca com letras maiusculas os palindromos achados
                    mat_final[a][b] = toupper(mat[a][b]);
                    printf("%c", mat[a][b]);
                    }
                    printf("\n");
                }
            }
        }

    return aux;
}
