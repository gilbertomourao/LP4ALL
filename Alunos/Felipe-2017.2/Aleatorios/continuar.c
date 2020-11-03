#include <stdio.h>

int main(){
	
	int num1,num2,i;
	printf("Digite dois numeros entre 0 e 255:\n");
	scanf("%d %d",&num1,&num2);
	if (num1<=num2){
		for (i=num1;i<=num2;i++){
			printf("%d------>%c\n",i,(char)i);
		}	
	}
	else{
		for (i=num2;i<=num1;i++){
			printf("%d------>%c\n",i,(int)i);
		}
	}
	
	return 0;
}