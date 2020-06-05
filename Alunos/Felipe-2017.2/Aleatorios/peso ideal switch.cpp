#include <stdio.h>

int main()
{
	float h,pi;
	char sexo;
	printf("Digite sua altura:\n");
	scanf("%f",&h);
	printf("Digite seu sexo [M ou F]:\n");
	scanf("%s",&sexo);
	switch(sexo)
	{
	case 'M':
		pi=72.7*h-58;
		printf("O peso ideal e': %f",pi);
		break;
	case 'm':
		pi=72.7*h-58;	
		printf("O peso ideal e': %f",pi);
		break;
	case 'F':
		pi=62.1*h-44.7;
		printf("O peso ideal e': %f",pi);
		break;
	case 'f':	
		pi=62.1*h-44.7;
		printf("O peso ideal e': %f",pi);
		break;
	default:
		printf("Nao posso informar !!!");
		break;
	}
	return 0;
}