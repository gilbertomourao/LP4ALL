#include <stdio.h>
#include <stdlib.h>

struct lista
{
    char num;
    struct lista *prox;
};
typedef struct lista list;

list *inserir(list *add, char info)
{
    list *new_add;

    new_add = (list *)malloc(sizeof(list));
    new_add->num = info;
    //printf("%c", new_add->num);
    new_add->prox = add;

    return new_add;
}
void histograma (list *add, int frequencia[], char numeros[])
{
    char v[100];
    int i,j,lim;
    list *aux = add;

    i = 0;
    while(aux != NULL)
    {
        v[i] = aux->num;
        //printf("%c", aux->num);
        //printf("%c.", v[i]);
        i++;
        aux = aux->prox;
    }
    lim = i;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < lim; j++)
        {
            if(v[j] == numeros[i])
                frequencia[i] += 1;
        }
    }
}

void imprimirHistograma(int frequencia[], char numeros[])
{
    int i;

    printf("\n");
    for(i = 0; i < 10; i++)
        if(frequencia[i] != 0)
            printf("%c  -  %d\n", numeros[i], frequencia[i]);
}
void ordenarFreq (int frequencia[], char numeros[])
{
    int i, j;
    char auxC, auxI;

    for(i = 0; i < 10; i++)
    {
        for(j = i; j < 10; j++)
        {
            if(frequencia[i] < frequencia[j])
            {
                auxI = frequencia[i];
                frequencia[i] = frequencia[j];
                frequencia[j] = auxI;

                auxC = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = auxC;
            }
        }
    }
}
list *voltarLista(list *add, int frequencia[], char numeros[])
{
    //list *aux = add;
    int i;

    for(i = 0; i < 10; i++)
    {
        if(frequencia[i])
        {
            add = inserir(add, numeros[i]);
            //printf("%c", add->num);
        }
    }
    return add;
}
void imprimir(list *add)
{
    list *aux;
    aux = add;

    while(aux != NULL)
    {
        printf("%c", aux->num);
        aux = aux->prox;
    }
}

list *inverter(list *add, list *in_add)
{
    list *aux;
    aux = add;
    while(aux != NULL)
    {
        in_add = inserir(in_add, aux->num);
        aux = aux->prox;
    }
    return in_add;
}

int main()
{
    int frequencia[10] = {0};
    char numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    list *add = NULL, *Fadd = NULL, *in_add = NULL;
    char numero;

    printf("Digite a sequencia: (digite $ para finalizar a sequencia)\n");
    while(numero != '$')
    {
        scanf("%c", &numero);
        fflush(stdin);
        if(numero != '$')
            add = inserir(add, numero);
    }
    in_add = inverter(add, in_add);
    imprimir(in_add);
    histograma(add, frequencia, numeros);
    imprimirHistograma(frequencia, numeros);

    ordenarFreq(frequencia, numeros);
    Fadd = voltarLista(Fadd, frequencia, numeros);

    in_add = NULL;
    in_add = inverter(Fadd, in_add);
    imprimir(in_add);

    return 0;
}
