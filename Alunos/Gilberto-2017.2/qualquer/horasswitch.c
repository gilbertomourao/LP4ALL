#include <stdio.h>
main()
{
	int h; /*Número de Horas*/
	long res; 
	char tipo;
	
	printf("Insira o numero de horas: ");
	scanf("%d", &h);
	printf("O que mostrar? (m/s/d)");
	scanf(" %c", &tipo);
		switch (tipo)
		{
			case 'm' : 
			case 'M' : res = h<0 ? 0 : h*60L; 
				   break;
			case 's' : 
			case 'S' : res = h<0 ? 0 : h*3600L; 
				   break;
			case 'd' :
			case 'D' : res = h<0 ? 0 : h*36000L;	   	   	
		}
	printf("%d horas = %ld %c", h, res, tipo);	
}