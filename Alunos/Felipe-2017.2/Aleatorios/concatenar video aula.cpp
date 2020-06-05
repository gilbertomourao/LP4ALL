#include <stdio.h>

int main(void){
	void cs(char string1[],int t1,char string2[], int t2, char string3[]);
	char teste[]={'p','a','o',' '};
	char teste2[]={'m','o','r','t','a','d','e','l','a'};
	char np[13];
	int i;
	cs(teste,4,teste2,9,np);
	for (i=0;i<13;i++){
		printf("%c",np[i]);
	}
	return 0;
}
void cs(char string1[],int t1,char string2[], int t2, char string3[]){
	int i,j;
	for (i=0;i<t1;i++){
		string3[i]=string1[i];
	}
	for (j=0;j<t2;j++){
		string3[j+t1]=string2[j];
	}
		
}
