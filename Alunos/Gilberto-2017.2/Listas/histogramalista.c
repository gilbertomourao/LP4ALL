#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

struct list {
	char ch; /*Lista de chars*/
	struct list *P; /*Próximo*/
};

typedef struct list Lista;

/****Funções****/
Lista *insere (Lista *,char *);
unsigned int tamanho (Lista *);
void imprime (Lista *);
Lista *clona (Lista *);
Lista *histograma (Lista *,Lista *,Lista *,unsigned int);
/***************/

int main(){

	Lista *L1 = NULL, *L2 = NULL, *L3 = NULL;
	char str1[TAM], str2[TAM];
	unsigned int n;
	
	printf("String 1: "); gets(str1); strrev(str1); L1 = insere(L1,str1); 
	printf("String 2: "); gets(str2); strrev(str2); L2 = insere(L2,str2); n = tamanho(L2);
	L3 = clona(L1);
	imprime(L1); putchar('\n'); imprime(L2);
	putchar('\n'); imprime(histograma(L1,L2,L3,n));
	
	free(L1); free(L2); free(L3);
	
	return 0;	
}

Lista *insere (Lista *L,char *ch){

	Lista *novo;
	
	while (*ch){
		novo = (Lista *) malloc(sizeof(Lista));
		
		if (novo == NULL)
			exit(0);	
		
		novo->ch = *ch;
		novo->P = L;
		L = novo;
		ch++; 
	}
	
	return novo;
}

unsigned int tamanho (Lista *L){

	unsigned int n = 0;
	Lista *aux = L;
	
	while (aux){
		if (tolower(aux->ch) >= 'a' && tolower(aux->ch) <= 'z')
			n++;
		aux = aux->P;
	}
	
	return n;	
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%c", aux->ch);
		aux = aux->P;
	}
}

Lista *clona (Lista *L1){
	
	Lista *novo = NULL,*aux = L1;
	char ch[TAM];
	int i = 0;
	
	while (aux){
		ch[i] = aux->ch;
		aux = aux->P;
		i++;
	}
	ch[i] = '\0';
	strrev(ch);
	novo = insere(novo,ch);
	
	return novo;
}

Lista *histograma (Lista *L1,Lista *L2,Lista *L3,unsigned int n){

	Lista *aux1 = L1, *aux2, *prox1 = NULL,*prox3 = NULL, *ant1 = NULL;
	Lista *aux3 = L3;
	unsigned int conta;
	
	while (aux1){
		ant1 = aux1;
		aux2 = clona(L2);
		while (aux2->ch == ' ') {aux2 = aux2->P;if(!aux2) break;}
		if (!aux2) break;	
		prox1 = aux1->P;
		prox3 = aux3->P;
		if (tolower(aux1->ch) == tolower(aux2->ch)){
			conta = 0;
			while (aux1 && aux2){
				while (aux1->ch == ' ') {aux1 = aux1->P;if(!aux1) break;}
				while (aux2->ch == ' ') {aux2 = aux2->P;if(!aux2) break;}
				if (!aux1 || !aux2) break;
				if (tolower(aux1->ch) == tolower(aux2->ch))
					conta++; 
				aux1 = aux1->P;
				aux2 = aux2->P;	
			}
			if (conta == n){
				aux2 = clona(L2);
				aux1 = ant1;
				while (aux1 && aux2){
					while (aux1->ch == ' ') {aux1 = aux1->P;if(!aux1) break;}
					while (aux2->ch == ' ') {aux2 = aux2->P;if(!aux2) break;}
					while (aux3->ch == ' ') {aux3 = aux3->P;if(!aux3) break;}
					if (!aux1 || !aux2) break;
					if (tolower(aux1->ch) == tolower(aux2->ch))
						aux3->ch = '*';
					aux3 = aux3->P;
					aux1 = aux1->P;
					aux2 = aux2->P;
				}
			}
		}
		aux1 = prox1;
		aux3 = prox3;
	}	
	
	return L3;
}