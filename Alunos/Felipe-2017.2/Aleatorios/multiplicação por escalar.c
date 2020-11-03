#include <stdio.h>
int linha(){
	int i;
	for (i=1;i<=10;i++){
		printf("*");
	}
}
int main(int argc, char** argv)
{
	float x,vetor[10];
	int i;
	printf("Digite as componentes do vetor:\n");
	for(i=0;i<10;i++){
		scanf("%f",&vetor[i]);
	}
	printf("Digite um valor:\n");
	scanf("%f",&x);
	linha();//imprimi linha de 10 asteriscos 
	for (i=0;i<10;i++){
		vetor[i]*=x;
		printf("\n%7.2f",vetor[i]);
	}
	return 0;
}