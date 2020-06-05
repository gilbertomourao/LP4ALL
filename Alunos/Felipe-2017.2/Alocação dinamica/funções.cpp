//Funções lista encadeada
#include <stdlib.h>
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
//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->p;		
	}
}
//concatena
void concatenar(lista *l1,lista *l2){
	lista *aux1=l1;
	lista *ant=NULL;
	while(aux1 != NULL){
		ant=aux1;
		aux1=aux1->p;
	}
	ant->p=l2;
	
}

//buscar
void busca(lista *l,int i){
	lista *aux=l;
	while(aux!=NULL){
		if(aux->info==i){
			printf("Achou\n");
			break;
		}
		else{
			aux=aux->p;	
		}
	}
}

//retira
lista *retira(lista *l,int i){
	lista *ant=NULL;
	lista *aux=l;
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

//insere string
lista *insere(lista *l){
	lista *novo;
	char nome[50];
	novo=(lista *)malloc(sizeof(lista));
	if(novo==NULL){
		exit(0);
	} 
	printf("Digite o nome:\n");
	fflush(stdin);
	gets(nome);
	strcpy(novo->str,nome);
	novo->p=l;
	return novo;
}


