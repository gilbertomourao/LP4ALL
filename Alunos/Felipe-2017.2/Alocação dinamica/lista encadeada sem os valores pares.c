#include <stdio.h>
#include <stdlib.h>
struct list{
	int info;
	struct list *p;
};

typedef struct list lista;
 
lista *insere(lista *l,int i);
lista *retira(lista *l,int i);
void imprime(lista *l);

int main(){
	lista *l=NULL;
	int i,qnt,num[50];
	printf("Digite a qnt de valores:\n");
	scanf("%d",&qnt);
	fflush(stdin);
	for(i=0;i<qnt;i++){
		printf("Digite o valor:\n");
		scanf("%d",&num[i]);
		fflush(stdin);
		l=insere(l,num[i]);
	}
	for(i=0;i<qnt;i++){
		if(num[i]%2==0){
			l=retira(l,num[i]);
		}
	}
	if(l==NULL){
		printf("**********Lista vazia***********\n");
	}
	else{
		printf("Sem os valores pares:\n");
		imprime(l);
	}
	
	return 0;
}

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

void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->p;		
	}
}

lista *retira(lista *l,int i){
	lista *ant=NULL;
	lista *aux=l;
	if(i%2==0){
		while(aux!=NULL && aux->info!=i){
			ant=aux;
			aux=aux->p;
		}
		if(aux==NULL){
			return l;
		}
		if(ant==NULL){
			l=aux->p;
		}
		else{
			ant->p=aux->p;
		}
		free(aux);
		return l;
	}
}








