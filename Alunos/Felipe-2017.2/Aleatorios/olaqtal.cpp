#include <stdio.h>

int main(int argc, char** argv)
{
	float num1,num2;
	
	printf("Digite dois numeros para saber qual o maior:\n");
	scanf("%f %f",&num1,&num2);
	num1>num2 ? printf("O maior e':%f",num1):printf("O maior e':%f",num2);
	return 0;
}
