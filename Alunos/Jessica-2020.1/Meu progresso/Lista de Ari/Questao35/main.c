#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*/35.	Elaborar um programa em C que leia uma frase e armazene-a em um vetor de caracteres
(cuidado com a leitura!). Depois crie uma função para contar o número de espaços em branco na
frase, outra para contar o número de vogais, e outra para contar o número de consoantes.*/
#define MAX 100
int main()
{
    int ContaEspacoBranco (char string[]);
    int ContaVogais(char string[]);
    int ContaConsoantes(char string[]);
    void ConverteStringMinuscula (char string[]);

    char frase[MAX];
    int Espacos=0;
    int Vogais=0;
    int Consoantes=0;

    printf("Entre com a frase:\n");
    gets(frase);

    ConverteStringMinuscula(frase);

    printf("\n\nFrase convertida toda em minusculas: %s", frase);

    Espacos = ContaEspacoBranco (frase);
    printf ("\n\nA frase inserida contem %i espaços em branco.", Espacos);

    Vogais = ContaVogais(frase);
    printf ("\n\nA frase inserida contem %i vogais.", Vogais);

    Consoantes = ContaConsoantes(frase);
    printf ("\n\nA frase inserida contem %i consoantes.\n", Consoantes);

    return 0;
}

void ConverteStringMinuscula (char string[]){
    int i;
    for (i=0; string[i]!='\0'; i++){
        if (string[i]>= 'A' && string[i]<= 'Z')
            string[i]=tolower(string[i]);
    }
}

 int ContaEspacoBranco (char string[]){
    int i;
    int espacos=0;

    for (i=0; string[i] != '\0'; i++){
        if(string[i] == ' ')
            ++espacos;
    }

    return espacos;
 }

 int ContaVogais(char string[]){
    int i;
    int Quant_Vogais=0;

    for (i=0; string[i] != '\0'; i++){
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            ++Quant_Vogais;
    }

    return Quant_Vogais;
 }

 int ContaConsoantes(char string[]){
    int i;
    int Quant_Consoantes=0;

    for (i=0; string[i] != '\0'; i++){
        if( (string[i]>'a' && string[i]<='z') && (string[i]!='a' && string[i]!='e' && string[i]!='i' && string[i]!='o' && string[i]!='u'))
            ++Quant_Consoantes;
    }

    return Quant_Consoantes;
 }
