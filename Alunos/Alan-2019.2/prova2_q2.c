#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int compara(char c, char* str, int size);
void histograma(int vet[]);
void imprime(int freq[], char* str, int size,int num);
void deleteFreq(int num, char* str, int freq[]);
int maiorFreq(int freq[]);


int main()
{
	//entrada
	char string[MAX];
	int num;
	//vetor frequencia
	int vet[10];

	//preenche de zeros
	for(int j = 0; j<10; j++){
		vet[j] = 0;
	}
	//Le entrada
	printf("Insira sequencia:\n");
	fgets(string, 50, stdin);


	int size = strlen(string);
	//pega frequencia
	for(char i = '0'; i <= '9'; i++ ){

		vet[i-'0'] = compara(i, string, size);
	}


	histograma(vet);


	printf("Insira numero: \n");
	scanf("%d", &num);

	imprime(vet,string,size,num);
	

	return 0;
}

void imprime(int freq[], char* str, int size,int num){
	int maior;
	for(int j=0;j<num;j++){
		maior=maiorFreq(freq);
		freq[maior]=0;
	}
	

	for(int i=0;i<size;i++){
		if(freq[(str[i]-'0')] != 0){
			printf("%c",str[i]);
		}
	}
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


int maiorFreq(int freq[]){
	int maior = freq[0];
	int index = 0;
	for(int i = 1; i < 10; i++){
		if(freq[i] > maior){
			maior = freq[i];
			index = i;
		}
	}
	return index;
}


