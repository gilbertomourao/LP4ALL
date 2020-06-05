#include <stdio.h>

int main(int argc, char** argv)
{
	int ano,dia,mes,a,b,resto;
	printf("PERFIL\n");
	printf("Digite o dia do nascimento:\n");
	scanf("%f",&dia);
	printf("Digite o mes de nascimento:\n");
	scanf("%f",&mes);
	printf("Digite o ano por extenso em q vc nasceu:\n");
	scanf("%f",&ano);
	a=(dia*1000)+mes+ano;
	switch((a/100 + a%100)%5)
	{
	case 0:
		printf("RRRR");
		break;
	default:
		break;
	}
	
	return 0;
}