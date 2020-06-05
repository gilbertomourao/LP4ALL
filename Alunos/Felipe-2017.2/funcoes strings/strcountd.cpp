#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

void strcountd(char st[]){

	int i,contador=0;
	for(i=0;st[i]!='\0';i++){
		if(isdigit(st[i])){
			contador+=1;
		}
	}
	printf("O total de digitos na frase foi: %d",contador);	
}

int main(){
	char frase[MAX];
	puts("Digite uma frase contendo ou não digitos:");
	gets(frase);
	strcountd(frase);
	return 0;
}