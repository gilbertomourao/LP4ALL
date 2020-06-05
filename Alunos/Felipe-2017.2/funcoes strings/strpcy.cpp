#include <stdio.h>
#include <stdlib.h>

char *strcpy(char dest[],char orig[]){
	int i=0;
	for (i=0;orig[i]!='\0';i++){
		dest[i]=orig[i];	
	}
	return dest;
}

int main(){
	   	
	char string1[10],string2[10];
	puts("Digite a string:");
	gets(string1);
	puts("Digite a string a ser copiada:");
	gets(string2);
	printf("%s",strcpy(string1,string2));
	return 0;
}