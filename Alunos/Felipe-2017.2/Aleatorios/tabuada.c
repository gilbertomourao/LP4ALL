#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int i,j;
	
	for (i=1;i<=5;i++){
		for (j=1;j<=10;j++){
			printf("%2i x %2i = %2i\n",i,j,i*j);
			}
		if (i!=5){
			printf("Digite enter pra continuar !!!");
			getchar();
		}
	}
	
	return 0;
}