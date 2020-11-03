#include <stdio.h>
#include <ctype.h>
#define MAX 100
int strlen(char s[]);
void checar(char s1[],char s2[],char s3[]);
int main(){
	char nome[MAX],end[MAX],tel[MAX];
	puts("Digite o nome");
	gets(nome);
	puts("Digite o endereco");
	gets(end);
	puts("Digite o telefone");
	gets(tel);
	checar(nome,end,tel);
	return 0;
}
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void checar(char s1[],char s2[],char s3[]){
	int i,j,cont1=0,cont2=0;
	char s4[MAX],s5[MAX];
	for(i=0;i<=strlen(s1);i++){
		s4[i]=s1[i];
	}
	for(j=0;j<=strlen(s2);j++){
		s4[j+strlen(s1)]=s2[j];
	}
	s4[i+j+1]='\0';
	for(i=0;i<=strlen(s4);i++){
		s5[i]=s4[i];
	}
	for(j=0;j<=strlen(s3);j++){
		s5[j+strlen(s4)]=s3[j];
	}
	s5[i+j+1]='\0';
	for(i=0;s5[i]!='\0';i++){
		if((s5[i]>='a'&&s5[i]<='z')||(s5[i]>='A'&&s5[i]<='Z')){cont1++;}
		if(isdigit(s5[i])){cont2++;}
	}
	printf("Total de carcteres: %d\n",cont1);
	printf("Total de digitos: %d",cont2);
}