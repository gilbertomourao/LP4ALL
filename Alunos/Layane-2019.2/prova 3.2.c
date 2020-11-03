#include <stdio.h>
#include <stdlib.h>

struct lista
{
    char tecla;
    struct lista *prox;
};
typedef struct lista list;

list *inserir(list *add, char info)
{
    list *new_add;

    new_add = (list *)malloc(sizeof(list));
    new_add->tecla = info;
    new_add->prox = add;

    return new_add;
}

list *ordenar (list *add)
{
    list *ant = NULL, *aux = NULL;
    char x;
    aux = add;

    while(aux != NULL)
    {
        ant = add;
        while(ant != NULL)
        {
            if(aux->tecla > ant->tecla)
            {
                x = aux->tecla;
                aux->tecla = ant->tecla;
                ant->tecla = x;
            }
            ant = ant->prox;
        }
        aux = aux->prox;
    }
    return add;
}

list *minuscula(list *add)
{
    list *aux = add, *new_add = NULL;

    while(aux != NULL)
    {
        if(aux->tecla >= 'a' && aux->tecla <='z')
            new_add = inserir(new_add, aux->tecla);
        aux = aux->prox;
    }
    return new_add;
}

void imprimir(list *add)
{
    list *aux;
    aux = add;

    while(aux != NULL)
    {
        printf("%c", aux->tecla);
        aux = aux->prox;
    }
}

int main()
{
    list *add = NULL;
    char caractere;

    printf("Digite a sequencia: (digite $ para finalizar a sequencia)\n");
    while(caractere != '$')
    {
        scanf("%c", &caractere);
        fflush(stdin);
        if(caractere != '$')
            add = inserir(add, caractere);
    }
    add = ordenar(add);
    add = minuscula(add);
    printf("\nSaida:\n\t");
    imprimir(add);
    printf("\n");

    return 0;
}
