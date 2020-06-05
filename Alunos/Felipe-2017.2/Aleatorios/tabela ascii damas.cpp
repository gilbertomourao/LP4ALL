#include <stdio.h>

int main(){
	
	int i;
	char resp;
	printf("TABELA ASCII:\n");
	for (i=0;i<=255;i++){
		printf("%d----->%c\n",i,(char)i);
		if (i%20==0){
			printf("deseja continuar:\n");
			scanf(" %c", &resp);
			switch(resp){
			case 'c':
				getchar();
				break;
			case 'C':
				getchar();
				break;
			}
		}
		
	}
	return 0;
}