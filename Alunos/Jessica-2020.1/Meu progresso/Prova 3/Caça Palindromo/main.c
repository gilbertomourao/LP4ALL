#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>

/*Funcoes Usadas*/
    void AlocaMatriz (char **mat, int *L, int *C);
    void DesalocaMatriz (char *mat);
    void ReadDimensions (int *L, int *C);
    void PrintMatriz (char *mat, int *L, int *C);
    void RecebeMatriz (char *mat, int *L, int *C);
    void ReadLetter (char *letra);

    void CacaPalindromo(char *mat, int *L, int *C, int *casos);
    void VarreLinhas(char *mat, int *L, int *C, int *casos);
    void VarreColunas(char *mat, int *L, int *C, int *casos);
    void VarreDiagonaisP(char *mat, int *L, int *C, int *casos);
    void VarreDiagonaisS(char *mat, int *L, int *C, int *casos);

int main()
{
    int linha, coluna;
    char *Matriz=NULL;
    int eventos=0;

    ReadDimensions(&linha, &coluna);
    AlocaMatriz (&Matriz, &linha, &coluna);
    RecebeMatriz (Matriz, &linha, &coluna);
    CacaPalindromo(Matriz, &linha, &coluna, &eventos);
    DesalocaMatriz(Matriz);

    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Ca%ca-Pal%cndromos ********* \n", 135, 161);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0) { // Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0) { // Caso a dimenção recebida esteja fora dos paramentros
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

    printf("********* Bem Vindo ao Ca%ca-Pal%cndromos ********* \n", 135, 161);
	printf("\nPreencha a matriz com letras:");
    PrintMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida a letra
            ReadLetter(mat+i*(*C)+j); // Chama a função que recebe apenas numeros inteiros positivos do usuario
            system("CLS"); // Limpa a tela para exibir tudo com o numero recebido acima

            printf("********* Bem Vindo ao Ca%ca-Pal%cndromos ********* \n", 135, 161);
            printf("\nPreencha a matriz com letras:");
            PrintMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); // Pausa
    system("CLS"); // Limpa a tela
}

/* FUNÇÃO QUE LÊ UM CARACTER APENAS*/
void ReadLetter (char *letra) {
	char ch; //Capta cada caractere digitado
	int i = 0;
	while(1) {
		fflush(stdin); // Limpa o buffer
		ch = getch(); // Captura o caractere digitado pelo usuario;
		if (isalpha(ch) && i<1) { // Se for uma letra e estiver dentro do tamanho
			printf("%c", ch); // Exibe letra ou numero digitado na tela
			ch = tolower(ch);
			*letra = ch; // É direcionado todos minusculos para ponteiro
			i++; // Passa para proxima iteração
		} else if (ch==8 && i==1) { // Se o Blackspace for digitado e tiver letra para apagar
			i--;
			printf("\b \b"); // Apaga o caractere anterior da tela
		} else if (ch==13 && i==1) // Quando o ENTER for digitado e tiver letra, termina o loop
            break;
    }
}

/*------------------------------------------ CAÇANDO A PALÍNDROMO ------------------------------------------*/

    //------ CAÇA NAS LINHAS ------
void VarreLinhas(char *mat, int *L, int *C, int *casos) {
    int i, j, k, m, n;
    bool confirma;

	for(i=0; i<*L; i++) // Laço principal, controla a mudança das linhas da matriz
        for(j=0; j<*C; j++) // j define o ponto inicial da verificação do possivel palindromo (percorre toda linha)
            for(k=j+1; k<*C; k++) { // k define o ponto final da verificação do possivel palindromo (percorre toda linha)
                confirma=true;
                for(m=j,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if (tolower(*(mat+i*(*C)+m)) != tolower(*(mat+i*(*C)+n))) {
                        confirma=false;
                        break;
                    }
                if ( confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+i*(*C)+k)) ) { // Confirma se existe um palindromo na verificação

                    for(m=j+1; m<k; m++) // Evita completamente ocorrencias com numeros e caracteres especiais
                       if(!isalpha(*(mat+i*(*C)+m))) {
                            confirma=false;
                            break;
                       }
                     if (confirma) {
                        (*casos)++; // Soma as ocorrencias de um palíndromo
                        printf("\n");
                        for(m=j; m<=k; m++) { // Demarca com letras maiusculas os palindromos achados
                            printf("%c", *(mat+i*(*C)+m));
                            *(mat+i*(*C)+m) = toupper(*(mat+i*(*C)+m));
                        }
                        printf("\n");
                     }
                }
            }
}

    //------ CAÇA NAS COLUNAS ------
void VarreColunas(char *mat, int *L, int *C, int *casos) {
    int i, j, k, m, n;
    bool confirma;

	for(j=0; j<*C; j++) // Laço principal, controla a mudança das colunas da matriz
        for(i=0; i<*L; i++) // i define o ponto inicial da verificação do palindromo (percorre toda coluna)
            for(k=i+1; k<*L; k++) { // k define o ponto final da verificação do palindromo (percorre toda coluna)
                confirma=true;
                for(m=i,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if (tolower(*(mat+m*(*C)+j)) != tolower(*(mat+n*(*C)+j))) {
                        confirma=false;
                        break;
                    }
                if( confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+k*(*C)+j)) ) { //Confirma se existe um palindromo na verificacao
                    for(m=i+1; m<k; m++) // Evita completamente ocorrencias com numeros e caracteres especiais
                       if(!isalpha(*(mat+m*(*C)+j))) {
                            confirma=false;
                            break;
                       }
                    if (confirma) {
                        (*casos)++; // Soma as ocorrencias de um palíndromo
                        printf("\n");
                        for(m=i; m<=k; m++) { // Demarca com letras maiusculas os palindromos achados
                            printf("%c", *(mat+m*(*C)+j));
                            *(mat+m*(*C)+j) = toupper(*(mat+m*(*C)+j));
                        }
                        printf("\n");
                     }
                }
            }
}

    //------ CAÇA NO SENTIDO DA DIAGONAL PRINCIPAL ------
void VarreDiagonaisP(char *mat, int *L, int *C, int *casos) {
    int i, j, k, m, n;
    int a,b,c,d; // a-> I_inicial | b-> J_inicial | c-> I_final | d-> J_final - Variam esses valores
    bool confirma;

    // Sentido da diagonal principal para cima
    for (k=0; k<*C;k++)
        for (i=0; i<*L; i++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            j=k+i;
            if (j<*C) { //Lógica de percorrer diagonais
                for(m=i+1, n=j+1; m<*L && n<*C; m++, n++) { //Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo
                    confirma=true;
                    for (a=i, b=j, c=m, d=n; a<c && b<d; a++, b++, c--, d--)
                        if(tolower(*(mat+a*(*C)+b)) != tolower(*(mat+c*(*C)+d))) {
                            confirma=false;
                            break;
                        }
                    if (confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+m*(*C)+n))) {
                        for(a=i+1, b=j+1; a<m && b<n; a++,b++) // Evita completamente ocorrencias com numeros e caracteres especiais
                            if(!isalpha(*(mat+a*(*C)+b))) {
                                confirma=false;
                                break;
                            }
                        if (confirma) {
                            (*casos)++; // Soma as ocorrencias de um palíndromo
                            printf("\n");
                            for(a=i, b=j; a<=m && b<=n; a++,b++) {  // Demarca com letras maiusculas os palindromos achados
                                printf("%c", *(mat+a*(*C)+b));
                                *(mat+a*(*C)+b) = toupper(*(mat+a*(*C)+b));
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }

    // Sentido abaixo da diagonal principal
    for(k=1; k<*L; k++)
        for(j=0; j<*C; j++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            i=k+j;
            if (i<*L) { //Lógica de percorrer diagonais
                for(m=i+1, n=j+1; m<*L && n<*C; m++, n++) { // Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo
                    confirma=true;
                    for (a=i, b=j, c=m, d=n; a<c && b<d; a++, b++, c--, d--)
                        if(tolower(*(mat+a*(*C)+b)) != tolower(*(mat+c*(*C)+d))) {
                            confirma=false;
                            break;
                        }
                    if (confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+m*(*C)+n))) {
                        for(a=i+1, b=j+1; a<m && b<n; a++,b++) // Evita completamente ocorrencias com numeros e caracteres especiais
                            if(!isalpha(*(mat+a*(*C)+b))) {
                                confirma=false;
                                break;
                            }
                        if (confirma) {
                            (*casos)++; // Soma as ocorrencias de um palíndromo
                            printf("\n");
                            for(a=i, b=j; a<=m && b<=n; a++,b++) {  // Demarca com letras maiusculas os palindromos achados
                                printf("%c", *(mat+a*(*C)+b));
                                *(mat+a*(*C)+b) = toupper(*(mat+a*(*C)+b));
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
}

    //------ CAÇA NO SENTIDO DA DIAGONAL SECUNDÁRIA ------
void VarreDiagonaisS(char *mat, int *L, int *C, int *casos) {
    int i, j, k, m, n;
    int a,b,c,d; // a-> I_inicial | b-> J_inicial | c-> I_final | d-> J_final - Variam esses valores
    bool confirma;

    // Sentido da diagonal secundária para cima
    for(k=(*C)-1; k>=0; k--)
        for(i=0; i<*L; i++) { // i e j guardam e definem as posições iniciais de um possivel palindromo
            j=k-i;
            if (j>=0) { // Lógica de percorrer diagonais
                for(m=i+1, n=j-1; m<*L && n>=0; m++, n--) { //Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo
                    confirma=true;
                    for (a=i, b=j, c=m, d=n; a<c && b>d; a++, b--, c--, d++)
                        if(tolower(*(mat+a*(*C)+b)) != tolower(*(mat+c*(*C)+d))) {
                            confirma=false;
                            break;
                        }
                    if (confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+m*(*C)+n))) {
                        for(a=i+1, b=j-1; a<m && b>n; a++,b--) // Evita completamente ocorrencias com numeros e caracteres especiais
                            if(!isalpha(*(mat+a*(*C)+b))) {
                                confirma=false;
                                break;
                            }
                        if (confirma) {
                            (*casos)++; // Soma as ocorrencias de um palíndromo
                            printf("\n");
                            for(a=i, b=j; a<=m && b>=n; a++,b--) {  // Demarca com letras maiusculas os palindromos achados
                                printf("%c", *(mat+a*(*C)+b));
                                *(mat+a*(*C)+b) = toupper(*(mat+a*(*C)+b));
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }

    //Sentido abaixo da diagonal secundaria
    for(k=0; k<*L; k++)
        for(i=1+k , j=(*C)-1; i<*L; i++, j--) { // Lógica de percorrer diagonais - i e j guardam e definem as posições iniciais de um possivel palindromo
            for(m=i+1, n=j-1; m<*L && n>=0; m++, n--) { // Lógica para achar palindromo começa - m e n guardam e definem as posições finais de um possivel palindromo
                confirma=true;
                for (a=i, b=j, c=m, d=n; a<c && b>d; a++, b--, c--, d++)
                    if(tolower(*(mat+a*(*C)+b)) != tolower(*(mat+c*(*C)+d))) {
                        confirma=0;
                        break;
                    }
                if (confirma && isalpha(*(mat+i*(*C)+j)) && isalpha(*(mat+m*(*C)+n))) {
                    for(a=i+1, b=j-1; a<m && b>n; a++,b--) // Evita completamente ocorrencias com numeros e caracteres especiais
                        if(!isalpha(*(mat+a*(*C)+b))) {
                            confirma=false;
                            break;
                        }
                    if (confirma) {
                        (*casos)++; // Soma as ocorrencias de um palíndromo
                        printf("\n");
                        for(a=i, b=j; a<=m && b>=n; a++,b--) {  // Demarca com letras maiusculas os palindromos achados
                            printf("%c", *(mat+a*(*C)+b));
                            *(mat+a*(*C)+b) = toupper(*(mat+a*(*C)+b));
                        }
                        printf("\n");
                    }
                }
            }
        }
}

void CacaPalindromo(char *mat, int *L, int *C, int *casos) {
    printf("********* Ca%ca-Pal%cndromos ********* \n", 135, 161);

    // Varrendo a matriz
    VarreLinhas(mat, L, C, casos);
    VarreColunas(mat, L, C, casos);
    VarreDiagonaisP(mat, L, C, casos);
    VarreDiagonaisS(mat, L, C, casos);

    printf("\nQuantidade de pal%cndromos encontrados: %i\n",161, (*casos));

    PrintMatriz(mat,L,C);

}



