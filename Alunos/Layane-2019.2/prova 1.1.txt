#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main()
{
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char string[MAX];
    int vetorFreq[26];
    int i, j, auxInt, tamString;
    char auxChar;

    //preencher vetor frequencia com 0
    for(i = 0; i < 26; i++)
    {
        vetorFreq[i] = 0;
    }

    //ler string
    printf("Digite a string:\n");
    gets(string);
    fflush(stdin);
    //descobrir o tamanho da string
    tamString = strlen(string);

    //armazenar a frequencia do caracter no vetor frequencia
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < tamString; j++)
        {
            if(string[j] == alfabeto[i])
            {
                vetorFreq[i] += 1;
            }
        }
    }

    //ordenar decrescentemente o vetor frequencia e o vetor alfabeto de acordo com o de frequencia
    for(i = 0; i < 26; i++)
    {
        for(j = i; j < 26; j++)
        {
            if(vetorFreq[i] < vetorFreq[j])
            {
                auxInt = vetorFreq[i];
                vetorFreq[i] = vetorFreq[j];
                vetorFreq[j] = auxInt;

                auxChar = alfabeto[i];
                alfabeto[i] = alfabeto[j];
                alfabeto[j] = auxChar;
            }
        }
    }
    //imprimir string ordenada de acordo com a frequencia
    printf("\n");
    for(i = 0; i < 26; i++)
    {
        if(vetorFreq[i])
        {
            for(j = 0; j < vetorFreq[i]; j++)
            {
                printf("%c",alfabeto[i]);
            }
        }
    }

    //imprimir o caracter e sua frequencia
    printf("\n\nLetra\tFrequencia\n");
    for(i = 0; i < 26; i++)
    {
        if(vetorFreq[i])
        {
            printf("  %c\t    %d\n", alfabeto[i], vetorFreq[i]);
        }
    }
    return 0;
}
