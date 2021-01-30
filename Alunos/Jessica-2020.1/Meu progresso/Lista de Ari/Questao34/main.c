#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/*34.	Elabore um programa que, dado 2 vetores inteiros de 20 posições, efetue as respectivas
operações indicadas por um terceiro vetor de caracteres de 20 posições também fornecido pelo
usuário, contendo as quatro operações aritméticas em qualquer combinação, armazenando os
resultados num quarto vetor.*/

int main()
{
    int ReadNumbers(void);
    int vet_A[19], vet_B[19];
    char operador[20];
    int resultado[19], resto[19];
    int i,j,k;

    /*Entrando com os dois vetores*/
    printf("Entre com os valores do primeiro vetor:\n");
    for(i=0; i<20; i++){
        printf("vet_A [%i]:",i+1);
        vet_A[i] = ReadNumbers();
        printf("\n");
    }
    printf("\n\n");
    printf("Entre com os valores do segundo vetor:\n");
    for(j=0; j<20 ;j++){
        printf("vet_B [%i]:",j+1);
        vet_B[j] = ReadNumbers();
        printf("\n");
    }
    printf("\n\n");

    /*Entrando com a string de operadores*/
    printf("\nEntre com os operadores:\n");
    printf("+ Adicao\n- Subtracao\n/Divisao\nx Multiplicacao\n\n");

    for(i=0; i<20; i++){
        printf("operador [%i]:",i+1);
        scanf(" %c", &operador[i]); //espaco entre " e % para desconsiderar o ENTER recebido anteriormente ou fflush(stdin)
        while(operador[i]!='+' && operador[i]!='-' && operador[i]!='/' && operador[i]!='x'){
            printf("Operador invalido, insira novamente:\noperador [%i]:",i+1);
            scanf(" %c", &operador[i]);
        }
    }
    operador[i]='\0';
    system("CLS"); //Limpa a tela do usuario completamente

    /* Efetuar os Calculos*/
    for(i=0; i<20; i++){ //Efetua as operações pedidas
        if(operador[i]=='+'){ //Adição
            resultado[i]= vet_A[i] + vet_B[i];
            resto[i] = 0;
        } else if(operador[i]=='-'){ //Subtração
            resultado[i]= vet_A[i] - vet_B[i];
            resto[i] = 0;
        }else if(operador[i]=='x'){ //Multiplicação
            resultado[i]= vet_A[i] * vet_B[i];
            resto[i] = 0;
        }else if(operador[i]=='/'){ //Divisão
            resultado[i]= vet_A[i] / vet_B[i];
            resto[i] = vet_A[i] % vet_B[i];
        }
    }

    /*Exibir calculos*/
    for(i=0;i<20; i++){ //Exibe todas as conta realizadas
        printf("%i   %c    %i  =  %i      %i \n", vet_A[i], operador[i], vet_B[i], resultado[i], resto[i]);
    }

	return 0;
}

int ReadNumbers(void){
    char ch; //Capta cada caractere digitado
    char digitado[50]; //Junta todos os digitos digitados
    int i=0;
    int numero; //Recebe o numero final

    do{
            fflush(stdin); //Limpa o buffer
            ch = getch( ); //Captura o caractere digitado pelo usuario;

            if (isdigit(ch) != 0) { // Se for um numero
                digitado[i]=ch; //É direcionado para string de numeros
                i++; //Passqa para proxima posição
                printf("%c", ch); //Exibe o numero digitado na tela

            } else if (ch == 8 && i) { //Se o Blackspace for digitado e tiver caractere para apagar
                digitado[i] = '\0';
                i--;
                printf("\b \b"); //Apaga o caractere anterior
            }
        } while(ch != 13); // Quando o ENTER for digitado, termina o loop

        digitado[i] = '\0'; //Finaliza a string finalmente
        numero = atoi(digitado); // Converte a string em inteiros e passa para variavel numero

        return numero; // Retorna o numero inteiro
}
