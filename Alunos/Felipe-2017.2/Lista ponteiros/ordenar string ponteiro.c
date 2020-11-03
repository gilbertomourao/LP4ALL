#include <stdio.h>
#define MAX 100

void ler(char *s);
void ordenar(char *s);
void tela(char *s);

int main(){
	char nome[MAX];
	ler(&nome[0]);
	ordenar(&nome[0]);
	tela(&nome[0]);
	return 0;
}

void ler(char *s){
	puts("Insira um nome:");
	gets(s);
}

void ordenar(char *s){
	int i,j;
	char aux;
	puts("Ordenado:");
	for(i=0;*(s+i)!='\0';i++){
		for(j=i+1;*(s+j)!='\0';j++){
			if(*(s+i)>*(s+j)){
				aux=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=aux;
			}
		}
	}
}

void tela(char *s){
	puts(s);
}