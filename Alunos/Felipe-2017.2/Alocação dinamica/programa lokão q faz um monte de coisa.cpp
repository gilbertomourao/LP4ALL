#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct list{
	int cod;
	char user[MAX];
	struct list *p;
};
typedef struct list lista;

lista *insere(lista *l);
void imprime(lista *l);
void ordenar(lista *l);
lista *retira(lista *l,int i);
int busca(lista *l,int i);
int main(){
	lista *l=NULL;
	int cond=0,esc,c;
	do{
		system("cls");
		printf(" ------------------CADASTRO UNICO----------------------\n");
		printf("|# Digite 1 para cadastro:                              |\n");
		printf("|# Digite 2 para conferir os dados:                     |\n");
		printf("|# Digite 3 para ordenar a lista em função do codigo:   |\n");
		printf("|# Digite 4 para excluir usuario:                       |\n");
		printf("|# Digite 5 para sair do programa:                      |\n");
		printf("|# SELECIONE:                                           |\n");
		fflush(stdin);
		scanf("%d",&esc);
		switch(esc){
		case 1:
			l=insere(l);
			break;
		case 2:
			if(l==NULL){
				printf("LISTA VAZIA\n");
			}
			else{
				imprime(l);
			}
			break;
		case 3:
			if(l==NULL){
				printf("NAO POSSO ORDENAR\n");
			}
			else{
				printf("ORDENADO\n");
				ordenar(l);
			}
			break;
		case 4:
			if(l!=NULL){
				printf("Digite o codigo do usuario a ser retirado:\n");
				scanf("%d",&c);
				fflush(stdin);
				if(busca(l,c)==1){
					l=retira(l,c);
					printf("Usuario retirado !!!\n");
				}
				else{
					printf("Esse codigo nao esta na lista\n");
				}
			}
			else{
				printf("LISTA VAZIA\n");
			}
			break;
		case 5: 
			printf("Encerrando \n");
			cond=1;
			break;
		default:
			printf("INVALIDO, TENTE NOVAMENTE:\n");
		}
		system("pause");
	}while(cond==0);
	return 0;
}
lista *insere(lista *l){
	int i;
	char name[MAX];
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	if(novo==NULL){
		exit(0);
	}
	printf("Digite o codigo do cliente:\n");
	scanf("%d",&i);
	printf("Digite o nome do novo usuario:\n");
	fflush(stdin);
	gets(name); 
	novo->cod=i;
	strcpy(novo->user,name);
	novo->p=l;
	return novo;
}
//imprime
void imprime(lista *l){
	lista *aux=l;
	while(aux!=NULL){
		printf("%d\n",aux->cod);
		printf("%s\n",aux->user);
		aux=aux->p;		
	}
}
//ordena
void ordenar(lista *l){
	lista *primeiro=l;
	lista *ant=NULL;
	int aux;
	char aux_str[MAX];
	while(primeiro!=NULL){
		ant=l;
		while(ant!=NULL){
			if(primeiro->cod < ant->cod){
				aux=primeiro->cod;
				primeiro->cod=ant->cod;
				ant->cod=aux;	
				//ordenar os nomes pra não alterar o código durante a exibição
				strcpy(aux_str,ant->user);
				strcpy(ant->user,primeiro->user);
				strcpy(primeiro->user,aux_str);	
			}
			ant=ant->p;
		}
		primeiro=primeiro->p;
	}	
}

//retira
lista *retira(lista *l,int i){
	lista *ant=NULL;
	lista *aux=l;
	while(aux!=NULL && aux->cod!=i){
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

//buscar
int busca(lista *l,int i){
	lista *aux=l;
	while(aux!=NULL){
		if(aux->cod==i){
			return 1;
			break;
		}
		else{
			aux=aux->p;	
		}
	}
}
