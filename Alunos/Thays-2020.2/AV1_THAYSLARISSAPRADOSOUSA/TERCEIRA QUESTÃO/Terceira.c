/*  PRIMEIRA AVALIA��O DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUEST�O 3 */

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
    int it_pos; // ITERADOR POSI��O

    printf("Insira o nome completo:");
    fflush(stdin);
    gets(nome_completo);

// CALCULA TAMANHO DO NOME COMPLETO INSERIDO
    while ( nome_completo[i] != '\0')
    {
        i++;
    }
    tam = i;

// VERIFICA A STRING AO CONTR�RIO PARA IDENTIFICA��O DO ULTIMO NOME
    for (i=tam-1; nome_completo[i]!= ' ' ; i--)
    {
        it_pos=i; //INDICA A POSI��O DA PRIMEIRA LETRA DO ULTIMO NOME

    }

    for (i=it_pos, j=0; nome_completo[i]!= '\0'; i++)
    {
        nome_final[j]=nome_completo[i]; // NOME FINAL RECEBE O ULTIMO NOME
        j++;
    }

    nome_final[j]='\0'; // FINALIZANDO A STRING

// INSERE V�RGULA AP�S O ULTIMO NOME E ESPA�O ANTES DO PRIMEIRO NOME

    nome_final[j]=',';
    nome_final[j+1]=' ';

// IDENTIFICA��O DO PRIMEIRO NOME

    for (i=0, j=j+2; nome_completo[i]!=' '; i++)
    {
        nome_final[j]=nome_completo[i]; // NOME FINAL RECEBE O PRIMEIRO NOME AP�S ESPA�O INSERIDO
        j++;
    }

    nome_final[j]='\0'; // FINALIZANDO A STRING

    printf("%s", nome_final);

    return 0;
}
