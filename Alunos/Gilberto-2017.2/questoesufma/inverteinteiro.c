#include <stdio.h>

void inverte(int *,int *);

int main(){
	
	int a,b;
	
	printf("a: "); scanf("%d",&a);
	printf("b: "); scanf("%d",&b);
	
	inverte(&a,&b);
	
	printf("\na: %d   b: %d\n",a,b);
	
	return 0;
}	 	 	 

void inverte(int *x,int *y){
	
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
	
}