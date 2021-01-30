#include <stdio.h>
#include <stdlib.h>
/*4 – FACA UM PROGRAMA QUE LEIA UMA LISTA DE X NÚMEROS COLOCANDO-OS
EM UM ARRAY E, APÓS O TERMINO DA LEITURA, MOSTRE OS ELEMENTOS COM
ÍNDICE MAIOR OU IGUAL A X/2*/
#define LIM 500
int main()
{
    int vet[LIM];
    int n=0;

    printf("Insira o tamanho do vetor desejado:");
    scanf("%i", &n);
    printf("\n");

    printf("Insira os %i membro(s) do array: \n", n);
    for (int i=0; i<n; ++i){
        scanf("%i", &vet[i]);
    }
    printf("\n");
    printf ("ELEMENTOS COM ÍNDICE MAIOR OU IGUAL A X/2\n");
     for (int j=(n/2); j<n; ++j){
        printf("%i", vet[j]);
     }
    return 0;
}
