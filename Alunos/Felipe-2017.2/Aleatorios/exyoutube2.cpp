#include <stdio.h>

int main(){
	
	int n1,n2;
	
	printf("Coloca dois numeros fdp\n");
	scanf("%i%i",&n1,&n2);
	
	if (n2==0){
		printf("foda-se");
	}
	else {
		if (n1 % n2==0){
			printf("Retardado");
		}
		else {
			printf("Idiota");
		}
		
	}
	
	return 0;
}
