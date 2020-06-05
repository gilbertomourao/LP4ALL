#include <stdio.h>

void intv(int x,int limi,int lims){
	if (x<=lims && x>=limi){
		printf("O valor esta no intevalo\n");
	}
	else{
		printf("O valor nao esta no intevalo\n");
	}
}
int main(int argc, char** argv)
{
	int a,int1,int2;
	printf("Digite um valor:\n");
	scanf("%i",&a);
	printf("Digite o intevalo inferior:\n");
	scanf("%i",&int1);
	printf("Digite o intevalo superior:\n");
	scanf("%i",&int2);
	intv(a,int1,int2);
	return 0;
}