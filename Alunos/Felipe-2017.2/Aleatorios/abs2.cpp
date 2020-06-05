#include <stdio.h>

int main(int argc, char** argv)
{
	float n;
	printf("Digite um numero para saber seu valor absoluto:\n");
	scanf("%f",&n);
	n>=0 ? printf("%f",n):printf("%f",-n);

	return 0;
}
