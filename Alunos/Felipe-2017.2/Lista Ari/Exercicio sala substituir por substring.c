#include <stdio.h>
#include <string.h>

int main(){
	char str1[30],str2[30],ch;
	int i,k,j;
	puts("Digite a string:");
	gets(str1);
	puts("Digite a substring");
	gets(str2);
	puts("Digite o caractere a ser achado na string");
	scanf(" %c",&ch);
	for(i=0;str1[i]!='\0';i++){
		if(str1[i]==ch){
			for(j=strlen(str1);j>i;j--){
				str1[j+strlen(str2)-1]=str1[j];
			}
			for(k=i,j=0;str2[j]!='\0';j++,k++){
				str1[k]=str2[j];
			}
			i+=strlen(str2)-1;
		}
	}
	printf("%s",str1);
	return 0;
}