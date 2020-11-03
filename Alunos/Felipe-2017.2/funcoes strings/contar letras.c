#include <stdio.h>
#include <ctype.h>

int strlen(char st[]);

int main(int argc, char** argv){
	char frase[100];
	int i,j,k,cont;
	printf("Digite uma frase:\n");
	gets(frase);
	for(i=0;frase[i]!='\0';i++){
		cont=0;
		for(j=0;j<strlen(frase);j++){
			if(toupper(frase[i])==toupper(frase[j])){		
				cont++;
				if(cont>=2){
					for(k=j;k<strlen(frase);k++){
						frase[k]=frase[k+1];
					}
				}
			}
		}
		if(frase[i]!=' ')
			printf("%c - %d\n",frase[i],cont );
	}
	
	return 0;
}
int strlen(char st[]){
	int i=0;
	while(st[i]!='\0'){
		i++;
	}
	return i;
}