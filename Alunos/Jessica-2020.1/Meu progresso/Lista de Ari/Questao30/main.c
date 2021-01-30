#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

/*30.	Faça um programa onde o usuário digita 3 informações a respeito de uma pessoa:
Nome, endereço e telefone. Concatene essas três informações em uma única string e
faça uma contagem de quantas letras do alfabeto estão presentes nesta string (considerando as
redundâncias) e também de dígitos numéricos. Os espaços e os caracteres de pontuação devem
ser ignorados(as funções de contagem já fazem isso).
Dica: use as funções int isalpha(char cr) e int isdigit(char cr).

Exemplo:
Nome: Ana Claudia
Endereço: Rui Barbosa, 234
Tel: 234-0912

Resultado:
Quantidade de letras pertencentes ao alfabeto = 20.
Quantidade de dígitos numéricos = 10 */

#define MAX 100

int main()
{
    char nome[MAX], endereco[MAX], telefone[MAX], total[MAX];
    int tam1=0, tam2=0, tam3=0;
    int i,j,k;
    int letras=0, numeros=0;

    printf("Nome: ");
    gets(nome);
    printf("Endereco: ");
    gets(endereco);
    printf("Tel: ");
    gets(telefone);

    /*Medindo as strings*/
    while(nome[tam1]!='\0') ++tam1; //Mede a string nome
    while(endereco[tam2]!='\0') ++tam2; //Mede a string endereco
    while(telefone[tam3]!='\0') ++tam3; //Mede a string telefone

    /*Concatenando as strings*/
    for(i=0; i<tam1; ++i)
        total[i]=nome[i];

    for(j=0;j<tam2;++j)
        total[tam1+j]=endereco[j];

    for(k=0;k<tam3;++k)
        total[tam1+tam2+k]=telefone[k];

    total[tam1+tam2+tam3]='\0';

    /*Contar as letras*/
    for(i=0; total[i]!='\0'; i++){ //Verificar se o caracter é uma letra do alfabeto
        if( isalpha(total[i]) ){
            ++letras;
        }
    }

    /*Contar os numeros*/
    for(i=0; total[i]!='\0'; i++){ //Verificar se o caracter é um digito decimal
        if( isdigit(total[i]) ){
            ++numeros;
        }
    }

    printf("\nQuantidade de letras pertencentes ao alfabeto = %i\n",letras);
    printf("\nQuantidade de dígitos numéricos = %i\n", numeros);

    return 0;
}
