#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compara(char f[],char p[]);
int palindrome(char s[]);
char *strrev(char st[]);
int main(int argc, char** argv)
{
	char frase[50],pal[50];
	puts("Digite uma frase:");
	gets(frase);
	puts("Digite uma palavra:");
	gets((pal));
	printf("%d\n",compara(frase,pal));	
	return 0;
}
int palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[i]==s[j]){
			return 1;
		}
	}
	return 0;
}
char *strrev(char st[]){
	
	int i,j;
	char aux;
	for(i=0,j=strlen(st)-1;i<j;i++,j--){
		aux=st[i];
		st[i]=st[j];
		st[j]=aux;
	}
	return st;
}
int compara(char f[],char p[]){
	int tf,tp,i,j,aux,cont=0,x;
	tf=strlen(f);
	tp=strlen(p);
	if(palindrome(p)){
		strrev(p);
		for(i=0;i<tf;i++){
		if(p[0]==f[i]){
			x=0;
			aux=i;
			for(j=0;j<tp;j++){
				if(p[j]==f[aux]){
					x++;
					aux++;
				}
				if(x>=tp){
					cont++;
				}
			}
		}
	}
	}
	else{
		   for(i=0;i<tf;i++){
		if(p[0]==f[i]){
			x=0;
			aux=i;
			for(j=0;j<tp;j++){
				if(p[j]==f[aux]){
					x++;
					aux++;
				}
				if(x>=tp){
					cont++;
				}
			}
		}
	}	
	}
	return cont;
}
