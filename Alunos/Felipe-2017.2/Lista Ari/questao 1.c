#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(){
	
	char string[MAX],vetmin[MAX],vetmai[MAX],vetnum[MAX],s1[MAX],s2[MAX],aux;
	int i,j,k,contmin=0,contmai=0,contnum=0;
	puts("Digite a string:");
	gets(string);
	//colocando as minusculas em uma string
	k=0;
	for(i=0;string[i]!='\0';i++){
		if(string[i]>='a'&&string[i]<='z'){
			vetmin[k]=string[i];
			contmin++;
			k++;
		}
	}
	vetmin[k]='\0';
	//colocando as maiusculas em uma string
	k=0;
	for(i=0;string[i]!='\0';i++){
		if(string[i]>='A'&&string[i]<='Z'){
			vetmai[k]=string[i];
			contmai++;
			k++;
		}
	}
	vetmai[k]='\0';
	//colocando os numeros em uma string
	k=0;
	for(i=0;string[i]!='\0';i++){
		if(string[i]>='0'&&string[i]<='9'){
			vetnum[k]=string[i];
			contnum++;
			k++;
		}
	}
	vetnum[k]='\0';
	//logica da ordenação minusculas
	for(i=0;vetmin[i]!='\0';i++){
		for(j=i+1;vetmin[j]!='\0';j++){
			if(vetmin[i]>vetmin[j]){
				aux=vetmin[i];
				vetmin[i]=vetmin[j];
				vetmin[j]=aux;
			}
		}
	}
	//logica da ordenação numeros
	for(i=0;vetnum[i]!='\0';i++){
		for(j=i+1;vetnum[j]!='\0';j++){
			if(vetnum[i]>vetnum[j]){
				aux=vetnum[i];
				vetnum[i]=vetnum[j];
				vetnum[j]=aux;
			}
		}
	}
	for(i=0;i<=strlen(vetmin);i++){
		s1[i]=vetmai[i];
	}
	for(j=0;j<=strlen(vetmai);j++){
		s1[j+strlen(vetmin)]=vetmai[j];
	}
	s1[i+j+1]='\0';
	for(i=0;i<=strlen(s1);i++){
		s2[i]=s1[i];
	}
	for(j=0;j<=strlen(vetnum);j++){
		s2[j+strlen(s1)]=vetnum[j];
	}
	s2[i+j+1]='\0';
	printf("%s",s2);
	system("pause");
}