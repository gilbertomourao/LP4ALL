#include <stdio.h>

int tamanhostring(char string[]){
	int numcarac=0;
	while(string[numcarac] != '\0'){
		numcarac++;
	}
	numcarac++;
	return numcarac;
}
int main(){
	
	char stringusuario[20];
	printf("Digite uma palavra:\n");
	scanf("%s", stringusuario);
	
	printf("O numero de caracteres e: %i\n",tamanhostring(stringusuario));
	
	return 0;
}
//vai mostrar um numero a mais de letras por causa do caractere nulo !!!