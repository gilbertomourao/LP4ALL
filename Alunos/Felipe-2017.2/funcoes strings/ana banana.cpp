#include <stdio.h>

int compara(char st1[],char st2[]);

int main(int argc, char** argv)
{
	char palavra[100],frase[100];
	printf("Digite uma frase:\n");
	gets(frase);
	printf("Digite uma palavra:\n");
	gets(palavra);
	printf("A palavra %s aparece %d vez(es)",palavra,compara(frase,palavra));
	return 0;
}

//Funções 
int compara(char st1[],char st2[]){
	int i=0,cont=0,j=0;
	while(st1[i]!='\0'){
		while(st1[i+j]!='\0'&&st2[j]!='\0'&&st1[i+j]==st2[j]){j++;}
		if(st2[j]=='\0'){
			cont+=1;
		}
		j=0;
		i++;
	}
	return cont;
}
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
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













