#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i,j,aux,l,c;
	printf("Digite a quantidade de linhas e colunas:\n");
	scanf("%d %d",&l,&c);
	int matA[l][c];
	//pegar os elementos da matriz
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("\nDigite o elemento [%d][%d]:\n",i,j);
			scanf("%d",&matA[i][j]);
		}
	}
	//exibir a matriz selecionada
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("%3d",matA[i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");
	//inversão na 1º linha 
	for (i=0,j=c-1;i<c,j>0;i++,j--){
			aux=matA[0][j];
			matA[0][j]=matA[0][i];
			matA[0][i]=aux;
	}
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("%3d",matA[i][j]);
		}
		printf("\n");
	}
	return 0;
}