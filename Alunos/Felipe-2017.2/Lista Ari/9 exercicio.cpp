/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Função pra contar letras minúsculas em uma string
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int contminu(char st[]);
int main(){
	char string[MAX];
	
	printf("Digite uma string:\n");
	
	gets(string);
	
	printf("O total de letras min%csculas: %d",-93,contminu(string));
	return 0;
}
int contminu(char s[]){
	int i,cont=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='a' && s[i]<='z')
			cont++;
	}
	return cont;
}