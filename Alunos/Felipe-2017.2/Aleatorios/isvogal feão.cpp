#include <stdio.h>
#include <ctype.h>
void isvogal(char c){
	switch(c){
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		printf("e vogal");			
		break;
	default:
		printf("nao e vogal");
		break;
	}
}
int main(){
	char nome;
	nome=getchar();
	isvogal(nome);
	return 0;
}