/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Doação de sangue
Ano: 2017.2
*/
#include <stdio.h>

int main(){
	int idade;
	printf("Digite sua idade pra saber se pode doar sangue:\n");
	scanf("%d",&idade);
	if(idade>=18 && idade<=67){
		printf("\nVoc%c est%c apto pra doar !!!\n",-120,-96);
	}
	else{
		printf("\nVoc%c  infelismente n%co pode doar\n",-120,-58);
	}
	return 0;
}