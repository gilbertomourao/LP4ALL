#include <stdio.h>

int main(){
	
	int x,y,aux;
	
	printf("Digite um numero:\n");
	
	scanf("%d",&x);
	
	printf("Digite um numero:\n");
	
	scanf("%d",&y);
	
	if(x>y){
		
		aux=x;
		x=y;
		y=aux;
		
	}
	
	printf("%d %d \n",x,y);
	
	return 0;
}