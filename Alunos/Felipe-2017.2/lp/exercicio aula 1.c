/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Mostrar o maior e o menor número
Ano: 2017.2
*/
#include <stdio.h>

int main(){
	int num1,num2,num3;
	printf("Digite o primeiro numero:\n");
	scanf("%d",&num1);
	printf("Digite o segundo numero:\n");
	scanf("%d",&num2);
	printf("Digite o terceiro numero:\n");
	scanf("%d",&num3);
	if(num1>num2){
		if(num1>num3){
			printf("\nO maior e %d",num1);
		}
		else{
			printf("\nO maior e %d",num3);
		}
	}
	if(num2>num3){
		if(num2>num1){
			printf("\nO maior e:%d\n",num2);
		}
		else{
			printf("\nO maior e:%d\n",num3);
		}
	}
	if(num1<num2){
		if(num1<num3){
			printf("\nO menor e %d",num1);
		}
		else{
			printf("\nO menor e %d",num3);
		}
	}
	if(num2<num3){
		if(num2<num1){
			printf("\nO menor e:%d\n",num2);
		}
		else{
			printf("\nO menor e:%d\n",num3);
		}
	}
	
	return 0;
}