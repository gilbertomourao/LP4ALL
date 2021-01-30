#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
/*45.	Escrever uma função que:
a.	receba dois strings como parâmetro, bem como um valor inteiro representando uma posição.
b.	insira o segundo string no primeiro, na posição indicada pelo valor.
c.	Fazer um programa que receba dois strings do usuário, o valor da posição, chame a função anteriormente
implementada e exiba o resultado ao usuário.*/
#define MAX 100

int main()
{
    void SubstStringEmString(char string1[MAX], char string2[MAX], int posicao);
    int ReceberParametros(char string1[MAX], char string2[MAX]);

    int posicao;
    char str1[MAX];
    char str2[MAX];

    posicao=ReceberParametros(str1,str2);

    SubstStringEmString(str1,str2,posicao);

    printf("-----------------------------------------\n");
    printf("\t\tREPOSTA\n");
    printf("-----------------------------------------\n");
    printf("%s\n", str1);
    printf("-----------------------------------------\n");

    return 0;
}

/*ISERE o SEGUNDO STRING NO PRIMEIRO, NA POSIÇÃO INDICADA*/
void SubstStringEmString (char string1[MAX], char string2[MAX], int posicao) {
    int i,j,k=0;
    char aux[MAX];

    for(i=0; string1[i]!='\0'; i++){
        if(i==posicao){
            for(j=0; string2[j]!='\0'; j++){
                aux[k++]=string2[j];
            }
        }

        aux[k++]=string1[i];
    }
    aux[k]='\0';

    for(i=0; aux[i]!='\0'; i++){
        string1[i]=aux[i];
    }
    string1[i]='\0';

}

/*RECEBE AS DUAS STRINGS E A POSICAO DA PRIMEIRA*/
int ReceberParametros(char string1[MAX], char string2[MAX]){
    int posicao,i;
    int tam1;

    printf("Insira a primeira string: ");
    fflush(stdin);
    gets(string1);
    printf("\n\n");

    tam1=strlen(string1);

    printf("Insira a segunda string: ");
    fflush(stdin);
    gets(string2);
    printf("\n\n");

    printf("Insira a posicao:  ");
    scanf("%i", &posicao);
    printf("\n\n");
    while(posicao<0 || posicao>=tam1){
        printf("posicao invalida, temos disponiveis a posicao:  ");
        for(i=0;i<tam1;i++){
            printf("%i, ", i);
        }
        printf("\b\b. Tente novamente, insira uma posicao:  ");
        scanf("%i", &posicao);
        printf("\n\n");
    }

    return posicao;
}

/*LER APENAS LETRAS NUMA STRING*/
void ReadLetters(char *s) {
    char ch; //Capta cada caractere digitado
    int i=0, j;
    do{
        fflush(stdin); // Limpa o buffer
        ch = getch(); // Captura o caractere digitado pelo usuario;
        if ( (isalpha(ch) || ch ==' ') && i<15 ) { // Se for uma letra ou espaço
            *(s+i)=ch; // É direcionado para string de letras
            ++i; // Passa para proxima posição
            printf("%c", ch); // Exibe letra ou espaço digitado na tela
        } else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
            --i;
            *(s+i) = '\0';
            printf("\b \b"); //Apaga o caractere anterior
        }
    } while(ch != '\n'); // Quando o ENTER for digitado, termina o loop
    *(s+i) = '\0'; // Finaliza a string
}
