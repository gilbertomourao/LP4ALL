#include <stdio.h>

void leitura(char []);
void conta(int *,char []);
void tamanho(char [],int *);
void ordena(char []);
void imprime(char []);

int main(){
	
	char str[100];
	int p;
	
	leitura(str);  /*Pois str = &str[0]*/
	conta(&p,str);
	tamanho(str,&p);
	ordena(str);
	imprime(str);
	
	return 0;
}

void leitura(char str[100]){
	
	printf("Insira a string: ");
	gets(str);	
	
}

void conta(int *p,char str[100]){
	
	int i;
	
	for (i=0;str[i]!='\0';i++)
		;
	
	*p = i;
}

void tamanho(char str[100],int *p){
	
	int n;
	
	n = *p;
	
	printf("A quantidade de caracteres e: %d\n", n);
}

void ordena(char str[100]){
		
	int i,j;
	char aux;
	
	for (i=0;str[i]!='\0';i++)
		for (j = i+1;str[j]!='\0';j++)
			if (str[i] < str[j]){
				aux = str[i];
				str[i] = str[j];
				str[j] = aux;
			}
	
}

void imprime(char str[100]){
	
	puts(str);
	
}