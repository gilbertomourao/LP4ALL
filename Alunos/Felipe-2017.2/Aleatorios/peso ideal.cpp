#include <stdio.h>

int main(){
	char s;
	float h,pideal;
	
	printf("Digite sua altura:\n");
	
	scanf("%f",&h);
	
	printf("Digite seu sexo [M/F]:\n");
	
	scanf("%s",&s);
	
	if(s=='m'){
		pideal=72.7*h-58;
		printf("O peso ideal e: %f",pideal);
	} 
	else if (s=='f');{
		pideal=62.1*h-44.7;
		printf("O pesso ideal e: %f",pideal);
	}
	return 0;
}
