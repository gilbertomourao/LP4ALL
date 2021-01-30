#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numb1;
    int numb2;

    printf("Insira o dividendo desejado:");
    scanf("%i", &numb1);
    printf("Insira o divisor desejado:");
    scanf("%i", &numb2);

    if (numb2==0) {
        printf("Divisao por zero nao e permitida.\n");
    } else {
                if (numb1%numb2==0) {
                    printf("%i e' divisível por % i\n", numb1,numb2);
                } else{
                    printf("%i nao e' divisivel por %i \n", numb1,numb2);
                    }
            }
    return 0;
}

