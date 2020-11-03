/*Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Palindromo com retorno booleano
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
void nospace(char s[]);
int strlen(char s[]);
bool palindrome(char s[]);
int main(){
	char string[MAX];
	printf("Digite uma string:\n");
	gets(string);
	nospace(string);
	printf("%d",palindrome(string));
	return 0;
}

int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void nospace(char s[]){
	int i,j;
	for(i=0,j=0;s[i]!='\0';i++,j++){
		if(s[j]==' '){
			j++;
		}
		s[i]=s[j];
	}
} 
bool palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[i]==s[j]){
			return true;
		}
		else{
			return false;
		}
	}
}