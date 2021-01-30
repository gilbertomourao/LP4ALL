#include <stdio.h>
#include <stdlib.h>
/*8-LER UM VETOR VET DE 10 ELEMENTOS E OBTER UM VETOR FAT CUJOS COMPONENTES
SÃO OS FATORIAIS DOS RESPECTIVOS COMPONENTES DE VET.*/
int main()
{
    int vetor[10]={0};
    int i;
    int fatorial=1;
    int VetFat[10]={0};

    printf("Entre com os elementos do vetor:\n");
    for(i=0;i<10;i++){
        scanf("%i", &vetor[i]);
        }

    for(i=0;i<10;i++){

        if(vetor[i]==0){
           VetFat[i]=1;
        } else {
            while(vetor[i]!=0){
            fatorial*=vetor[i];
           --vetor[i];
            }
            VetFat[i]=fatorial;
        }
        fatorial=1;
    }

     printf("Vetor Fatorial:\n");
     for(i=0;i<10;i++){
        printf("%i\n",VetFat[i]);
        }
    printf("\n");
    return 0;
}
