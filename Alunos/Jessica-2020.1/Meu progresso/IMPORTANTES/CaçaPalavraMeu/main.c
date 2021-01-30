#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<stdbool.h>

#define MAX 100

    /*Funcoes usadas*/
    int ReadNumbers(void);
    char ReadLetter(void);
    void ExibirMat(char mat[][MAX], int L);
    void ReceberMat(char mat[][MAX], char mat_final[][MAX], int L, int C);
    void TransformarMatMinuscula(char mat[][MAX], int L);
    void ConstruirMatFinal(char mat[][MAX], char mat_final[][MAX], int L);
    void ReceberPalavra(char pal[], char pal_aux[], char pal_inversa[]);
    bool Palidromo(char pal[], char pal_inversa[]);
    int MedirTamanho (char string[]);

int main()
{
    int linha, coluna;
    int i,j,k,m,n;
    int tam1;
    bool palidromo;
    char Matriz[MAX][MAX], Matriz_final [MAX][MAX];
    char palavra[MAX], palavra_inversa[MAX], aux_palavra[MAX];
    int confirma=0;
    int aux_i, aux_j;
    int ocorrencia=0;

    /*Recebendo as dimensões da Matriz do usuario*/
    printf("Digite a dimensão da linha, por favor:  ");
    linha = ReadNumbers();
    while(linha<=0 || linha>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimensão de linha invalida, insira novamente: ");
        linha = ReadNumbers();
    }
    printf("\n\nDigite a dimensão da coluna, por favor:  ");
    coluna = ReadNumbers();
    while(coluna<=0 || coluna>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimensão de coluna invalida, insira novamente: ");
        coluna = ReadNumbers();
    }
    printf("\n\n");
    system("PAUSE");
    system("CLS");

    /*Receber Matriz do usuario*/
    ReceberMat(Matriz,Matriz_final, linha, coluna);

    /*Ignorando Case sensitive da Matriz*/
    TransformarMatMinuscula(Matriz, linha);

    /*Exibindo o Caça palavra para o usuario*/
    printf("------------------------------\n");
	printf("      Caça-Palavras \n");
	printf("------------------------------\n\n\n");

	ExibirMat(Matriz,linha);

	/*Recebendo a palavra ser procurada*/
	ReceberPalavra(palavra, aux_palavra, palavra_inversa);

	/*Verifica se palavra é palídromo*/
	palidromo=Palidromo(palavra,palavra_inversa);

    /*CAÇANDO A PALAVRA NAS LINHAS*/
    for (i=0; i<linha; i++){
        for(j=0; j<coluna; j++){

            if(Matriz[i][j]==palavra[0]){
                confirma=1;
                for(k=0, aux_j=j; aux_j<coluna && palavra[k]!= '\0'; k++, aux_j++){ // Vai verificar se palavra esta completamente la
                    if (Matriz[i][aux_j] != palavra[k]){ //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && palavra[k]=='\0'){ //Se palavra for encontrada realmente
                    ocorrencia++; //Soma as ocorrencias da palavra
                    for(k=0; palavra[k]!='\0'; k++){
                        Matriz[i][j++] = toupper(palavra[k]); //Substitu por palavra em maiusculo
                    }
                    j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    ConstruirMatFinal(Matriz, Matriz_final, linha);
                }
            }

            if(palidromo==false){ // Se palavra não palidromo
                if(Matriz[i][j]==palavra_inversa[0]){
                    confirma=1;
                    for(k=0, aux_j=j; aux_j<coluna && palavra_inversa[k]!= '\0'; k++, aux_j++){ // Vai verificar se palavra inversa esta completamente la
                        if (Matriz[i][aux_j] != palavra_inversa[k]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra_inversa[k]=='\0'){ //Se palavra inversa for encontrada realmente
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(k=0; palavra_inversa[k]!='\0'; k++){
                            Matriz[i][j++] = toupper(palavra_inversa[k]); //Substitu por palavra inversa em maiusculo
                        }
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }
            }
        }
    }

    /*CAÇANDO A PALAVRA NAS COLUNAS*/
    for (j=0; j<coluna; j++){
        for(i=0; i<linha; i++){

            if(Matriz[i][j]==palavra[0]){ //Detecta uma possivel palavra
                confirma=1;
                for(k=0, aux_i=i; aux_i<linha && palavra[k]!= '\0'; k++, aux_i++){ // Vai verificar se palavra esta completamente la
                    if (Matriz[aux_i][j] != palavra[k]){ //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && palavra[k]=='\0'){ //Se palavra for encontrada realmente
                    ocorrencia++; //Soma as ocorrencias da palavra
                    for(k=0; palavra[k]!='\0'; k++){
                        Matriz[i++][j] = toupper(palavra[k]); //Substitu por palavra em maiusculo
                    }
                    i = aux_i -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    ConstruirMatFinal(Matriz, Matriz_final, linha);
                }
            }

            if(palidromo==false){ // Se palavra não palidromo
                if(Matriz[i][j]==palavra_inversa[0]){ //Detecta uma possivel palavra
                    confirma=1;
                    for(k=0, aux_i=i; aux_i<linha && palavra_inversa[k]!= '\0'; k++, aux_i++){ // Vai verificar se palavra inversa esta completamente la
                        if (Matriz[aux_i][j] != palavra_inversa[k]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra_inversa[k]=='\0'){ //Se palavra inversa for encontrada realmente
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(k=0; palavra_inversa[k]!='\0'; k++){
                            Matriz[i++][j] = toupper(palavra_inversa[k]); //Substitu por palavra inversa em maiusculo
                        }
                        i = aux_i -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }
            }
        }
    }

    /*CAÇANDO A PALAVRA NAS DIAGONAIS*/

        //Sentido da diagonal principal para cima
    for(k=0; k<coluna;k++){
        for(i=0; i<linha; i++){
            j=k+i;
            if(j<coluna){
                if(Matriz[i][j]==palavra[0]){ //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j<coluna && palavra[m]!= '\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta la
                        if (Matriz[aux_i][aux_j] != palavra[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra[m]== '\0'){
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(n=0; palavra[n]!='\0'; n++){
                            Matriz[i++][j++] = toupper(palavra[n]); //Substitu por palavra em maiusculo
                        }
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }

                if(palidromo==false){ // Se palavra não palidromo
                    if(Matriz[i][j]==palavra_inversa[0]){ //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j<coluna && palavra_inversa[m]!= '\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta la
                            if (Matriz[aux_i][aux_j] != palavra_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && palavra_inversa[m]== '\0'){
                            ocorrencia++; //Soma as ocorrencias da palavra
                            for(n=0; palavra_inversa[n]!='\0'; n++){
                                Matriz[i++][j++] = toupper(palavra_inversa[n]); //Substitu por palavra em maiusculo
                            }
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                            ConstruirMatFinal(Matriz, Matriz_final, linha);
                        }
                    }
                }
            }
        }
    }

        //Sentido abaixo da diagonal principal
    for(k=1; k<linha; k++){
        for(j=0; j<coluna; j++){
            i=k+j;
            if(i<linha){
                if(Matriz[i][j]==palavra[0]){ //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j<coluna && palavra[m]!= '\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta la
                        if (Matriz[aux_i][aux_j] != palavra[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra[m]== '\0'){
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(n=0; palavra[n]!='\0'; n++){
                            Matriz[i++][j++] = toupper(palavra[n]); //Substitu por palavra em maiusculo
                        }
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }
                if(palidromo==false){ // Se palavra não palidromo
                    if(Matriz[i][j]==palavra_inversa[0]){ //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j<coluna && palavra_inversa[m]!= '\0'; m++, aux_i++, aux_j++) { // Vai verificar se palavra esta la
                            if (Matriz[aux_i][aux_j] != palavra_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && palavra_inversa[m]== '\0'){
                            ocorrencia++; //Soma as ocorrencias da palavra
                            for(n=0; palavra_inversa[n]!='\0'; n++){
                                Matriz[i++][j++] = toupper(palavra_inversa[n]); //Substitu por palavra em maiusculo
                            }
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j -1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                            ConstruirMatFinal(Matriz, Matriz_final, linha);
                        }
                    }
                }
            }
        }
    }

        //Sentido da diagonal secundaria para cima
     for(k=coluna-1; k>=0;k--){
        for(i=0; i<linha; i++){
            j=k-i;
            if(j>=0){
                if(Matriz[i][j]==palavra[0]){ //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j>=0 && palavra[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra esta la
                        if (Matriz[aux_i][aux_j] != palavra[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra[m]== '\0'){
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(n=0; palavra[n]!='\0'; n++){
                            Matriz[i++][j--] = toupper(palavra[n]); //Substitu por palavra em maiusculo
                        }
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }
                if(palidromo==false){ // Se palavra não palidromo
                    if(Matriz[i][j]==palavra_inversa[0]){ //Detecta uma possivel palavra
                        confirma=1;
                        for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j>=0 && palavra_inversa[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra esta la
                            if (Matriz[aux_i][aux_j] != palavra_inversa[m]){ //Se algum caratere for diferente nas duas
                                confirma=0; //Palavra inversa nao encotrada
                                break; //Sai do laco
                            }
                        }
                        if(confirma && palavra_inversa[m]== '\0'){
                            ocorrencia++; //Soma as ocorrencias da palavra
                            for(n=0; palavra_inversa[n]!='\0'; n++){
                                Matriz[i++][j--] = toupper(palavra_inversa[n]); //Substitu por palavra em maiusculo
                            }
                            i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                            j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                            ConstruirMatFinal(Matriz, Matriz_final, linha);
                        }
                    }
                }
            }
        }
    }

        //Sentido abaixo da diagonal secundaria
     for(k=0; k<linha; k++){
        for(i=1+k , j=coluna-1; i<linha; i++, j--){
            if(Matriz[i][j]==palavra[0]){ //Detecta uma possivel palavra
                confirma=1;
                for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j>=0 && palavra[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra esta la
                    if (Matriz[aux_i][aux_j] != palavra[m]){ //Se algum caratere for diferente nas duas
                        confirma=0; //Palavra inversa nao encotrada
                        break; //Sai do laco
                    }
                }
                if(confirma && palavra[m]== '\0'){
                    ocorrencia++; //Soma as ocorrencias da palavra
                    for(n=0; palavra[n]!='\0'; n++){
                        Matriz[i++][j--] = toupper(palavra[n]); //Substitu por palavra em maiusculo
                    }
                    i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                    j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                    ConstruirMatFinal(Matriz, Matriz_final, linha);
                }
            }

            if(palidromo==false){ // Se palavra não palidromo
                if(Matriz[i][j]==palavra_inversa[0]){ //Detecta uma possivel palavra
                    confirma=1;
                    for(m=0, aux_i=i, aux_j=j; aux_i<linha && aux_j>=0 && palavra_inversa[m]!= '\0'; m++, aux_i++, aux_j--) { // Vai verificar se palavra esta la
                        if (Matriz[aux_i][aux_j] != palavra_inversa[m]){ //Se algum caratere for diferente nas duas
                            confirma=0; //Palavra inversa nao encotrada
                            break; //Sai do laco
                        }
                    }
                    if(confirma && palavra_inversa[m]== '\0'){
                        ocorrencia++; //Soma as ocorrencias da palavra
                        for(n=0; palavra_inversa[n]!='\0'; n++){
                            Matriz[i++][j--] = toupper(palavra_inversa[n]); //Substitu por palavra em maiusculo
                        }
                        i = aux_i -1; //Coloca i em posicao de detectar uma possivel outra palavra depois
                        j = aux_j +1; //Coloca j em posicao de detectar uma possivel outra palavra depois
                        ConstruirMatFinal(Matriz, Matriz_final, linha);
                    }
                }
            }
        }
    }

    system("PAUSE");
    system("CLS");

    printf("\nHouveram %i ocorrencias de '%s'.\n", ocorrencia, aux_palavra);

    printf("\n------------------------------\n");
	printf("      Caça-Palavras \n");
	printf("------------------------------\n\n\n");

	for (i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf(" %c ", Matriz_final[i][j]);
        }
        printf("\n");
	}

    return 0;
}

/*LER APENAS NUMEROS NUMA VARIAVEL INTEIRA*/
int ReadNumbers(void){
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

/*LER APENAS UMA LETRA*/
char ReadLetter(void) {
	char ch; //Capta cada caractere digitado
	char digitado[2]; //Junta letra e enter
	int i = 0, j;

	do {
		fflush(stdin); //Limpa o buffer
		ch = _getch(); //Captura o caractere digitado pelo usuario;

		if (isalpha(ch) != 0  && i < 1) { // Se for uma letra ou numeros e estiver dentro do tamanho
			digitado[i] = ch; // É direcionado para string auxilar
			i++; //Passa para proxima posição
			printf("%c", ch); //Exibe letra ou numero digitado na tela

		}
		else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
			i--;
			digitado[i] = '\0';
			printf("\b \b"); //Apaga o caractere anterior
		}
	} while (ch != 13); // Quando o ENTER for digitado, termina o loop
	digitado[i] = '\0';

	 return digitado[0];
}

/*MEDE O TAMANHO DE UMA STRING*/
int MedirTamanho (char string[]){
    int tamanho=0;
    while(string[tamanho]!='\0') ++tamanho;

    return tamanho;
}
/*FUNÇÃO QUE EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMat(char mat[][MAX], int L){
    int k, z;

    for (k=0; k<L; k++){ //Laço principal das linhas
            for(z=0; mat[k][z] != '\0'; z++){ //Laço secundario das colunas
                printf(" %c ", mat[k][z]); //Exibe cada caractere
                }
                printf("\n"); //Pula a linha
            }
}

/*FUÇÃO QUE RECEBE AS LETRAS DA MATRIZ DO USUARIO E PASSA A MATRIZ PARA UMA AUX FINAL*/
void ReceberMat(char mat[][MAX], char mat_final[][MAX], int L, int C){ // Matriz recebida - numero de linha - numero de coluna
    int i,j;
    printf("------------------------------\n");
	printf("     Recebendo a matriz \n");
	printf("------------------------------\n\n\n");

	for (i=0; i<L; i++){ // Preenhe toda matriz com asteriscos primeiramente
        for(j=0; j<C; j++){
            mat[i][j]='*';
            printf(" %c ", mat[i][j]);
        }
        printf("\n");
	}
	printf("\n\n");

	for (i=0; i<L; i++){ //Finaliza a toda a matriz com \0
        mat[i][C] = '\0';
	}

	for(i=0; i<L; i++){
        for(j=0; mat[i][j] != '\0'; j++){
            printf("Matriz [%i][%i]: ", i+1, j+1);
            mat[i][j]=ReadLetter(); //Chama a função que recebe apenas caracteres alfabeticos do usuario

            system("CLS"); //Limpa a tela para exibir tudo com o caractere recebido acima

            printf("------------------------------\n");
            printf("     Recebendo a matriz \n");
            printf("------------------------------\n\n\n");

            ExibirMat(mat,L); // Exibe a matriz com o caractere recebido nessa interação
        }
    }

    for (i=0; i<L; i++){
        for(j=0; mat[i][j] != '\0'; j++){
            mat_final[i][j]=mat[i][j];
        }
	}

    printf("\n\n");
    system("PAUSE"); //Pausa o sistema
    system("CLS"); //Limpa a tela
}

/*CONVERTE TODA MATRIZ EM LETRAS MINUSCULAS*/
void TransformarMatMinuscula(char mat[][MAX], int L){
     int i, j;

     for (i=0; i<L; i++){
        for(j=0; mat[i][j] != '\0'; j++){
            if(mat[i][j]>='A' && mat[i][j]<='Z'){
                mat[i][j]=tolower(mat[i][j]);
            }
        }
	}
}

/*RECEBE PALAVRA, GUARDA EM AUX, TIRA ESPACO, CONVERTE P/ MINUSCULA, INVERTE E DEVOLVE*/
void ReceberPalavra(char pal[], char pal_aux[], char pal_inversa[]){
    int tam1=0, espacos=0;
    int i, j;
    printf("\n\nDigite a palavra a ser procurada:  ");
	fflush(stdin);
	gets(pal);
	fflush(stdin);
	printf("\n\n");
	tam1= MedirTamanho(pal);

	while(tam1 == 0 || tam1 ==1){
        printf("Digite uma PALAVRA, por favor:");
        fflush(stdin);
        gets(pal);
        fflush(stdin);
        tam1= MedirTamanho(pal);
        printf("\n\n");
	}
    /*Passa palavra para outra string para mante-la */
    for(i=0; pal[i]!='\0'; i++){
        pal_aux[i]=pal[i];
    }
    pal_aux[i]='\0';

    /*Ignorando case sensitive de palavra*/
    for(i=0; pal[i]!='\0'; i++){
        if (pal[i]>='A' && pal[i]<='Z'){
            pal[i]=tolower(pal[i]);
        }
    }

    /*Tirando espaços da palavra*/
    for (i=0; pal[i]!='\0'; i++) {
		if (pal[i]==' ') {
            espacos++;
			for(j=i; j<tam1; j++) {
				pal[j]=pal[j+1];
			}
		}
	}
	pal[tam1-espacos]='\0';

	tam1=MedirTamanho(pal); //Mede o tamanho novamente sem espaços

	/*Invertendo a palavra*/
	j=0;
	for (i=tam1-1; i>=0; i--){
        pal_inversa[j++]=pal[i];
	}
	pal_inversa[j]='\0';
}

/*VERIFICA SE PALAVRA É PALIDROMO*/
bool Palidromo(char pal[], char pal_inversa[]){
    bool palidromo=false;
    int i=0;
    while (pal[i]==pal_inversa[i] && pal[i]!='\0' && pal_inversa[i]!='\0') ++i;//Percorre as duas strings comparando-as

    if (pal[i]=='\0' && pal_inversa[i]=='\0'){ // Indica ao usuario quando as duas strings sao iguais, logo um palidromo
       palidromo=true;
    }

    return palidromo;
}

void ConstruirMatFinal(char mat[][MAX], char mat_final[][MAX], int L){
    int i, j;

    for (i=0; i<L; i++){
        for(j=0; mat[i][j] != '\0'; j++){
            if(mat[i][j]>='A' && mat[i][j]<='Z' )
                mat_final[i][j]=mat[i][j];
        }
	}
    TransformarMatMinuscula(mat,L);
}


