#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	
	int p,sb,num,aux=0,tot=0;
	puts("Digite o numero binario:");
	scanf("%d",&num);
	p=1;//condi��o inicial do incremento da pot�ncia de dois
	
	while(num!=0){
		while(num<0){
			printf("Valor invalido\n");
			puts("Digite novamente:");
			scanf(" %d",&num);
		}
		aux=num%10;//aux resto do n�mero bin�rio
		num/=10;//recebe a parte inteira da divis�o para continuar o c�lculo com aux
		sb=aux*p;//realiza a convers�o multiplicando pela pot�ncia de dois
		p=p*2;//incrementa a potencia de dois
		tot+=sb;//soma as parcelas da convers�o para formar o n�mero bin�rio
	}
	printf("DECIMAL------->%d",tot);
	return 0;
}