#include <stdio.h>

int main(){
	float distot,litrosc,consmedio;
	
	//dados informados pelo usu�rio
	printf ("Digite a distancia percorrida em KM:\n");
	
	scanf("%f",&distot);
	
	printf("Digite o total de litros de combsutivel consumido em LITROS:\n");
	
	scanf("%f",&litrosc);
	
	consmedio=distot/litrosc;//c�lculo do consumo m�dio
	
	printf("O consumo medio de combustivel foi: %.2f Km/L",consmedio);//Mostra o consumo m�dio na tela %.2f=mostra com duas casas ap�s a virgulo
	return 0;
}
