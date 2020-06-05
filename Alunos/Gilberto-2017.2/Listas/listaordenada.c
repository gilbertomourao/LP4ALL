/*Ordenar Lista*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct list {
	char ch;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,char);
void imprime (Lista *);
Lista *ordena (Lista *);

int main(){
	
	Lista *L1 = NULL;
	int n,i = 0;
	char ch;
	
	printf("Quantos elementos sua lista devera ter? "); scanf("%d", &n); fflush(stdin);
	
	while (n){
		printf("Elemento %d: ",i); ch = getchar(); fflush(stdin);
		L1 = insere(L1,ch);
		i++;n--;	
	}
	system("cls");
	printf("Lista: "); imprime(L1); putchar('\n');
	L1 = ordena(L1);
	printf("Lista ordenada: "); imprime(L1);
	
	free(L1);
	
	return 0;
}

Lista *insere (Lista *L,char i){

	Lista *novo;
	
	novo = (Lista *) malloc(sizeof(Lista));
	
	if (novo == NULL)
		exit(0);
	
	novo->ch = i;
	novo->P = L;
	
	return novo;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%c ", aux->ch);
		aux = aux->P;
	}
}

Lista *ordena (Lista *L){

	Lista *aux = L, *prox = NULL;
	char ch; /*Falta-me um pouco de criatividade (e aulas de português) T-T */	
	
	while (aux){
		prox = aux->P;
		while (prox){
			if (tolower(aux->ch) > tolower(prox->ch)){
				ch = aux->ch;
				aux->ch = prox->ch;
				prox->ch = ch;
			}
			prox = prox->P;
		}
		aux = aux->P;
	}
	
	return L;
}