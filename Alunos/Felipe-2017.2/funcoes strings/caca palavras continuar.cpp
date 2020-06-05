#include <stdio.h>

int main(){
	int k,i,j,num,dim,encontrado;
	char caca[100][100],palavras[100][100];
	printf("Digite a dimensao da matriz caca palavras:\n");
	scanf("%d",&dim);
	for(i=0;i<dim;i++){
			scanf("%s",caca[i]);
	}
	printf("Digite o numero de palavras desejado:\n");
	scanf("%d",&num);
	printf("Digite as palavras q vc encontrou:\n");
	for(i=0;i<num;i++){
		scanf("%s",palavras[i]);
	}
	for(k=0;k<num;k++){
		encontrado=0;
		for(i=0;i<num;i++){
			for(j=0;i<num;j++){
				if(palavras[k][0]==caca[i][j]){

				}
			}
		}
	}
	return 0;
}