#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
/*6 – DADO UM ARRAY A DE 128 ELEMENTOS, VERIFICAR SE EXISTE UM ELEMENTO
IGUAL A K (CHAVE) NO ARRAY. SE EXISTIR, IMPRIMIR APOSIÇÃO ONDE FOI
ENCONTRADA A CHAVE. AO FINAL, IMPRIMIR A QUANTIDADE DE VEZES QUE FOI
ENCONTRADA; SE NENHUMA OCORRÊNCIA DE K FOR ENCONTRADA, IMPRIMIR
“CHAVE K NÃO ENCONTRADA”.*/
int main()
{
    int vetor[128]={0};
    int k=0;
    int quant=0;

    printf("Insira a chave um numero inteiro:\n");
    scanf("%i",&k);
    printf("\n\n");

    //gerando membros aleatorios pro vetor
    srand(time(NULL));
    for(int i =0; i<128;++i){
       vetor[i]=rand()%200;
    }
    //mostrando o vetor formado
        printf("Apresentando o vetor:\n");
     for(int i =0; i<128;++i){
       printf("%i \n", vetor[i]);
    }
    for(int i =0; i<128;++i){
        if(vetor[i]==k){
            printf("A chave %i foi encontrada na posição %i.\n",k, i+1);
            quant++;
        }
    }
    printf("\n\n");

    if(quant==0){
        printf("CHAVE %i NAO ENCONTRADA.\n",k);
    } else{
        printf("CHAVE %i  FOI ENCONTRADA %i VEZES",k, quant);
        quant=0;
    }
    return 0;
}
