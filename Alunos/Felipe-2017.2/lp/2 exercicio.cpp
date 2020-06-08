/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Mostrar a string no intervalo digitado
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100

int main(){
	char s[MAX];
	int i,j,k;
	printf("Digite uma string:\n");
	gets(s);
	printf("Digite os numeros pra obeter a sequencia de string:\n");
	scanf("%d %d", &i, &j);
	if(i<0||j<0){
		printf("Intervalo invalido!!!\n");
	}
	else{
		for(k=i;k<=j;k++){
			printf("%c",s[k]);
		}
	}
	return 0;
}