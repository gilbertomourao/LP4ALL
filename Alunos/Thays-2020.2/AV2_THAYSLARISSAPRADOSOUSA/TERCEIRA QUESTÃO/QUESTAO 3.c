/*  SEGUNDA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 3 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200
#define ALFABETO(ch) ((ch>= 'A' && ch <= 'Z') ||(ch >= 'a' && ch <= 'z')) // MACRO CRIADA PARA VERIFICAÇÃO DE CARACTER ALFABETICO
#define NUMERO(ch) (ch>='0' && ch<='9') // MACRO CRIADA PARA VERIFICAÇÃO DE DÍGITOS

// PROTOTIPOS
void Concatena(char [], char[], char[], char[]); // UNE AS TRES STRINGS EM UMA SO
void Contagem (char[], int *, int *); // CONTA AS OCORRENCIAS DE LETRAS E NUMEROS
void Imprime (char[], int, int); // IMPRIME OS RESULTADOS

void main ()
{
    char Nome[MAX]; // STRING NOME
    char Casa[MAX]; // STRING ENDEREÇO
    char Fone[MAX]; // STRING TELEFONE
    char Str_conc[MAX]; // STRING CONCATENA
    int letra=0, dig=0; // CONTADORES

    printf("Informe o nome:");
    fflush(stdin);
    gets(Nome);
    printf("Informe o endereco:");
    fflush(stdin);
    gets(Casa);
    printf("Informe o telefone:");
    fflush(stdin);
    gets(Fone);

    printf("\n");
    printf("RESULTADO:\n");
    Concatena(Nome,Casa,Fone,Str_conc);
    Contagem(Str_conc, &letra, &dig); // &letra RETORNA O ENDEREÇO DE LETRA E &dig RETORNA O ENDEREÇO DE DIG
    Imprime(Str_conc, letra, dig);

}

void Concatena(char Nome[], char Casa[], char Fone[], char Str_conc[])
{
    int i,j,k; // ITERADORES
    int tam=0; // VARIAVEL TAMANHO

    for (i=0; Nome[i]!='\0'; i++)
    {
        Str_conc[i]=Nome[i];
    }

    tam=i; // TAMANHO DA STRING CONCATENA

    Str_conc[tam]=' '; // ADICIONO ESPAÇO APOS A PRIMEIRA STRING SER ADICIONADA

    for (i=tam+1, j=0; Casa[j]!='\0'; i++) // COMEÇO A ADICIONAR A SEGUNDA STRING APOS O ESPAÇO INSERIDO
    {
        Str_conc[i]=Casa[j];
        j++;

    }

    Str_conc[i]=' '; // ADICIONO ESPAÇO APOS SEGUNDA STRING

    for (k=i+1, j=0; Fone[j]!='\0'; k++)
    {
        Str_conc[k]=Fone[j];
        j++;

    }

    Str_conc[k]='\0'; // FINALIZO A STRING CONCATENA

}

void Contagem (char Str_conc[], int *cont_letra, int *cont_dig) // ACESSO INDIRETO AS VARIAVEIS: LETRA E DIG
{
    int i; // INTERADOR

    for (i=0; Str_conc[i]!='\0'; i++)
    {
        if (ALFABETO(Str_conc[i])) // VERIFICO SE É UMA LETRA USANDO A MACRO
        {
            *cont_letra= *cont_letra+1; // *cont_letra APONTA PARA O CONTEUDO DE LETRA (cont_letra =&letra)
        }
        if (NUMERO(Str_conc[i])) // VERIFICO SE É UM DÍGITO USANDO A MACRO
        {
            *cont_dig= *cont_dig+1; // *cont_dig APONTA PARA O CONTEUDO DE DIG (cont_dig =&dig)
        }
    }

}

void Imprime (char Str_conc[], int letra, int dig)
{
    printf("String Concatenada: %s\n", Str_conc);
    printf("Quantidade de letras: %d\n", letra);
    printf("Quantidade de digitos: %d\n", dig);

}
