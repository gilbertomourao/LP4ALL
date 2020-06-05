#include <stdio.h>

int totchar(char string[]){
	int i=0;
	while(string[i]!='\0'){
		i++;
	}
	return i;
}

int main(){
	char nome[20];
	printf("Digite uma palavra (STRING):\n");
	scanf("%[^\n]s",nome);
	printf("O numero de bytes e = %i ",totchar(nome));
	return 0;
}