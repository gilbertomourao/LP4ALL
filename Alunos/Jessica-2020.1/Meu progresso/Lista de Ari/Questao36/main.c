#include <stdio.h>
#include <stdlib.h>
/*36.	Com o vetor do exercício 8, faça uma função que transfira as consoantes para um vetor
e as vogais para outro. Depois mostre cada um dos vetores.*/
#define MAX 100
int main()
{
    void SepararConsoantesVogais(char string[], char cons[], char vog[]);

    char frase[MAX];
    char consoantes[MAX];
    char vogais[MAX];

    printf("Entre com a frase:\n");
    gets(frase);

    SepararConsoantesVogais(frase, consoantes, vogais);

    printf("\n\n%s\n\n%s\n\n%s\n\n", frase,consoantes,vogais);
    return 0;
}

void SepararConsoantesVogais (char string[], char cons[], char vog[]){
    int i, j=0, k=0;
    for (i=0; string[i]!='\0'; i++){
        if (string[i]=='A'||string[i]=='E'||string[i]=='I'||string[i]=='O'||string[i]=='U'||string[i]=='a'||string[i]=='e'||string[i]=='i'||string[i]=='o'||string[i]=='u')
            vog[j++]=string[i];
        else if (string[i]!=' ')
            cons[k++]=string[i];
    }

    vog[j]='\0';
    cons[k]='\0';
}
