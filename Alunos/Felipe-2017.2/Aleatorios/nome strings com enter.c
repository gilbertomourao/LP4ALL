#include <stdio.h>

int main(){
	
	char nome[100];
	char caractere;
	int i=0;
	do {
		caractere = getchar();//getchar pega caractere por caractere
		nome[i] = caractere;
		i++;
	}while(caractere!='\n');
	nome[i-1]='\0';
	printf("%s\n",nome);
	return 0;
}