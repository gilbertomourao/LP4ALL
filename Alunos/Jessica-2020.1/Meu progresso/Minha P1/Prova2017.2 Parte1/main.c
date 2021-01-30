#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k;
    int tam1,tam2,tam3;
    char temp;
    char string[100];
    char maiusculas[100];
    char minusculas[100];
    char numeros[100];

    printf("Entre com  letras maiusculas, minusculas e numeros aleatoriamente:\n");
    fgets(string,100,stdin); //Recebe a tring que sera organizada
    printf("\n\n");

    /*Separando as letras maiusculas:*/
    tam1=0;  //Recebera a quantidade de caracteres maiusculos
    for(i=0; string[i] != '\0';++i) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            maiusculas[tam1]=string[i];
            ++tam1;
        }
    }
    maiusculas[tam1]='\0';
    /*Organizando a string de maiusculas*/
    for(i=0;i<tam1;++i){
            for(j=i+1;j<tam1;++j){
                if (maiusculas[i]>maiusculas[j]){ //Compara e organiza
                    temp=maiusculas[i];
                    maiusculas[i]=maiusculas[j];
                    maiusculas[j]=temp;
                }
            }
    }

    /*Separando as letras minusculas:*/
     tam2=0; //Recebera a quantidade de caracteres minusculos
     for(i=0; string[i] != '\0';++i) {
        if (string[i] >= 'a' && string[i] <= 'z') { //Compara e organiza
            minusculas[tam2]=string[i];
            ++tam2;
        }
    }
    minusculas[tam2]='\0';
    /*Organizando a string de minusculos*/
    for(i=0;i<tam2;++i){
        for(j=i+1;j<tam2;++j){
            if (minusculas[i]>minusculas[j]){ //Compara e organiza
                temp=minusculas[i];
                minusculas[i]=minusculas[j];
                minusculas[j]=temp;
            }
        }
    }

    /*Separando os numeros:*/
    tam3=0; //Recebera a quantidade de caracteres numericos
     for(i=0; string[i] != '\0';++i) {
        if (string[i] >= '0' && string[i] <= '9') {
            numeros[tam3]=string[i];
            ++tam3;
        }
    }
     numeros[tam3]='\0';
    /*Organizando a string de numeros*/
    for(i=0;i<tam3;++i){
            for(j=i+1;j<tam3;++j){
                if (numeros[i]>numeros[j]){
                    temp=numeros[i]; // troquei j por i
                    numeros[i]=numeros[j];
                    numeros[j]=temp;
                }
            }
    }

    /*Juntando todas as strings organizadas*/
    for(i=0;i<tam1;++i){
        string[i]=maiusculas[i];
    }
    for(j=0;j<tam2;++j){
        string[tam1+j]=minusculas[j];
    }
    for(k=0;k<tam3;++k){
        string[tam1+tam2+k]=numeros[k];
    }
    string[tam1+tam2+tam3]='\0';

    printf("Organizada:\n%s\n", string);

    return 0;
}
