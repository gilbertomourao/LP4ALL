#include <stdio.h>

int main(int argc, char** argv)
{
	int i,j,vetor[9];
	printf("Digite numeros:\n");
	for (i=0;i<9;i++){
		scanf("%d",&vetor[i]);
	}
	for(i=0;i<9;i++){
		for(j=i+1;j<9;j++){
			if(vetor[j]==vetor[i]){
				printf("%d\n",vetor[i]);
			}
		}
	}
	return 0;
}