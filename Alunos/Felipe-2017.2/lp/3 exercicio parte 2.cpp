/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Informar o indice da primeira aparcição de uma letra em uma string
Ano: 2017.2
*/
#include <stdio.h>
#include <string.h>
#define MAX 100
int main(){
	char s[MAX];
	int i;
	printf("Digite uma string:\n");
	gets(s);
	printf("Digite uma posicao:\n");
	scanf("%d",&i);
	if(i < 0 || i > strlen(s)){
		printf("Posição invalida");
	}
	else{
		printf("O caractere que esta na posicao digitada eh : %c",s[i-1]);
	}
	
	
	return 0;
}