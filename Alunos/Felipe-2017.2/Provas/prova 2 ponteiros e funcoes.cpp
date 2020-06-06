#include <stdio.h>
void ler(char s[]);
void nospace(char s[]);
void casesens(char s[]);
int strlen(char s[]);
int palindrome(char s[]);
void tela(int vdd);
int main(){
	char str[50];
	ler(str);
	nospace(str);
	casesens(str);
	tela(palindrome(str));
	return 0;
}
void ler(char s[]){
	printf("Digite sua string:\n");
	gets(s);
}
void nospace(char s[]){
	int i,j;
	for (i=0,j=0;s[i]!='\0';i++,j++) {
		if (s[j]==' ')
			j++;	
		s[i]=s[j];
	}	
}
void casesens(char s[]){
	int i=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='a' && s[i]<='z'){
			s[i]=s[i]-32;
		}
		else{
			s[i]=s[i];
		}
	}
}
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
int palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[j]==s[i] ){
			return 1;
		}
		else{
			return 0;
		}
	}
}

void tela(int vdd){
	if(vdd==1){
		printf("Eh palindromo !\n");
	}
	else if(vdd==0){
		printf("Nao eh palindromo !\n");
	}
}





