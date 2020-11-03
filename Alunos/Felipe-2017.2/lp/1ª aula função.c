#include <stdio.h>
int tamst(char str[]);
void tela(char str[]);
int main(){
	char string[50];
	printf("Digite a string:");
	gets(string);
	puts("");
	tela(string);
	
	return 0;
}
//função strlen
int tamst(char str[]){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
//função exibir string
void tela(char str[]){
	int i;
	for(i=0;i<tamst(str);i++){
		printf("%c",str[i]);
	}
}
