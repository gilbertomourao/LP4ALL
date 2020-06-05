#include <stdio.h>

int main(){
	int i;
	char teste[]={'a','e','i','o','u'}; 
	char teste2[]={'i','d','i','o','t','a'};
	char np[11];
	void concatenarstrings(char string1[], int t1,
                           char string2[], int t2,
						   char string3[]);
	concatenarstrings(teste,5,teste2,6,np);					   		   	
	for (i=0;i<11;i++){
		printf("%c",np[i]);
	}
	return 0;
}
void concatenarstrings(char string1[], int t1,
char string2[], int t2, char string3[]){
	int i,j;
	for (i=0;i<5;i++){
		string3[i]=string1[i];
	}						
	for (j=0;j<6;j++){
		string3[t1+j]=string2[i];
	}	   
}