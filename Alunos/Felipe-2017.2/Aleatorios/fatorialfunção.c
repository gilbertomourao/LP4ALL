#include <stdio.h>
int fat(int n);
int main(){
	int num;
	printf("Digite um numero:\n");
	scanf("%i",&num);
	if (num>=0){ 
		printf("%d",fat(num));
	}
	else{
		printf("Não tem fatorial !!!");
	}
	return 0;
}
int fat(int n){
	int i,fat;
	fat=1;
	for (i=1;i<=n;i++){
	fat*=i;
	}
	return fat;
}