#include <stdio.h>

void strlen(char *s);

int main(){
	
	char str[100];
	gets(str);
	strlen(str);
	return 0;
}

void strlen(char *s){
	char *t=s;//posi��o do primeiro endere�o
	int dif=0;
	while(*s++);
	s--;//pois � incrementado uma vez a mais, pois ele conta at� o \0 junto
	dif=s-t;//difern�a entre o endere�o final e inicial
	printf("%d",dif);
}