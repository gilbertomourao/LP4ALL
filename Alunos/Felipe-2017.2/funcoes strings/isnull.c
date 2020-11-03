#include <stdlib.h>
#include <stdio.h>
int isnull(char st[]){
	if (st[0]=='\0'){
		puts("TRUE");
	}
	else{
		puts("FALSE");
	}
}

int main(){
	char string[10];
	puts("Nome:");
	gets(string);
	isnull(string);
	return 0;
}