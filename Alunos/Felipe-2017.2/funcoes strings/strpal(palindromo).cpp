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

void strpal(char st[]){
	
	int i,j;
	for(i=0,j=strlen(st)-1;st[i]!='\0';i++,j--){
		if(st[i]!=' '&&st[j]==st[i]){
			printf("E palindromo\n");
			break;
		}
		else{
			printf("Nao e palindromo\n");
			break;
		}
	}
}

int main(){
	
	char frase[MAX];
	puts("Digite uma palavra pra saber se e palindromo:");
	gets(frase);
	strpal(frase);
	return 0;
}