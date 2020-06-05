#include <stdio.h>
#define MAX 50
int main(){
	
	char nome[MAX];
	int i;
	printf("Digite um nome:\n");
	gets(nome);
	puts("\n");
	for (i=0;i<=MAX;i++){
		if(nome[i]>='a'&&nome[i]<='z')//caso seja letras minusculas
			nome[i]=nome[i]-32;//pois a diferença entre dois caracteres é uma constante 32
	}
	printf("%s",nome);
	return 0;
}

