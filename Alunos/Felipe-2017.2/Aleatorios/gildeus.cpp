#include <stdio.h>

int main(int argc, char** argv)
{
	float notas[2];
	int i;
	char nome[2][10];
	for (i=0;i<2;i++){
		printf("Digite um nome:\n");
		scanf("%s",&nome[i]);
		printf("Digite a nota:\n");
		scanf("%f",&notas[i]);
	}
	for (i=0;i<2;i++){
		printf("Nota de %s: %7.2f\n",nome[i],notas[i]);
		printf("Gildeus>>>>>>>>>ABISMO>>>>>>>>>Fundo do poco>>>>>>>>> Luan\n");
	}
	return 0;
}