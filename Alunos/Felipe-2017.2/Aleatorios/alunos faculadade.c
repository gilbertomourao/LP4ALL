#include <stdio.h>

int main(int argc, char** argv)
{
	float n1,n2,m;
	printf("Digite as duas notas:\n");
	scanf("%f %f",&n1,&n2);
	m=(n1+n2)/2;
	if (m>=7) printf("Aprovado");
	else if(m>=3 && m<7){
		printf("Recuperação");
	}
	else printf("Reprovado");
	return 0;
}