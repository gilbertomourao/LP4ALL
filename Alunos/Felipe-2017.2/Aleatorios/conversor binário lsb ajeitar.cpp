#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
	int i,tot=0,y;
	int bit[3];
	printf("digite um numero em binario (onde o primeiro sera o lsb):\n");
	for (i=0;i<3;i++){
		scanf("%d",&bit[i]);
	}
	bit[i]='\0';
	for(i=0;i<3;i++){
		y=bit[i]*pow(2,i);
		tot+=y;
	}
	printf("%d",tot);
	return 0;
}