#include <stdio.h>

int main(){
	int lin,col,i,j,selin,secol;
	char sel;
	printf("Digite as dimensoes da matriz:\n");
	scanf("%i",&lin);
	scanf("%i",&col);
	int mataux[lin][col],matriz[lin][col];
	if (lin==col){
		for (i=0;i<lin;i++){
			for (j=0;j<col;j++){
				printf("Digite a posicao [%i][%i]\n",i,j);
				scanf("%i",&matriz[i][j]);
			}
		}
		printf("MATRIZ LIDA:\n");
		for (i=0;i<lin;i++){
			for (j=0;j<col;j++){
				printf("%2i",matriz[i][j]);
			}
			printf("\n");
		}	
		for (i=0;i<lin;i++){
			for (j=0;j<col;j++){
				mataux[i][j]=matriz[j][i];
			}
		}
		printf("DESEJA SELECIONAR UMA LINHA(l) OU COLUNA(c):\n");
		scanf(" %c",&sel);
		switch(sel){
		case 'l':
			printf("Selecione a linha:\n");
			scanf("%i",&selin);
			for (i=0;i<lin;i++){
				if (selin==i){
					for (j=0;j<col;j++){
						printf("%i",mataux[i][j]);
					}
					printf("\n");
				}
			}
			break;
		case 'c':
			printf("Selecione a coluna:\n");
			scanf("%i",&secol);
			break;
		default:
			printf("Nao posso proceder!!!");
			break;
		}
	}
	
	return 0;
}