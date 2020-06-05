#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main(){
	char nome[MAX],end[MAX],num[MAX];
	char s3[MAX],s4[MAX];
	int i,j,t,q,k,n,cont=0,cont2=0;
	puts("nome");
	gets(nome);
	puts("end");
	gets(end);
	puts("num");
	gets(num);
	t=strlen(nome);
	q=strlen(end);
	for(i=0;i<=t;i++){
		s3[i]=nome[i];
	}
	for(j=0;j<=q;j++){
		s3[j+t]=end[j];
	}
	s3[i+j+1]='\0';
	k=strlen(s3);
	n=strlen(num);
	for(i=0;i<=k;i++){
		s4[i]=s3[i];
	}
	for(j=0;j<=n;j++){
		s4[j+k]=num[j];
	}
	s4[i+j+1]='\0';
	printf("%s",s4);
	for(i=0;s4[i]!='\0';i++){
		if((s4[i]>='a'&&s4[i]<='z')||(s4[i]>='A'&&s4[i]<='Z')){cont++;}
		if(isdigit(s4[i])){cont2++;}	
	}
	printf("\ntotal de caracteres: %d\n",cont);
	printf("\ntotal de digitos: %d\n",cont2);
	return 0;
}