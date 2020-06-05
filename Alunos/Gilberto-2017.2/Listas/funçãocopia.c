#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct list {
	char ch;
	struct list *P;   	
};

typedef struct list Lista;

Lista *insere (Lista *,char);
void imprime (Lista *);
Lista *clona (Lista *);

int main(){
	
	Lista *L1 = NULL;
	int n,i;
	char vet[MAX];
	
	printf("Quantos caracteres deseja digitar? "); scanf("%d", &n); fflush(stdin);
	
	for (i=0;i < n;i++){
		printf("Caractere %d: ",i+1);
		scanf(" %c", &vet[i]);
		L1 = insere(L1,vet[i]);
	}
	
	imprime(L1); putchar('\n');
	imprime(clona(L1));
	
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

Lista *clona (Lista *L){
	
	Lista *novo,*aux = L, *ant = NULL;
	Lista *clone = (Lista *) malloc(sizeof(Lista));
	
	while (aux){
		novo = (Lista *) malloc(sizeof(Lista));
		novo->ch = aux->ch;
		novo->P = NULL;
		
		if (ant == NULL)
			clone = novo;
		else 
			ant->P = aux;
		
		ant = novo;
		aux = aux->P;
	}
	
	return clone;
}