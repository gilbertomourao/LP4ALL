/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Procura se uma string está dentro de outra !!!
Ano: 2017.2
*/
#include <stdio.h>
int segm(char s[],char t[]);
int main(){
	char st[]="ola";
	char st2[]="ola mundo";
	printf("%d",segm(st,st2));
	return 0;
}

int segm(char s[],char t[]){
	int i=0,j=0;
	while(t[i]!='\0'){
		while(t[j]!='\0'&&s[j]!='\0'&&t[i+j]==s[j]){
			j++;
		}
		if(s[j]=='\0'){
			return 1;
		}
		j=0;
		i++;
	}
	return 0;
}