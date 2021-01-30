#include <stdio.h>
#include <stdlib.h>

/*
28.	Fa�a um programa que dado um nome completo, retorne a abreviatura deste nome.
N�o se devem abreviar as preposi��es como: do, de, etc. A abreviatura deve vir separada
por pontos. Ex: Paulo Jose de Almeida Prado. Abreviatura: P.J.A.P.*/
#define MAX 100

int main()
{
    char nome[MAX];
    char nome_aux[MAX];
    char abreviatura[MAX];
    char preposicoes[6][6] = {" DA "," DE "," DO "," DAS "," DOS ", " E "};
    int casos;
    int tam=0;
    int i,j,k=0;
    int aux;
    int confirma=0;

    printf("Insira o nome:\n"); // Recebe o nome a ser abreviado
    gets(nome);

     /*Desconsiderando Case-sensitive*/
     for(j=0;nome[j]!='\0';++j){ //Transforma todas as letras em maiusculas
          if (nome[j] >= 'a' &&  nome[j] <= 'z')
             nome[j] = nome[j] - 'a' + 'A';
     }

     printf("\nNome todo maiusculo: %s\n", nome);

    /* Retirando Preposi��es*/
    for(casos=0; casos<6; casos++){ // La�o principal - Vai verificar e retirar todas as preposi��es
         tam=0;
         while(preposicoes[casos][tam]!='\0') ++tam; //Mede o tamanho da preposi��o procurada na volta

         for (i=0; nome[i]!='\0';i++) { // Corre o nome completo

            if (nome[i]==preposicoes[casos][0]){ //Indentifica uma provavel preposi��o
                confirma=1;
                for(j=0, aux=i; preposicoes[casos][j] != '\0' && nome[aux] !='\0' ; j++, aux++){
                    if(preposicoes[casos][j] != nome[aux]) { //Confirma ou n�o a existencia da preposi��o
                        confirma=0;
                        break ;
                    }
                }
                if(confirma && preposicoes[casos][j] == '\0'){ // Se a preposi��o estiver no nome
                    i=i+(tam-2); //Pula a preposi��o para exclui-la
                    confirma=0;
                } else { //Se a preposi��o n�o estiver no nome
                    nome_aux[k++]=nome[i];
                }
            } else { //Caso n�o ache a peposi��o no nome
                nome_aux[k++]=nome[i];
            }
        }
        nome_aux[k]='\0'; //Finaliza a string auxilar
        k=0;

        for(i=0; nome_aux[i]!='\0'; i++){ //Passa a string auxilar de volta pro nome pra procurar outra preposicao
            nome[i]=nome_aux[i];
        }
        nome[i]='\0';
    }

    printf("\nNome sem preposi��es: %s\n", nome);

    /* Realizando a abrevia��o*/
    abreviatura[0]=nome[0]; //Realiza a abrevia��o do primeiro nome
    abreviatura[1]='.';
    i=2; //Situa onde devemos continuar abreviando depois do primeiro nome;
    for(j=0; nome[j] != '\0'; j++){
        if(nome[j]==' ' && (nome[j+1]>= 'A' && nome[j+1]<='Z')){
            abreviatura[i]=nome[j+1]; //Realiza a abrevia��o dos demais nomes
            abreviatura[i+1]='.';
            i=i+2;
        }
    }

    printf("\nNome abreviado: %s\n", abreviatura);

    return 0;
}
