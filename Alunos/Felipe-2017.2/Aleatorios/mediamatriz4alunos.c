#include <stdio.h>
//Função para o cálculo de média
float media(float x){
	float media;
	media=x/4;
	return media;
}
int main(int argc, char** argv)
{
	float soma,matriz[10][4];
	int i,j;
	for (i=0;i<10;i++){
		soma=0;//reinicia o somatório cada vez q muda-se o linha 
		for (j=0;j<4;j++){
			printf("Digite a nota %i do aluno %i\n",j+1,i+1);
			scanf("%f",&matriz[i][j]);
			soma+=matriz[i][j];//somatório das notas de cada aluno
		}
		printf("A media do aluno %i foi = %f\n",i+1,media(soma));
	}
	return 0;
}