#include <stdio.h>
#include <stdlib.h>
void strlen(char st[]){
	int i=0;
	while(st[i]!='\0'){
		i++;
	}
	printf("O total de caracteres e: %d",i);
}

int main(){
	char string[10];
	puts("Digite uma string:");
	gets(string);
	strlen(string);
	return 0;
}