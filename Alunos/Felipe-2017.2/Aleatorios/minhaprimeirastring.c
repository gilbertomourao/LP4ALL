#include <stdio.h>
#define MAX 100
int main(){
	
	char resp='s',string[MAX];
	int i;
		while (resp=='s'){
		
			printf("Digite um nome:\n");	  		
			scanf("%s",&string);
			printf("%s \n",string);
			
			printf("Deseja continuar [s] ou [n]:\n");
			scanf(" %c",&resp);
			
		}
	return 0;
}