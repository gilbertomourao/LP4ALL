#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
	int i,j,dim,esc,num;
	char mat[100][100],vet[100],aux;
	puts("MATRIZ");
	puts("Digite a dimensao:");
	scanf("%d",&dim);
	fflush(stdin);
	puts("Preencha a matriz:");
	for(i=1;i<dim+1;i++){
		for(j=1;j<dim+1;j++){
			printf("[%d][%d]\n",i,j);
			scanf(" %c",&mat[i][j]);
			system("cls");
		}
	}
	puts("________________");
	puts("MATRIZ DIGITADA:");
	for(i=1;i<dim+1;i++){
		for(j=1;j<dim+1;j++){
			printf("%3c",mat[i][j]);
		}
		puts(" ");
	}
	puts("Digite (1) para ordenar linha ou (0) para ordenar coluna:");
	scanf("%d",&esc);
	while((esc<0)||(esc>1)){
		puts("invalido, tente novamente:");
		scanf("%d",&esc);
		
	}
	if(esc==1){
		printf("Digite a linha:\n");
		scanf("%d",&num);
		while((num<1)||(num>dim)){
			printf("Nao foi encotrada a linha %d, tente novamente:\n",num);
			scanf("%d",&num);
		}
		for(j=1;j<dim+1;j++){
			vet[j]=mat[num][j];
		}
		for(i=1;i<dim+1;i++){
			for(j=i+1;j<dim+1;j++){
				if(vet[i]>vet[j]){
					aux=vet[i];
					vet[i]=vet[j];
					vet[j]=aux;
				}
			}
		}
		for(j=1;j<dim+1;j++){
			mat[num][j]=vet[j];
		}
	}
	if(esc==0){
		printf("Digite a coluna:\n");
		scanf("%d",&num);
		while((num<1)||(num>dim)){
			printf("Nao foi encotrada a linha %d, tente novamente:\n",num);
			scanf("%d",&num);
		}
		for(i=1;i<dim+1;i++){
			vet[i]=mat[i][num];
		}
		for(i=1;i<dim+1;i++){
			for(j=i+1;j<dim+1;j++){
				if(vet[i]>vet[j]){
					aux=vet[i];
					vet[i]=vet[j];
					vet[j]=aux;
				}
			}
		}
		for(i=1;i<dim+1;i++){
			mat[i][num]=vet[i];
		}
	}
	puts("________________");
	puts("MATRIZ ORDENADA:");
	for(i=1;i<dim+1;i++){
		for(j=1;j<dim+1;j++){
			printf("%3c",mat[i][j]);
		}
		puts(" ");
	}
	return 0;
}