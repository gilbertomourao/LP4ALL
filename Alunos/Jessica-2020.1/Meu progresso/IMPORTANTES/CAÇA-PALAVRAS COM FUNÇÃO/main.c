#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

    /*Funcoes Globais*/
    int ReadNumbers(void);
    char ReadLetter(void);
    void TransformarMatrizMinuscula(char mat[][MAX], int L);
    void ExibirMatriz(char mat[][MAX], int L, int C);
    void ExibirMatrizPosioes(int vet [][4], int L);

    /*Funções Usadas Para Receber Parametros do Caca Palavra*/
    int ReadLinha (void);
    int ReadColuna (void);
    void RecebeMatriz(char mat[][MAX], char mat_final[][MAX], int L, int C);
    bool ReceberPalavra(char pal[], char pal_aux[], char pal_inversa[]);
    /*Funções Usadas Para Cacar  Palavra*/

    int VarreDiagonalPrincipal(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]);
    int VarreDiagonalSecundaria(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]);
    int VarreLinhas(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]);
    int VarreColunas(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]);

int main()
{
    int l, c;
    int DiagonalP=0, DiagonalS=0, Linha=0, Coluna=0, ocorrencias=0;
    int DP[MAX][4], DS[MAX][4], L[MAX][4], C[MAX][4];
    bool palindromo;
    char Matriz[MAX][MAX], Matriz_final [MAX][MAX];
    char palavra[MAX], palavra_aux[MAX], palavras_inv[MAX];
    int controle=2; // Vai controlar se procura outra palavra ou se entra com uma nova matriz

    while(1) {

        if (controle == 2) { //Só recebe outra matriz nova quando controle==1
            //Recebe as dimensoes da matriz
            printf("Bem vindo ao CA%cA-PALAVRAS DA JESS s2!\n\n", 128);
            l = ReadLinha();
            c = ReadColuna();

            printf("\n\n");
            system("PAUSE");
            system("CLS");

            //Recebe a matriz de letras
            printf("           CA%cA-PALAVRAS DA JESS s2", 128);
            RecebeMatriz(Matriz, Matriz_final, l, c);
        }

        //Exibe o caca-palavras e pede a palavra a ser procurada
        printf("           CA%cA-PALAVRAS DA JESS s2", 128);
        ExibirMatriz(Matriz, l, c);
        palindromo = ReceberPalavra(palavra, palavra_aux, palavras_inv);

        printf("\n\n");
        system("PAUSE");
        system("CLS");

        //Procura a palavra
        DiagonalP=VarreDiagonalPrincipal(Matriz,Matriz_final, palavra,palavras_inv,l,c,palindromo, DP);
        DiagonalS=VarreDiagonalSecundaria(Matriz,Matriz_final, palavra,palavras_inv,l,c,palindromo,DS);
        Coluna=VarreColunas(Matriz,Matriz_final, palavra,palavras_inv,l,c,palindromo,C);
        Linha=VarreLinhas(Matriz,Matriz_final, palavra,palavras_inv,l,c,palindromo,L);
        ocorrencias=DiagonalP+DiagonalS+Linha+Coluna;

        //Exibe os resultados das procura
        if (ocorrencias==1) {
            printf("CA%cA-PALAVRAS DA JESS s2\n", 128);
            ExibirMatriz(Matriz_final,l,c);
            printf("Foi encontrado %i caso da palavra '%s'.\n\n\n",ocorrencias, palavra_aux);
            ExibirMatrizPosioes(DP,DiagonalP);
            ExibirMatrizPosioes(DS, DiagonalS);
            ExibirMatrizPosioes(C, Coluna);
            ExibirMatrizPosioes(L, Linha);
            printf("\n\n");
        } else if (ocorrencias>1) {
            printf("CA%cA-PALAVRAS DA JESS s2\n", 128);
            ExibirMatriz(Matriz_final,l,c);
            printf("Foram encontrados %i casos da palavra '%s'.\n\n\n",ocorrencias, palavra_aux);
            ExibirMatrizPosioes(DP,DiagonalP);
            ExibirMatrizPosioes(DS, DiagonalS);
            ExibirMatrizPosioes(C, Coluna);
            ExibirMatrizPosioes(L, Linha);
            printf("\n\n");
        } else
            printf("Nao houve nenhuma ocorrencia da palavra '%s'.\n\n\n",palavra_aux);

        ocorrencias=0;

        //Decide a proxima ação
        printf("---------------------------------------\nSelecione uma das opç%ces abaixo:\n---------------------------------------\n", 148);
        printf("-Digite 1 para procurar outra palavra.\n");
        printf("-Digite 2 para entrar com um novo caça-palavras.\n");
        printf("-Digite 3 para encerrar a procura de palavras.\n\n");
        printf("Op%c%co:  ",135,198);
        controle=ReadNumbers();
        while(controle>3 || controle<1) {
            printf("Op%c%co Inv%clida, tente novamente:  ", 135,198,160);
            controle=ReadNumbers();
            printf("\n\n");
        }

        if (controle==3) { // Fim do caca-palavras
            system("CLS");
            printf("Fim da divers%co, at%c a pr%cxima...\n", 198,130,162);
            break; //Sai do loop
        } else if (controle==1) {
            system("CLS");
            TransformarMatrizMinuscula(Matriz_final,l);
        } else if (controle==2) { //Limpa a tela para a proxima palavra ou matriz
            system("CLS");
        }
    }

    return 0;
}

/*LENDO A DIMENSÃO DA LINHA DA MATRIZ DE CARACTERES*/
int ReadLinha (void){
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
int ReadColuna (void){
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
    char digitado[2]; //Junta todos os digitos digitados
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
void RecebeMatriz(char mat[][MAX], char mat_final[][MAX], int L, int C){ // Matriz recebida - Matriz auxiliar- numero de linha - numero de coluna
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
        printf("----");
     printf("\n");

    for (k=0; k<L; k++) { //Laço principal das linhas
        for(z=0; mat[k][z] != '\0'; z++) { //Laço secundario das colunas
            printf(" %c ", mat[k][z]); //Exibe cada caractere
        }
        printf("\n"); //Pula a linha
    }

    for(i=0; i<C; i++) //Estetico apenas
        printf("----");
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

/*RECEBE PALAVRA, GUARDA EM AUX, TIRA ESPACO, CONVERTE P/ MINUSCULA, INVERTE E DEVOLVE*/
bool ReceberPalavra(char pal[], char pal_aux[], char pal_inversa[]) {

    int tam_pal=0, espacos=0;
    bool palindromo=false;
    int i, j;

    printf("\n\nDigite a palavra a ser procurada:  ");
	fflush(stdin);
	gets(pal); //Lê a palavra procurada pelo usuário
	fflush(stdin);

    tam_pal = strlen(pal); //Mede tamanho da palavra

	while(tam_pal == 0 || tam_pal ==1) {
        printf("\nDigite uma PALAVRA DE VERDADE, por favor:");
        fflush(stdin);
        gets(pal);
        fflush(stdin);
        tam_pal = strlen(pal);
	}

    /*Passa palavra para outra string para mante-la intacta*/
    for(i=0; pal[i]!='\0'; i++)
        pal_aux[i]=pal[i];
    pal_aux[i]='\0';

    /*Ignorando case sensitive de palavra*/
    for(i=0; pal[i]!='\0'; i++) {
        if (pal[i]>='A' && pal[i]<='Z')
            pal[i]=tolower(pal[i]);
    }

    /*Tirando espaços da palavra*/
    for (i=0; pal[i]!='\0'; i++) {
		if (pal[i]==' ') {
            espacos++;
			for(j=i; j<tam_pal; j++)
				pal[j]=pal[j+1];
		}
	}
	pal[tam_pal-espacos]='\0'; //Realocando o limitador da string palavra
	tam_pal = strlen(pal); //Medindo o novo tamanho da palavra

	/*Invertendo a palavra*/
	j=0;
	for (i=tam_pal-1; i>=0; i--)
        pal_inversa[j++]=pal[i];
	pal_inversa[j]='\0';

	//Verificando se palavra é palíndromo
	i=0;
    while (pal[i]==pal_inversa[i] && pal[i]!='\0' && pal_inversa[i]!='\0') ++i;//Percorre as duas strings comparando-as

    if (pal[i]=='\0' && pal_inversa[i]=='\0') // Indica ao usuario quando as duas strings sao iguais, logo um palidromo
       palindromo=true;

    return palindromo;
}

/*CAÇA A PALAVRA NO SENTIDO DA DIAGONAL PRINCIPAL*/
int VarreDiagonalPrincipal(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]) {
    int i, j, k, aux_i, aux_j,m, confirma, ocorrencia=0;

    //Sentido da diagonal principal para cima
    for (k=0; k<C;k++)
        for (i=0; i<L; i++) {
            j=k+i;
            if (j<C) {
                if(mat[i][j]==pal[0]) { //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j<C && pal[m]!='\0'; m++, aux_i++, aux_j++) { // Verifica se palavra esta completamente la
                        if (mat[aux_i][aux_j] != pal[m]) { //Se algum caratere for diferente nas duas strings
                            confirma=0; //Palavra nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal[m]=='\0') {

                        vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=j;
                        vet[ocorrencia][2]=aux_i -1;
                        vet[ocorrencia][3]=aux_j -1;

                        ocorrencia++; //Soma as ocorrencias da palavra

                        for(m=0; pal[m]!='\0'; m++)
                            mat_final[i++][j++] = toupper(pal[m]); //Substitu por palavra em maiusculo na matriz que sera exibida no fim
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }

                if(IsPalindromo==false) { // Se palavra não palidromo
                    if(mat[i][j]==pal_inversa[0]) { //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j<C && pal_inversa[m]!= '\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra inversa esta completamente la
                            if (mat[aux_i][aux_j] != pal_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && pal_inversa[m]== '\0') {

                            vet[ocorrencia][0]=aux_i-1; // Preenche a matriz com as posicões inicial e final das palavras achadas
                            vet[ocorrencia][1]=aux_j-1;
                            vet[ocorrencia][2]=i;
                            vet[ocorrencia][3]=j;

                            ocorrencia++; //Soma as ocorrencias da palavra

                            for(m=0; pal_inversa[m]!='\0'; m++)
                                mat_final[i++][j++] = toupper(pal_inversa[m]); //Substitu por palavra inversa em maiusculo
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        }
                    }
                }
            }
        }

    //Sentido abaixo da diagonal principal
    for(k=1; k<L; k++)
        for(j=0; j<C; j++) {
            i=k+j;
            if (i<L) {
                if(mat[i][j]==pal[0]) { //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j<C && pal[m]!='\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta completamente la
                        if (mat[aux_i][aux_j] != pal[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal[m]=='\0') {

                        vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=j;
                        vet[ocorrencia][2]=aux_i -1;
                        vet[ocorrencia][3]=aux_j -1;

                        ocorrencia++; //Soma as ocorrencias da palavra

                        for(m=0; pal[m]!='\0'; m++)
                            mat_final[i++][j++] = toupper(pal[m]); //Substitu por palavra em maiusculo
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }

                if(IsPalindromo==false){ // Se palavra não palidromo
                    if(mat[i][j]==pal_inversa[0]){ //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j<C && pal_inversa[m]!='\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta completamente la
                            if (mat[aux_i][aux_j] != pal_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && pal_inversa[m]== '\0') {

                            vet[ocorrencia][0]=aux_i-1; // Preenche a matriz com as posicões inicial e final das palavras achadas
                            vet[ocorrencia][1]=aux_j-1;
                            vet[ocorrencia][2]=i;
                            vet[ocorrencia][3]=j;

                            ocorrencia++; //Soma as ocorrencias da palavra

                            for(m=0; pal_inversa[m]!='\0'; m++)
                                mat_final[i++][j++] = toupper(pal_inversa[m]); //Substitu por palavra em maiusculo
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        }
                    }
                }
            }
        }

    return ocorrencia;
 }

 /*CAÇA A PALAVRA NO SENTIDO DA DIAGONAL SECUNDARIA*/
int VarreDiagonalSecundaria(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]) {
    int i, j, k, aux_i, aux_j,m, confirma, ocorrencia=0;

    //Sentido da diagonal secundaria para cima
     for(k=C-1; k>=0;k--)
        for(i=0; i<L; i++) {
            j=k-i;
            if(j>=0) {
                 if(mat[i][j]==pal[0]) { //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j>=0 && pal[m]!='\0'; m++, aux_i++, aux_j--) { // Verifica se palavra esta completamente la
                        if (mat[aux_i][aux_j] != pal[m]) { //Se algum caratere for diferente nas duas strings
                            confirma=0; //Palavra nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal[m]=='\0') {

                        vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=j;
                        vet[ocorrencia][2]=aux_i -1;
                        vet[ocorrencia][3]=aux_j +1;

                        ocorrencia++; //Soma as ocorrencias da palavra

                        for(m=0; pal[m]!='\0'; m++)
                            mat_final[i++][j--] = toupper(pal[m]); //Substitu por palavra em maiusculo na matriz que sera exibida no fim
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }

                if(IsPalindromo==false) { // Se palavra não palidromo
                    if(mat[i][j]==pal_inversa[0]) { //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j>=0 && pal_inversa[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra inversa esta completamente la
                            if (mat[aux_i][aux_j] != pal_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && pal_inversa[m]== '\0') {

                            vet[ocorrencia][0]=aux_i-1; // Preenche a matriz com as posicões inicial e final das palavras achadas
                            vet[ocorrencia][1]=aux_j+1;
                            vet[ocorrencia][2]=i;
                            vet[ocorrencia][3]=j;

                            ocorrencia++; //Soma as ocorrencias da palavra

                            for(m=0; pal_inversa[m]!='\0'; m++)
                                mat_final[i++][j--] = toupper(pal_inversa[m]); //Substitu por palavra inversa em maiusculo
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        }
                    }
                }
            }
        }

    //Sentido abaixo da diagonal secundaria
    for(k=0; k<L; k++)
        for(i=1+k , j=C-1; i<L; i++, j--) {
            if(mat[i][j]==pal[0]) { //Detecta uma possivel palavra
                confirma=1;
                for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j>=0 && pal[m]!='\0'; m++, aux_i++, aux_j--) { // Verifica se palavra esta completamente la
                    if (mat[aux_i][aux_j] != pal[m]) { //Se algum caratere for diferente nas duas strings
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && pal[m]=='\0') {

                    vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                    vet[ocorrencia][1]=j;
                    vet[ocorrencia][2]=aux_i -1;
                    vet[ocorrencia][3]=aux_j +1;

                    ocorrencia++; //Soma as ocorrencias da palavra

                    for(m=0; pal[m]!='\0'; m++)
                        mat_final[i++][j--] = toupper(pal[m]); //Substitu por palavra em maiusculo na matriz que sera exibida no fim
                    i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                    j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                }
            }

            if(IsPalindromo==false) { // Se palavra não palidromo
                if(mat[i][j]==pal_inversa[0]) { //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<L && aux_j>=0 && pal_inversa[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra inversa esta completamente la
                        if (mat[aux_i][aux_j] != pal_inversa[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal_inversa[m]== '\0') {

                        vet[ocorrencia][0]=aux_i-1; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=aux_j+1;
                        vet[ocorrencia][2]=i;
                        vet[ocorrencia][3]=j;

                        ocorrencia++; //Soma as ocorrencias da palavra

                        for(m=0; pal_inversa[m]!='\0'; m++)
                            mat_final[i++][j--] = toupper(pal_inversa[m]); //Substitu por palavra inversa em maiusculo
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
    return ocorrencia;
 }

 /*CAÇA A PALAVRA NAS LINHAS*/
 int VarreLinhas(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]) {
    int i, j, k, aux_j, confirma, ocorrencia=0;

 for (i=0; i<L; i++)
        for(j=0; j<L; j++) {

            if(mat[i][j]==pal[0]) {
                confirma=1;
                for(k=0, aux_j=j; aux_j<C && pal[k]!= '\0'; k++, aux_j++) { // Vai verificar se palavra esta completamente la
                    if (mat[i][aux_j] != pal[k]) { //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && pal[k]=='\0') { //Se palavra for encontrada realmente

                    vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                    vet[ocorrencia][1]=j;
                    vet[ocorrencia][2]=i;
                    vet[ocorrencia][3]=aux_j -1;

                    ocorrencia++; //Soma as ocorrencias da palavra

                    for(k=0; pal[k]!='\0'; k++)
                        mat_final[i][j++] = toupper(pal[k]); //Substitu por palavra em maiusculo
                    j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                }
            }

            if(IsPalindromo==false) { // Se palavra não palidromo
                if(mat[i][j]==pal_inversa[0]) {
                    confirma=1;
                    for(k=0, aux_j=j; aux_j<C && pal_inversa[k]!= '\0'; k++, aux_j++) { // Vai verificar se palavra inversa esta completamente la
                        if (mat[i][aux_j] != pal_inversa[k]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal_inversa[k]=='\0') { //Se palavra inversa for encontrada realmente

                        vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=aux_j-1;
                        vet[ocorrencia][2]=i;
                        vet[ocorrencia][3]=j;

                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(k=0; pal_inversa[k]!='\0'; k++)
                            mat_final[i][j++] = toupper(pal_inversa[k]); //Substitu por palavra inversa em maiusculo
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
    return ocorrencia;
 }

 /*CAÇA A PALAVRA NAS COLUNAS*/
int VarreColunas(char mat[][MAX], char mat_final[][MAX], char pal[], char pal_inversa[], int L, int C, bool IsPalindromo, int vet[][4]) {
    int i, j, k, aux_i, confirma, ocorrencia=0;

    for (j=0; j<C; j++)
        for(i=0; i<L; i++) {

            if(mat[i][j]==pal[0]) { //Detecta uma possivel palavra
                confirma=1;
                for(k=0, aux_i=i; aux_i<L && pal[k]!='\0'; k++, aux_i++) { // Vai verificar se palavra esta completamente la
                    if (mat[aux_i][j] != pal[k]) { //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && pal[k]=='\0') { //Se palavra for encontrada realmente

                    vet[ocorrencia][0]=i; // Preenche a matriz com as posicões inicial e final das palavras achadas
                    vet[ocorrencia][1]=j;
                    vet[ocorrencia][2]=aux_i -1;
                    vet[ocorrencia][3]=j;

                    ocorrencia++; //Soma as ocorrencias da palavra

                    for(k=0; pal[k]!='\0'; k++)
                        mat_final[i++][j] = toupper(pal[k]); //Substitu por palavra em maiusculo
                    i = aux_i -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                }
            }

            if(IsPalindromo==false) { // Se palavra não palidromo
                if(mat[i][j]==pal_inversa[0]) { //Detecta uma possivel palavra
                    confirma=1;
                    for(k=0, aux_i=i; aux_i<L && pal_inversa[k]!= '\0'; k++, aux_i++) { // Vai verificar se palavra inversa esta completamente la
                        if (mat[aux_i][j] != pal_inversa[k]) { //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && pal_inversa[k]=='\0') { //Se palavra inversa for encontrada realmente

                        vet[ocorrencia][0]=aux_i-1; // Preenche a matriz com as posicões inicial e final das palavras achadas
                        vet[ocorrencia][1]=j;
                        vet[ocorrencia][2]=i;
                        vet[ocorrencia][3]=j;

                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(k=0; pal_inversa[k]!='\0'; k++)
                            mat_final[i++][j] = toupper(pal_inversa[k]); //Substitu por palavra inversa em maiusculo
                        i = aux_i -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    }
                }
            }
        }
    return ocorrencia;
}

/*FUNÇÃO QUE VAI EXIBIR AS POSIÇÕES DE CADA PALAVRA ACHADA  L=OCORRENCIAS=linha=coluna=DiagonalP=DiagonalS*/
void ExibirMatrizPosioes(int vet [][4], int L){
    int i;
    for (i=0; i<L; i++)
        printf("Posicao [%i][%i] , [%i][%i]\n", vet[i][0], vet[i][1], vet[i][2], vet[i][3]);
}
