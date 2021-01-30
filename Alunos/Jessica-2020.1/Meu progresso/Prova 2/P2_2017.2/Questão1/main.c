// Organiza maiusculas-minusculas-numeros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void OrganizaString (char *s);

int main()
{
    char string[MAX], aux;
    int i,j;

    printf("Entre com  letras maiusculas, minusculas e numeros aleatoriamente:\n");
    gets(string); //Recebe a tring que sera organizada
    printf("\n\n");

    OrganizaString(string);
    puts("String organizada:");
    puts(string);

    return 0;
}

void OrganizaString (char *s) {
    int i,j,k=0,inicio;
    char aux[MAX], temp;

    for (i=0; s[i]!='\0'; i++) // Separa as maiusculas
        if (s[i] >= 'A' && s[i] <= 'Z')
            aux[k++]=s[i];
    for (i=0; i<k; i++) // Organiza as maiusculas
        for (j=i+1; j<k; j++)
            if (aux[i]>aux[j]) {
                temp=aux[i];
                aux[i]=aux[j];
                aux[j]=temp;
            }

    inicio=k;
    for (i=0; s[i]!='\0'; i++) // Separa as minusculas
        if (s[i] >= 'a' && s[i] <= 'z')
            aux[k++]=s[i];
    for (i=inicio; i<k; i++) // Organiza as minusculas
        for (j=i+1; j<k; j++)
            if (aux[i]>aux[j]) {
                temp=aux[i];
                aux[i]=aux[j];
                aux[j]=temp;
            }

    inicio=k;
    for (i=0; s[i]!='\0'; i++) // Separa os numeros
        if (s[i] >= '0' && s[i] <= '9')
            aux[k++]=s[i];
    aux[k]='\0';
    for (i=inicio; aux[i]!='\0'; i++) // Organiza os numeros
        for (j=i+1; aux[j]!='\0'; j++)
            if (aux[i]>aux[j]) {
                temp=aux[i];
                aux[i]=aux[j];
                aux[j]=temp;
            }
    strcpy(s,aux);
}
