#include <stdio.h>

int main(){
	
	char str[30],*p=str;//ponteiro recebe o valor da primeira posição da string
	gets(str);
	while(*p!='\0'){
		putchar(*p++);
	}
	puts("");
	p--;//por causa do ultimo incremento
	while(p>=str){
		putchar(*p--);
	}
	return 0;
}