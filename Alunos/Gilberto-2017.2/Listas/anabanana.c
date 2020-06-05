/*Ana Banana com lista*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 50

struct list {
	char *ch;
	struct list *P;   	
};

typedef struct list Lista;

Lista *insere (Lista *,char *);
void imprime (Lista *);
Lista *clona (Lista *);
Lista *substitui (Lista *,Lista *);

int main(){
	
	char str1[TAM],str2[TAM];
	Lista *L1 = NULL,*L2 = NULL;
	
	printf("Insira uma string: "); gets(str1); L1 = insere(L1,str1);
	printf("Insira outra string: "); gets(str2); L2 = insere(L2,str2);
	system("cls");
	printf("String 1: "); imprime(L1); putchar('\n'); 
	printf("String 2: "); imprime(L2); putchar('\n');
	imprime(substitui(L1,L2));
	
	return 0;
}

Lista *insere (Lista *L,char *vet){

	Lista *novo;
	
	novo = (Lista *) malloc(sizeof(Lista));
	
	if (novo == NULL)
		exit(0);	
	
	novo->ch = vet;
	novo->P = L;
	
	return novo;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux){
		puts(aux->ch);
		aux = aux->P;
	}	
}

Lista *clona (Lista *L){
	
	Lista *novo,*aux = L, *ant = NULL;
	Lista *clone = (Lista *) malloc(sizeof(Lista));
	
	while (aux){
		novo = (Lista *) malloc(sizeof(Lista));
		novo->ch = aux->ch;
		novo->P = NULL;
		
		if (ant == NULL)
			clone = novo;
		else 
			ant->P = aux;
		
		ant = novo;
		aux = aux->P;
	}
	
	return clone;
}

Lista *substitui (Lista *L1,Lista *L2){
	
	Lista *aux1 = L1, *aux2 = L2,*aux3,*ant1 = NULL,*prox1 = NULL;
	unsigned int conta;
	
	while (aux1){
		prox1 = aux1->P;
		aux2 = clona(L2);
		if (tolower(*aux1->ch) == tolower(*aux2->ch)){
			aux3 = L1;
			conta = 0;
			while (*aux2->ch && *aux3->ch)
				if (tolower(*aux3->ch++) == tolower(*aux2->ch++))
					conta++;
			while (conta > 0){	/*Retorna à posição de origem*/
					*aux3->ch--;
					*aux2->ch--;
					conta--;
			}	
			if (conta == strlen(L2->ch)){
				while (*aux3->ch)
					if (tolower(*aux3->ch) == tolower(*aux2->ch)){
						*aux3->ch++ = '*';
						*aux2->ch++;
					}
				conta = strlen(L2->ch);
				while (conta > 0){	/*Retorna à posição de origem*/
					*aux3->ch--;
					*aux2->ch--;
					conta--;
				}	
			}
		}
		else 
			ant1 = aux1;
		aux1 = prox1; /*Estou pulando a string, devo apenas percorrer o endereço em ch*/
	}
	return L1;
}