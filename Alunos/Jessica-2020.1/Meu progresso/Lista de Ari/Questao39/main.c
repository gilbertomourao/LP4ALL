#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*39.	Fazer um programa que receba uma string de no máximo 20 caracteres do usuário e
mostre o conteúdo desta string de forma invertida.*/
#define MAX 20
int main()
{
    char string[MAX];
    char string_inv[MAX];
    int i,j=0;

    printf("Insira uma string:  ");
    gets(string);

    for(i=strlen(string)-1; i>=0; i--){
        string_inv[j++]=string[i];
    }
    string_inv[j]='\0';

    printf("\n%s\n\n\n%s", string_inv,string);

    return 0;
}
