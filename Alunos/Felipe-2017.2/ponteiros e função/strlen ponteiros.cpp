#include <stdio.h>

void strlen(char *s);

int main(){
	
	char str[100];
	gets(str);
	strlen(str);
	return 0;
}

void strlen(char *s){
	char *t=s;//posição do primeiro endereço
	int dif=0;
	while(*s++);
	s--;//pois é incrementado uma vez a mais, pois ele conta até o \0 junto
	dif=s-t;//difernça entre o endereço final e inicial
	printf("%d",dif);
}