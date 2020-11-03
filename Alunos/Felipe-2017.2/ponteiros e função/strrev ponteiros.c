#include <stdio.h>

void ler(char *s);
void inverter(char *s);

int main(){
	
	char str[50];
	ler(&str[0]);
	inverter(&str[0]);
	return 0;
}
void ler(char *s){
	printf("Digite a string:\n");
	gets(s++);
}

void inverter(char *s){
	printf("Invertendo:\n");
	char *p=s;
	while(*p!='\0'){
		p++;
	}
	p--;//por causa do ultimo incremento
	while(p>=s){
		putchar(*p--);
	}
}
