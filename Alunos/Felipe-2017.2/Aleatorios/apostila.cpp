#include <stdio.h>

int main(){
	float salinicio,sal,reaj,abono;
	printf("Digite seu salario:\n");
	scanf("%f",&salinicio);
	abono=salinicio*1.05;
	if (salinicio<=750){
		sal=abono+100;
		reaj=sal-salinicio;
		printf("O seu novo salario e: %f \n",sal);
		printf("O reajuste foi de: %f\n",reaj);
	}
	else{
		reaj=abono-salinicio;
		printf("O seu novo salario e: %f\n",abono);
		printf("O reajuste foi de: %f\n",reaj);
	}
	return 0;
}
