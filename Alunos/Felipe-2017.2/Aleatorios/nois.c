#include <stdio.h>

int main(int argc, char** argv)
{
	int numero,soma,contador;
	soma=0;
	
	do {
		
	printf("Digite um número de 1 a 5");
	scanf("%d",&numero);
	
	switch(numero)
	{
	case 1:
		soma=soma+1;
		break;
	case 2:
		soma=soma+1;
		break;
	} 
	}while (numero != 0);
	printf("%i",soma);
	
	return 0;
}
