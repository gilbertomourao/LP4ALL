#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int escolha(int *n);
void conversordec(char *s);
void conversorbin(int *x);
int main(){
	int dec,numdec;
	char numbin[MAX];
	
	if(1==escolha(&dec)){
		fflush(stdin);
		conversordec(&numbin[0]);
	}
	else{
		conversorbin(&numdec);
	}
	
	return 0;
}

int escolha(int *n){
	int esc;
	printf("-----------------------------------\n");
	printf("|                                 |\n");
	printf("|                             	  |\n");
	printf("|       CONVERSOR BINARIO E    	  |\n");
	printf("|             DECIMAL          	  |\n");
	printf("|   DIGITE[1] conv. pra decimal   |\n");
	printf("|              ou              	  |\n");
	printf("|   DIGITE[2] conv. pra binario   |\n");
	printf("|                           	  |\n");
	printf("|                           	  |\n");
	printf("-----------------------------------\n");
	scanf("%d",&esc);
	*n=esc;
	system("cls");
	while(*n < 1||*n > 2){
		printf("Invalido, tente novamente\n");
		printf("-----------------------------------\n");
	   	printf("|                                 |\n");
		printf("|                             	  |\n");
		printf("|       CONVERSOR BINARIO E    	  |\n");
		printf("|          DECIMAL          	  |\n");
		printf("|   DIGITE[1] conv. pra decimal   |\n");
		printf("|           ou              	  |\n");
		printf("|   DIGITE[2] conv. pra binario   |\n");
		printf("|                           	  |\n");
		printf("|                           	  |\n");
		printf("-----------------------------------\n");
		scanf("%d",&esc);
		*n=esc;
		system("cls");
	}
	if(*n==1){
		return 1;
	}
	else{
		return 0;
	}
}
void conversordec(char *s){
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
void conversorbin(int *x){
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