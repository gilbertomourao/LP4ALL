#include<stdio.h>


void contCaractere(char s1[][2], char *x  )
{ int i,j,cont=0;
	char ch;
	
		for(i=0;i<2;i++)
{	for(j=0;j<2;j++)
{
	printf("entre com os valores da matriz de caractere");
	scanf("%c", &s1[i][j]);
	fflush(stdin);
	
}	
	
} 
printf("Entre com o caractere que vc busca:");
scanf("%c", &ch);

	*x = ch;
	
	for(i=0;i<2;i++)
{	for(j=0;j<2;j++)
{
	if(s1[i][j]==*x)
	{
		cont++;
	}
}	
	
} 
	
	printf("%d",cont);
}

main(){
	
	char s1[2][2];
	char x;
	
	

contCaractere(s1,&x);
	
}