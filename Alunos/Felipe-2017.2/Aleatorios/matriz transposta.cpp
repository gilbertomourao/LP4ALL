#include <stdio.h>

int main(){
	
	int l,c,i,j;
	printf("Digite as dimensoes da MATRIZ:\n");
	scanf("%i",&l);
	scanf("%i",&c);
	int matA[l][c],matB[l][c];
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("Digite a posicao [%i][%i]\n",i+1,j+1);
			scanf("%i",&matA[i][j]);
		}
	}
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			matB[i][j]=matA[j][i];
		}
	}
	printf("MATRIZ DIGITADA:\n");
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("%3i",matA[i][j]);
		}
		printf("\n");
	}
	printf("MATRIZ TRANSPOSTA:\n");
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("%3i",matB[i][j]);
		}
		printf("\n");
	}
	return 0;
}