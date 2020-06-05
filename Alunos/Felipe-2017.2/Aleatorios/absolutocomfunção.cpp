#include <stdio.h>

int abs(int x){
	if (x>0){
		return x;
	}
	else{
		return -x;
	}
}
int main(){
	int a;
	printf("Digite um valor:\n");
	scanf("%i",&a);
	printf("O valor absoluto e':%i",abs(a));
	return 0;
}