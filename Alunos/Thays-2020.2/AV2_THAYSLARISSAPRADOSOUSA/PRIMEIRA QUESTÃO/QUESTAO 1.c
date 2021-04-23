/*  SEGUNDA AVALIA��O DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUEST�O 1 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200

// PROTOTIPOS
void Ler_Str(char[]); // FUN��O PARA LER STRING PRINCIPAL
void Ler_StrSubs(char[]); // FUN��O PARA LER STRING QUE SUBSTITUI
void Insere(int,char[], char[], char[]); // FUN��O PARA INSERIR A STRING SUBSTITUI��O NA STRING PRINCIPAL
void Imprimir (char[]); // FUN��O PARA IMPRIMIR A STRING MODIFICADA

void main()
{
    char string[MAX], str_subs[MAX], str_mod[MAX];
    int pos;

    Ler_Str(string);
    Ler_StrSubs(str_subs);
    Insere(pos, string, str_subs,str_mod);
    printf("\n");
    printf("RESULTADO:\n");
    Imprimir(str_mod);
}


void Ler_Str(char string[]) // LER
{
    printf("Informe a string principal: ");
    fflush(stdin);
    gets(string);
}

void Ler_StrSubs(char str_subs[]) // LER
{
    printf("Informe a string a ser inserida na string principal: ");
    fflush(stdin);
    gets(str_subs);
}


void Insere(int pos, char string[], char str_subs[], char str_mod[])
{
    int tam=0; // VARIAVEL TAMANHO
    int erro; // VERIFICA SE O SCANF TA RECEBENDO UM VALOR V�LIDO
    int i,j,k; // ITERADORES

    while ( string[tam] != '\0') // ENQUANTO A STRING N�O CHEGA AO FIM
    {
        tam++; // A QUANTIDADE DE VEZES INCREMENTADO � IGUAL AO TAMANHO DA STRING
    }

     do // FOR�A O USUARIO A INSERIR UM NUMERO VALIDO PARA INDICAR A POSI��O
    {   printf("Informe a posicao da string principal em que deseja colocar a string substituicao: ");
        erro = scanf("%d", &pos);
        fflush(stdin);
    } while ( pos< 0 ||pos >= tam ||erro == 0 );

    for (i=0, j=0; string[i] != '\0'; i++) // VARRO A STRING PRINCIPAL
    {
        if (i==pos) // ENCONTRA A POSI��O ESCOLHIDA PELO USU�RIO
        {
            for(k=0; str_subs[k] != '\0'; k++)
            {
                str_mod[j] = str_subs[k]; // INSERE A STRING SUBSTITUI��O
                j++;
            }

        }
        else
        {
            str_mod[j] = string[i]; // INSERE A STRING PRINCIPAL
            j++;
        }
    }

    str_mod[j] = '\0'; // ENCERRA A STRING
}

void Imprimir (char str_mod[]) // IMPRIMIR
{
    printf("String Modificada: %s\n", str_mod);

}
