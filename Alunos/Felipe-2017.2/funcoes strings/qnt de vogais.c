#include <stdio.h>
#define MAX 20
int strlen(char s[]);
int main(){
	
	char letra,frase[MAX];
	int i,qnt;
	
	printf("Digite uma frase:\n");
	gets(frase);
	
	for(i=0,qnt=0;i<strlen(frase);i++){
		letra=frase[i];
		switch(letra){
		case 'a':
			qnt++;
			break;
		case 'e':
			qnt++;
			break;
		case 'i':
			qnt++;
			break;
		case 'o':
			qnt++;
			break;
		case 'u':
			qnt++;
			break;
		}
	}
	
	printf("A quantidade de vogais :%d",qnt);
	return 0;
}

int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}