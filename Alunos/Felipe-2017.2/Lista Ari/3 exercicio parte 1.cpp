/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Informar o indice da primeira aparcição de uma letra em uma string
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int main(){
	char s[MAX],ch;
	int i,posicao=0;
	printf("Digite uma string:\n");
	gets(s);
	printf("Digite um caractere pra procura-lo:\n");
	scanf("%c",&ch);
	for(i=0;s[i]!='\0';i++){
		if(s[i]==ch){
			posicao=i+1;
			break;
		}
	}
	if(posicao>0){
		printf("A primeira letra '%c' aparece na %d%c posicao\n",ch,posicao,166);
	}
	else
	{
		printf("O caractere digita nao esta contido na string\n");
	}
	return 0;
}