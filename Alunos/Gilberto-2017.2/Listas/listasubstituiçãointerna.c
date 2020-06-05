#include <stdio.h>
#include <stdlib.h>

struct list {
	int info;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,int);
void imprime (Lista *);
Lista *substitui (Lista *,Lista *,int);

int main(){
	
	Lista *L1 = NULL, *L2 = NULL;
	int sim = 1, num, n;
	
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
	
	printf("Lista 1: "); imprime (L1); putchar('\n');
	printf("Lista 2: "); imprime (L2); putchar('\n');
	
	printf("Selecione um numero: "); scanf("%d", &n); fflush(stdin);
	
	imprime (substitui (L1,L2,n));
	
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

Lista *substitui (Lista *L1,Lista *L2,int n){
	
	Lista *aux1 = L1,*aux2 = L2,*prox1 = NULL,*ant1 = NULL,*ant2 = NULL;
	
	while (aux1){
			prox1 = aux1->P;
			if (aux1->info == n){
				if (aux1 == L1) 
					L1 = aux2;
				else 
					ant1->P = aux2;
				while (aux2){
					ant2 = aux2;
					aux2 = aux2->P;
					if (aux2 == NULL)
						ant2->P = prox1;
				}
				break;
			}
			else
				ant1 = aux1;
			aux1 = prox1;
	}
	
	return L1;
}