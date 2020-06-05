#include <stdio.h>

//Protótipos das funções
void concatenar(char string1[],int t1,char string2[],int t2,char string3[]);
int strlen(char st[]);

int main(){
     int t1,t2;  
	 char p1[100];
	 char p2[100];
	 char p3[100];
	 printf("Digite uma palavra:\n");
	 gets(p1);
	 t1=strlen(p1);
	 printf("Digite uma palavra:\n");
	 gets(p2);
	 t2=strlen(p2);
	 printf("---------\n");
	 printf("JUNTANDO:\n");
	 concatenar(p1,t1,p2,t2,p3);
	 printf("\n---------");
	return 0;
}

//Função para concatenar strings
void concatenar(char string1[],int t1,char string2[],int t2,char string3[]){
	int i,j;
	for (i=0;i<=t1;i++){
		string3[i]=string1[i];
	}
	for (j=0;j<=t2;j++){
		string3[j+t1]=string2[j];//A terceira string recebe a segunda na posição posterior a primeira, no caso j+tamanho da string 1
	}
	printf("%s",string3);
}
int strlen(char st[]){
	int i=0;
	while(st[i]!='\0'){
		i++;
	}
	return i;
}
