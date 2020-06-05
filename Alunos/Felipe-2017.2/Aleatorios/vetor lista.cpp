#include <stdio.h>
int main(int argc, char** argv)
{
	int i,nota[3];
	char nome[3][10];
	printf("ffefe\n");
	for (i=0; i<=2; i++){
		printf("Digite seu nome:\n");
		scanf("%s",&nome[i]);
		printf("Digite sua nota:\n");
		scanf("%i",&nota[i]);
	}
	for (i=0;i<=2;i++){
		printf("%s\n",nome[i]);
	}
	return 0;
}
