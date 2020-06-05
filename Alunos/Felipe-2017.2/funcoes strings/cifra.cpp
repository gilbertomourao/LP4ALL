#include <stdio.h>

void inverte(int num){
	int cifra;
	if(num>0){
		do{
			cifra=num%10;
			printf("%d",cifra);
			num/=10;
		}while(num!=0);
	}
	else if(num<0){
		num*=-1;
		printf("-");
		do{
			cifra=num%10;
			printf("%d",cifra);
			num/=10;
		}while(num!=0);
	}
}

int main(int argc, char** argv)
{
	int numero;
	printf("diigite um numero:\n");
	scanf("%d",&numero);
	inverte(numero);
	return 0;
}