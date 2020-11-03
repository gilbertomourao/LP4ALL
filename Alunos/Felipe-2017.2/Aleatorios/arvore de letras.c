#include <stdio.h>

int main(int argc, char** argv)
{
	int i,j,num;
	printf("Digite um numero:\n");
	scanf("%d",&num);
	for(i=64;i<64+num;i++){
		for(j=64;j<i;j++){
			printf("%c",j);
		}
		printf("\n");
	}
	return 0;
}