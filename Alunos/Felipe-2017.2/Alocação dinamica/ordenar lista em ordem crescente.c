#include <stdio.h>
#include <stdlib.h>

struct list{
	int info;
	struct list *p;
};
typedef struct list lista;

lista *insere(lista *l,int i);
void ordenar(lista *l);
void imprime(lista *l);

int main(){
	lista *l=NULL;
	int qnt,num,i;
	printf("Digite a qnt de elementos:\n");
	scanf("%d",&qnt);
	fflush(stdin);
	for(i=0;i<qnt;i++){
		printf("Digite a posicao %d\n",i+1);
		scanf("%d",&num);
		l=insere(l,num);
	}
	ordenar(l);
	printf("Imprimindo:\n");
	imprime(l);
	return 0;
}

//insere
lista *insere(lista *l,int i){
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	if(novo==NULL){
		exit(0);
	} 
	novo->info=i;
	novo->p=l;
	return novo;
}

//ordena
void ordenar(lista *l){
	lista *primeiro=l;
	lista *ant=NULL;
	int aux;
	while(primeiro!=NULL){
		ant=l;
		while(ant!=NULL){
			if(primeiro->info < ant->info){
				aux=primeiro->info;
				primeiro->info=ant->info;
				ant->info=aux;	
			}
			ant=ant->p;
		}
		primeiro=primeiro->p;
	}	
}

//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->p;		
	}
}













