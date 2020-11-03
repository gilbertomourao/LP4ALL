#include <stdio.h>

int main (){
	
	float cel,fah;
	
	printf("Digite a temperatura em Fahrenheit para a conversao:\n");
	
	scanf("%f",&fah);
	
	cel=(fah-32)*5/9;
	
	printf("A temperatura e: %.2f Celsius",cel);
	return 0;
}
