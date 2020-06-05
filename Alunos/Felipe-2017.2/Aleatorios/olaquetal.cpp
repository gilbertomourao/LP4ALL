#include <stdio.h>

int main(int argc, char** argv)
{
	float a,b;
	printf("Digite dois numeros para saber qual o maior:\n");
	scanf("%f %f",&a,&b);
	if (a!=b){
		a>b ? printf("O maior e': %7.2f\ \n",a):printf("O maior e': %7.2f\ \n",b);	
	}
	else{
		printf("Os numeros sao iguais");
	}
	return 0;
}