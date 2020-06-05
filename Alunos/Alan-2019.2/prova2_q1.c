#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int compara(char c, char* str, int size);
void histograma(int vet[]);
void saida2(int vet[]);

int main()
{
	//entrada
	char string[MAX];
	//vetor frequencia
	int vet[10];
	//preenche de zeros
	for(int j = 0; j<10; j++){
		vet[j] = 0;
	}
	//Le entrada
	printf("Insira numero:\n");
	fgets(string, 50, stdin);

	int size = strlen(string);

	for(char i = '0'; i <= '9'; i++ ){

		vet[i-'0'] = compara(i, string, size);
	}

	histograma(vet);
 
	saida2(vet);
	return 0;
}

int compara(char c, char* str, int size){


	int cont = 0;

	for(int j=0; j<size; j++){

		if(c == str[j]){
			cont++;
		}
	}
	return cont;
}

void histograma(int vet[]){
	int* p = vet;
	printf("HISTOGRAMA\n");
	for(int i = 0; i < 10; i++){
		printf("%d: %d\n", i, *p);
		p++;
	}
}

void freq(int vet[]){

	for(int i = 0; i<10; i++){
		if(vet[i] !=0){
			printf("%d: %d", i, vet[i]);
		}
	}
}


void saida2(int vet[]){

	for(int i = 0; i<10; i++){
		if(vet[i] !=0){
			printf("%d-", vet[i]);
		}
		for (int j=0; j < vet[i]; j++){
			printf("%d", i);
		}
	}
}