#include <linp/linp.h>
#include <stdio.h>

int main()
{
	int num;

	input("~Insira um inteiro: ", "%d", &num);
	printf("Inteiro: %d\n", num);

	char ch;

	input("~Insira um caractere: ", "%c", &ch);
	printf("Caractere: %c\n", ch);

	char string[20];

	input("~Insira uma string: ", "%s", string, .buffer_size = 20);
	printf("String: %s\n", string);

	return 0;
}