//Exercícios em sala

#include <stdio.h>

#define MAX 100

int main(){
	
	char str[MAX];
	int i, pala = 0;
	
	printf("Insira uma string: "); gets(str);
	
	for (i=0;str[i]!='\0';i++)      //Contagem de palavras
		if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0')
			pala++;
		
	printf("Palavras: %d\n", pala);	
	
	return 0;	
}