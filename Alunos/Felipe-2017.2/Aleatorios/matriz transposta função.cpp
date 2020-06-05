#include <stdio.h>
#define DIM 3
void receber(int mat[][DIM],int mataux[][DIM]);
void tela(int mat[][DIM]);
void telatrans(int mataux[][DIM]);
int main(){
	int matriz[DIM][DIM],matriz2[DIM][DIM];
	
	printf("--------------------------------------------------\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|              MATRIZ TRANSPOSTA 3X3             |\n");
	printf("|             	    PRESSIONE                    |\n");
	printf("|                     ENTER                      |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("--------------------------------------------------\n");
	
	getchar();
	
	receber(matriz,matriz2);
	tela(matriz);
	telatrans(matriz2);
	return 0;
}
void receber(int mat[][DIM],int mataux[][DIM]){
	int i,j;
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
			printf("Digite o elemento [%d][%d]:\n",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
				mataux[i][j]=mat[j][i];
			}
		}
}
void tela(int mat[][DIM]){
	int i,j;
	printf("-----------------------------\n");
	printf("MATRIZ DIGITADA:\n");
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
			printf("%3d",mat[i][j]);
		}
		printf("\n");
	}
}
void telatrans(int mataux[][DIM]){
	int i,j;
	printf("-----------------------------\n");
	printf("MATRIZ TRANSPOSTA:\n");
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++){
			printf("%3d",mataux[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}