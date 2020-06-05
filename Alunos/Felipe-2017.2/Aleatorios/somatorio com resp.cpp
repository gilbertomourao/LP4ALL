#include <stdio.h>

int main(int argc, char** argv)
{
	int n,soma;
	soma=0;
	char resp='s';
	printf("Digite numeros aleatoriamente:\n");
	
	while(resp=='s'||resp=='S'){
		printf("Digite um numero:\n");
		scanf("%d",&n);
		soma+=n;
		printf("Deseja continuar 's' ou 'n'\n");
		scanf(" %c",&resp);
	}
	printf("SOMA: %d",soma);
	return 0;
}