#include <stdio.h>
int max(int n1,int n2);//prototipo das funções
int min(int n1,int n2);//prototipo das funções 

int main(int argc, char** argv)
{
	int a,b,maior,menor;
	printf("Digite dois numeros:\n");
	scanf("%i %i",&a,&b);
	maior=max(a,b);
	menor=min(a,b);
	printf("O maior e'= %i\n",maior);
	printf("O menor e'= %i\n",menor);
	return 0;
}
int max(int n1,int n2){
	if (n1>n2){
		return n1;
	}
	else{
		return n2;
	}
}
int min(int n1,int n2){
	if (n1>n2){
		return n2;
	}
	else {
		return n1;
	}
}