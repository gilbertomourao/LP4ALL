/*
UFMA-ENGENHARIA ELÉTRICA
ALUNO:Felipe Alencar Araujo
PROFESSOR: Ari
PROGRAMA: HISTOGRAMA
ANO:2017
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	char nome[100];
	int i,j,cont,k;
	puts("Digite a string:");
	gets(nome);
	for(i=0;nome[i]!='\0';i++){
		cont=0;//a cada nova letra que sera comparada o contador reinicia
		for(j=0;nome[j]!='\0';j++){
			if(nome[i]==nome[j]){
				cont++;
				if(cont>=2){//só limpa a string se o numero de letras for maior ou igual a dois
					for(k=j;k<strlen(nome);k++){
						nome[k]=nome[k+1];//limpar a string do caractere repetido
					}
				}
			}
		}
		if(nome[i]!=' '){
		printf("%c------>%d\n",nome[i],cont);//roda cada letra com o contador menos os espaços da string
		}
	}
	return 0;
}