#include <stdio.h>
char toupper(char c);
void touppers(char s[]);
int strlen(char s[]);
int main(){
	char nome[30];
	int i;
	printf("Digite seu nome completo:\n");
	gets(nome);
	
	
	for(i=0;nome[i]!='\0';i++){
		if(nome[i]>='A' && nome[i]<='Z'){
			printf("%c.",nome[i]);
		}
	}
		
	return 0;
}

//Funções

int strlen(char s[]){
	
	int i=0;
	
	while(s[i]!='\0'){i++;}
		
	return i;

}

char toupper(char c){
	
	if(c>='a'&&c<='z'){
		
		return (c-=32);
		
	}
	else{
		
		return c;
		
	}
}

void touppers(char s[]){
	
	int i;
	
	char c;
	
	for(i=0;i<strlen(s);i++){
		
		c=s[i];
		
		s[i]=toupper(c);
		
	}
}