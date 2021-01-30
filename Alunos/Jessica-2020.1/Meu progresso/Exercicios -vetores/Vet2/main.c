#include <stdio.h>
#include <stdlib.h>
/*2 – FAÇA UM PROGRAMA QUE LEIA X NÚMEROS INTEIROS, COLOQUE-OS EM
UM ARRAY E MOSTRE-OS NA ORDEM INVERSA DA LEITURA.*/
int main()
{
    int c =0;
    printf("Insira a quatidade de componentes do array desejado\n");
    scanf("%i", &c);
    if(c<1){
    printf("Quantidade invalida, insira novamente:");
    scanf("%i", &c);
    }
    printf("\n");

    const int x=c;

    int num [x];

    printf("Insira os %i componente(s)do array:\n", x);
    for(int i=0; i<x;++i){
        scanf("%i", &num[i]);
    }
    printf("\n");
  //Mostrando o array inverso.
     for(int j=x-1; j>=0; --j){
        printf("%i", num[j]);
    }
    return 0;
}
