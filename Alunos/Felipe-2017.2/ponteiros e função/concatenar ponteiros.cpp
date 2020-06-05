#include <stdio.h>

void ler(char s[]);
void concatenar(char *s1,char *s2);

int main(){
	char str1[40],str2[40];
	ler(&str1[0]);
	ler(&str2[0]);
	concatenar(str1,str2);
	puts(str1);
	return 0;
}

void ler(char *s){
	gets(s);
}

void concatenar(char *s1,char *s2){
	while(*s1++);
	s1--;
	while(*s2!='\0'){
		*s1++=*s2++;
	}
	*s1='\0';
}
