#include <string.h>
#include <stdio.h>
#define MAX 100
int main(){
	
	char num[MAX];
	int i,j,tam=0,pot,tot=0;
	puts("Digite um numero em binario");
	
	for (i=0;i<MAX;i++){
		scanf("%c",&num[i]);
		if (num[i] == '\n'){
			break;
		}	
		tam++;
	}
	for (i=0;i<tam;i++){
		if (num[i] < '0' || num[i] > '1'){
			puts("Invalido, tente novamente:");
			tam=0;
			for (j=0;j<MAX;j++){
				scanf("%c",&num[j]);
				if (num[j] == '\n'){
					break;
				}
				tam++;
			}
			i = -1;
		}
	}
	
	for(i=0;i<tam;i++){
		j=tam-i-1;
		pot=1;
		while(j>0){
			pot=pot*2;
			j--;
		}
		tot+=(num[i]-'0')*pot;//o '0' serve pra exibir o resultado inteiro do numero, se nao for posto o valor exibido sera da tabela ascii 
	}
	printf("Em decimal : %d",tot);
	return 0;
}