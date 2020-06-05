/*
UFMA-ENGENHARIA ELÉTRICA
ALUNO:Felipe Alencar Araujo
PROFESSOR: Ari
PROGRAMA: HISTOGRAMA VOGAIS
ANO:2017
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char** argv)
{
	char nome[100],vogais[30]="AEIOU";
	int i,j,cont,k;
	puts("Digite a string:");
	gets(nome);
	for(i=0;vogais[i]!='\0';i++){
		cont=0;
		for(j=0;nome[j]!='\0';j++){
			if(toupper(vogais[i])==toupper(nome[j])){
				cont++;
				if(cont>=2){
					for(k=j;k<strlen(vogais);k++){
						vogais[k]=vogais[k+1];
					}
				}
			}
		}
		
		printf("%c------>%d\n",vogais[i],cont);
		
	}
	return 0;
}