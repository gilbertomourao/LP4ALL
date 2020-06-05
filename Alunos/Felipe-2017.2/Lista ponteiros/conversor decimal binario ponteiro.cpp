#include <stdio.h>

void conversor(int *x);

int main(){
	int num;
	conversor(&num);
	return 0;
}

void conversor(int *x){
	int a,aux[50],i=0,tam;
	printf("Digite o numero em decimal:\n");
	scanf("%d",&a);
	*x=a;
	while((*x)!=0){
		aux[i]=(*x)%2;
		i++;
		*x = (*x)/2;
	}
	tam=i-1;
	//inverte o valor pra ser mostrado na ordem correta
	for(i=tam;i>=0;i--){
		printf("%d",aux[i]);
	}
}