#include <stdio.h>

int main (){
	float sal,emp;
	
	printf("Digite seu salario:\n");
	
	scanf("%f",&sal);
	
	printf("Digite a parcela do emprestimo:\n");
	
	scanf("%f",&emp);
	
	if (emp>0.2*sal){
		printf("Emprestimo nao concedido");
	}
	else {
		printf("Emprestimo concedido");
	}
	return 0;
}
