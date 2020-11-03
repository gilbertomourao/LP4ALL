#include <stdio.h>
#include <stdlib.h>

struct list{
	int info;
	struct list *p;
};
typedef struct list lista;

lista *insere(lista *l,int i);
void substitui(lista *l1,lista *l2,int i);
void imprime(lista *l);

int main(){
	lista *l1=NULL;
	lista *l2=NULL;
	int i,qnt1,qnt2,num1,num2,esc;
	printf("Digite a qnt de valores da lista 1:\n");
	scanf("%d",&qnt1);
	fflush(stdin);
	for(i=0;i<qnt1;i++){
		printf("Digite o valor:\n");
		scanf("%d",&num1);
		fflush(stdin);
		l1=insere(l1,num1);
	}
	printf("Digite a qnt de valores da lista 2:\n");
	scanf("%d",&qnt2);
	fflush(stdin);
	for(i=0;i<qnt2;i++){
		printf("Digite o valor:\n");
		scanf("%d",&num2);
		fflush(stdin);
		l2=insere(l2,num2);
	}
	printf("Digite o elemento q vc deseja trocar:\n");
	scanf("%d",&esc);
	fflush(stdin);
	substitui(l1,l2,esc);
	imprime(l1);
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

void substitui(lista *l1,lista *l2,int i){
	lista *aux1=l1;
	lista *aux2=l2;
	lista *ant1=NULL;
	lista *ant2=NULL;
	while(aux2!=NULL){
		ant2=aux2;
		aux2=aux2->p;
	}
	while(aux1!=NULL && aux1->info!=i){
		ant1=aux1;
		aux1=aux1->p;
	}
	if(aux1!=NULL){
		ant1->p=l2;
		ant2->p=aux1->p;
	}
}

void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d",aux->info);
		aux=aux->p;		
	}
}