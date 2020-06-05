#include <stdio.h>

int main (){
	
	int numero;
	
	printf("Digite o numero para saber se e par ou impar:\n");//informações ofertadas pelo usuário
	
	scanf("%d",&numero);

	if (numero%2==0)/*Resto da divisão nos mostra se é impar ou par*/{
		printf("O numero digitado e par !!!\a");//se o número for par será escutado um som ao final do programa
	}
	else {
		printf("O numero digitado e impar !!!\a");// se o número for impar será escutado um som ao final do programa
	}
	
	return 0;
}
