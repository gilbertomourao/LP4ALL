#include <stdio.h>

int main (){
	
	int n,soma,cont;
	cont=1;
	soma=0;
	
	while (cont<=5){
		printf("Digite o %d valor:\n",cont);
		
		scanf("%d",&n);
		
		cont=cont+1;
		
		soma=soma+n;
	}
	printf("A soma dos valores digitados e= %d",soma);
	
	return 0;
}
