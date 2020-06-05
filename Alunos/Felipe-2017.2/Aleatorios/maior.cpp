#include <stdio.h>

int main (){
	int a, b;
	
	printf("Digite o primeiro valor:\n");
	
	scanf("%d",&a);
	
	printf("Digite o segundo valor:\n");
	
	scanf("%d",&b);
	
	// estrura condicional para saber qual o maior ou mnenor
	if (b>a){
		printf("O maior e %d",b);
	}
	else {
		printf("O maior e %d",a);
	}
	return 0;
}
