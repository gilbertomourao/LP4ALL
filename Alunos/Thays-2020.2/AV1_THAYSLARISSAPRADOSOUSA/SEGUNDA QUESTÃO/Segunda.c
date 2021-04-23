/*  PRIMEIRA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 2 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 300

int main()
{
    int vetor[MAX]; // VETOR INSERIDO
    int quant; // QUANTIDADE DE ELEMENTOS DO VETOR
    int erro; // VERIFICA SE O SCANF TA RECEBENDO UM INTEIRO
    int i,j; // ITERADORES
    int cont=1; // CONTADOR DE OCORRÊNCIAS
    int comp=1; // COMPRIMENTO DA OCORRENCIA DE SEQUENCIA CRESCENTE

// USUARIO INSERE QUANTIDADE DE ELEMENTOS DO VETOR
   do // FORÇA O USUARIO A INSERIR UM NUMERO VALIDO DE ELEMENTOS
    {   printf("Insira o numero de elementos do vetor: ");
        erro = scanf("%d", &quant);
        fflush(stdin);
    } while ( quant<= 0 ||quant > MAX ||erro == 0 );

// USUARIO INSERE OS ELEMENTOS DO VETOR
    for(i=0;i<quant;i++)
    {
        do // FORÇA O USUARIO A INSERIR UM ELEMENTO INTEIRO
        {
            printf("Insira o elemento [%d] do vetor: ", i);
            erro = scanf("%d",&vetor[i]);
            fflush(stdin);
        } while ( erro == 0 );
    }

// EXIBE NA TELA O VETOR INSERIDO
    printf("Vetor Inserido: ");
    for(i=0;i<quant;i++)
    {
        printf("%d  ", vetor[i]);
    }
    printf("\n");

// COMPARA O ELEMENTO i COM O ELEMENTO POSTERIOR A ELE PARA VERIFICAR SE HÁ OCORRÊNCIA DE UMA SEQUÊNCIA CRESCENTE
    for (i = 0; i < quant - 1; i++)
    {
        if (vetor[i] <= vetor[i+1] && i != quant-2) // VERIFICA DO PRIMEIRO AO ANTEPENULTIMO ELEMENTO
        {
            cont++;
        }
        else
        {
            if (vetor[i] <= vetor[i+1] && i == quant-2) // VERIFICA O PENULTIMO E ULTIMO ELEMENTO
            {
                cont++;
            }
            if (cont >= comp) // VERIFICA SE O NUMERO DE OCORRENCIAS É SUPERIOR A 1
            {
                comp = cont;
            }

              cont = 1; // CONTAGEM REINICIADA
        }
    }

    printf("o comprimento de um segmento crescente maximo e %d\n", comp);

    return 0;

}

