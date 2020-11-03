#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main()
{
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char string[MAX];
    int vetorFreq[26], vetorMaior[MAX];
    int i, j, a, tamString, maiorFreq;


    //preencher vetores com 0
    for(i = 0; i < 26; i++)
    {
        vetorFreq[i] = 0;
        vetorMaior[i] = 0;
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
    //procura maior frequencia
    maiorFreq = vetorFreq[0];
    for(i = 0; i < 26; i++)
    {
        if(vetorFreq[i] >= maiorFreq)
        {
            maiorFreq = vetorFreq[i];
        }
    }
    //armazenando as maiores frequencias em outro vetor
    for(i = 0; i < 26; i++)
    {
        if(vetorFreq[i] == maiorFreq)
        {
            vetorMaior[i] = vetorFreq[i];
        }
    }
    //imprimindo a nova string
    for(a = 0; a < tamString; a++)
    {
        for(i = 0; i < 26; i++)
        {
            if(alfabeto[i] == string[a])
            {
                if(vetorMaior[i])
                {
                    for(j = 0; j < maiorFreq; j++)
                    {
                        printf("*");
                    }
                }
                else
                {
                    printf("%c", string[a]);
                }
            }
            if(string[a] == ' ')
            {
                printf(" ");
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
