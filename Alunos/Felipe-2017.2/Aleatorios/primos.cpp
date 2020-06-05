#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, primo, vprimo[100], j=0;

    for(n=1; n<=100; n++){
        primo=0;
        for(k=1; k<=n; k++)
            if((n%k)==0)
                 primo++;
        if(primo<=2){
			vprimo[j]=n;
			j++;
		}   
    }
	for(j=0;j<=10;j++){
		printf("%d\n",vprimo[j]);
	}
    return 0;
}