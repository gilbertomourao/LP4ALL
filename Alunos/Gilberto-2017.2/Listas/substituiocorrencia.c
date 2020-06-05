/*Substitui ocorrência*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 1000

struct list {
	char ch;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,char *);
void imprime (Lista *);
Lista *clona (Lista *);
unsigned int tamanho (Lista *);
Lista *substitui (Lista *,Lista *,Lista *,unsigned int);

int main(){
	
	Lista *L1 = NULL, *L2 = NULL, *L3 = NULL;
	char str1[TAM], str2[TAM], str3[TAM];
	
	printf("String Principal: "); gets(str1); strrev(str1); L1 = insere(L1,str1);
	printf("String Secundaria: "); gets(str2); strrev(str2); L2 = insere(L2,str2);
	printf("String para substituicao: "); gets(str3); strrev(str3); L3 = insere(L3,str3);
	putchar('\n');
	printf("String Resultante: "); imprime(substitui(L1,L2,L3,tamanho(L2)));

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

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		printf("%c", aux->ch);
		aux = aux->P;
	}
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

Lista *substitui (Lista *L1,Lista *L2,Lista *L3,unsigned int n){

	Lista *aux1 = L1, *aux2 = NULL, *aux3 = NULL,*novo = NULL,*prox1 = NULL, *ant1 = NULL, *aant1 = NULL;
	unsigned int conta,i = 0,fez = 0;
	char str[TAM];
	
	while (aux1){
		ant1 = aux1;
		aux2 = clona(L2);
		while (aux2->ch == ' ') {aux2 = aux2->P;if(!aux2) break;}
		if (!aux2) break;	
		prox1 = aux1->P;
		if (tolower(aux1->ch) == tolower(aux2->ch)){
			conta = 0;
			while (aux1 && aux2){
				while (aux1->ch == ' ') {aux1 = aux1->P;if(!aux1) break;}
				while (aux2->ch == ' ') {aux2 = aux2->P;if(!aux2) break;}
				if (!aux1 || !aux2) break;
				if (tolower(aux1->ch) == tolower(aux2->ch))
					conta++;
				aant1 = aux1; 
				aux1 = aux1->P;
				aux2 = aux2->P;	
			}
			if (conta == n){
				aux3 = clona(L3);
				while (aux3){
					str[i++] = aux3->ch;
					aux3 = aux3->P;
				}
				fez = 1;
				aux1 = aant1;
				continue;
			}
			else { if (fez == 0)
					str[i++] = ant1->ch;  
				fez = 0;
			} 	
		}
		else { if (fez == 0)
					str[i++] = ant1->ch;  
				fez = 0;
		}
		aux1 = prox1;
	}
	str[i] = '\0'; strrev(str);
	novo = insere(novo,str);
	
	return novo;	
}