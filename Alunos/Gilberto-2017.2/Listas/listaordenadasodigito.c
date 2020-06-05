#include <stdio.h>
#include <stdlib.h>

struct list {
	char ch;
	struct list *P;	
};

typedef struct list Lista;

Lista *insere (Lista *,char);
void imprime (Lista *);
Lista *digit (Lista *);
void ordena (Lista *);

int main(){

	Lista *L1 = NULL, *L2 = NULL;
	char ch;
	int n, i=0;
	
	printf("Quantos elementos deseja inserir na sua lista? "); scanf("%d", &n); fflush(stdin);
	while (n <= 0){
		printf("IMPOSSIVEL!!! TENTE NOVAMENTE COM UM NUMERO NATURAL POSITIVO: ");
		scanf("%d", &n); fflush(stdin);
	}
	putchar('\n');
	while(n){
		printf("Elemento %d: ",i+1); ch = getchar(); 
		if (ch == '\n')
			ch = ' ';
		fflush(stdin);
		L1 = insere(L1,ch);
		i++;n--;
	}
	system("cls");
	printf("Lista original: "); imprime(L1); putchar('\n');
	L2 = digit(L1); ordena(L2);
	printf("Lista resultante ordenada: "); imprime(L2); putchar('\n');
	
	free(L1); free(L2);
	
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

Lista *digit (Lista *L){
	
	Lista *aux = L, *novo = NULL; 
	
	while (aux){
		if (aux->ch >= '0' && aux->ch <= '9')
			novo = insere(novo,aux->ch);
		aux = aux->P;
	}
	
	return novo;
}

void ordena (Lista *L){

	Lista *aux = L, *prox = NULL;
	char ch;
	
	while (aux){
		prox = aux->P;
		while (prox){
			if (aux->ch > prox->ch){
				ch = aux->ch;
				aux->ch = prox->ch;
				prox->ch = ch;
			}
			prox = prox->P;
		}
		aux = aux->P;
	}
	
}