#include <stdio.h>

int main(int argc, char** argv)
{
	int ano;
	
	/*
	�rea destinada ao envio de informa��es entre o usu�rio e a m�quina !
	*/
	printf("Digite o ano para saber se e ou nao bissexto:\n");
	scanf("%i",&ano);
	
	/*
	Estruturas condicionais que ir�o informar a resposta
	*/
	if (ano%4==0 && ano%100!=0){
		printf("O ano de %i e' bissexto\n",ano);
	}
	else{
		printf("O ano de %i nao e' bissexto\n",ano);
	}
	
	return 0;
}
