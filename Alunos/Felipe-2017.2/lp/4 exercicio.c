/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Informar o indice da primeira aparcição de uma string em outra string
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100

int main(){
	char palavra[MAX],frase[MAX];
	int i=0,j=0;
	printf("Digite uma frase:\n");
	gets(frase);
	printf("Digite uma palavra:\n");
	gets(palavra);
	
	while(frase[i]!='\0'){
		while(frase[j]!='\0' && palavra[j]!='\0' && frase[j+i]==palavra[j]){
			j++;
		}
		if(palavra[j]=='\0'){
			printf("A frase '%s' possui a palavra '%s' a partir da %d%c posicao",frase,palavra,i+1,166);
			break;
		}
		i++;
	}
	return 0;
}