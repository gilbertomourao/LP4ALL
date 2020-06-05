/*Concatenação de string*/

#include <stdio.h>
#include <string.h>

void concatena(char [],char []);

int main(){
	
	char str1[100],str2[100];
	
	printf("Insira a primeira string: "); gets(str1);
	printf("Insira a segunda string: "); gets(str2);
	
	concatena(str1,str2);
	
	puts(str1);
	
	return 0;
}

void concatena(char str1[100],char str2[100]){

	int i,j,k;
	
	for (i=0;str1[i]!='\0';i++)
		if (str1[i+1] == '\0'){
			for (j = i+1,k=0;str2[k]!='\0';j++,k++)
				str1[j] = str2[k];
			break;
		}
				
	str1[j] = '\0';
}