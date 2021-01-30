#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numb;
    int cifra;

    printf("Insira um numero inteiro:\n");
    scanf("%i", &numb);

    printf("O numero invertido sera:");

    if (numb>=0) {

        do{
            cifra=numb%10;
            printf("%i",cifra);
            numb=numb/10;
        } while (numb>0);
        printf("\n");

    } else {

        numb=numb*(-1);
        printf("-");

        do{
            cifra=numb%10;
            printf("%i",cifra);
            numb=numb/10;
        }while(numb>0);
          printf("\n");
    }
return 0;
}
