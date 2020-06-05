/*Função existe*/

#include <stdio.h>
#include <stdlib.h>

struct list {
	int info;
	struct list *P;  	
};

typedef struct list Lista;

/****Funções****/
Lista *insere (Lista *,int);
void imprime (Lista *);
int existe (Lista *,int);
Lista *intersection (Lista *,Lista *);
/***************/

int main(){
	
	Lista *L1 = NULL, *L2 = NULL, *L3 = NULL;
	int n,i,j=0;
	
	printf("Quantos numeros deseja inserir na sua primeira lista? "); scanf("%d", &n); fflush(stdin);
	
	while (j<n){
		printf("Elemento %d: ",j+1); scanf("%d", &i); fflush(stdin);
		L1 = insere(L1,i);
		j++;
	}
	system("cls");
	
	printf("Quantos numeros deseja inserir na sua segunda lista? "); scanf("%d", &n); fflush(stdin);
	
	j = 0;
	while (j<n){
		printf("Elemento %d: ",j+1); scanf("%d", &i); fflush(stdin);
		L2 = insere(L2,i);
		j++;
	}
	system("cls");
	
	printf("Primeira Lista: "); imprime(L1); putchar('\n');
	printf("Segunda Lista: "); imprime(L2); putchar('\n');
	L3 = intersection(L1,L2);
	printf("Interseccao: "); imprime(L3);
	
	free(L1); free(L2); free(L3);
	
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

int existe (Lista *L,int i){

	Lista *aux = L;
	
	while (aux){
		if (aux->info == i)
			return 1;
		aux = aux->P;
	}
	
	return 0;	
}

Lista *intersection (Lista *L1,Lista *L2){
	
	Lista *aux1 = L1, *aux2,*novo = NULL;
	
	while (aux1){
		aux2 = L2;
		while (aux2){
			if (aux1->info == aux2->info && !existe(novo,aux1->info))
				novo = insere(novo,aux1->info);
			aux2 = aux2->P;
		}
		aux1 = aux1->P;
	}
	
	return novo;
}