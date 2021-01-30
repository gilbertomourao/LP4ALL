#include <stdio.h>
#include <stdlib.h>
/*3 – FACA UM PROGRAMA QUE LEIA UMA LISTA DE 20 NÚMEROS COLOCANDO-OS EM
UM ARRAY E, APÓS O TERMINO DA LEITURA, MOSTRE OS ELEMENTOS COM ÍNDICE
MAIOR OU IGUAL A 10.*/
int main()
{
    int vetor[20]={0};

    printf("Insira 20 numeros inteiros:\n");
    for (int m = 0; m<20;++m){
    scanf("%i",&vetor[m]);
    }
    //Mostrando os elementos com indice maior ou igual a 10
    printf("Elementos com indices maiores ou iguais a 10:\n");
    for(int n =9; n<20;++n){
        printf("%i    ",vetor[n]);
    }
    return 0;
}
