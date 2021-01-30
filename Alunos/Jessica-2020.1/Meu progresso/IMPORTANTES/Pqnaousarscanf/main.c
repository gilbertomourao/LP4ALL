#include <stdio.h>
#include <stdlib.h>

int main()
{
	char string1[20], string2[20];

	printf("Insira a primeira string: ");
	fgets(string1,20,stdin);
	printf("Insira a segunda string: ");
    fgets(string2,20,stdin);

	printf("String1: %s\nString2: %s\n", string1, string2);

	return 0;
}
