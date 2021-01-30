#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<locale.h>
#define MAX 100
/*29.	Faça um programa que dado 2 palavras, determine:
a.	Se as palavras são iguais;
b.	Caso as palavras sejam diferentes, qual delas tem maior comprimento (não esquecer
    a possibilidade de existirem palavras diferentes de mesmo tamanho);
c.	Verifique se a segunda palavra é uma sub string da primeira:
Exemplo: Palavra 1=  casamento
               Palavra 2 = casa*/
int main()
{
    int i,j,aux;
    char string1[MAX], string2[MAX], string1M[MAX], string2M[MAX];
    int confirma, ocorrencias=0;
    int tam1, tam2, comp;

    /* Lendo as duas strings */
    printf("Entre com a primeira string a ser comparada:\n");
    gets(string1);
    printf("Entre com a segunda string a ser comparada:\n");
    gets(string2);

    /*Medindo o tamanho das strings*/
    tam1=0;
    tam2=0;
    while (string1[tam1]!='\0') tam1++;
    while (string2[tam2]!='\0') tam2++;

    if(tam1== tam2)
        comp = 0;
    else if(tam1>tam2)
        comp = 1;
    else if (tam1<tam2)
        comp = -1;

    /* Ignorando o case sensitive*/

    for(i=0;string1[i]!='\0';++i){ //Passando frase para auxiliar
        string1M[i] = tolower(string1[i]);
     }
     string1M[i]='\0';
    for(i=0;string2[i]!='\0';++i){ //Passando frase para auxiliar
        string2M[i] = tolower(string2[i]);
     }
     string2M[i]='\0';

    /*Verificando se as strings são iguais ou não*/
    if(comp == 0) { //Caso tenham o mesmo tamanho
        i=0;
        while (string1M[i]==string2M[i] && string1M[i]!='\0' && string2M[i]!='\0') i++; //Percorre as strings comparando-as

        if(string1M[i]=='\0' && string2M[i]=='\0'){
            setlocale(LC_ALL, "Portuguese");
            printf("\nSão iguais\n");
            printf("Tem o mesmo tamanho\n");
        } else {
            setlocale(LC_ALL, "Portuguese");
            printf("\nSão diferentes\n");
            printf("Tem o mesmo tamanho\n");
        }
    }
    else if (comp==1) { //caso a primeira string seja maior que a segunda
        setlocale(LC_ALL, "Portuguese");
        printf("\nSão diferentes\n\n");
        setlocale(LC_ALL, "Portuguese");
        printf("A primeira string é maior que a segunda string\n");

        ocorrencias=0; //Verifica se a segunda string esta contida na primeira

        for(i=0 ; string1M[i]!='\0'; i++){
            if (string1M[i] == string2M[0]) {
                confirma=1;
                for(j=0, aux=i ; string1M[aux]!='\0' && string2M[j]!='\0' ; j++, aux++){
                    if( string1M[aux] != string2M[j] ) {
                        confirma=0;
                        break;
                    }
                }
                if(confirma && string2M[j]=='\0')
                    ocorrencias++;
            }
        }

        if ( ocorrencias>0 ) {
            setlocale(LC_ALL, "Portuguese");
            printf ("\nA segunda string está contida na primeira string %i vez(es)\n", ocorrencias);
        } else if ( ocorrencias==0 ) {
            setlocale(LC_ALL, "Portuguese");
            printf ("\nA segunda string não está contida na primeira string\n");
        }


    } else if (comp==-1){ //caso a segunda string seja maior que a primeira
        setlocale(LC_ALL, "Portuguese");
        printf("\nSão diferentes\n");
        setlocale(LC_ALL, "Portuguese");
        printf("\nA segunda string é maior que a primeira string\n");

        ocorrencias=0; //Verifica se a primeira string esta contida na segunda

        for(i=0 ; string2M[i]!='\0'; i++){
            if (string2M[i]== string1M[0]){
                confirma=1;
                for(j=0, aux=i ; string2M[aux]!='\0' && string1M[j]!='\0' ; j++, aux++){
                    if(string1M[j]!=string2M[aux]){
                        confirma=0;
                        break;
                    }
                }
                if(confirma && string1M[j]=='\0')
                    ++ocorrencias;
            }
        }
        if (ocorrencias>0){
            setlocale(LC_ALL, "Portuguese");
            printf ("\nA primeira string está contida na segunda string %i vez(es)\n", ocorrencias);
        }
        else if (ocorrencias==0){
            setlocale(LC_ALL, "Portuguese");
            printf ("\nA primeira string não está contida na segunda string\n");
        }
    }
    printf("\n");
    return 0;
}
