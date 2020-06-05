#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;
	char carac;
	printf("Digite o caractere q deseja procurar na tabela ASCII:\n");
	carac=getchar();
	for (i=0;i<=255;i++){
		if ((char)i==carac){
			printf("%c = %i em ASCII",i,(char)i);
			break;
		}
	}
	return 0;
}