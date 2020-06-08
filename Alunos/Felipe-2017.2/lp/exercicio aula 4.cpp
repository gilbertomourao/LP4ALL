/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Pergunte o dia, mês e ano do aniversário e diga se a data é válida
Ano: 2017.2
*/
#include <stdio.h>

int main(){
	int dia,mes,ano;
	
	printf("Digite o dia do seu nascimento:\n");
	scanf("%d",&dia);
	printf("Digite o m%cs do seu nascimento:\n",-120);
	scanf("%d",&mes);
	printf("Digite o ano de nascimento:\n");
	scanf("%d",&ano);
	if(dia>=1 && dia<=31){
		if(mes>=1 && mes<=12){
			if(ano<=2017){
				printf("Data v%clida\n",-96);
			}
			else{
				printf("Data inv%clida\n",-96);
				printf("Motivo: ");
				printf("Ano incorreto !!!\n");

			}
		}
		else{
			printf("Data inv%clida\n",-96);
			printf("Motivo: ");
			printf("M%cs incorreto !!!\n",-120);

		}
	}
	else{
		printf("Data inv%clida\n",-96);
		printf("Motivo: ");
		printf("Dia incorreto !!!\n");
	}
	
	return 0;
}