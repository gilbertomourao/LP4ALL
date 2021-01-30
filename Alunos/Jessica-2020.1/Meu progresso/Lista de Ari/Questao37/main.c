#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*37.	Escreva um programa que utilize uma função "replace" que aceita um string como parâmetro e
retorna um inteiro. A função substitui todos os espaços do seu parâmetro pelo caracter '-', e retorna o
número de substituições feitas. O programa que a usa deverá testar a sua funcionalidade.*/
#define MAX 100
int main()
{
    int Replace (char str[]);
    int ReplaceAll (char str[], char a, char b);

    char frase[MAX];
    char procurado, substituto;
    int i,j=0;
    int subst1,subst2;

    printf("Insira a string:  ");
    gets(frase);
    subst1=Replace(frase);
    printf("\n\nA quantidade de susbstituicoes feitas foi %i.\n\n%s\n\n\n", subst1, frase);

    printf("***Substitua um caractere na string por outro***\n\n");
    printf("Insira um caractere contido em frase: ");
    scanf(" %c", &procurado);
    while(1){ //Controlar se o caractere inserido pertence a frase
        for(i=0; frase[i]!='\0'; i++){
            if(frase[i]==procurado)
                j++;
        }
        if(j>0)
            break;
        else{
            printf("\n\nInsira um caractere CONTIDO em frase: ");
            scanf(" %c", &procurado);
        }
    }
    printf("Insira o caractere de substituição na frase: ");
    scanf(" %c", &substituto);

    subst2=ReplaceAll(frase, procurado, substituto);

    printf("\n\nA quantidade de susbstituicoes feitas foi %i.\n\n%s\n\n\n", subst2, frase);

    return 0;
}

int Replace (char str[]){
    int i,quant=0;

    for(i=0; str[i]!='\0'; i++){
        if(str[i]==' '){
            str[i]='-';
            quant++;
        }
    }
    return quant;
}

/*SUBSTITUIR UM CARACTERE ESPECIFICO POR OUTRO NUMA STRING*/
int ReplaceAll (char str[], char a, char b){
    int i,quant=0;

    for (i=0; str[i]!='\0'; i++) {
        if(str[i]==a){
            str[i]=b;
            quant++;
        }
    }
    return quant;
}
