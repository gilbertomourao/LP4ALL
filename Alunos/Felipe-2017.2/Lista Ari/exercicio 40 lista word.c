#include <stdio.h>
#include <string.h>
//limpa string
int main(int argc, char** argv)
{
	char ch,nome[20];
	int i,j,tam;
	puts("digite a string");
	gets(nome);
	puts("Digite o char");
	fflush(stdin);
	scanf("%c",&ch);
	tam=strlen(nome);
	for(i=0;nome[i]!='\0';i++){
		if(ch==nome[i]){
			for(j=i;j<tam;j++){
				nome[j]=nome[j+1];
			}
		}
	}
	printf("%s",nome);
	return 0;
}