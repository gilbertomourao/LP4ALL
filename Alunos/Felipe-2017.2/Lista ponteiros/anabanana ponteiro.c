#include <stdio.h>
#define MAX 100
int strlen(char p[]);
void compara(char *p,char *f,int tp);
int main(){
	char pal[MAX],frase[MAX];
	int tamp;
	printf("Digite a frase:\n");
	gets(frase);
	printf("Digite a palavra:\n");
	gets(pal);
	tamp=strlen(pal);
	compara(&pal[0],&frase[0],tamp);
	return 0;
}

int strlen(char p[]){
	int i=0;
	while(p[i]!='\0'){
		i++;
	}
	return i;
}

//p=palavra,f=frase,tp=tamanho da palavra
void compara(char *p,char *f,int tp){
	int i,j,x,cont=0;
	for(i=0;*(f+i)!='\0';i++){//percorre e aponta para o valor do endereço de f+i,onde f é fixo 
		if(*p==*(f+i)){
			x=0;
			for(j=0;*(p+j)!='\0';j++){
				if(*(p+j)==*(f+i+j)){
					x++;
				}
				if(x==tp){
					cont++;
				}
			}
		}
	}
	printf("%d",cont);
}






