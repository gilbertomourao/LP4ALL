#include <stdio.h>

int main(){
	
	int fat,i,n;
	fat=1;
	i=0;
	
	printf("Digite um numero para saber seu fatorial:\n");
	
	scanf("%d",&n);
	
	if (n>=0){
		for (i=1;i<=n;i=i+1){/*Loop para o cálculo do fatorial, onde i é a variável contadora*/
			fat=fat*i;/*Fórmula utilizada para o cálculo do fatorial*/
		}
		printf("O fatorial e= %d",fat);
	}
	else {
		printf("Nao existe fatorial de numero negativo !!!");//Só será exibido caso a 1º condição não seja verdadeira
	}
	
	return 0;
}
