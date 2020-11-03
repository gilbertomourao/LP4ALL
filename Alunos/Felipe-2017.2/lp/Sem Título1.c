#include <stdio.h>
struct lista{
	char nome[300];
	char end[1000];
	int idade[100];
	float renda;
};
typedef struct lista tipo;
void ler(tipo id[10]);

int main(){
	tipo id[10];
	ler(id);
	return 0;
}

void ler(tipo id[10]){
	int i;
	for(i=0;i<10;i++){
		printf("%d\n",i+1);
		scanf("%d",&id[i].idade);
		printf("%d\n",id[i].idade);
		fflush(stdin);
	}
}
/*
float media(tipo id[10]){
	int i;
	float md=0;
	for(i=0;i<10;i++){
	}
	return md/10;
}
*/
