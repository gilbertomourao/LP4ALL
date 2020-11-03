#include <stdio.h>

int main(int argc, char** argv)
{
	int i,x[3],y[3],maior,menor,posmen,posmai,dif;
	i=0;
	printf("Digite um numero inteiro:\n");
	scanf("%i",&x[i]);
	maior=x[i];
	menor=x[i];
	posmen=i;
	posmai=i;
	for (i=1;i<3;i++){
		printf("Digite um numero inteiro:\n");
		scanf("%i",&x[i]);
		if (x[i]>=maior){
			maior=x[i];
			posmai=i;
		}
		if (x[i]<=menor){
			menor=x[i];
			posmen=i;
		}
	}
	dif=maior-menor;
	printf("A diferenca e': %i\n",dif);
	printf("A posicao do maior e: %i\n",posmai);
	printf("A posicao do menor e: %i\n",posmen);
	return 0;
}