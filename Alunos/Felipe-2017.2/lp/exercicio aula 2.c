/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Mostrar se um número é ou não par
Ano: 2017.2
*/
#include <stdio.h>

int main(){
	int num;
	printf("Digite um valor inteiro:\n");
	scanf("%d",&num);
	if(num%2==0){
		printf("O numero %d %c par\n",num,130);
	}
	else{
		printf("O numero %d %c n%co %c par",num,130,-58,130);
	}
	
	return 0;
}