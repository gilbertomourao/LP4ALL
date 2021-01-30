#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int fatorial=1;
    int numero = 0;
    int j;

    printf("Digite o numero para o calculo do fatorial:\n");
    scanf("%i", &numero);

    j=numero;

    for(i=0; i<numero; i++) {
        fatorial = fatorial * j;
        printf("%i\n",fatorial);
        --j;
    }

    printf("O fatorial de %i sera %i.\n",numero,fatorial);

    return 0;
}
