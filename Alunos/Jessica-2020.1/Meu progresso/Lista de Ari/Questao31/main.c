#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 100

/*31.	Fazer um programa para:
a.	Receber uma string de no máximo 100 caracteres
b.	Receber uma segunda string e contar quantas vezes a segunda string ocorre dentro da primeira.*/

int main()
{
    char string1[MAX], string2[MAX];
    int i,j,k;
    int i_aux=0, confirma=0;
    int ocorrencias=0;
    int especial=0;
    int tam2=0;

    printf("Insira uma string:\n");
    gets(string1);
    printf("Insira outra string:\n");
    gets (string2);

    /* Tranformando as strings completas em minusculas*/
    for(i=0; string1[i]!='\0'; i++){
        if( string1[i]>='A' && string1[i]<='Z' ){
            string1[i]=tolower(string1[i]);
        }
    }

    for(i=0; string2[i]!='\0'; i++){
        if( string2[i]>='A' && string2[i]<='Z' ){
            string2[i]=tolower(string2[i]);
        }
    }

    /*Verificando se o primeiro caractere da segunda string é igual ao ultimo*/
    while (string2[tam2]!='\0') ++tam2;

    especial = (string2[0] == string2[tam2-1]) ? 1 : 0;

    /*Verificando as ocorrencias da segunda string na primeira*/
    for(i=0; string1[i]!='\0'; i++){ // Laço principal - Corre toda a primeira string
        if(string1[i] == string2[0]){ // Identifica uma provavel ocorrencia
            confirma=1;
            for(j=0, i_aux=i; string1[i_aux] != '\0' && string2[j] != '\0'; j++, i_aux++){
                if(string1[i_aux] != string2[j]){
                    confirma=0;
                    break;
                }
            }

            if(confirma && string2[j]=='\0'){ //Encontrou uma ocorrencia
                ++ocorrencias; //Vai somar todas as ocorrencias da segunda string na primeira
                i = (especial) ? i_aux-2 :  i_aux-1;
            }
        }
    }

    if (ocorrencias>0)
        printf("\nA segunda string ocorreu %i vez(es) na primeira string.\n", ocorrencias);
    else
        printf("\nA segunda não ocorreu nenhuma vez na primeira.\n");

    return 0;
}
