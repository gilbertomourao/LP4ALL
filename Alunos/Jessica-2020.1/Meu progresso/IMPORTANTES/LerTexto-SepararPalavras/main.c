#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100

/*Funções usadas no texto*/
int CaracteresTexto(char c);

int ReadLetters(char txt[][MAX]); // Função que lê o texto
int NumPalavras(char txt[][MAX], int L); //Função que conta a quantidade de palavras do texto
int SepararPalavras (char txt[][MAX], char pal[][MAX], int L); //Função que separa palavras do texto
int NumLetras (char txt[][MAX], int L); //Função que conta a quantidade de letras do texto
int NumLinhaBranco (char txt[][MAX], int L); //Função que conta a quantidade de linhas em branco do texto



int main()
{
    char texto[MAX][MAX];
    char palavras[MAX][MAX];
    int linhas; //Quantidade de linhas do texto
    int i,j;
    int palavras, linhas_branco, letras;

    printf("Escreva seu texto abaixo, para finalizar use CTRL-D ou CTRL-Z.\n");
    printf("--------------------------------------------------------------\n");
    linhas = ReadLetters(texto);
    printf("\n--------------------------------------------------------------\n");
    system("pause");
    system("CLS");

    /*Exibindo o texto lido*/
    printf("\t\tTEXTO INSERIDO\n");
    printf("----------------------------------------------------\n");
    for(i=0; i<linhas; i++)
        printf("%s\n", texto[i]);
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

    /*Separar as palavras*/
   /* j=SepararPalavras(texto,TodasPalavras,linhas);

    printf("As palavras do texto:\n\n");
    for(i=0; i<j; i++)
            printf("%s\n", TodasPalavras[i]);*/

    return 0;
}

/* LER UM TEXTO*/
int ReadLetters(char txt[][MAX]) {
    char ch; //Capta cada caractere digitado
    int i=0, j=0;

    while(1) {

        fflush(stdin); //Limpa o buffer
        ch = getch(); //Captura o caractere digitado pelo usuario;

        if ( (isalpha(ch) || ch==' ' || CaracteresTexto(ch)) && (i<MAX && j<MAX) ) {
            txt[i][j]=ch; //É direcionado para string de letras
            j++; //Passa para proxima posição
            printf("%c", ch); //Exibe letra ou espaço digitado na tela

        } else if (ch==8 && j) { //Se o Blackspace for digitado e tiver caractere para apagar
            j--;
            txt[i][j]='\0';
            printf("\b \b"); //Apaga o caractere anterior

        } else if ( ch == 13 ) { // Quando o ENTER for digitado, muda a linha
            txt[i][j]='\0';
            i++;
            j=0;
            printf("\n");

        } else if (ch==4 || ch==26) { // Quando Ctrl D ou Ctrl Z for digitado, finaliza laço
            txt[i][j]='\0';
            break;
        }
    }

    return i+1;
}

/*DESCOBRINDO NUMERO DE PALAVRAS*/
int NumPalavras(char txt[][MAX], int L) {
    int i,j;
    int num=0;

    for(i=0; i<L; i++)
        for(j=0; txt[i][j]!='\0'; j++) {

            if ( isalpha(txt[i][j]) && txt[i][j+1]=='\0' ) { //Jessica\0
                num++;
            } else if ( isalpha(txt[i][j]) && isspace(txt[i][j+1]) ) { //Jessica\0 || Jessica_linda

                do { j++;
                } while (isspace(txt[i][j]));

                if ( isalpha(txt[i][j]) || txt[i][j]=='\0' || CaracteresTexto(txt[i][j]) )
                    num++;

            } else if ( isalpha(txt[i][j]) && CaracteresTexto(txt[i][j+1]) ) {

                do j++;
                while (CaracteresTexto(txt[i][j]));

                while(isspace(txt[i][j])) j++;

                if ( isalpha(txt[i][j]) || txt[i][j]=='\0' || CaracteresTexto(txt[i][j]) )
                    num++;
            }

        }

    return num;
}

/*SEPARANDO AS PALAVRAS*/
int SepararPalavras (char txt[][MAX], char pal[][MAX], int L) {
    int i, j;
    int m=0, n=0;
    int num=0;

    for(i=0; i<L; i++)
        for(j=0; txt[i][j]!='\0'; j++) {

            if ( isalpha(txt[i][j]) || txt[i][j]=='-')
                pal[m][n++]=txt[i][j];

            else if ( (isalpha(txt[i][j-1])||CaracteresTexto(txt[i][j-1]) ) && isspace(txt[i][j]) ) {
                pal[m][n]='\0';
                n=0;
                m++;
            } else if (txt[i][j]=='\0') {
                pal[m][n]='\0';
                m++;
            }



                if ( isalpha(txt[i][j]) || txt[i][j]=='\0' || CaracteresTexto(txt[i][j]) )
                    num++;

            } else if ( isalpha(txt[i][j]) && CaracteresTexto(txt[i][j+1]) ) {

                do j++;
                while (CaracteresTexto(txt[i][j]));

                while(isspace(txt[i][j])) j++;

                if ( isalpha(txt[i][j]) || txt[i][j]=='\0' || CaracteresTexto(txt[i][j]) )
                    num++;
            }

        }

    return num;



}

/*VERIFICAR TODOS CARACTERES POSSIVEIS NUM TEXTO*/
int CaracteresTexto(char c) {
    if ( c==',' || c =='!' || c=='-' || c==':' || c==';' || c=='?'|| c=='.') {
        return 1;
    } else
        return 0;
}

/*DESCOBRINDO NUMERO DE LETRAS*/
int NumLetras (char txt[][MAX], int L){
    int i,j;
    int num=0;

    for(i=0; i<L; i++)
        for(j=0; txt[i][j]!='\0'; j++) {
            if (isalpha(txt[i][j]))
                num++;
        }
    return num;
}

int NumLinhaBranco (char txt[][MAX], int L) {
    int i,j,k;
    int aux[MAX];
    int num=0;

    for(i=0; i<L; i++) //Zera vetor auxiliar que sera preenchido com as quant de caracteres de cada linha do texto
        aux[i]=0;

    for(i=0; i<L; i++)
        for(j=0; txt[i][j]!='\0'; j++)//Preenche vetor aux com a quantidade de caracteres de cada linha
            aux[i]++;

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

