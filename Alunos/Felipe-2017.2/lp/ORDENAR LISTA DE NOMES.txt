#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50

struct list {
	char *ch;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,char *);
void imprime (Lista *);
int ordemalfa (char *,char *);
void ordena (Lista *);

int main(){
	
	Lista *L = NULL;
	char str[TAM][TAM];
	int n,i=0;
	
	printf("Quantos nomes sua lista deve ter? "); scanf("%d", &n); fflush(stdin);
	
	while (n){
		printf("Nome %d: ",i+1); gets(str[i]); L = insere(L,str[i]);
		i++;n--;
	}
	system("cls");
	puts("**LISTA DE NOMES**");
	imprime(L);
	putchar('\n');
	puts("**LISTA ORDENADA**");
	ordena(L); imprime(L);
	
	free(L);
	
	return 0;	
}

Lista *insere (Lista *L,char *ch){

	Lista *novo;
	
	novo = (Lista *) malloc(sizeof(Lista));
	
	if (novo == NULL)
		exit(0);	
	
	novo->ch = ch;
	novo->P = L;
	
	return novo;
}

void imprime (Lista *L){
	
	Lista *aux = L;
	
	while (aux != NULL){
		puts(aux->ch);
		aux = aux->P;
	}
}

int ordemalfa (char *ch1,char *ch2) {
	
	while (ch1 && ch2){
		if (tolower(*ch1) > tolower(*ch2))
			return 1;
		else if (tolower(*ch1) < tolower(*ch2)) 
			return 0;
		*ch1++; *ch2++;
	}
	
	return 0;
}

void ordena (Lista *L){
	
	Lista *aux = L, *prox = NULL;
	char *ch; //Falta-me um pouco de criatividade (e português) T-T
	
	while (aux){
		prox = aux->P;
		while (prox){
			if (ordemalfa(aux->ch,prox->ch)){
				ch = aux->ch;
				aux->ch = prox->ch;
				prox->ch = ch;
			}
			prox = prox->P;
		}
		aux = aux->P;
	}
}