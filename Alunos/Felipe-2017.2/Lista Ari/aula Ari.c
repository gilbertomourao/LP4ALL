#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i,j;
	char mat[5][5],aux[5],ord;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("Digite a posicao [%d][%d]",i+1,j+1);
			scanf(" %c",&mat[i][j]);
		}
	}
	printf("Matriz:\n");
	puts(" ");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c",mat[i][j]);
		}
		puts(" ");
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==j){
				aux[i]=mat[i][j];
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=i+1;j<5;j++){
			if(aux[i]>aux[j]){
				ord=aux[i];
				aux[i]=aux[j];
				aux[j]=ord;
			}
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i==j){
				mat[i][j]=aux[i];
			}
		}
	}
	puts(" ");
	printf("Matriz com diagonal ordenada\n");
	puts(" ");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c",mat[i][j]);
		}
		puts(" ");
	}
	
	system("pause");
}
