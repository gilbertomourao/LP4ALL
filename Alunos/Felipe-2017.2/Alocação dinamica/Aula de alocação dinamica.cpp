#include <stdio.h>
//------------------------------------------------------------------------------------------------
//DECLARADO ANTES DA MAIN
struct cad {
	char nome[300];
	char end[1000];
	int idade;
	float renda;
}/*z*/;
/*onde z é uma variavel global*/
typedef struct cad L;//muda o nome da estrutura (tipo) pra L
//dentro da estrutura eu posso ter varios tipos de dados, como se fosse um novo tipo de dado
//-----------------------------------------------------------------------------------------------
int main(){
	int i;
	/*
	struct cad x; //variavel criada com o tipo cad
	gets(x.nome);
	recebe a variavel que vai para a alocação do tipo char*/
	/*struct cad y[1000];
	a variavel y recebe recebe ate 1000 posições, cadastros*/
	L y[1000]; // a variavel y recebe ate 1000 posições to tipo L, definido pelo struct cad
	for(i=0;i<5;i++){
	gets(y[i].nome);//envia 5 strings para o struct nome
	}                                                                                      
 	printf("%c",y[0].nome[0]);//printar a primeira letra da primeira linha              
	//OBS: SÓ FUNCIONA COM PRINTF %c ou PUTCHAR !!!!!!!!!                               
	//-------------------------------------------------------------------------------------------
	return 0;
}