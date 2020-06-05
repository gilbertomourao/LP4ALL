#include <stdio.h> 
#include <stdlib.h>

struct list {
	int info;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,int);
void imprime (Lista *);
Lista *retira (Lista *);

int main(){

	Lista *L = NULL;
	int sim = 1, num;
	
	while (sim){
		printf("Insira um elemento na lista: "); scanf("%d", &num); fflush(stdin);
		L = insere (L,num);
		printf("Deseja parar? [0 PARA SIM, OUTRO PARA NAO]"); scanf("%d", &sim); fflush(stdin);
	}
	
	printf("Lista Atual: ");imprime(L); putchar('\n');
	L = retira(L);
	printf("Lista ALterada: "); imprime(L);
		
	return 0;
}

Lista *insere (Lista *L,int i){

	Lista *novo;
	
	novo = (Lista *) malloc(sizeof(Lista));
	
	if (novo == NULL)
		exit(0);	
	
	novo->info = i;
	novo->P = L;
	
	return novo;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%d ", aux->info);
		aux = aux->P;
	}
	
}

Lista *retira (Lista *L){
	
	Lista *ant = NULL;
	Lista *aux, *ref = L;

	while (ref != NULL){
		aux = ref;	
		while (aux != NULL && aux->info%2 != 0){
			ant = aux;
			aux = aux->P;
		}
		
		if (aux == NULL)
			return L;
		if (ant == NULL){
			L = aux->P;
			return L;
		}
		else 
			ant->P = aux->P;
		free(aux);
		ref = ant->P;
	}
	
	return L;
}