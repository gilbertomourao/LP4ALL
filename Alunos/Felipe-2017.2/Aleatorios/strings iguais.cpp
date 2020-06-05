#include <stdio.h>
#define MAX 100
int stringsiguais(char s1[], char s2[]){
	int i=0;
	while(s1[i]==s2[i] && s1!='\0' && s2[i]!='\0'){
		i++;
	}
	if(s1[i]=='\0' && s2[i]=='\0'){
		printf("Sao iguais\n");
	}else {
		printf("Sao diferentes\n");
	}
}
int main(){
	char s1[MAX],s2[MAX];
	printf("Digite uma palavra:\n");
	scanf("%s",&s1);
	printf("Digite uma palavra:\n");
	scanf("%s",&s2);
	printf("%i",stringsiguais(s1,s2));
	
	return 0;
}
//onde o valor 1 é verdadeiro e o valor 0 e falso