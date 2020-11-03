#include <stdio.h>

int main(){
	
	char opc;
	
	do{
		printf("MENU:\n");
		printf("Selecione a opcao:\n");
		printf("Clientes\n");
		printf("Fornecedores\n");
		printf("Encomendas\n");
		printf("Sair\n");
		scanf(" %c", &opc);
		switch(opc){
		case 'C':	
		case 'c':
			puts("Opc Cliente\n");
			break;
		case 'F':
		case 'f':
			puts("Opc Fornecedores\n");
			break;
		case 'E':
		case 'e':
			puts("Opc Encomendas\n");
			break;
		case 'S':
		case 's':
			break;			
		default:
			puts("Opc invalida");
			break;
		}	
	}while(opc!='s'&&opc!='S');
	
	return 0;
}