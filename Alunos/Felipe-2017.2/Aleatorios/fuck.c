#include <stdio.h>

int main(){
	
	int fat,i,n;
	fat=1;
	i=0;
	
	printf("Digite um numero para saber seu fatorial:\n");
	
	scanf("%d",&n);
	
	if (n>=0){
		for (i=1;i<=n;i=i+1){/*Loop para o c�lculo do fatorial, onde i � a vari�vel contadora*/
			fat=fat*i;/*F�rmula utilizada para o c�lculo do fatorial*/
		}
		printf("O fatorial e= %d",fat);
	}
	else {
		printf("Nao existe fatorial de numero negativo !!!");//S� ser� exibido caso a 1� condi��o n�o seja verdadeira
	}
	
	return 0;
}
