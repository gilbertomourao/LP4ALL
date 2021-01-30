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
void Substitui(char*phrase, char *word, char *replace, char *answer, int *casos);

bool String_Ana(char *string);
bool Ocorre_Str_Str (char *string1, char *string2, int *p1, int *p2);

int main()
{
    char frase[MAX], palavra[MAX], substituto[MAX], resposta[MAX];
    int eventos;

    RecebeStrings(frase, palavra, substituto);

    Substitui(frase,palavra,substituto,resposta,&eventos);

    if (eventos>0) {
        printf("\n\n---------- NOVA FRASE ----------");
        printf("\n\n%s\n\n", resposta);
	}
    return 0;
}

void RecebeStrings(char *str1, char *str2, char *str3) {
    printf("Insira a frase: ");
    fflush(stdin);
    gets(str1);
    putchar('\n');
    printf("Insira a palavra: ");
    fflush(stdin);
    gets(str2);
    putchar('\n');
    printf("Insira a o item de substitui%c%co: ", 135, 198);
    fflush(stdin);
    gets(str3);
    putchar('\n');
}

//--------- REALIZA AS SUBSTITUIÇÕES
void Substitui(char *phrase, char *word, char *replace, char *answer, int *casos) {
    int i, j, k=0, alarme=0;

    if( strlen(word) > strlen(phrase) )
       printf("\n\nSitua%c%co inv%clida, pois a palavra procurada %c maior que a p%cpria frase\n\n", 135, 198, 160, 130,162);
    else {
        /*Localizando a palavra na frase*/
        for (i=0; phrase[i]!='\0'; i++) { //Percorre toda string - laço principal
            if ( tolower(phrase[i]) == tolower(word[0]) ) { // Primeiro caractere igual
                if ( Ocorre_Str_Str(phrase, word, &i, &j) ) { //Se procurada for achada
                    ++(*casos);
                    for(j=0; replace[j]!='\0'; j++)
                        answer[k++]=replace[j];
                    if ( String_Ana(word) ) {
                        i = i - 2;
                        alarme=1;
                    } else
                        i = i - 1;
                } else {
                    if (alarme && (word[j]!='\0') ) { //anABananA - j mudado na função Ocorre_Str_Str
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

//---------VERIFICA SE STRING OCORRE EM OUTRA STRING
bool Ocorre_Str_Str (char *string1, char *string2, int *p1, int *p2) {
    bool confirma;
    int m,n;
    confirma=true;
    for (m=0, n=*p1; string1[n]!='\0' && string2[m]!='\0'; m++, n++) // Confirma se existe a palavra na frase
        if ( tolower(string1[n]) != tolower(string2[m]) ) {
            confirma=false;
            break;
        }
    if (confirma && string2[m]=='\0') { // Se procurada for achada
        (*p1)=n; // Quado palavra achada, indica posição da frase que palavra termina
        return true;
    } else {
        (*p2)=m; // Quando palavra ñ achada, indica posição de palavra que o loop parou
        return false;
    }
}

