#include <stdio.h>
#include <string.h>
int main(){
	char string[100];
	int i,j,cont=0;
	puts("Digite uma string:");
	gets(string);
	for(i=0;string[i]!='\0';i++){
		if(string[i]>='a'&&string[i]<='z'){
			string[i]-=32;//conversor pra maiuscula
		}
	}
	if(string[0]>='A'&&string[0]<='Z'){
		cont++;
	}
	for(i=0,j=strlen(string);string[i]!='\0';i++,j--){
		if((string[i]<'A'||string[i]>'Z')&&(string[i+1]>='A'&&string[i+1]<='Z')){
			if(string[i]==string[j]){
				cont++;
			}
		}
	}
	printf("A string: %s tem %d palavras\n",string,cont);
	return 0;
}