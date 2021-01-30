#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*40.	Faça um programa que receba uma string do usuário (máx. 20 caracteres) e um caracter qualquer.
O programa deve remover todas as ocorrências do caracter da string e mostrar o resultado.*/
#define MAX 20
int main()
{
    char frase[MAX];
    char c;
    int i,j=0;
    int tam=0, ocorrencia=0;

    printf("Insira a string:  ");
    gets(frase);
    printf("\n\n");

    printf("***Remova um caractere na string***\n\n");
    printf("Insira um caractere que esteja contido em frase: ");
    scanf(" %c", &c);
    while(1){ //Controlar se o caractere inserido pertence a frase
        for(i=0; frase[i]!='\0'; i++){
            if(frase[i]==c)
                j++;
        }
        if(j>0)
            break;
        else{
            printf("\n\nO caractere inserido nao se encontra na frase, tente novamente.\nInsira um caractere que esteja contido em frase: ");
            scanf(" %c", &c);
        }
    }

    tam=strlen(frase);

    for(i=0; frase[i]!='\0'; i++) {
        if(frase[i]==c) {
            ocorrencia++;
            for(j=i; j<tam; j++) {
                frase[j]=frase[j+1];
            }
            i--; //caso tenham casos seguidas do caractere, ex: jessica caractere: s
        }
    }
    frase[tam-ocorrencia]='\0'; //Relocaliza o limitador da string
    printf("\n\n");

    printf("%s", frase);
    return 0;
}
