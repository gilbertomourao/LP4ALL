#include <stdio.h>

int main(){
	float distot,litrosc,consmedio;
	
	//dados informados pelo usuário
	printf ("Digite a distancia percorrida em KM:\n");
	
	scanf("%f",&distot);
	
	printf("Digite o total de litros de combsutivel consumido em LITROS:\n");
	
	scanf("%f",&litrosc);
	
	consmedio=distot/litrosc;//cálculo do consumo médio
	
	printf("O consumo medio de combustivel foi: %.2f Km/L",consmedio);//Mostra o consumo médio na tela %.2f=mostra com duas casas após a virgulo
	return 0;
}
