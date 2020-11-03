#include <stdio.h>
void trocar(int *x,int *y);
int main(){
	
	int a,b;
	int *p=&a,*q=&b;
	printf("Digite os valores:\n");
	scanf("%d %d",&a,&b);
	puts("Trocados:");
	trocar(p,q);
	
	
	return 0;
}

void trocar(int *x,int *y){
	int aux=0;
	aux=*x;
	*x=*y;
	*y=aux;
	printf("%d",*x);
	puts("");
	printf("%d",*y);
}
