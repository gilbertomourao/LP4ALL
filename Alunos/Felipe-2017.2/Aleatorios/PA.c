#include <stdio.h>
#define MAX 100

int main(int argc, char** argv)
{
	int r,i,t,an[MAX];
	printf("Digite quantos termos tera a P.A.:\n");
	scanf("%i",&t);
	printf("Digite uma razao:\n");
	scanf("%i",&r);
	printf("Digite o primeiro termo:\n");
	scanf("%i",&an[0]);
	for (i=1;i<=t;i++){
		an[i]=an[0]+(i-1)*r;
		printf("%i na posicao %i\n",an[i],i);
	}
	return 0;
}