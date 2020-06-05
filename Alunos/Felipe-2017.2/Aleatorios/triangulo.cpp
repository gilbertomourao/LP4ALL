#include <stdio.h>
int main(){
	int a,b,c;
	printf("Digite o lados a,b,c:\n");
	scanf("%i",&a);
	scanf("%i",&b);
	scanf("%i",&c);
	if(a+b>=c&&a+c>=b&&c+b>=a)
	{	
		if(a==b && a==c && b==c){
			printf("Equilatero");
		  }	
		else if(a==b || a==c || b==c){
			printf("Isoceles");
		}
		else{
			printf("Escaleno");
		}
	}
	else{
		printf("Não e triangulo\n");
	}
	return 0;
}
