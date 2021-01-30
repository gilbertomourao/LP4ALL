#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

/*47.	Fazer um programa que receba três nomes de no máximo 15 caracteres cada um (nomes com
mais de 15 caracteres devem ser rejeitados) e as idades das respectivas pessoas em um vetor de
estruturas de dados. Após o recebimento,  listar os 3 nomes e idades que nela foram armazenados.*/

struct BancoDados {
    char nome[15];
    int idade;
};
typedef struct BancoDados cadastro;

//Funções Usadas:
void ReadDimension(int *D);
void LerCadastro (cadastro *v, int *D);
void PrintfCadastro (cadastro *v, int *D);
void ReadLetters(char *s);

int main()
{
    int tam;
    cadastro *vetor;

    ReadDimension(&tam);

    // Aloca tam elementos para vetor (Create an array of structures)
    vetor = (cadastro *) malloc(tam * sizeof(cadastro));

    LerCadastro(vetor, &tam);

    PrintfCadastro(vetor, &tam);

    free (vetor);

    return 0;
}

void ReadDimension(int *D) {
    printf("Digite quantas pessoas deseja-se listar: ");
    scanf("%i", D);
}

void LerCadastro (cadastro *v, int *D) {
    int i;
    printf ("\n\n\t    PREENCHENDO CADASTRO\n");
    printf("-------------------------------------------\n");
    for (i=0; i<*D; i++) {
        printf("Insira o nome: ");
        fflush(stdin);
        ReadLetters((v + i) -> nome);

        printf("\nInsira a idade: ");
        fflush(stdin);
        scanf("%i", &((v + i)->idade));
        printf("-------------------------------------------\n");
    }
    system("pause");
    system("cls");
}

/*LER APENAS LETRAS NUMA STRING COM PONTEIROS*/
void ReadLetters(char *s) {
    char ch; //Capta cada caractere digitado
    int i=0;
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
        } else if (i==15 && ch != 13)
            printf("\a"); // Limite de caracteres do nome atingido -> Sinal sonoro de alerta
    } while(ch != 13); // Quando o ENTER for digitado, termina o loop
    *(s+i) = '\0'; // Finaliza a string
}

void PrintfCadastro (cadastro *v, int *D) {
    int i;
    printf ("\n\n\t    CADASTROS\n");
    printf("-------------------------------------------\n");
    for (i=0; i<*D; i++) {
        printf("Nome: %s. \n", (v + i) -> nome);

        printf("Idade: %i.\n", (v + i)->idade);
        printf("-------------------------------------------\n");
    }
}




