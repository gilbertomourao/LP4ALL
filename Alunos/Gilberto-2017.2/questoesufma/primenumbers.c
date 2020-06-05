#include <stdio.h> 

int isprime (int);

int main(){
	
	int qtd,n;
	
	printf("Quantos numeros deseja informar? "); scanf("%d",&qtd);
	while (getchar()!='\n');
	
	while (qtd){
		printf("\nInsira um numero: "); scanf("%d", &n);
		while (getchar()!='\n');
		if (isprime(n))
			printf("\nE PRIMO!!!\n");
		else 
			printf("\nNAO E PRIMO!!!\n");
		qtd--;
	}
	
	return 0;	
}

int isprime (int n){

	int i = n/2;
	
	if (n < 2) return 0;
	else if (n == 2) return 1;
	else if (n%2 == 0) return 0;
	else {
		if (i%2 == 0) i--;
		if (i == 1) return 1;
		else 
			while (i-1){
				if (n%i == 0) return 0;
				i-=2;
			}
	}
	
	return 1;
}