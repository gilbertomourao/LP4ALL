#include <stdio.h>
//função para a escrita de asteriscos 
int linha (int num, char op){
	int i;
	for (i=1;i<=num;i++){
		printf("%c",op);
	}
	printf("\n");
}
//programa principal, onde será mostrado o uso da função linha
int main(int argc, char** argv)
{
	int j;
	linha (3,'+');//escreve uma linha de 20 asteriscos 
	printf("Numeros de 1a 5\n");
	linha (3,'-');//escreve uma linha de 20 asteriscos 
	for (j=1;j<=5;j++){
		printf("%i\n",j);
	}
	linha (20,'&');//escreve uma linha de 20 asteriscos 
	return 0;
}