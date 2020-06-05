//Alunos: FELIPE E KEVIN
#include <stdio.h>
#include <stdlib.h>

struct list{
	char ch;
	struct list *p;
};
typedef struct list lista;
lista *insere(lista *l);
lista *retira(lista *l);
void imprime(lista *l);
void ordenar(lista *l);

int main(){
	int qnt,aux;
	lista *l=NULL;
	printf("Digite a qnt de elementos:\n");
	scanf("%d",&qnt);
	aux=qnt;
	fflush(stdin);
	while(qnt!=0){
		l=insere(l);
		qnt--;
	}
	while(aux!=0){
		l=retira(l);
		aux--;
	}
	ordenar(l);
	printf("Ordenada:\n");
	imprime(l);
	return 0;
}

//insere
lista *insere(lista *l){
	lista *novo;
	char opc;
	novo=(lista *)malloc(sizeof(lista));
	if(novo==NULL){
		exit(0);
	} 
	printf("Digite o elemento:\n");
	scanf("%c",&opc);
	fflush(stdin);
	novo->ch=opc;
	novo->p=l;
	return novo;
}

//retira letras
lista *retira(lista *l){
	lista *ant=NULL;
	lista *aux=l;
	while((aux!=NULL) && (aux->ch>='0' && aux->ch<='9' )){
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
//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%c",aux->ch);
		aux=aux->p;		
	}
}
//ordenar
void ordenar(lista *l){
	lista *primeiro=l;
	lista *ant=NULL;
	int aux;
	while(primeiro!=NULL){
		ant=l;
		while(ant!=NULL){
			if(primeiro->ch < ant->ch){
				aux=primeiro->ch;
				primeiro->ch=ant->ch;
				ant->ch=aux;	
			}
			ant=ant->p;
		}
		primeiro=primeiro->p;
	}	
}