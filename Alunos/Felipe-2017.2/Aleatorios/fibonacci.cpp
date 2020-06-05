#include <stdio.h>

int main (){
	
	int p,s,t,n,cont;
	p=0;
	s=1;
	printf("Sabendo que os dois primeiros termos da sequencia de Fibonacci");
	printf("\nsao 0 e 1\n");
	printf("Digite ate qual termo deseja saber a sequencia de Fibonacci:\n");
	scanf("%d",&n);
		if (n>2){
				printf("A sequencia e:\n");
				printf("%d\n",p);
				printf("%d\n",s);
				for (cont=3;cont<=n;cont++){ /*Contador para a sequência */
				t=s+p;	//operações para o cálculo da sequência
				p=s; //operações para o cálculo da sequência
				s=t; //operações para o cálculo da sequência
				printf("%d\n",t);		
			}
		}
		else if(n==1){
				printf("O primeiro termo da sequencia e:\n");
				printf("%d\n",p);
		}
		else if (n==2){
				printf("A sequencia e:\n");
				printf("%d\n",p);
				printf("%d\n",s);
		}
		else{
			printf("Digite um numero maior que zero !\n\a");//caso o numero digitado for zero ou menor será ixibida essa mensagem e soará um alarme
		}
	return 0;
}
