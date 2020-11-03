#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int indchr(char st[],char a){
	int i;
	for(i=0;st[i]!='\0';i++){
		if(st[i]==a){
			printf("A primeira aparicao foi na posicao: %d\n",i);
			return i;
		}
	}
	return -1;
}

int main(){
	
	char frase[MAX],carac;
	puts("Digite uma frase:");
	gets(frase);
	puts("Digite um caractere:");
	scanf("%c",&carac);
	indchr(frase,carac);
	return 0;
}