#include <stdio.h>
#include <stdlib.h>

void dimensao(int *,int *);
void leitura(int *,int *,int [][100]);
void mostra(int *,int *,int [][100]);
void fator(int *);
void multiplica(int *,int *,int *,int [][100]);

int main(){
	
	int L,C,n;
	int mat[100][100];
	
	dimensao(&L,&C);
	leitura(&L,&C,mat);
	mostra(&L,&C,mat);
	fator(&n);
	multiplica(&L,&C,&n,mat);
	mostra(&L,&C,mat);
	
	
	return 0;
}

void dimensao(int *L,int *C){
	
	int i, j;
	
	printf("Insira o numero de linhas: "); scanf("%d", &i); fflush(stdin);
	printf("Insira o numero de colunas: "); scanf("%d", &j); fflush(stdin);
	
	*L = i;
	*C = j;
}

void leitura(int *L,int *C,int mat[][100]){
	
	int i,j;
	
	for (i = 0;i < *L;i++)
		for (j = 0;j < *C;j++){
			printf("Elemento [%d][%d] ",i,j);
			scanf("%d", &mat[i][j]);
		}
		
	system("cls");	
	
}

void mostra(int *L,int *C,int mat[][100]){

	int i,j;
	
	for (i = 0;i < *L;i++){
		for (j = 0;j < *C;j++)
			printf("\t%d", mat[i][j]);
		putchar('\n');
	}
}	

void fator(int *n){
	
	int f;
	
	/*Leitura de um fator*/
	
	printf("\nInsira um fator: "); scanf("%d", &f);
	
	*n = f;
}

void multiplica(int *L,int *C,int *n,int mat[][100]){
	
	int i,j;
	
	/*Multiplica pela diagonal*/
	
	for (i = j = 0;i < *L && i < *C;i++,j++)
		mat[i][j] *= *n;
	
}