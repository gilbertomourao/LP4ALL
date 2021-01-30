//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 3 - Transformar maiúscula em minúscula e vice-versa	as linhas e
//     imprimir a matriz resultante.
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main()
{
    char Matriz[MAX][MAX], Matriz_final[MAX][MAX];
    int linha, coluna;
    int i,j,k,z;

    /*RECEBENDO DIMENSÕES DA MATRIZ DO USUÁRIO*/
    printf("Digite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &linha);
    while(linha<=0 || linha>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimens%co de linha inv%clida, insira novamente: ",198 , 160);
        scanf("%i", &linha);
    }
    printf("\n\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf("%i", &coluna);
    while(coluna<=0 || coluna>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\n\nDimens%co de coluna inv%clida, insira novamente: ",198 , 160);
        scanf("%i", &coluna);
    }
    system("PAUSE");
    system("CLS");

    /*RECEBENDO OS COMPONENTES DA MATRIZ DO USUARIO*/
    printf("-------------------------------\n");
	printf("     Recebendo a matriz \n");
	printf("-------------------------------\n\n");

	for (i=0; i<linha; i++){ // Preenhe toda matriz com asteriscos primeiramente
        for(j=0; j<coluna; j++){
            Matriz[i][j]='*';
            printf(" %c ", Matriz[i][j]);
        }
        printf("\n");
	}
	printf("\n\n");

	for (i=0; i<linha; i++){ //Finaliza a toda a matriz com \0
        Matriz[i][coluna] = '\0';
	}

	for(i=0; i<linha; i++){
        for(j=0; Matriz[i][j]!='\0'; j++) {
            printf("Matriz [%i][%i]: ", i+1, j+1);
            fflush(stdin);
            scanf("%c", &Matriz[i][j]); //Recebe caracteres do usuario

            system("CLS"); //Limpa a tela para exibir tudo com o caractere recebido acima

            printf("-------------------------------\n");
            printf("     Recebendo a matriz \n");
            printf("-------------------------------\n\n");

            for (k=0; k<linha; k++) { // Exibe a matriz com o caractere recebido nessa interação
                for(z=0; Matriz[k][z]!='\0'; z++) {
                    printf(" %c ", Matriz[k][z]); //Exibe cada caractere
                }
                printf("\n"); //Pula a linha
            }
            printf("\n\n");
        }
    }
    system("PAUSE"); //Pausa o sistema
    system("CLS"); //Limpa a tela

    /*PASSANDO A MATRIZ PARA OUTRA AUXILIAR*/
    for(i=0; i<linha; i++) {
        for(j=0; Matriz[i][j]!='\0'; j++) {
            Matriz_final[i][j]=Matriz[i][j];
        }
    }

    for (i=0; i<linha; i++){ //Finaliza a toda a matriz auxiliar com \0
        Matriz_final[i][coluna] = '\0';
	}

	/*CONVERTENDO AS LETRAS MAIUSCULAR EM MINUSCULAR E VIRSE E VERSA*/
	for(i=0; i<linha; i++) {
        for(j=0; Matriz[i][j]!='\0'; j++) { //Usa como base de comparação a matriz original para evitar conflitos depois da conversao

            if (Matriz[i][j]>='A' && Matriz[i][j]<='Z') { //Se o caractere for maiusculo
                Matriz_final[i][j] = tolower(Matriz[i][j]); //Converte caractere para minusculo na matriz auxiliar
                continue; //Pula para proxima interação
            }

            if (Matriz[i][j]>='a' && Matriz[i][j]<='z') { //Se o caractere for minusculo
                Matriz_final[i][j] = toupper(Matriz[i][j]); //Converte caractere para maiusculo na matriz auxiliar
            }
        }
    }

    /*EXIBE MATRIZ ORIGINAL E MATRIZ APOS A CONVERSAO DAS LETRAS*/
    printf("------------------------------\n"); //Exibindo a matriz inserida pelo usuario
    printf("\t Matriz Original\n");
    printf("------------------------------\n");
    for (i=0; i<linha; i++) {
        for(j=0; Matriz[i][j]!='\0'; j++) {
            printf(" %c ", Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("------------------------------\n");//Exibindo a matriz com as conversoes
    printf("   Matriz Convertida\n");
    printf("------------------------------\n");
    for (i=0; i<linha; i++) {
        for(j=0; Matriz_final[i][j]!='\0'; j++) {
            printf(" %c ", Matriz_final[i][j]);
        }
        printf("\n");
    }

    return 0;
}
