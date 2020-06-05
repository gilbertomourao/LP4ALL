#include <stdio.h>
#define MAX 100

void conversor(char *s);

int main(){
	
	char num[MAX];
	conversor(&num[0]);
	return 0;
}

void conversor(char *s){
	int i,j=0,tam=0,pot,tot=0;
	printf("Insira o numero binario:\n");
	gets(s);
	for(i=0;*(s+i)!='\0';i++){
		tam++;
	}
	for (i=0;i<tam;i++){
		if (*(s+i) < '0' || *(s+i) > '1'){
			puts("Invalido, tente novamente:");
			tam=0;
			gets(s);
			for(j=0;*(s+j)!='\0';j++){
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
		tot+=(*(s+i)-'0')*pot;
	}
	printf("Em decimal: %d",tot);
}















