#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct list
{
	int info;
	struct list *p;
};
typedef struct list Lista;


Lista *inserir(Lista *L, int i)
{
	Lista *novo;
	novo = (Lista *) malloc(sizeof(Lista));
	if(novo == NULL)
	{
		exit(0);
	}
	novo->info = i;
	novo->p = L;
	return novo;
}

void imprimir(Lista *L)
{
	Lista *aux = L;
	while(aux != NULL)
	{
		printf(" %i\n", aux->info);
		aux = aux->p;
	}
}

void comparar(Lista *L1, Lista *L2, int *quant_f)
{
	Lista *aux3;
	Lista *aux1;
	Lista *aux2;
	int verdade;
	for(aux1 = L1; aux1 != NULL; aux1 = aux1->p)
	{
		if(aux1->info == L2->info)
		{
			verdade = 0;
			for(aux2 = L2, aux3 = aux1; aux2 != NULL; aux2 = aux2->p, aux3 = aux3->p)
			{
				if((aux2->info != aux3->info) || (aux3 == NULL))
				{
					verdade = 0;
					break;
				}
				else
					verdade = 1;
			}
			if(verdade == 1)
				*quant_f = *quant_f + 1;
		}
	}
}

int main()

{
	Lista *l1 = NULL;
	Lista *l2 = NULL;
	int i, num1, num2, x, y = 0;

	puts("Digite o numero de inteiros que vc deseja inserir na Lista 1:");
	scanf(" %i", &num1);
	fflush(stdin);

	for(i = 0; i < num1; i++)
	{
		printf("Insira o elemento da lista 1 %i:\n", i + 1);
		scanf(" %i", &x);
		fflush(stdin);
		l1 = inserir(l1, x);
	}
	imprimir(l1);
	puts("Digite o numero de inteiros que vc deseja inserir na Lista 2:");
	scanf(" %i", &num2);
	fflush(stdin);

	for(i = 0; i < num2; i++)
	{
		printf("Insira o elemento da lista 2 %i:\n", i + 1);
		scanf(" %i", &x);
		fflush(stdin);
		l2 = inserir(l2, x);
	}
	imprimir(l2);
	comparar(l1, l2, &y);

	puts("----------------------------");
	imprimir(l1);
	printf("\nA lista2 aparece %i vezes!", y);
	return 0;
}
