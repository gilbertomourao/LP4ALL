/*
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Procura se uma string está dentro de outra !!!
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int segm(char s[],char t[]);
int main(){
	char frase[MAX],palavra[MAX];
	int i=0,j=0,cont=0;
	printf("Digite uma frase:\n");
	gets(frase);
	printf("Digite uma palavra:\n");
	gets(palavra);
	while(frase[i]!='\0'){
		while(frase[j+i]!='\0' && palavra[j]!='\0' && frase[i+j]==palavra[j]){
			j++;
		}
		if(palavra[j]=='\0'){
			cont++;
		}
		j=0;
		i++;
	}
	printf("A palavra aparece na frase %d vez(es)",cont);
	return 0;
}