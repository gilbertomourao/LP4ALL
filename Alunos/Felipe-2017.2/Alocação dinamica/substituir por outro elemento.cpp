#include <stdio.h>
#include <stdlib.h>

struct list{
	int info;
	struct list *p;
};
typedef struct list lista;
//funções
lista *insere(lista *l,int i);
void imprime(lista *l);
void substitui(lista *l,int subs,int substituto);
int main(){
	lista *l1=NULL;
	int qnt1,x,y,w;
	printf("Digite a qnt de elementos da lista 1:\n");
	scanf("%d",&qnt1);
	while(qnt1!=0){
		printf("Digite o elemento:\n");
		scanf("%d",&x);
		fflush(stdin);
		l1=insere(l1,x);
		qnt1--;
	}
	printf("Digite o numero a ser substituido:\n");
	scanf("%d",&y);
	printf("Digite o numero a ser posto no local:\n");
	scanf("%d",&w);
	substitui(l1,y,w);
	imprime(l1);
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
//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d\n",aux->info);
		aux=aux->p;		
	}
}
//substituir elemento
void substitui(lista *l,int subs,int substituto){
	lista *aux=l;
	int cont=0;
	while(aux!=NULL){
		if(aux->info==subs){
			aux->info=substituto;
			cont++;//incrementa se for encontrado
		}
		else{
			aux=aux->p;
		}

	}
	if(cont==0){
		printf("Nao foi encontrado na lista\n");
	}
}