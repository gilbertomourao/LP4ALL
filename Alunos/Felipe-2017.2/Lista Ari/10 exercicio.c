/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Dada uma string trocar as letra maiúsculas por minúsculas e vice-versa
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
void alterar(char st[]);
int main(){
	char string[MAX];
	
	printf("Digite uma string:\n");
	
	gets(string);
	
	printf("\nSubstituindo mai%csculas por min%csculas ",-93,-93);
	printf("e vice-versa:\n");
	
	alterar(string);
	return 0;
}

void alterar(char s[]){
	int i;
	
	//Lembre-se que a diferença entre duas letras é uma cte(32), na tabela ASCII
	//Percorre a string e onde for maiuscula troca por minuscula e vice versa
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i]+=32;//Troca maiúscula pra minúscula
		}
		else if(s[i]>='a' && s[i]<='z'){
			s[i]-=32;//Troca minúscula pra maiúscula
		}
	}
	printf("\n%s\n",s);
}