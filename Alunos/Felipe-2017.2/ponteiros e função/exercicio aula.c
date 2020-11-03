#include <stdio.h>
#define MAX 100
void dim(int *lin,int *col);
void ler(int mat[][MAX],int lin,int col);
void tela(int mat[][MAX],int lin,int col);
void manip(int mat[][MAX],int lin,int col);
int main(int argc, char** argv){
	int l,c,mat[MAX][MAX];
	dim(&l,&c);//enviando os endereços onde serão amarzenado os valores de l e c
	ler(mat,l,c);
	tela(mat,l,c);
	manip(mat,l,c);
	printf("MATRIZ ALTERADA:\n");
	tela(mat,l,c);
	return 0;
}
void dim(int *lin,int *col){
	int a,b;
	printf("DIGITE A DIMENSAO DA MATRIZ:\n");
	scanf("%d %d",&a,&b);
	*lin=a;
	*col=b;
}
void ler(int mat[][MAX],int lin,int col){
	int i,j;
	printf("DIGITE A MATRIZ\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("[%d][%d]",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
}
void tela(int mat[][MAX],int lin,int col){
	int i,j;
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%3d",mat[i][j]);
		}
		puts("");
	}
}
void manip(int mat[][MAX],int lin,int col){
	int i,j,mult;
	printf("Digite o valor a multiplicar:\n");
	scanf("%d",&mult);
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			if(i==j){
				mat[i][j]=mult * mat[i][j];
			}
		}
	}
}


















