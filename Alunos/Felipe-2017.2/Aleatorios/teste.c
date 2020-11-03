#include <stdio.h>

int main(){
	float x,y,media;
	
	printf("Digite a nota:\n ");
	scanf("%f",&x);
	printf("Digite a nota:\n ");
	scanf("%f",&y);
	if (0<x&&y<10) {
		media=(x+y)/2;
		printf(" A media e'=%f\n",media);
		printf("Notas validas !!!\n");
	}
	else {
		printf("Notas invalidas !!!\n");
	}
	return 0;
}
