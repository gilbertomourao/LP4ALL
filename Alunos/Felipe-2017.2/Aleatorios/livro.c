#include <stdio.h>

/*
int main(){
	char v1,v2;
	printf("Digite um caractere:\n");
	scanf("%c",&v1);
	printf("Digite um caractere:\n");
	fflush(stdin);//essa função limpa o buffer
	scanf("%c",&v2);//espaço em branco ignora todos os enters como caracteres
	printf("Os digitados foram %c e %c",v1,v2);
	return 0;
}
*/
/*
int main(){
	
	char v1,v2;
	printf("Digite um caractere:\n");
	v1=getchar();
	fflush(stdin);
	printf("Digite um caractere:\n");
	v2=getchar();
	printf("Os digitados foram %c e %c",v1,v2);
	//msm caso só q usando o getchar
	return 0;
}
*/
int main(){
	
	char ch;
	printf("Digite um caractere:\n");
	ch=getchar();
	printf("O caractere digitado %c tem numero ASCII = %d",ch,ch);
	return 0;
}