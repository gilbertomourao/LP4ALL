#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void prencher_vetor(char tabela[],int freq[])
{
    int i;
    for(i = 0;i <MAX;i++,tabela++,freq++)
    {
        *tabela = i;
        *freq = 0;
    }
}
void histograma(char str[],char tabela[],int freq[],int tam)
{
    int i,j;
    char *aux_str;
    for(i = 0; i < MAX;i++,tabela++,freq++)
    {
        aux_str = str;
        for(j = 0; j <tam;j++,aux_str++)
        {
            if(*aux_str == *tabela)
            {
                *freq+=1;
            }
        }
    }
}

void imprimir_histograma(char tabela[],int freq[],char hist[])
{
    int i;
    char x;

    for(i = 0; i <MAX; i++,tabela++,freq++)
    {
        if(*freq != 0)
        {
            *hist = *tabela;
            hist++;
            x = *freq + '0';
            *hist = x;
            hist++;
            //printf("%c%c \n",*tabela,*freq + '0');
        }
    }
    *hist = '\0';
}


void criar_seq(char hist[],char new_vetor[],int tam)
{
    int i,j,x;
    char *aux1 = hist;
    char *aux2 = &hist[1];
    //tam = (tam / 2) ;
    for(i = 0; i < tam;i++)
    {
        if(*aux2 != 0)
        {
            x = *aux2 - '0';
            for(j = 0; j < x;j++,new_vetor++)
            {
                //printf("%c",*aux1);
                *new_vetor = *aux1;
            }
            aux1+=2;
        }
        aux2+=2;
    }
    *new_vetor = '\0';

}


int main()
{
    char str[MAX],tabela[MAX],new_str[MAX],hist[MAX];
    int freq[MAX],tam_str;

    printf("Informe a string:\n");
    gets(str);
    tam_str = strlen(str);
    prencher_vetor(tabela,freq);
    histograma(str,tabela,freq,tam_str);
    imprimir_histograma(tabela,freq,hist);
    puts(hist);
    printf("\n");

    criar_seq(hist,new_str,tam_str);
    puts(new_str);

    return 0;
}
