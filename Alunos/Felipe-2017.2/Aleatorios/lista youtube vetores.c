#include <stdio.h>

int main(int argc, char** argv)
{
	int i,x[10];
	
	printf("Digite as componentes do vetor:\n");
	for(i=0;i<10;i++){
		scanf("%i",&x[i]);
	}
	for (i=0;i<10;i++){
		if(x[i]<0){
			x[i]=0;
		}
		printf("%i",x[i]);
	}
		
	return 0;
}