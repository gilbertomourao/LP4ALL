#include <stdio.h>
#define MAX 100
int main(int argc, char** argv)
{
	int i,t,num[MAX];
	printf("Digite o tamanho da sequencia:\n");
	scanf("%i",&t);
	printf("Digite a sequencia:\n");
	for (i=0; i < t; i++){
		scanf("%i",&num[i]);
	}
	printf("A ordem inversa e':\n");
	for (i=t-1; i>=0; i--){
		printf("%i",num[i]);
		printf("\n");
	}
	return 0;
}