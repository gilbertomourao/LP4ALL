#include <stdio.h>

void ler(char *s);
int strlen(char *s);
int palindrome(char *s);
void maius(char *s);
void nospace(char *s);
void tela(int vdd);
int main(){
	char str[50];
	ler(str);
	maius(str);
	nospace(str);
	tela(palindrome(str));
	return 0;
}
/*ler string*/
void ler(char *s){
	printf("Digite a string:\n");
	gets(s);
}
/*ignorar o case sensitive*/
void maius(char *s){
	int i;
	for(i=0;*(s+i)!='\0';i++){
		if(*(s+i)>='a' && *(s+i)<='z'){
			*(s+i)-=32;
		}
	}
}
/*tirar espaços*/
void nospace(char *s){
	int i,j;
	for(i=0,j=0;*(s+i)!='\0';i++,j++){
		if(*(s+j)==' '){
			j++;
		}
		*(s+i)=*(s+j);
	}
}
/*verificar se é palindromo*/
int palindrome(char *s){
	int i,j,dif=0;
	char *t=s;
	while(*s++);
	s--;//pois é incrementado uma vez a mais, pois ele conta até o \0 junto
	dif=s-t;
	for(i=0,j=dif-1;*(t+i)!='\0';i++,j--){
		if(*(t+j)==*(t+i) ){
			return 1;
		}
		else{
			return 0;
		}
	}
}
/*imprimir resultado*/
void tela(int vdd){
	if(vdd==1){
		printf("Eh palindromo !\n");
	}
	else if(vdd==0){
		printf("Nao eh palindromo !\n");
	}
}

