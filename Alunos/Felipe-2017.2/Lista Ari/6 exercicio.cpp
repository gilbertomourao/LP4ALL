/*Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Imprimir uma sring ao contrário
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int strlen(char s[]);
void inverso(char s[]);
int main(){
	char frase[MAX];
	printf("Digite uma frase:\n");
	gets(frase);
	printf("O inverso %c:\n",-126);
	inverso(frase);
	return 0;
}
int strlen(char s1[]){
	int i=0;
	while(s1[i]!='\0'){
		i++;
	}
	return i;
}
void inverso(char s[]){
	int i;
	for(i=strlen(s)-1;i>=0;i--){
		printf("%c",s[i]);
	}
}