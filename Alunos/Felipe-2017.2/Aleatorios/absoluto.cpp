#include <stdio.h>

int main (){
	float n;
	
	printf("Digite qualquer real:\n");
	
	scanf("%f",&n);
	
	if (n>=0){
		printf("O valor absoluto e: %f",n);
	}
	else {
		printf("O valor absoluto e: %f",-n);
	}	
	return 0;
}
