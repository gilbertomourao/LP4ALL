#include <stdio.h>

int main (){
	
	int numero;
	
	printf("Digite o numero para saber se e par ou impar:\n");//informa��es ofertadas pelo usu�rio
	
	scanf("%d",&numero);

	if (numero%2==0)/*Resto da divis�o nos mostra se � impar ou par*/{
		printf("O numero digitado e par !!!\a");//se o n�mero for par ser� escutado um som ao final do programa
	}
	else {
		printf("O numero digitado e impar !!!\a");// se o n�mero for impar ser� escutado um som ao final do programa
	}
	
	return 0;
}
