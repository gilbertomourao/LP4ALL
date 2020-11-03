#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,l,c,coluna,escalar;
	printf("Digite o numero de linhas e colunas da matriz:\n");
	scanf("%i",&l);
	scanf("%i",&c);
	int matriz[l][c];
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("Digite o termo: [%i][%i]\n",i,j);
			scanf("%i",&matriz[i][j]);
		}
	}
	printf("MATRIZ DIGITADA:\n");
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			printf("%i ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("Digite qual coluna pretende alterar (0 a 2) e o escalar:\n");
	scanf("%i",&coluna);
	scanf("%i",&escalar);
	for (i=0;i<l;i++){
		for(j=0;j<c;j++){
			if (j==coluna){
				printf ("(POSICAO[%d][%d]) %d x %d = %d\n",i,j,matriz[i][j],escalar,matriz[i][j]*escalar);
			}
			printf("\n");
		}
	}
	return 0;
}