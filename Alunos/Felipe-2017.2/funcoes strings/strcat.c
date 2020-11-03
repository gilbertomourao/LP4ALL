#include <stdio.h>
#include <stdlib.h>

int strlen(char st[]){
	int i=0;
	while(st[i]!='\0'){
		i++;
	}
	return i;
}

void strcat(char st1[],char st2[]){
	
	int i,j;
	for(i=0,j=strlen(st1);st2[i]!='\0';i++,j++){
		st1[j]=st2[i];
	}
	printf("%s",st1);
}

int main(){
	char string1[10],string2[10];
	puts("Digite a primeira string:");
	gets(string1);
	puts("Digite a segunda string:");
	gets(string2);
	strcat(string1,string2);
	return 0;
}