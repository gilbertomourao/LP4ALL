#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50
//Ordenar letra ´por frequência
int main()
{
    char alfabeto[MAX],frase[MAX],aux_letras[MAX];
    int freq[MAX] = {0}, aux_freq[MAX]= {0};
    char c,auxC;
    int i,j,a,tam_frase,quant_letras = 0,aux,cont;

    printf("Informe uma frase:\n");
    gets(frase);

    c = 'a';
    for(i = 0; i < 26; i++)
    {
        alfabeto[i] = c;
        c++;
    }

    tam_frase = strlen(frase);

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

    //Passando a frquecia e as letras para vetores menores;
    a = 0;
    for(i = 0; i < 26; i++)
    {
       if(freq[i] != 0)
       {
           aux_freq[a] = freq[i];
           aux_letras[a] = alfabeto[i];
           quant_letras++;// para saber a quantidade de letras na hora de ordenar;
           a++;
       }
    }

    //ordenar as letras pela frequencia
    for(i = 0 ; i < quant_letras;i++)
    {
        for(j = i; j < quant_letras ; j++)
        {
            if(aux_freq[j] > aux_freq[i])
            {
                auxC = aux_letras[j];
                aux_letras[j] = aux_letras[i];
                aux_letras[i] = auxC;

                //Ordenando o numero da frequencia;
                aux = aux_freq[j];
                aux_freq[j] = aux_freq[i];
                aux_freq[i] = aux;

            }
        }
    }

    printf("\n");

    for(i = 0; i < quant_letras; i++)
    {
        cont = aux_freq[i];
        for( j = 0; j < cont ; j++)
        {
            printf("%c ",aux_letras[i]);
        }
    }


    return 0;
}
