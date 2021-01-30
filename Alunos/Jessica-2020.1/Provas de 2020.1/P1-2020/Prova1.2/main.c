//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 2 - Ordenar crescentemente as linhas	da matriz e imprimir a matriz	resultante.
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    char Matriz[MAX][MAX], Matriz_organizada[MAX][MAX];
    int linha, coluna;
    int i,j,k,z;
    char aux;

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
	printf("      Recebendo a Matriz \n");
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
            scanf("%c", &Matriz[i][j]); //Recebe apenas caracteres do usuario

            system("CLS"); //Limpa a tela para exibir tudo com o caractere recebido acima

            printf("-------------------------------\n");
            printf("      Recebendo a Matriz \n");
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
            Matriz_organizada[i][j]=Matriz[i][j];
        }
    }

    for (i=0; i<linha; i++){ //Finaliza a toda a matriz auxiliar com \0
        Matriz_organizada[i][coluna] = '\0';
	}

	/*ORGANIZANDO AS LINHAS DA MATRIZ*/
	for(i=0; i<linha; i++) {
        for(j=0; Matriz_organizada[i][j]!='\0'; j++) {
            for(k=j+1; Matriz_organizada[i][k]!='\0'; k++) {
                if (Matriz_organizada[i][j]>Matriz_organizada[i][k]) { //Se o caractere na posicao [j] for maior (tabela ASCII) que da posicao [j+1]
                    aux=Matriz_organizada[i][j];  //Faz-se a troca de lugares dos caracteres em [j] e [j+1]
                    Matriz_organizada[i][j]=Matriz_organizada[i][k];
                    Matriz_organizada[i][k]=aux;
                }
            }
        }
    }

    /*EXIBE MATRIZ ORIGINAL E MATRIZ COM LINHAS ORGANIZADAS*/
    printf("------------------------------\n");
    printf("\tMatriz Original\n");
    printf("------------------------------\n");
    for (i=0; i<linha; i++) {
        for(j=0; Matriz[i][j]!='\0'; j++) {
            printf(" %c ", Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("------------------------------\n");
    printf("    Matriz Organizada\n");
    printf("------------------------------\n");
    for (i=0; i<linha; i++) {
        for(j=0; Matriz_organizada[i][j]!='\0'; j++) {
            printf(" %c ", Matriz_organizada[i][j]);
        }
        printf("\n");
    }

    return 0;
}
