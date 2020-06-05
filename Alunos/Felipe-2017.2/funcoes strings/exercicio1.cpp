#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main(){
	char nome[MAX],sob[MAX];
	while(1){
		puts("Digite o nome:");
		gets(nome);
		if(nome[0]=='\0'){
			break;
		}
		else{
			puts("Digite o sobrenome:");
			gets(sob);
			printf("%s, %s\n",sob,nome);
		}
		
	}
	return 0;
}