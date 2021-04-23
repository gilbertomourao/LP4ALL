/*  SEGUNDA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 2 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200

// PROTOTIPOS
void Ler_Str(char[]); // FUNÇÃO PARA LER A STRING INSERIDA PELO USUARIO
void Ordena_Imprime (char[]); // FUNÇÃO PARA ORDENAR E IMPRIMIR
void Conta_Imprime (char[]); // FUNÇÃO PARA CONTAR E IMPRIMIR TOTAL DE DUPLAS


int main()
{
    char string[MAX];

    Ler_Str(string);
    printf("\n");
    printf("RESULTADO:\n");
    Ordena_Imprime(string);
    Conta_Imprime(string);

    return 0;
}

void Ler_Str(char string[]) // LER
{
    printf("Informe a string:");
    fflush(stdin);
    gets(string);
}

void Ordena_Imprime(char string[]) // ORDENAR E IMPRIMIR
{
    int i,j; // ITERADORES
    char aux; // VARIAVEL QUE AUXILIA ORDENAÇÃO

    // CASE SENSITIVE - TRANSFORMA TUDO PARA MAIUSCULA
    for (i=0; string[i]!='\0'; i++)
    {
            if(( string[i] >= 'a' ) && ( string[i] <= 'z' ))
            {
                string[i]=string[i]-32;

            }

    }

    // ORDENAÇÃO
    for (i=0; string[i]!='\0'; i++)
    {
        for (j = i+1; string[j]!='\0'; j++)
        {
            if (string[i] > string[j]) // VERIFICA SE O ELEMENTO DA POSIÇÃO i É MAIOR QUE O ELEMENTO DA POSIÇÃO SEGUINTE E FAZ A TROCA
            {
                aux = string[i];
                string[i] = string[j];
                string[j] = aux;
            }
        }

    }

     printf("String Ordenada:%s\n", string); // IMPRIMINDO STRING ORDENADA

}

void Conta_Imprime(char string[]) // CONTAR OCORRENCIAS E IMPRIMIR
{
    int i; // ITERADOR
    int cont = 0; // CONTADOR DE DUPLA PARA CADA CARACTER
    int total = 0; // CONTADOR DE TOTAL DE DUPLAS REPETIDAS

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == string[i+1])
        {
            cont++;
        }
        else
        {
            if (cont >= 1) // VERIFICA DUPLAS ENCONTRADAS
            {
                printf("%c - %d ", string[i], cont); // IMPRIMINDO QUANTIDADE DE DUPLA PARA CADA CARACTER
                total += cont;

            }

            cont = 0; // REINICIA A CONTAGEM
        }

    }
    printf("total -> %d\n", total); // IMPRIMINDO TOTAL DE DUPLAS REPETIDAS
}
