#include <stdio.h>

#define MAX 30

int main(){
	
	int num,i,j;
	int vet[MAX], mat[MAX][MAX];
	
	printf("Insira um numero inteiro positivo: "); scanf("%d", &num); fflush(stdin); /*Não recomendo fazer isso*/
	
	while (num <= 0){
		printf("NUMERO INVALIDO!!! Tente novamente: ");
		scanf("%d", &num); fflush(stdin);/*Não recomendo fazer isso*/
	}
	
	/*Cria o vetor*/
	for (i=0;i< num;i++)
		vet[i] = i+1;
	
	/*Cria a matriz*/
	for (i=0;i<=num/2;i++)
		for (j=0;j<num;j++)
			mat[i][j] = 0;
	
	for (i=0;i<=num/2;i++)
		for (j=i;j<num-i;j++)
			mat[i][j] = vet[j];	
	/**/	
		
	/*Imprime a matriz*/ 
	for (i=0;i<=num/2;i++){
		for (j=0;j<num;j++)
			if (mat[i][j] == 0)
				printf("  ");
			else
				printf("%d ", mat[i][j]);
		putchar('\n');
	}
	
	return 0;
}