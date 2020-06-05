#include <stdio.h>
#include <string.h>
#define MAX 100
int main(){
	int i,t,j;
	char str[MAX],aux;
	printf("Digite uma string:\n");
	gets(str);
	t=strlen(str);
	for(i=0;i<t;i++){
		for(j=i+1;j<t;j++){
			if(str[i]>str[j]){
				aux=str[i];
				str[i]=str[j];
				str[j]=aux;
			}
		}
	}
	printf("Ordenando:\n");
	printf("%s",str);
	return 0;
}