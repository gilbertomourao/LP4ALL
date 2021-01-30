#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*38.	Escreva um programa que leia texto do teclado, linha a linha, até chegar ao fim de texto (Ctrl-D ou Ctrl-Z).
O programa deverá escrever uma estatística do texto lido: nº de palavras, número de linhas em branco,
nº total de linhas, nº de letras. O programa deverá usar funções separadas para cada uma das suas tarefas.*/
#define MAX 100
int main()
{
    int ReadLetters(char txt[][MAX]); //Funcao que le o texto
    int NumPalavras(char txt[][MAX], int L);
    int NumLetras (char txt[][MAX], int L);
    int NumLinhaBranco (char txt[][MAX], int L);

    char texto[MAX][MAX];
    int linhas; //Quantidade de linhas do texto
    int i;
    int palavras, linhas_branco, letras;

    printf("Escreva seu texto abaixo, para finalizar use CTRL D ou CTRL Z.\n");
    printf("--------------------------------------------------------------\n");
    linhas= ReadLetters(texto);
    printf("\n--------------------------------------------------------------\n");
    system("pause");
    system("CLS");

    /*Exibindo o testo lido*/
    printf("\t\tTEXTO INSERIDO\n");
    printf("----------------------------------------------------\n");
    for(i=0; i<linhas; i++){
        printf("%s\n", texto[i]);
    }
    printf("----------------------------------------------------\n");

    /*Numero total de linhas do texto*/
    printf("\nNumero de linhas do texto: %i", linhas);

    /*Descobrindo numero de linhas em brando do texto*/
    linhas_branco=NumLinhaBranco(texto,linhas);
    printf("\nNumero de linhas em branco do texto: %i", linhas_branco);

    /*Descobrindo numero de palavras do texto*/
    palavras = NumPalavras(texto,linhas);
    printf("\nNumero de palavras do texto: %i", palavras);

    /*Descobrindo numero de letras do texto*/
    letras = NumLetras(texto,linhas);
    printf("\nNumero de letras do texto: %i\n\n", letras);

    return 0;
}

/* LER UM TEXTO*/
int ReadLetters(char txt[][MAX]) {
    char ch; //Capta cada caractere digitado
    int i=0, j=0;

    while(1){

        fflush(stdin); //Limpa o buffer
        ch = getch( ); //Captura o caractere digitado pelo usuario;

        if (isalpha(ch)!=0 || ch==32 || ch==44 || ch==33 || ch==34 || ch==45 || ch==58 || ch==59 || ch==63 && (i<MAX && j<MAX)) {
            //Se for uma letra|espaço|virgula|exclamação|aspas|traço|dois pontos|ponto e virgula|interrogação
            txt[j][i]=ch; //É direcionado para string de letras
            i++; //Passa para proxima posição
            printf("%c", ch); //Exibe letra ou espaço digitado na tela

        } else if (ch==8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
            i--;
            txt[j][i]='\0';
            printf("\b \b"); //Apaga o caractere anterior
        }
        else if (ch == 13) { // Quando o ENTER for digitado, muda a linha
            txt[j][i]='\0';
            j++;
            i=0;
            printf("\n");
        }
        else if (ch==4 || ch==26) { // Quando Ctrl D ou Ctrl Z for digitado, finaliza laço
            txt[j][i]='\0';
            break;
        }
    }

    return j+1;
}

/*DESCOBRINDO NUMERO DE PALAVRAS*/
int NumPalavras(char txt[][MAX], int L){
    int i,j;
    int num=0;

    for(i=0; i<L; i++){
        for(j=0; txt[i][j]!='\0'; j++){
            if ((txt[i][j]==' ' && isalpha(txt[i][j+1])) || isalpha(txt[i][j]) && txt[i][j+1]=='\0')
                num++;
        }
    }
    return num;
}

/*DESCOBRINDO NUMERO DE LETRAS*/
int NumLetras (char txt[][MAX], int L){
    int i,j;
    int num=0;

    for(i=0; i<L; i++){
        for(j=0; txt[i][j]!='\0'; j++){
            if (isalpha(txt[i][j]))
                num++;
        }
    }
    return num;
}

int NumLinhaBranco (char txt[][MAX], int L) {
    int i,j,k;
    int aux[MAX];
    int num=0;

    for(i=0; i<L; i++) //Zera vetor auxiliar que sera preenchido com as quant de caracteres de cada linha do texto
        aux[i]=0;

    for(i=0; i<L; i++) {
        for(j=0; txt[i][j]!='\0'; j++){ //Preenche vetor aux com a quantidade de caracteres de cada linha
            aux[i]++;
        }
    }

    for(i=0; i<L; i++){
        k=0;
        for(j=0; txt[i][j]!='\0'; j++){
            if(isspace(txt[i][j]))
                k++;
        }

        if(aux[i]==k)
            num++;
    }

    return num;
}

