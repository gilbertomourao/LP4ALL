#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void strcountc(char st1[],char a){

	int i,contador=0;
	for(i=0;st1[i]!='\0';i++){
		if(st1[i]==a){
			contador+=1;
		}
	}
	printf("O total de %c foi de %d",a,contador);
}

int main(){
	char palavra[MAX],carac;
	puts("Digite a string:");
	gets(palavra);
	puts("Digite um caractere:");
	scanf("%c",&carac);
	strcountc(palavra,carac);
	return 0;
}