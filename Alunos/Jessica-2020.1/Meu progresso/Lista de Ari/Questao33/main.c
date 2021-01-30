#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<stdbool.h>

/*33.	Fazer um programa para cadastro e diálogo de login. O programa deve:
a.	Cadastrar um nome de usuário via teclado. O nome de usuário tem, no máximo, 8 caracteres,
 sendo válidos somente os caracteres numéricos e as letras maiúsculas ou minúsculas. Somente
os caracteres válidos devem ser exibidos no console durante a digitação do nome de usuário.
b.	Cadastrar uma senha do usuário via teclado. Esta segue as mesmas regras do nome de usuário,
com a diferença de que são exibidos somente asteriscos no console à medida que a senha é digitada.
c.	Receber um novo nome de usuário e uma nova senha, utilizando os mesmos procedimentos descritos
nos itens a e b.
d.	Comparar o nome de usuário cadastrado com o recebido posteriormente  e a  senha cadastrada com
a senha recebida. Caso sejam idênticos, informar “OK”, do contrário informar “Acesso negado”.*/

int main()
{
	void ReadLettersAndNumbers(char string[]);
	void ReadKey(char string[]);
	bool IgualdadeString(char str1[], char str2[]);

	char usuario[9], senha[9], teste_usuario[9], teste_senha[9];
	int i = 0, j = 0;

	/*Cadastrando o Login*/
	printf("------------------------------\n");
	printf("Cadastre seu nome de usuario:\n");
	printf("------------------------------\n");

	ReadLettersAndNumbers(usuario);

	printf("\n\n-------------------------------\n");
	printf("Cadastre sua senha de usuario:\n");
	printf("-------------------------------\n");

	ReadKey(senha);

	printf("\n\n");


	system("PAUSE");
    system("CLS");

    /*Confirmando o Login*/
    printf("------------------------------\n");
	printf("      Confirmar Cadastro\n");
	printf("------------------------------\n\n\n");

	printf("------------------------------\n");
	printf("Entre com seu nome de usuario:\n");
	printf("------------------------------\n");

	ReadLettersAndNumbers(teste_usuario);

	printf("\n\n------------------------------\n");
	printf("Entre com sua senha de usuario:\n");
	printf("------------------------------\n");

	ReadKey(teste_senha);

	printf("\n\n");

    system("PAUSE");
    system("CLS");

    if (IgualdadeString(usuario,teste_usuario) && IgualdadeString(senha, teste_senha))
        printf("**** OK ****\n");
    else
        printf("**** ACESSO NEGADO ****\n");

    system("PAUSE");
	return 0;
}

void ReadLettersAndNumbers(char string[]) {
	char ch; //Capta cada caractere digitado
	char digitado[8]; //Junta todos as letras e numeros digitados
	int i = 0, j;

	do {
		fflush(stdin); //Limpa o buffer
		ch = _getch(); //Captura o caractere digitado pelo usuario;

		if ((isalpha(ch) != 0 || isdigit(ch) != 0) && i < 8) { // Se for uma letra ou numeros e estiver dentro do tamanho
			digitado[i] = ch; // É direcionado para string auxilar
			i++; //Passa para proxima posição
			printf("%c", ch); //Exibe letra ou numero digitado na tela

		}
		else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
			i--;
			digitado[i] = '\0';
			printf("\b \b"); //Apaga o caractere anterior
		}
	} while (ch != 13); // Quando o ENTER for digitado, termina o loop

	for (j = 0; j < i; j++) {
		string[j] = digitado[j];
	}
	string[j] = '\0';

}

void ReadKey(char string[]) {
	char ch; //Capta cada caractere digitado
	char digitado[8]; //Junta todos as letras e numeros digitados
	int i = 0, j;

	do {
		fflush(stdin); //Limpa o buffer
		ch = _getch(); //Captura o caractere digitado pelo usuario;

		if ((isalpha(ch) != 0 || isdigit(ch) != 0) && i < 8) { // Se for uma letra ou numeros
			digitado[i] = ch; // É direcionado para string auxilar
			i++; //Passa para proxima posição
			printf("*"); //Exibe apenas o asterisco

		}
		else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
			i--;
			digitado[i] = '\0';
			printf("\b \b"); //Apaga o caractere anterior
		}
	} while (ch != 13); // Quando o ENTER for digitado, termina o loop

	for (j = 0; j < i; j++) {
		string[j] = digitado[j];
	}
	string[j] = '\0';

}

bool IgualdadeString(char str1[], char str2[]){
    int i=0;

    while(str1[i]==str2[i] && str1[i]!='\0' && str2[i]!='\0') ++i;

    if(str1[i]=='\0' && str2[i]=='\0')
        return true;
    else
        return false;
}

