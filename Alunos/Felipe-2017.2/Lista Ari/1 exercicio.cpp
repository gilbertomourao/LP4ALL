/*
UFMA-ENGENHARIA EL�TRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Mostrar o caractere digitado em uma posi��o dada pelo usu�rio
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
void nospace(char s1[]);
int main(){
	char s[MAX];
	int i;
	printf("Digite uma frase:\n");
	gets(s);
	nospace(s);//n�o vai contar os espa�os como caractere!
	printf("Digite um numero inteiro maior que zero\n");
	scanf("%d",&i);
	//se o numero digitado for menor q zero uma mensagem sera mostrada
	//caso contrario sera executada a fun��o do programa
	if(i<0){
		printf("Numero invalido\n");   	
	}
	else{
		printf("%c",s[i-1]);
	}
	return 0;
}
void nospace(char s1[]){
	int i,j;
	for (i=0,j=0;s1[i]!='\0';i++,j++) {
		if (s1[j]==' ')
			j++;	
		s1[i]=s1[j];
	}	
}
