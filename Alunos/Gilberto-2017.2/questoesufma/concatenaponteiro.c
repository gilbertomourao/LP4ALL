#include <stdio.h>

#define MAX 100

void concatena(char *,char *);

int main(){

	char str1[MAX], str2[MAX];
	
	printf("Insira a primeira string: "); gets(str1);
	printf("Insira a segunda string: "); gets(str2);
	
	concatena(str1,str2);
	
	puts(str1);
	
	return 0;	
}

void concatena(char *str1,char *str2){
	
	while (*(str1++)){
		if ( ! *str1 )
			while (*str2)
				*(str1++) = *(str2++);
		if ( ! *str2 )
			*str1 = '\0';	
	}
							 				
}