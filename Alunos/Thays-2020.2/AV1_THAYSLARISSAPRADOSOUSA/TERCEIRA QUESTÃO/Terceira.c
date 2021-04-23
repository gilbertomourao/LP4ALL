/*  PRIMEIRA AVALIAÇÃO DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUESTÃO 3 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 300

int main()
{
    char nome_completo[MAX];// STRING QUE RECEBE O NOME COMPLETO INSERIDO PELO USUARIO
    char nome_final[MAX]; // STRING COM O NOME ORGANIZADO
    int tam; // TAMANHO DA STRING
    int i,j; // ITERADORES
    int it_pos; // ITERADOR POSIÇÃO

    printf("Insira o nome completo:");
    fflush(stdin);
    gets(nome_completo);

// CALCULA TAMANHO DO NOME COMPLETO INSERIDO
    while ( nome_completo[i] != '\0')
    {
        i++;
    }
    tam = i;

// VERIFICA A STRING AO CONTRÁRIO PARA IDENTIFICAÇÃO DO ULTIMO NOME
    for (i=tam-1; nome_completo[i]!= ' ' ; i--)
    {
        it_pos=i; //INDICA A POSIÇÃO DA PRIMEIRA LETRA DO ULTIMO NOME

    }

    for (i=it_pos, j=0; nome_completo[i]!= '\0'; i++)
    {
        nome_final[j]=nome_completo[i]; // NOME FINAL RECEBE O ULTIMO NOME
        j++;
    }

    nome_final[j]='\0'; // FINALIZANDO A STRING

// INSERE VÍRGULA APÓS O ULTIMO NOME E ESPAÇO ANTES DO PRIMEIRO NOME

    nome_final[j]=',';
    nome_final[j+1]=' ';

// IDENTIFICAÇÃO DO PRIMEIRO NOME

    for (i=0, j=j+2; nome_completo[i]!=' '; i++)
    {
        nome_final[j]=nome_completo[i]; // NOME FINAL RECEBE O PRIMEIRO NOME APÓS ESPAÇO INSERIDO
        j++;
    }

    nome_final[j]='\0'; // FINALIZANDO A STRING

    printf("%s", nome_final);

    return 0;
}
