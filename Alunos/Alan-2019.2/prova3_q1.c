#include <stdio.h>
#include <stdlib.h>

struct list{
	int info;
	struct list *p;
};
typedef struct list lista;

int maiorFreq(int *vet);
lista *insere(lista *l,int i);
void imprime(lista *l);
lista *exclui(lista *L, int a);
int procurar(lista *L, int a);
void histograma(lista *l, int qnt);

int main(){
	lista *L=NULL;
	int i,qnt,num;
	int freq[10];

	for(int i=0; i<10; i++){
        freq[i]=0;
	}

	printf("Digite a qnt de valores da lista 1:\n");
	scanf("%d",&qnt);
	fflush(stdin);
	for(i=0;i<qnt;i++){
		printf("Digite o valor:\n");
		scanf("%d",&num);
		fflush(stdin);
		L=insere(L,num);
	}

  histograma(L, qnt);


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

lista *exclui(lista *L, int a)
{
	lista *ant,*l;
	ant = NULL;
	l=L;

	while(l != NULL && l->info != a){
		ant = l;
		l = l->p;
	}

	if(l == NULL)
		return L;

	if(ant == NULL)
		L = l->p;
	else
		ant->p = l->p;

	free(l);
	return L;
}

int procurar(lista *L, int a)
{
	lista *aux = L;
	int cont=0;

	while(aux != NULL && a != aux->info){
		aux = aux->p;
	}

	if(aux->info == a){
		cont++;
	}else{
		cont = 0;
	}

	return cont;
}

void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d",aux->info);
		aux=aux->p;
	}
}

void histograma(lista *l, int qnt){
	int vet[10];//cada indice corresponde a um numero
	lista *aux=l;
	int indice;
	int cont = 0;
	
	for(int i = 0; i<10; i++){
		vet[i] = 0;
	}
	
	
	for(int i = 0; i < 100 ; i++){

		vet[aux->info]++;
		aux = aux->p;
		cont++;
		if(aux == NULL){
			break;
		}
	}
  
	
	printf("HISTOGRAMA\n");
	for(int i=0 ;i<10 ;i++ ){
        if(vet[i]!=0){
            printf("%d - %d\n", i, vet[i]);
        }
    }

	while(qnt >0){
		indice = maiorFreq(vet);
		if(vet[indice] == 0){
			break;
		}
		printf("%d", indice);
		vet[indice] = 0;
		qnt--;
	}
	
}

int maiorFreq(int *vet){
	int maior = vet[0];
	int indice = 0;
	for(int i =0; i<10; i++){
		if(vet[i]>maior){
			maior = vet[i];
			indice = i;
		}
	}
	return indice;
}

