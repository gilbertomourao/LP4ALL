#include <stdio.h> 
#include <stdlib.h>

struct list {
	int info;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,int);
Lista *concatena (Lista *,Lista *);
void imprime (Lista *);

int main(){

	Lista *L1 = NULL, *L2 = NULL;
	int sim = 1, num;
	
	while (sim){
		printf("Insira um elemento na lista 1: "); scanf("%d", &num); fflush(stdin);
		L1 = insere (L1,num);
		printf("Deseja parar? [0 PARA SIM, OUTRO PARA NAO]"); scanf("%d", &sim); fflush(stdin);
	}
	
	system("cls");
	
	sim = 1;
	while (sim){
		printf("Insira um elemento na lista 2: "); scanf("%d", &num); fflush(stdin);
		L2 = insere (L2,num);
		printf("Deseja parar? [0 PARA SIM, OUTRO PARA NAO]"); scanf("%d", &sim); fflush(stdin);
	}
	
	system("cls");
	
	imprime (concatena(L1,L2));
	
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

Lista *concatena (Lista *L1,Lista *L2){
	
	Lista *aux = L1,*aux2 = L2, *ant = NULL;
	
	while (aux != NULL){
			ant = aux;
			aux = aux->P;
	}
	
	ant->P = aux2;
	
	return L1;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%d ", aux->info);
		aux = aux->P;
	}
}