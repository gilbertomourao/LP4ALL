/*  PRIMEIRA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 1 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 300

int main()
{
    int vetor[MAX]; // VETOR INSERIDO
    int vet_org[MAX]; // VETOR ORGANIZADO
    int quant; // QUANTIDADE DE ELEMENTOS DO VETOR
    int erro; // VERIFICA SE O SCANF TA RECEBENDO UM INTEIRO
    int i,j; // ITERADORES
    int tam_par; // TAMANHO DO VETOR APENAS COM OS ELEMENTOS PARES
    int aux; // VARIÁVEL QUE AUXILIA NA ORDENAÇÃO

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

// ORGANIZANDO O VETOR: ELEMENTOS PARES
    for(i=0,j=0; i<quant;i++)
    {
        if (vetor[i] % 2 == 0) // PAR
        {
            vet_org[j]=vetor[i];
            j++;
        }

    }

    tam_par = j;


// ORGANIZANDO O VETOR: ELEMENTOS IMPARES
    for (i = 0, j = tam_par; i < quant; i++) // INICIA DEPOIS DOS ELEMENTOS PARES
    {
        if (vetor[i] % 2 != 0)
        {
            vet_org[j] = vetor[i];
            j++;
        }
    }

// EXIBE NA TELA O VETOR ORGANIZADO
    printf("Vetor Organizado entre pares e impares: ");
    for(i=0;i<quant;i++)
    {
        printf("%d  ", vet_org[i]);

    }
        printf("\n");

// ORDENAÇÃO DO VETOR
// ELEMENTOS PARES EM ORDEM DECRESCENTE
     for (i = 0; i < tam_par; i++)
    {
        for (j = i+1; j < tam_par; j++)
        {
            if (vet_org[i]<vet_org[j]) // VERIFICA SE O ELEMENTO DA POSIÇÃO i É MENOR QUE O ELEMENTO DA POSIÇÃO SEGUINTE
            {
                aux = vet_org[i];
                vet_org[i] = vet_org[j];
                vet_org[j] = aux;
            }
        }

    }
// ELEMENTOS IMPARES EM ORDEM CRESCENTE
    for (i = tam_par; i < quant; i++)
    {
        for (j = i+1; j < quant; j++)
        {
            if (vet_org[i]>vet_org[j]) // VERIFICA SE O ELEMENTO DA POSIÇÃO i É MAIOR QUE O ELEMENTO DA POSIÇÃO SEGUINTE
            {
                aux = vet_org[i];
                vet_org[i] = vet_org[j];
                vet_org[j] = aux;
            }
        }

    }

// EXIBE NA TELA O VETOR ORDENADO
    printf("Vetor Ordenado: ");
    for(i=0;i<quant;i++)
    {
        printf("%d  ", vet_org[i]);
    }

    return 0;
}

