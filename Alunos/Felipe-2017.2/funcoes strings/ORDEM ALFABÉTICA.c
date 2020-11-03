#include <stdio.h>
#include <string.h>

int main(){
	int num,i,j;
	puts("Digite o numero de nomes");
	scanf("%d",&num);
	char nome[num][30],aux[30];
	for(i=0;i<num;i++){
		printf("Nome:\n");
		fflush(stdin);
		scanf("%s", nome[i]);
	}
	for(i=1;i<num;i++){
		for(j=1;j<num;j++){
			if(strcmp(nome[j-1],nome[j])>0){
		          strcpy(aux, nome[j - 1]);
	 	 	      strcpy(nome[j - 1], nome[j]);
                  strcpy(nome[j], aux);
			}
		}
	}
	for (i = 0; i < num; i++)
   	   printf("\n%s", nome[i]);
	
	return 0;
}