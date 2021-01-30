#include <stdio.h>
#include <stdlib.h>
/*5 – FACA UM PROGRAMA QUE SOME DOIS ARRAYS DE MESMO NUMERO DE ELEMENTOS.*/
#define  LIM 500
int main()
{
    int A[LIM];
    int B[LIM];
    int AB[LIM];
    int x=0;

    printf("Insira a quantidade de menbros dos vetores a serem somados:");
    scanf("%i",&x);
    printf("\n");

    printf("Insira os membros do vetor A:\n");
    for(int n=0; n<x;++n){
        scanf("%i",&A[n]);
    }
      printf("Insira os membros do vetor B:\n");
    for(int m=0; m<x;++m){
        scanf("%i",&B[m]);
    }
    //efetuando a soma
      for(int n=0; n<x;++n){
        AB[n]=A[n]+B[n];
    }
    printf("Resultado da soma:\n");
    for(int i=0; i<x;++i){
       printf("%i\n", AB[i]);
    }

    return 0;
}
