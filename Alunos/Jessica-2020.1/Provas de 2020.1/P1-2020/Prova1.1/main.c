//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 1 - Achar palavras palíndromos nas linhas da matriz e imprimir a posição inicial
//     (linha x coluna) e posição final (linha x coluna), e a palavra achada.
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main()
{
    char Matriz[MAX][MAX], Matriz_aux[MAX][MAX];
    int linha, coluna;
    char Mat_Palindromos[MAX][MAX]; //Para armazenar os palindromos achados
    int posicoes[MAX][4]; //Para armazenar as posições dos palindromos achados
    int i,j,k,z,t,m,n;
    int j_inicio=0, j_fim=0, i_inicio, confirma=0;

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
            scanf("%c", &Matriz[i][j]); //Recebe caracteres do usuario

            system("CLS"); //Limpa a tela para exibir tudo novamente com o caractere recebido acima

            printf("-------------------------------\n");
            printf("      Recebendo a Matriz \n");
            printf("-------------------------------\n\n");

            for (m=0; m<linha; m++) { // Exibe a matriz com o caractere recebido nessa interação
                for(n=0; Matriz[m][n]!='\0'; n++) {
                    printf(" %c ", Matriz[m][n]); //Exibe cada caractere
                }
                printf("\n"); //Pula a linha
            }
            printf("\n\n");
        }
    }
    system("PAUSE"); //Pausa o sistema
    system("CLS"); //Limpa a tela

    /*PASSANDO A MATRIZ PARA OUTRA AUXILIAR*/
    for(i=0; i<linha; i++){ // Ajudará na identificação dos palindromos
        for(j=0; Matriz[i][j]!='\0'; j++){
            Matriz_aux[i][j]=Matriz[i][j];
        }
    }

    for (i=0; i<linha; i++){ //Finaliza a matriz auxiliar com \0
        Matriz_aux[i][coluna] = '\0';
	}

	/*TRANSFORMANDO TODAS AS MAIUSCULAS DA MATRIZ AUXILIAR EM MINUSCULAS*/
	for (i=0; i<linha; i++){
        for(j=0; Matriz_aux[i][j]!='\0'; j++){
            if(Matriz_aux[i][j]>='A' && Matriz_aux[i][j]<='Z'){
                Matriz_aux[i][j]=tolower(Matriz_aux[i][j]);
            }
        }
	}

	/*PROCURANDO PALINDROMOS NAS LINHAS DA MATRIZ AUXILIAR*/
	z=0;
	t=0;
	for(i=0; i<linha; i++) { //Laço principal, controla a mudança das linhas da matriz

        for(j=0; Matriz_aux[i][j]!='\0'; j++) { //Define o ponto inicial da verificação do palindromo (percorre toda linha)
            for(k=j+1; Matriz_aux[i][k]!='\0'; k++){    //Define o ponto final da verificação do palindromo (percorre toda linha)

                i_inicio=i; //Guarda a posição da linha de um possivel palindromo
                j_inicio=j; //Guarda a posição inicial da coluna de um possivel palindromo
                j_fim=k; //Guarda a posição final da coluna de um possivel palindromo

                for(m=j,n=k;  m<n;  m++,n--) { //Verifica se um palindromo é achado
                    if (Matriz_aux[i][m]==Matriz_aux[i][n]){
                        confirma=1;
                    }else{
                        confirma=0;
                        break;
                    }
                }

                if(confirma && isalpha(Matriz_aux[i_inicio][j_inicio]) && isalpha(Matriz_aux[i_inicio][j_fim])){ //Confirma se existe um palindromo na verificacao, evita ocorrencias com numeros e caracteres especiais
                    posicoes[z][0]=i_inicio; //Prenche as posições dos palindromos achados
                    posicoes[z][1]=j_inicio;
                    posicoes[z][2]=i_inicio;
                    posicoes[z][3]=j_fim;

                    for(m=j_inicio; m<=j_fim; m++){ ////Prenche um vetor de strings auxiliar com os palindromos achados
                       Mat_Palindromos[z][t++] = Matriz[i_inicio][m];
                    }
                    Mat_Palindromos[z][t]='\0';
                    t=0;
                    z++; //Vai contar quantos palindromos são achados -> Delimitador de tamanho
                }
            }
        }
	}

	/*EXIBINDO RESULTADOS*/

	if (z>0){ //Se houver pelo menos um palindromo achado
        printf ("------Palindromos Achados------\n\n"); //Exibe vetor de posições e vetor de strings contendo os palindromos achados
        for (i=0; i<z; i++){
            printf("%s (%i,%i) - (%i,%i) \n", Mat_Palindromos[i], posicoes[i][0], posicoes[i][1], posicoes[i][2], posicoes[i][3]);
        }
        printf("\n\n");

        /*EXIBINDO A MATRIZ*/
        printf("------------------------------\n");
        printf("\t   Matriz \n");
        printf("------------------------------\n\n");

        for (i=0; i<linha; i++) { // Exibe a matriz
            for(j=0; Matriz[i][j]!='\0'; j++) {
                printf(" %c ", Matriz[i][j]); //Exibe cada caractere
            }
            printf("\n"); //Pula a linha
        }
        printf("\n\n");
	} else{
        printf("N%co fora encontrada nenhuma ocorr%cncia de pal%cndromo nas linhas da matriz inserida.\n\n", 198, 136, 161);
	}
    return 0;
}

