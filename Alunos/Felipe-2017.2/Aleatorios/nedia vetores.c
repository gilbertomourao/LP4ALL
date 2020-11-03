#include <stdio.h>

int main(int argc, char** argv)
{
	int i,soma,media,vetor[3];
	soma=0;
	printf("Digite as notas:\n");
	for (i=0; i<3; i++){
		scanf("%i",&vetor[i]);
		soma=soma+vetor[i];
	}
	media=soma/3;
	printf("A media e': %i",media);
	return 0;
}