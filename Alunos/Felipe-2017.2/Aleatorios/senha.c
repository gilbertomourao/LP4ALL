#include <stdio.h>
#define SENHA 1234

int main(void){
	int s,i=0;
	printf("Senha:\n");
	scanf("%d",&s);
	while(i<=3){
		if (s!=SENHA){
			printf("Senha errada!\n\a");
			i++;
			printf("Vc tem mais %i chances",i);
		}
		else{
			printf("Senha valida");
		}
	}
	return 0;
}