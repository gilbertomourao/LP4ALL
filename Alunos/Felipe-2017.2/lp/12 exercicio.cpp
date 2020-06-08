/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Dada uma frase substituir uma palavra da frase por outra palavra
Ano: 2017.2
*/
#include <stdio.h>
#define MAX 100
int strlen(char x[]);
void substituir(char a[],char b[],char c[]);
int main(){
	char a[MAX],b[MAX],c[MAX];
	
	printf("Digite uma frase:\n");
	gets(a);
	printf("Digite a palavra a ser substituida:\n");
	gets(b);
	printf("Digite a palavra que ser%c posta no lugar:\n",-96);
	gets(c);
	
	substituir(a,b,c);
	return 0;
}
int strlen(char x[]){
	int i=0;
	while(x[i]!='\0'){
		i++;
	}
	return i;
}
void substituir(char a[],char b[],char c[]){
	int i=0,j=0,k=0;
	char d[MAX];//Será usado para receber os caracteres da frase resultante
	//Lógica do ANA BANANA, procurar uma substring dentro de uma string
	while(a[i]!='\0'){
		j=0;
		while(a[j]!='\0'&&b[j]!='\0'&&a[i+j]==b[j]){
			j++;
		}
		if(b[j]=='\0'){
			for(j=j-1;j>=0;j--){
				a[i+j]='*';//Maracador para a palavra que será substituida
			}
		}
		i++;
	}
	printf("%s\n",a);
	for(i=0;a[i]!='\0';i++){
		//Se for diferente do maracador então recebe a letra na posição
		if(a[i]!='*'){
			d[k]=a[i];
			k++;
		}
		//Se for igual o marcador recebe a string c em cada posição
		else{
			for(j=0;j<strlen(c);j++){
				d[k]=c[j];
				k++;
			}
			i=i+strlen(b)-1;//incremento após o tamanho da palavra
		}
	}
	d[k]='\0';//Transforma o vetor d em uma string
	printf("A palavra substitu%cda ficou assim: %s\n",-95,d);
}