#include <stdio.h>
#include <stdlib.h>
/*9 - CRIAR UM ALGORITMO QUE LEIA DADOS PARA UM VETOR DE 20 ELEMENTOS
INTEIROS. IMPRIMIR O MAIOR E O MENOR, SEM ORDENAR, O PERCENTUAL DE
NÚMEROS PARES E A MÉDIA DOS ELEMENTOS DO VETOR.*/
int main()
{
    int vetor[5];
    int i=0;
    int maior=0;
    int menor=0;
    int Npares=0;
    int media=0;

    printf("Insira os 5 elementos do vetor:\n");
    for(i=0;i<5;++i){
        scanf("%i",&vetor[i]);
    }
    //exibindo vetor
    printf("-----Vetor Formado-----\n");
    printf("|");
    for(i=0;i<5;++i){
        printf("%i   ",vetor[i]);
    }
    printf("|\n\n");
    //procurando o maior e o menor membro
   maior=vetor[0];
   menor=vetor[0];
   for(i=1;i<5;++i){

       if(vetor[i] > maior){
        maior=vetor[i];
        }

        if(vetor[i] < menor){
        menor=vetor[i];
        }
   }
   printf("O maior membro de vetor e: %i\n", maior);
   printf("O menor membro de vetor e: %i\n", menor);

   //percentual de numeros pares e fazendo a media
    for(i=0;i<5;++i){
        if(vetor[i]%2==0){
            ++Npares;
        }
        media+=vetor[i];
    }
   printf("Contou-se %i numeros pares\n", Npares);
   printf("A media dos componentes do vetor e: %i\n", media/5);

    printf("\n");

    return 0;
}
