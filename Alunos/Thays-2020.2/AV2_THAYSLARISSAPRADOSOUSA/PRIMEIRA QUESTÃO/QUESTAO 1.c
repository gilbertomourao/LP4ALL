/*  SEGUNDA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 1 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200

// PROTOTIPOS
void Ler_Str(char[]); // FUNÇÃO PARA LER STRING PRINCIPAL
void Ler_StrSubs(char[]); // FUNÇÃO PARA LER STRING QUE SUBSTITUI
void Insere(int,char[], char[], char[]); // FUNÇÃO PARA INSERIR A STRING SUBSTITUIÇÃO NA STRING PRINCIPAL
void Imprimir (char[]); // FUNÇÃO PARA IMPRIMIR A STRING MODIFICADA

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
    int erro; // VERIFICA SE O SCANF TA RECEBENDO UM VALOR VÁLIDO
    int i,j,k; // ITERADORES

    while ( string[tam] != '\0') // ENQUANTO A STRING NÃO CHEGA AO FIM
    {
        tam++; // A QUANTIDADE DE VEZES INCREMENTADO É IGUAL AO TAMANHO DA STRING
    }

     do // FORÇA O USUARIO A INSERIR UM NUMERO VALIDO PARA INDICAR A POSIÇÃO
    {   printf("Informe a posicao da string principal em que deseja colocar a string substituicao: ");
        erro = scanf("%d", &pos);
        fflush(stdin);
    } while ( pos< 0 ||pos >= tam ||erro == 0 );

    for (i=0, j=0; string[i] != '\0'; i++) // VARRO A STRING PRINCIPAL
    {
        if (i==pos) // ENCONTRA A POSIÇÃO ESCOLHIDA PELO USUÁRIO
        {
            for(k=0; str_subs[k] != '\0'; k++)
            {
                str_mod[j] = str_subs[k]; // INSERE A STRING SUBSTITUIÇÃO
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
