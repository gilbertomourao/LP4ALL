#include <stdio.h>

int soma(int a,int b){
	return a+b;
}
int dobro(int x){
	return 2*x;
}
int main(int argc, char** argv){
	int a,b,total,y;
	printf("Digite dois numeros:\n");
	scanf("%i %i",&a,&b);
	printf("A soma e': %i\n",soma(a,b));
	printf("O dobro de %i=%i e o dobro de %i=%i\n",a,dobro(a),b,dobro(b));
	return 0;
}