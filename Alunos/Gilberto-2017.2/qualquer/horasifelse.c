#include <stdio.h>
main()
{
	int h; /*Horas*/
	long res; 
	char tipo;
	
	printf("Insira o numero de horas: ");
	scanf("%d", &h);
	printf("O que mostrar (m/s/d)?");
	scanf(" %c", &tipo);
	if (tipo == 'm' || tipo == 'M') {
		res = h<0 ? 0 : h*60L;                /*Note o L após o 60*/
		printf("%d horas = %ld %c \n", h, res, tipo);
	}
	else
		if (tipo == 's' || tipo == 'S') {
			res = h<0 ? 0 : h*3600L;          /*Note o L após o 3600*/
			printf("%d horas = %ld %c \n", h, res, tipo);
		}
		else
			if (tipo == 'd' || tipo == 'D') {
				res = h<0 ? 0 : h*36000L;     /*Note o L após o 36000*/
				printf("%d horas = %ld %c \n", h, res, tipo);
			}
			else
				printf("Inseriu caractere invalido.");		
}