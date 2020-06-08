/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Função pra contar letras maiúsculas em uma string
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int contmaius(char st[]);
int main(){
	char string[MAX];
	
	printf("Digite uma string:\n");
	gets(string);
	
	printf("Total de mai%csculas: %d\n",-93,contmaius(string));
	return 0;
}

int contmaius(char s[]){
	int i,cont=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='Z')
			cont++;
	}
	return cont;
}