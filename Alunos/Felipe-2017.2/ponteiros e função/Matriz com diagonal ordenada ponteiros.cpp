#include <stdio.h>
#define MAX 100
void dim(int *t);
void ler(char mat[][MAX],int dim);
void tela(char mat[][MAX],int dim);
void ordenar(char *m,int dim);

int main(){
	int tam;
	char mat[MAX][MAX];
	dim(&tam);//enviando os endereços onde serão amarzenado os valores de l e c
	ler(mat,tam);
	tela(mat,tam);
	ordenar(&mat[0][0],tam);
	printf("MATRIZ ALTERADA:\n");
	tela(mat,tam);
	return 0;
}
void dim(int *t){
	int a;
	printf("DIGITE A DIMENSAO DA MATRIZ:\n");
	scanf("%d",&a);
	*t=a;
}
void ler(char mat[][MAX],int dim){
	int i,j;
	printf("DIGITE A MATRIZ\n");
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("[%d][%d]",i+1,j+1);
			scanf(" %c",&mat[i][j]);
		}
	}
}
void tela(char mat[][MAX],int dim){
	int i,j;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("%3c",mat[i][j]);
		}
		puts("");
	}
}
void ordenar(char *m,int dim){
	int i,j;
	char aux;
	for(i=0;i<(MAX+1)*dim;i+=(MAX+1)){
		for(j=i+(MAX+1);j<(MAX+1)*dim;j+=(MAX+1)){
			if(*(m+i)>*(m+j)){
				aux=*(m+i);
				*(m+i)=*(m+j);
				*(m+j)=aux;
			}
		}
	}
}






