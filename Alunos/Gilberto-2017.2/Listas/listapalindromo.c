/*Lista é palíndromo?*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 1000

struct list {
	char ch;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,char);
void imprime (Lista *);
Lista *reverter (Lista *);
int ispalindromo (Lista *,Lista *);
void destroy(Lista *);

int main(){

	Lista *L1 = NULL, *L2 = NULL;
	char ch;
	int n,i=0;
	
	printf("Quantos elementos deseja digitar? "); scanf("%d", &n); fflush(stdin); 
	while (n <= 0){
		printf("IMPOSSIVEL!!! TENTE NOVAMENTE COM UM NUMERO NATURAL POSITIVO: ");
		scanf("%d", &n); fflush(stdin);
	}
	putchar('\n');
	while (n){
		printf("Elemento %d: ", i+1); ch = getchar(); 
		if (ch == '\n')
			ch = ' ';
		fflush(stdin); 
		L1 = insere(L1,ch);
		i++;n--;
	}
	system("cls");
	printf("Lista: "); imprime(L1); putchar('\n'); 
	L2 = reverter(L1);
	if (ispalindromo(L1,L2))
		printf("E um palindromo!!!\n");
	else 
		printf("NAO e palindromo!!!\n");
	
	destroy(L1); destroy(L2);
	
	return 0;	
}

Lista *insere (Lista *L,char i){

	Lista *novo;
	
	novo = (Lista *) malloc(sizeof(Lista));
	
	if (novo == NULL)
		exit(0);	
	
	novo->ch = i;
	novo->P = L;
	
	return novo;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%c", aux->ch);
		aux = aux->P;
	}
}

Lista *reverter (Lista *L){
	
	Lista *aux = L, *novo = NULL;
	
	while (aux){
		novo = insere(novo,aux->ch);
		aux = aux->P;
	}
	
	return novo;
}

int ispalindromo (Lista *L1,Lista *L2){
	
	Lista *aux1 = L1, *aux2 = L2;
	
	while (aux1 && aux2){
		while (aux1->ch == ' ') {aux1 = aux1->P; if(!aux1) break;}
		while (aux2->ch == ' ') {aux2 = aux2->P; if(!aux2) break;}
		if (!aux1 || !aux2) break;		
		if (tolower(aux1->ch) != tolower(aux2->ch))
			return 0;
		aux1 = aux1->P;
		aux2 = aux2->P;
	}
	
	return 1;
}

void destroy(Lista *L){
	
	Lista *aux;
	
	while(L){
		aux = L;
		L = L->P;
		free(aux);
	}
	
}