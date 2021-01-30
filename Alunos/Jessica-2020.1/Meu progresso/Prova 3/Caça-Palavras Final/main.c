#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
#define ToLow(ch) ( (ch >= 'A' && ch <= 'Z') ? ch + 'a' - 'A' : ch ) // Ignora case sensitive

/*Funções Usadas*/
void ReadDimensions (int *L, int *C);
void RecebeMatriz(char *mat, int *L, int *C);
void AlocaMatriz(char **mat, int L, int C);
void DesalocaMatriz (char *mat);
void ReadLetter(char *letra);
void ExibirMatriz(char *mat, int *L, int *C);
void Matriz_ToLow (char *mat, int *L, int *C);
void RecebePalavra(char *pal);
void String_NoSpace(char *s);
bool Palindromo (char *s);
void String_Inverte(char *s);

void VarreLinhas(char *mat, char *pal, int *L, int *C, int *casos);
void VarreColunas (char *mat, char *pal, int *L, int *C, int *casos);
void VarreDiagonalPrincipal(char *mat, char *pal, int *L, int *C, int *casos);
void VarreDiagonalSecundaria (char *mat, char *pal, int *L, int *C, int *casos);
void CacaPalavras (char *mat, char *pal, int *L, int *C, int *casos);

int main()
{
    int linha, coluna;
    char *Matriz=NULL;
    char Palavra[MAX];
    int eventos=0;

    ReadDimensions(&linha,&coluna);
    AlocaMatriz(&Matriz, linha, coluna);

    RecebeMatriz(Matriz, &linha, &coluna);

    printf("*********Ca%ca-Palavras*******\n", 135);
    ExibirMatriz(Matriz, &linha, &coluna);
    RecebePalavra(Palavra);

    CacaPalavras (Matriz, Palavra, &linha, &coluna, &eventos);
    DesalocaMatriz(Matriz);

    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
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

void AlocaMatriz (char **mat, int L, int C) {
    *mat = (char *)malloc(L * C * sizeof(char));
}

void DesalocaMatriz (char *mat) {
    free(mat);
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char *mat, int *L, int *C) { // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
    int i,j;

	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            *(mat+i*(*C)+j) ='*';

    printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
	printf("\nPreencha a matriz com letras:", 163);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); // Informa a posição a ser recebida a letra
            ReadLetter(mat+i*(*C)+j); // Chama a função que recebe apenas numeros inteiros positivos do usuario
            system("CLS"); // Limpa a tela para exibir tudo com o numero recebido acima

            printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
            printf("\nPreencha os espacos com n%cmeros inteiros:", 163);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); // Pausa
    system("CLS"); // Limpa a tela

    Matriz_ToLow(mat, L, C);
}

/* FUNÇÃO QUE LÊ UM CARACTER APENAS*/
void ReadLetter (char *letra) {
	char ch; //Capta cada caractere digitado
	int i = 0;
	while(1) {
		fflush(stdin); //Limpa o buffer
		ch = getch(); //Captura o caractere digitado pelo usuario;
		if (isalpha(ch) && i<1) { // Se for uma letra e estiver dentro do tamanho
			*letra = ch; // É direcionado para ponteiro
			i++; //Passa para proxima iteração
			printf("%c", *letra); //Exibe letra ou numero digitado na tela
		} else if (ch==8 && i==1) { //Se o Blackspace for digitado e tiver letra para apagar
			i--;
			printf("\b \b"); //Apaga o caractere anterior da tela
		} else if (ch==13 && i==1) // Quando o ENTER for digitado e tiver letra, termina o loop
            break;
    }
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
			(j==*C) ? printf("|") : printf("|%c",*(mat+i*(*C)+j));
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

/*CONVERTE TODA MATRIZ EM LETRAS MINUSCULAS*/
void Matriz_ToLow (char *mat, int *L, int *C) {
     for (int i=0; i<*L; i++)
        for(int j=0; j<*C; j++)
            *(mat+i*(*C)+j) = ToLow(*(mat+i*(*C)+j));
}

/*RECEBE PALAVRA, GUARDA EM AUX, TIRA ESPACO, CONVERTE P/ MINUSCULA, INVERTE E DEVOLVE*/
void RecebePalavra(char *pal) {
    printf("\nDigite a palavra a ser procurada:  ");
	fflush(stdin);
	gets(pal); //Lê a palavra procurada pelo usuário
    printf("\n\n");
}

/*TIRANDO TODOS ESPACOS EM BRANCO DA STRING*/
void String_NoSpace(char *s) {
    int i, j=0;
    for(i=0; *(s+i); i++)
        if(*(s+i) != ' ')
            *(s+(j++))= *(s+i);
    *(s+j)='\0'; // Realocando o limitador da string palavra
}

/*RECONHECE SE UMA STRING É PALINDROMO*/
bool Palindromo (char *s) {
	int i,j;
	for(i=0, j=strlen(s)-1; *(s+i); i++, j--)
		if( *(s+i) != *(s+j) )
			return false;
	return true;
}

/*RETORNA UMA STRING INVERTIDA*/
void String_Inverte (char *s) {
	int i,j;
	char aux;
	for(i=0,j=strlen(s)-1; i<j ;i++,j--){
		aux=*(s+i);
		*(s+i)=*(s+j);
		*(s+j)=aux;
	}
}

/*------------------------------------------ CACANDO A PALAVRA ------------------------------------------*/

    //------CAÇA A PALAVRA NAS LINHAS------
void VarreLinhas (char *mat, char *pal, int *L, int *C, int *casos) {
    int i, j, k, aux_j, confirma;

    for (i=0; i<*L; i++)
        for (j=0; j<*C; j++)
            if ( *(mat+i*(*C)+j) == *pal ) {
                confirma=1;
                for (k=0, aux_j=j; aux_j<*C && *(pal+k); k++, aux_j++) // Verifica se palavra esta completamente lá
                    if ( tolower(*(mat+i*(*C)+aux_j))  != tolower(*(pal+k)) ) { //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra não encotrada
                        break; //Sai do laco
                    }
                if (confirma && *(pal+k) == '\0') { //Se palavra for encontrada realmente
                    printf("Posi%c%co [%i][%i] , [%i][%i]\n",135, 198, i, j, i, aux_j-1); // Exibe a posicão da palavra
                    (*casos)++; //Soma as ocorrencias da palavra
                    for(k=0; *(pal+k); k++)
                        *(mat+i*(*C)+(j++)) = toupper(*(pal+k)); //Substitu por palavra em maiusculo
                    j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                }
            }
}

 //------CAÇA A PALAVRA NAS COLUNAS------
void VarreColunas (char *mat, char *pal, int *L, int *C, int *casos) {
    int i, j, k, aux_i, confirma;
    for (j=0; j<*C; j++)
        for(i=0; i<*L; i++)
            if( *(mat+i*(*C)+j) == *pal ) { //Detecta uma possivel palavra
                confirma=1;
                for(k=0, aux_i=i; aux_i<*L && *(pal+k); k++, aux_i++) // Verifica se palavra está completamente la
                    if ( tolower(*(mat+aux_i*(*C)+j)) != tolower(*(pal+k)) ) { //Se algum caratere for diferente nas duas strings
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                if(confirma &&  *(pal+k) == '\0') { // Se palavra for encontrada realmente
                    printf("Posi%c%co [%i][%i] , [%i][%i]\n", 135, 198, i, j, aux_i-1, j); // Exibe a posicão da palavra
                    (*casos)++; //Soma as ocorrencias da palavra
                    for(k=0; *(pal+k); k++)
                        *(mat+(i++)*(*C)+j) = toupper(*(pal+k)); //Substitu por palavra em maiusculo
                    i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                }
            }
}

//------CAÇA A PALAVRA NO SENTIDO DA DIAGONAL PRINCIPAL------
void VarreDiagonalPrincipal (char *mat, char *pal, int *L, int *C, int *casos) {
    int i, j, k, aux_i, aux_j,m, confirma;
    //Diagonal principal e acima
    for (k=0; k<*C; k++)
        for (i=0; i<*L; i++) {
            j=k+i;
            if (j<*C) {
                if( *(mat+i*(*C)+j) == *pal ) { //Detecta uma possível palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<*L && aux_j<*C && *(pal+m); m++, aux_i++, aux_j++) // Verifica se palavra esta completamente la
                        if ( tolower(*(mat+aux_i*(*C)+aux_j)) != tolower(*(pal+m)) ) { //Se algum caratere for diferente nas duas strings
                            confirma=0; //Palavra não encotrada
                            break; //Sai do laco
                        }
                    if(confirma && *(pal+m)) {
                        printf("Posi%c%co [%i][%i] , [%i][%i]\n", 135, 198, i, j, aux_i-1, aux_j-1); // Exibe a posicão da palavra
                        (*casos)++; //Soma as ocorrencias da palavra
                        for(m=0; *(pal+m); m++)
                             *(mat+(i++)*(*C)+(j++)) = toupper(*(pal+m)); //Substitu por palavra em maiusculo
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
    //Abaixo da diagonal principal
    for (k=0; k<*C; k++)
        for (i=0; i<*L; i++) {
            i=k+j;
            if (i<*L) {
                if( *(mat+i*(*C)+j) == *pal ) { //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<*L && aux_j<*C && *(pal+m); m++, aux_i++, aux_j++) // Vai verificar se palavra esta completamente la
                        if ( tolower(*(mat+aux_i*(*C)+aux_j)) != tolower(*(pal+m)) ) { //Se algum caratere for diferente nas duas strings
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    if( confirma && *(pal+m)=='\0' ) {
                        printf("Posi%c%co [%i][%i] , [%i][%i]\n", 135, 198, i, j, aux_i-1, aux_j-1); // Exibe a posicão da palavra
                        (*casos)++; //Soma as ocorrencias da palavra
                        for(m=0; *(pal+m); m++)
                             *(mat+(i++)*(*C)+(j++)) = toupper(*(pal+m)); //Substitu por palavra em maiusculo
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
 }

//------CAÇA A PALAVRA NO SENTIDO DA DIAGONAL SECUNDARIA------
void VarreDiagonalSecundaria (char *mat, char *pal, int *L, int *C, int *casos) {
    int i, j, k, aux_i, aux_j,m, confirma;
    //Diagonal secundaria e acima
     for(k=*C-1; k>=0; k--)
        for(i=0; i<*L; i++) {
            j=k-i;
            if(j>=0) {
                 if( *(mat+i*(*C)+j) == *pal ) { //Detecta uma possível palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<*L && aux_j>=0 && *(pal+m); m++, aux_i++, aux_j--) // Verifica se palavra esta completamente la
                        if ( tolower(*(mat+aux_i*(*C)+aux_j)) != tolower(*(pal+m)) ) { //Se algum caratere for diferente nas duas strings
                            confirma=0; //Palavra nao encotrada
                            break; //Sai do laco
                        }
                    if(confirma && *(pal+m)=='\0') {
                        printf("Posi%c%co [%i][%i] , [%i][%i]\n", 135, 198, i, j, aux_i-1, aux_j+1); // Exibe a posicão da palavra
                        (*casos)++; //Soma as ocorrencias da palavra
                        for(m=0; *(pal+m); m++)
                             *(mat+(i++)*(*C)+(j--)) = toupper(*(pal+m)); //Substitu por palavra em maiusculo
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
    //Sentido abaixo da diagonal secundaria
    for(k=0; k<*L; k++)
        for(i=1+k , j=*C-1; i<*L; i++, j--) {
            if( *(mat+i*(*C)+j) == *pal ) { //Detecta uma possivel palavra
                confirma=1;
                for(m=0, aux_i=i, aux_j=j; aux_i<*L && aux_j>=0 && *(pal+m); m++, aux_i++, aux_j--) // Verifica se palavra esta completamente la
                    if ( tolower(*(mat+aux_i*(*C)+aux_j)) != tolower(*(pal+m)) ) { //Se algum caratere for diferente nas duas strings
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                if(confirma && *(pal+m)) {
                    printf("Posi%c%co [%i][%i] , [%i][%i]\n", 135, 198, i, j, aux_i-1, aux_j+1); // Exibe a posicão da palavra
                    (*casos)++; //Soma as ocorrencias da palavra

                    for(m=0; *(pal+m); m++)
                        *(mat+(i++)*(*C)+(j--)) = toupper(*(pal+m)); //Substitu por palavra em maiusculo
                    i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                    j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                }
            }
        }
 }

void CacaPalavras (char *mat, char *pal, int *L, int *C, int *casos) {
    printf("*******************Ca%ca-Palavras*****************\n\n", 135);
    String_NoSpace(pal);

    VarreLinhas (mat, pal, L, C, casos);
    VarreColunas (mat, pal, L, C, casos);
    VarreDiagonalPrincipal (mat, pal, L, C, casos);
    VarreDiagonalSecundaria (mat, pal, L, C, casos);

    if(!(Palindromo(pal))) {
        String_Inverte(pal);
        VarreLinhas (mat, pal, L, C, casos);
        VarreColunas (mat, pal, L, C, casos);
        VarreDiagonalPrincipal (mat, pal, L, C, casos);
        VarreDiagonalSecundaria (mat, pal, L, C, casos);
    }
    ExibirMatriz(mat, L, C);

    printf("\n-------------------------------------------------\n| Quantidade de eventos da palavra '%s' :   %i |\n-------------------------------------------------\n\n", pal, *casos);
}
