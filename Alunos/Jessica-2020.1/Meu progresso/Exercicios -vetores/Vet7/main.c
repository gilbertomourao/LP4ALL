#include <stdio.h>
#include <stdlib.h>
/* 7-ARMAZENAR NOME DE 20 PESSOAS. CALCULAR E ARMAZENAR O NOVO SALÁRIO
SABENDO-SE QUE O REAJUSTE FOI DE 8%. IMPRIMIR UMA LISTAGEM NUMERADA
COM NOME E NOVO SALÁRIO.*/
int main()
{
    int i;
    char Pessoas [5][100];
    float Salario[5]={0};

    for(i=0;i<5;i++)
        {
        printf("Insira o nome da %i pessoa:\n", i+1);
        setbuf(stdin,NULL);
        gets(Pessoas[i]);
        printf("\n");
        printf("Insira agora o salario da %i pessoa:\n", i+1);
        scanf("%f",&Salario[i]);
        printf("\n");
        Salario[i] += (Salario[i]/100)*8;
        }

        printf("****Pessoas*****|*****Novos Salarios*****\n");
        for(i=0;i<5;i++)
        {
           printf("%iº:  ", i+1);
           printf("%s    ",Pessoas[i]);
           printf("%f \n",Salario[i]);
        }
           printf("\n");
    return 0;
}
