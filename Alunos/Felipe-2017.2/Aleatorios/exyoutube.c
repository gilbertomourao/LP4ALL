#include <stdio.h>

int main()
{
	int n1,n2;
	printf("Digite o primeiro numero");
	scanf("%i",&n1);
	
	printf("Digite o segundo numero");
	scanf("i%",&n2);
	if (n2==0){
		printf("Divisao por zero nao e permitido");
	}
	else if (n1 % n2 == 0){
		printf("O primeiro numero nao e divisivel pelo segundo");
	}
	else {
		printf("O primeiro numero nao e divisivel pelo segundo");
	}
	
	return 0;
}