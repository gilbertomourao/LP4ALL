#include <stdio.h>
#include <string.h>
#define MAX 200
#define NUM 10

void histograma(char entrada[], int frequencia[], char numeros[])
{
    char *num = numeros, *ent = entrada;
    int *freq = frequencia;

    while(*num)
    {
        ent = entrada;
        while(*ent)
        {
            if(*ent == *num)
            {
                *freq +=1;
            }
            ent++;
        }
        freq++;
        num++;
    }
}
void ordenar (int frequencia[], int numeros[])
{
    int *freq1 = frequencia, *freq2 = frequencia;
    int *num1 = numeros, *num2 = numeros, aux2;
    int aux1, i, j;

    for(i = 0; i < 10; i++)
    {
        freq2 = frequencia;
        num2 = numeros;
        for(j = 0; j < 10; j++)
        {
            if(*freq1 < *freq2)
            {
                aux1 = *freq1;
                *freq1 = *freq2;
                *freq2 = aux1;

                aux2 = *num1;
                *num1 = *num2;
                *num2 = aux2;
            }
            freq2++;
            num2++;
        }
        freq1++;
        num1++;
    }
}
void sequencial(int frequencia[], int seq, int numeros[], char vetorResult[])
{
    int *freq = frequencia, *num = numeros;
    char *vetor = vetorResult, x, i;

    for(i = 0; i < (10 - seq); i++)
    {
        if(*freq != 0)
        {
            x = *num + 48;
            *vetor = x;
            vetor++;
        }
        freq++;
        num++;
    }
}
void imprimirResultado( char vetor[], char entrada[])
{
    char *v = vetor, *ent = entrada;
    while(*ent)
    {
        v = vetor;
        while(*v)
        {
            if(*v == *ent)
                printf("%c", *ent);
            v++;
        }
        ent++;
    }
}
int main()
{
    char numerosChar[11] = {'0','1','2','3','4','5','6','7','8','9','\0'};
    int numerosInt[10] = {0,1,2,3,4,5,6,7,8,9};
    char entrada[MAX], saida[MAX];
    int frequencia[NUM] = {0};
    int seq;

    printf("Digite a sequencia:\n");
    gets(entrada);
    histograma(entrada, frequencia, numerosChar);
    ordenar (frequencia, numerosInt);

    printf("\nQuantas sequencias serao retiradas?\t");
    scanf("%d", &seq);

    sequencial(frequencia,seq,numerosInt,saida);
    printf("\n");
    imprimirResultado(saida, entrada);

    return 0;
}
