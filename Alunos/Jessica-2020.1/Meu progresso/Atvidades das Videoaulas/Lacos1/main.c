#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for(int i = 1; i<=5;++i){
        printf(" *****BIGBANG %i***** \n",i);
        for(int j = 1; j<=5;++j) {
        printf("      BIGBANG is %i      \n",j);
        }

        printf("\n");
    }
    return 0;
}
