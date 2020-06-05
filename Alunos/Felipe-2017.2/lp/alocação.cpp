#include <stdio.h>
#include <stdlib.h>
struct list{
	int info;
	struct list *p;
};
typedef struct list lista;
 
lista *insere(lista *l,int i);
void imprime(lista *l);
int main(){
	lista *l=NULL;
	l=insere(l,25);
	l=insere(l,26);
	l=insere(l,4);
	l=imprime(l);
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

