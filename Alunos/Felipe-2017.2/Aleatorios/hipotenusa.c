#include <stdio.h>
#include <math.h>

int main(){
	float a,b,c;
	
	printf("Digite o valor do primeiro cateto:\n");
	scanf("%f",&a);
	
	printf("Digite o valor do segundo cateto:\n");
	scanf("%f",&b);
	
	c=sqrt (a*a+b*b);// C�lculo da hipotenusa
	
	printf("A hipotenusa e= %f",c);//Impress�o na tela do valor
	return 0;
}
