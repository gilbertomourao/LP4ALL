#include <stdio.h>
#include <math.h>
int main(int argc, char** argv)
{
	float a,b,c,raiz1,raiz2,delta;
	printf("Digite os coeficientes da equaçao do 2º grau:\n");
	scanf("%f %f %f",&a,&b,&c);
	delta=b*b-4*a*c;
	raiz1=(-b+sqrt(delta))/2*a;
	raiz2=(-b-sqrt(delta))/2*a;
	if (a!=0 && delta>0){
		printf("As raizes são: x1= %f e x2= %f ",raiz1,raiz2);
	}
	else printf("Nao existe raiz real");
	return 0;
}