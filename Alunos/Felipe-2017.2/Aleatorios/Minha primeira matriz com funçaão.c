#include <stdio.h>
void foda(){
	int s;
	for (s=1;s<=20;s++){
		printf("*");
	}
}
int main(int argc, char** argv)
{
	int i,j,l,c;
	printf("Matriz:\n");
	printf("Digite o numero de linhas e colunas:\n");
	scanf("%i %i",&l,&c);
	for (i=1;i<=l;i++){
		printf("*");
		for (j=1;j<=c;j++){
			printf("*");
		}
		printf("\n");
	}
	foda();//escreve uma linha de asteriscos
	return 0;
}