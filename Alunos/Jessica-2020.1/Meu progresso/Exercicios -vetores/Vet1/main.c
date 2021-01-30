#include <stdio.h>
#include <stdlib.h>
/*1 – FAÇA UM PROGRAMA QUE LEIA QUATRO NÚMEROS INTEIROS,
COLOQUE-OS EM UM ARRAY E MOSTRE-OS NA ORDEM INVERSA DA LEITURA.*/

int main()
{
    int Num[4]={0};

    printf("Insira 4 numeros inteiros: \n");
    for (int l=0;l<4;++l){
        scanf("%i", &Num[l]);
    }
//Mostrando na ordem inversa:
    printf("Numeros inseridos na ordem inversa:\n");
    for (int i=3; i>-1; --i){
        printf("%i\n", Num[i]);
    }
}
