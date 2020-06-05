#include <stdio.h>

main()
{
	int h; /*Horas*/
	long seg; /*Segundos*/
	
	printf("Quantos segundos tem um determinado numero de horas? \n");
	printf("\n");
	printf("Informe o numero de horas: "); 
	scanf("%d", &h);
	seg = h<0 ? 0 : h*3600L; /*Condição e atribuição. Note o L após o 3600*/
	printf("\n");
	printf("%d hora(s) possui(em) %ld segundos.", h,seg);
}