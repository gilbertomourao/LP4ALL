#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
	float soma,sal[12];
	int i;
	soma=0;
	for (i=0;i<12;i++){
		printf("Digite o salario do mes %i:\n",i+1);
		scanf("%f",&sal[i]);
		soma+=sal[i];
	}
	for (i=0;i<12;i++){
		printf("O valor no mes %i foi: %f\n",i+1,sal[i]);
	}
	printf("O total anual foi: %f\n",soma);
	return 0;
}