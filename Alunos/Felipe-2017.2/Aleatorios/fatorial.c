/*
UFMA-Engenharia El�trica
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: C�lculo de fatorial
Ano: 2017.2
*/

#include <stdio.h>


int main(){
	int numero,fat,cont;
	// Tela do usu�rio
	printf("Digite o numero para saber seu fatorial:\n");
	
	scanf("%d",&numero);
	// C�lculo do fatorial e impresss�o na tela
	// Se o numero for menor que 0 soar� um alarme !
	fat=1;
	if (numero >= 0){
		for (cont=1;cont<=numero;cont=cont+1) fat = fat * cont;
		printf("O fatorial e = %d\n",fat);
    }
	if(numero<0){
		printf("Nao existe fatorial !!!\7");
	}
	return 0;
}
