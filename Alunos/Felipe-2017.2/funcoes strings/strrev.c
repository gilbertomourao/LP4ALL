#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int strlen(char st[]){
	int i=0;
	while(st[i]!='\0'){
		i++;
	}
	return i;
}

char *strrev(char st[]){
	
	int i,j;
	char aux;
	for(i=0,j=strlen(st)-1;i<j;i++,j--){
		aux=st[i];
		st[i]=st[j];
		st[j]=aux;
	}
	return st;
}

int main(){
	
	char string[MAX];
	puts("Digite uma string:");
	gets(string);
	printf("%s",strrev(string));
	return 0;
}