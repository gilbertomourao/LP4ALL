#include <stdio.h>
#include <stdlib.h>

int main(){
	int num,aux[30],i=0,tam,dec;
	puts("Digite o numero decimal:");
	scanf("%d",&num);
	dec=num;
	while(num!=0){
		aux[i]=num%2;
		i++;
		num/=2;
	}
	tam=i-1;//tamanho do vetor "-1 pois o i é incrementado um vez a mais do que o tamanho do vetor"
	//lógica que inverte pra mostrar a conversão na ordem
	if(dec==0){
		printf("BINARIO----->0");
	}
	else{
		printf("BINARIO----->");
		for(i=tam;i>=0;i--){
			printf("%d",aux[i]);
		}
	}	
	return 0;
}