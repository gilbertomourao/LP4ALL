#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50
//Colocar '*' na quantidade das letras de maior frequência
int main()
{
    char alfabeto[MAX],frase[MAX];
    int freq[MAX] = {0},maiores_freq[MAX] = {0};
    char c;
    int i,j,k,tam_frase,maior;

    printf("Informe uma frase:\n");
    gets(frase);

    //alfabeto
    c = 'a';
    for(i = 0; i < 26; i++)
    {
        alfabeto[i] = c;
        c++;
    }

    tam_frase = strlen(frase);

    //pegar a frequancia
    for(i = 0; i < 26;i++)
    {
        for(j = 0 ; j < tam_frase;j++)
        {
            if(alfabeto[i] == frase[j])
            {
                freq[i] += 1;
            }
        }
    }

    //Pegar a maior frequencia
    maior = freq[0];
    for(i = 0; i < 26;i++)
    {
       if(freq[i] > maior)
       {
           maior = freq[i];
       }
    }

    //Armazenar as maiores frequencias em um vetor, em suas respectivas posições
    for(i = 0; i < 26;i++)
    {
        if(freq[i] == maior)
        {
            maiores_freq[i] = maior;
        }
    }


    //Imprimir a nova string c
    for(i = 0; i < tam_frase;i++)
    {
        for(j = 0;j< 26; j++)
        {
            if(frase[i] == alfabeto[j])
            {
                if(maiores_freq[j])
                {
                    for(k = 1; k <= maiores_freq[j];k++)
                    {
                        printf("*");
                    }
                }else{
                        printf("%c",frase[i]);
                }
            }
        }

    }

    return 0;
}
