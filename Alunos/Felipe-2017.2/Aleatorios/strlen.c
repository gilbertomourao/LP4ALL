#include <stdio.h>

int main(){
	char op[20];
	int i=0;
	printf("digite uma string:\n");
	gets(op);
	while(op[i]!='\0'){
		i++;
	}
	printf("%d",i);
	return 0;
}