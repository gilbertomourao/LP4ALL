#include <stdio.h>

struct CAD {
	
	char nome[300];
	char ende[1000];
	int idade;
	float renda;	
		
};

typedef struct CAD L;

void leitura (L *);
int media (int *);
void mostramedia (int);

int main(){
	
	L vet[10];
	
	leitura(vet);
	media (&vet[0].idade);
	mostramedia (media(&vet[0].idade));
	
	return 0;	
}

void leitura (L vet[]){

	int i;
	
	for (i=0;i < 10;i++){	
		printf("Insira a sua idade: ");
		scanf("%d", &vet[i].idade);
		printf("Insira o seu nome: ");
		gets(vet.nome);
		print("Insira a sua renda: ");
		scanf("%f", &vet[i].renda);
	}	
	
}


int media (int *vet){
	
	int soma = 0,i;
	float m;
	
	for (i = 0;i < 10;i++)
		soma += *(vet+i);
	
 	m = soma/i;
	
	return m;	
}

void mostramedia (int n){

	printf("A media das idades e: %d", n);
		
}