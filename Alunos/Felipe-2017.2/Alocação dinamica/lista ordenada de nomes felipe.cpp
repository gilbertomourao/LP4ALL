#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
struct list{
	char *ch;
	struct list *p;
};
typedef struct list lista;
//funcoes
lista *insere(lista *l,char *ch);
void imprime(lista *l);
int ordemalfa (char *ch1,char *ch2);
void ordenar(lista *l);
int main(){
	lista *l=NULL;
	int qnt,i=0;
	char nome[MAX][MAX];
	printf("Digite a qnt de nomes da lista:\n");
	scanf("%d",&qnt);
	fflush(stdin);
	while(qnt!=0){
		printf("Digite o %d nome:\n",i+1);
		gets(nome[i]);
		l=insere(l,nome[i]);
		i++;
		qnt--;
	}
	puts(" ");
	ordenar(l);
	printf("LISTA ORDENADA:\n");
	imprime(l);
	
	return 0;
}
//insere
lista *insere(lista *l,char *ch){
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	if(novo==NULL){
		exit(0);
	} 
	novo->ch=ch;
	novo->p=l;
	return novo;
}
//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%s\n",aux->ch);
		aux=aux->p;		
	}
}
//ordenação alfabetica de string
int ordemalfa (char *ch1,char *ch2){
	while (ch1 && ch2){
		if (tolower(*ch1) > tolower(*ch2)){
			return 1;
		}	
		else if (tolower(*ch1) < tolower(*ch2)){ 
			return 0;
		}	
		*ch1++; 
		*ch2++;
	}
	return 0;
}
//ordena
void ordenar(lista *l){
	lista *primeiro=l;
	lista *ant=NULL;
	char *aux;
	while(primeiro!=NULL){
		ant=primeiro->p;
		while(ant!=NULL){
			if(ordemalfa(primeiro->ch,ant->ch)){
				aux=primeiro->ch;
				primeiro->ch=ant->ch;
				ant->ch=aux;	
			}
			ant=ant->p;
		}
		primeiro=primeiro->p;
	}	
}