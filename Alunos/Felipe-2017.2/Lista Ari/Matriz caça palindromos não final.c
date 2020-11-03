#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	
	char mat[100][100];
	int i,j,dim,cont=0;
	puts("Digite a dimensao:");
	scanf("%d",&dim);
	puts("digite a matriz:");
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("[%d][%d]\n",i+1,j+1);
			scanf(" %c",&mat[i][j]);
			system("cls");
		}
	}
	puts("Matriz digitada:");
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("%c",mat[i][j]);
			if(mat[i][j]>='a'&&mat[i][j]<='z'){
				mat[i][j]-=32;//CONVERTER TUDO PRA MAIÚSCULA
			}
		}
		puts(" ");
	}
	//LÓGICA DO PROGRAMA
	for(i=0;i<dim;i++){
		if(mat[i][0]==mat[i][i+1]){
			cont++;
		}
	}
	for(j=0;j<dim;j++){
		if(mat[0][j]==mat[j+1][j]){
			cont++;
		}
	}
	printf("TOTAL DE PALINDROMOS: %d\n",cont);
	system("pause");
	return 0;
}