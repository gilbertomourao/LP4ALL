#include <stdio.h>
#include <math.h>

float fodac(float x,int n){
	float resp;
	resp=pow(x,n);
	return resp;
	
}
int main(){
	int e;
	float b;
	printf("Digite a base:\n");
	scanf("%f",&b);
	printf("Digite o expoente:\n");
	scanf("%i",&e);
	printf("O resultado e: %.2f\n",fodac(b,e));
	return 0;
}