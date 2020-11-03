// Procurar uma substring em uma string de forma mais fácil
#include <stdio.h>
#include <string.h>
#define MAX 50
int main(){
	char s1[MAX],s2[MAX];
	int i,j,cont=0,x,aux;
	puts("Digite uma frase:");
	gets(s1);
	puts("Digite uma palavra:");
	gets(s2);
	for(i=0;s1[i]!='\0';i++){
		if(s2[0]==s1[i]){
			x=0;
			for(j=0;s2[j]!='\0';j++){
				if(s2[j]==s1[i+j]){
					x++;
				}
				if(x==strlen(s2)){
					cont++;
				}
			}
		}
	}
	printf("%d",cont);
	return 0;
}