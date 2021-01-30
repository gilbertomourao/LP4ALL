// ANABANANA --> OBOO
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void ReadLetters(char *string);
void RecebeStrings(char *str1, char *str2, char *str3);
void Substtitui(char*phrase, char *word, char *replace, char *answer, int *casos);
bool String_Ana(char *string);

int main()
{
    char frase[MAX], palavra[MAX], substituto[MAX], resposta[MAX];
    int eventos;

    RecebeStrings(frase, palavra, substituto);

    Substtitui(frase,palavra,substituto,resposta,&eventos);

    if (eventos>0) {
        printf("\n\n---------- NOVA FRASE ----------");
        printf("\n\n%s\n\n", resposta);
	}
    return 0;
}

void RecebeStrings(char *str1, char *str2, char *str3) {
    printf("Insira a frase: ");
    fflush(stdin);
    ReadLetters(str1);
    putchar('\n');
    printf("Insira a palavra: ");
    fflush(stdin);
    ReadLetters(str2);
    putchar('\n');
    printf("Insira a o item de substitui%c%co: ", 135, 198);
    fflush(stdin);
    ReadLetters(str3);
    putchar('\n');
}

/* FUNÇÃO QUE LÊ STRINGS */
void ReadLetters(char *string) {
    char ch; //Capta cada caractere digitado
    char digitado[MAX]; //Junta todos as letras digitadas
    int i=0, j;
    do {
        fflush(stdin); //Limpa o buffer
        ch = getch(); //Captura o caractere digitado pelo usuario;
        if ( (isalpha(ch) || ch == ' ') && i<MAX) { // Se for uma letra ou espaço
            digitado[i]=ch; //É direcionado para string de letras
            i++; //Passa para proxima posição
            printf("%c", ch); //Exibe letra ou espaço digitado na tela
        } else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
            i--;
            digitado[i] = '\0';
            printf("\b \b"); //Apaga o caractere anterior
        }
    } while(ch != 13); // Quando o ENTER for digitado, termina o loop
    digitado[i] = '\0'; //Finaliza a string
    for(j=0; digitado[j]!='\0'; j++){
        string[j]= digitado[j];
    }
    string[j] = '\0';
}

void Substtitui(char*phrase, char *word, char *replace, char *answer, int *casos) {
    int i, j, a, k=0, confirma, alarme=0;

    if( strlen(word) > strlen(phrase) )
       printf("\n\nSitua%c%co inv%clida, pois a palavra procurada %c maior que a p%cpria frase\n\n", 135, 198, 160, 130,162);
    else {
        /*Localizando a palavra na frase*/
        for (i=0; phrase[i]!='\0'; i++) { //Percorre toda string - laço principal
            if ( tolower(phrase[i]) == tolower(word[0]) ) { // Primeiro caractere igual
                confirma=1; // Verifica se procurada ocorre em string
                for (j=0, a=i; word[j]!='\0' && phrase[a]!='\0'; j++, a++) //Confirma a exist. da palavra na frase
                    if ( tolower(phrase[a]) != tolower(word[j]) ) {
                        confirma=0;
                        break;
                    }
                if (confirma && word[j]=='\0') { //Se procurada for achada
                    ++(*casos);
                    for(j=0; replace[j]!='\0'; j++)
                        answer[k++]=replace[j];
                    if (String_Ana(word)) {
                        i = a - 2;
                        alarme=1;
                    } else
                        i = a - 1;

                } else {
                    if(alarme && (word[j]!='\0') ) { //anABanana
                        ++i; // Passa posição pra proxima iteração/procura
                        answer[k++]=phrase[i];
                        alarme=0;

                    } else
                        answer[k++]=phrase[i];
                }
            } else
                answer[k++]=phrase[i];
        }
        answer[k]='\0'; // Finaliza string com a resposta/substituições
    }
}

//---------VERIFICA SE PRIMEIRA LETRA É IGUAL A ULTIMA NUMA STRING
bool String_Ana (char *string) {
    if (string[0]==string[strlen(string)-1])
        return true;
    else
        return false;
}
