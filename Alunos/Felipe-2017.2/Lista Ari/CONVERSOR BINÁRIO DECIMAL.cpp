#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	
	int p,sb,num,aux=0,tot=0;
	puts("Digite o numero binario:");
	scanf("%d",&num);
	p=1;//condição inicial do incremento da potência de dois
	
	while(num!=0){
		while(num<0){
			printf("Valor invalido\n");
			puts("Digite novamente:");
			scanf(" %d",&num);
		}
		aux=num%10;//aux resto do número binário
		num/=10;//recebe a parte inteira da divisão para continuar o cálculo com aux
		sb=aux*p;//realiza a conversão multiplicando pela potência de dois
		p=p*2;//incrementa a potencia de dois
		tot+=sb;//soma as parcelas da conversão para formar o número binário
	}
	printf("DECIMAL------->%d",tot);
	return 0;
}