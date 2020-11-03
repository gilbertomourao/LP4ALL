#include <stdio.h>

int main(int argc, char** argv)
{
	int ano;
	
	/*
	Área destinada ao envio de informações entre o usuário e a máquina !
	*/
	printf("Digite o ano para saber se e ou nao bissexto:\n");
	scanf("%i",&ano);
	
	/*
	Estruturas condicionais que irão informar a resposta
	*/
	if (ano%4==0 && ano%100!=0){
		printf("O ano de %i e' bissexto\n",ano);
	}
	else{
		printf("O ano de %i nao e' bissexto\n",ano);
	}
	
	return 0;
}
