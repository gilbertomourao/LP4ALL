#include <stdio.h>
void nospace(char s1[]);
int main(){
	char s[10];
	printf("Digite uma frase:\n");
	gets(s);
	nospace(s);
	
	return 0;
}

void nospace(char s1[]){
	int i,j;
	for (i=0,j=0;s1[i]!='\0';i++,j++) {
		if (s1[j]==' ')
			j++;	
		s1[i]=s1[j];
	}
	printf("%s",s1);	
}