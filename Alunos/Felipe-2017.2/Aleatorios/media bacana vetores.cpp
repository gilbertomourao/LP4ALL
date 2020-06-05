#include <stdio.h>
int main(int argc, char** argv)
{
	int i;
	float soma,media,nota[4];
	printf("Digite as notas:\n");
	for (i=0; i<4; i++){
		scanf("%f",&nota[i]);
		soma=soma+nota[i];
	}
	media=soma/4;
	if (media>7){
		printf("A media e: %f\n",media);
		printf("Aluno aprovado !!!!\7");
	}
	else{
		printf("A media e: %f\n",media);
		printf("Aluno de recuperacao !!!!\7");
	}
	return 0;
}