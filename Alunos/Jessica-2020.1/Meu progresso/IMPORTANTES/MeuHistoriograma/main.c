#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
/*Historiograma de uma frase*/
#define MAX 100

int main()
{
    void ReadLetters(char string[]);
    char frase[MAX];
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int frequencia[26];
    int tam;
    int i,j;
    int aux_frenquecia;
    char aux_alfabeto;

    /*Zerar vetor frenquêcia*/
    for(i=0; i<26; i++){
        frequencia[i]=0;
    }

    /*Receber a frase*/
    printf("Insira a string:");
    ReadLetters(frase);
    printf("\n\n");

    /*Convertendo toda frase para letras minusculas*/
    for(i=0; frase[i]!='\0'; i++){
        if(frase[i]>='A' && frase[i]<='Z')
            frase[i]=tolower(frase[i]);
    }

    /*Armazenar a frequencia de um caractere na posição do vetor frequencia correspondente*/
    for(i=0; i<26; i++){ //Percorre as posições do vetor de caractere com alfabeto
        for(j=0; frase[j]!='\0'; j++){ //Percorre toda a frase comparando-a toda com cada letra do alfabeto

            if(frase[j] == alfabeto[i]){ //Vai preencher as frequencias dos caracteres
                frequencia[i] += 1;
            }
        }
    }

    /*Organizar letras por ordem decrescente de frequencias*/
    for(i=0; i<26; ++i){
        for(j=i+1; j<26; ++j){
            if (frequencia[i]<frequencia[j]){ //Compara e organiza, se primeiro menor que anterior => inverte

                aux_frenquecia = frequencia[i]; //Organiza vetor de frequência
                frequencia[i] = frequencia[j];
                frequencia[j] = aux_frenquecia;

                aux_alfabeto = alfabeto[i]; //Organiza vetor de caractere
                alfabeto[i] = alfabeto[j];
                alfabeto[j] = aux_alfabeto;
            }
        }
    }

    /*Organizar letras por ordem decrescente de frequencias e ALFABETICA*/
    tam=strlen(frase); //Descobrindo o tamanho da string

    for(i=0; i<26; i++) {
        for(j=i+1; j<26; j++) {
            if(frequencia[i]==frequencia[j]){
                if(alfabeto[i] > alfabeto[j]){
                    aux_alfabeto = alfabeto[i]; //Organiza vetor de caractere
                    alfabeto[i] = alfabeto[j];
                    alfabeto[j] = aux_alfabeto;
                }
            }
        }
    }

    //imprimir string ordenada de acordo com a frequencia e ordem alfabetica
    for(i=0; i<26; i++) {
        if(frequencia[i]) { //So imprime se frenquecia > 0, logo só letras da frase
            for(j=0; j<frequencia[i]; j++) //Vai imprimir a quatidade da letra achada
            {
                printf("%c",alfabeto[i]);
            }
        }
    }

    printf("\n\n");

    //Imprimir o caracter e sua frequencia
    printf("\n\nLetras\tFrequencias\n");
    for(i = 0; i < 26; i++) {
        if(frequencia[i]) {
            printf("  %c\t    %d\n", alfabeto[i], frequencia[i]);
        }
    }
    printf("\n\n");

    return 0;
}

/* LER APENAS LETRAS NUMA STRING*/
void ReadLetters(char string[]){
    char ch; //Capta cada caractere digitado
    char digitado[50]; //Junta todos as letras digitadas
    int i=0, j;

    do{
        fflush(stdin); //Limpa o buffer
        ch = getch( ); //Captura o caractere digitado pelo usuario;

        if ( isalpha(ch) != 0 || ch == 32 ) { // Se for uma letra ou espaço
            digitado[i]=ch; //É direcionado para string de letras
            i++; //Passa para proxima posição
            printf("%c", ch); //Exibe letra ou espaço digitado na tela

        } else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
            i--;
            digitado[i] = '\0';
            printf("\b \b"); //Apaga o caractere anterior
        }
    } while(ch != 13); // Quando o ENTER for digitado, termina o loop

    digitado[i] = '\0'; //Finaliza a string

    for(j=0; digitado[j]!='\0'; j++){
        string[j]= digitado[j];
    }
    string [j] = '\0';
}
