#include <stdio.h>

int main(){
	
	int n,contador;
	
	printf("Digite o numero que deseja para a contagem :\n");
	scanf("%d",&n);
	
	if (n>0){
		for (contador=0;contador<=n;contador=contador+1){
			printf("%d",contador);
		}
    }
    else (n<0);{
    	for (contador=0;contador>=n;contador=contador-1){
    		printf("%d\n",contador);
		}
    	
	}
	return 0;
}
