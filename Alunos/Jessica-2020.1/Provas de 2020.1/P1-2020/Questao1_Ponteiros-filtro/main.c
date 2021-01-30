//     PROGRAMA: Questão 1 - Achar palavras palíndromos nas linhas da matriz e imprimir a posição inicial

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

/*Funções Usadas*/
void ReadDimensions (int *L, int *C);
void RecebeMatriz(char mat[][MAX], int *L, int *C);
void ExibirMatriz (char mat[][MAX], int *L, int *C);
void VarreLinhas(char mat[][MAX], int *L, int *C, int *casos, int vet[][4], char pal[][MAX]);

void FiltroSubPalindromos(char mat[][MAX], int vet[MAX][4], int *l,  int position[][4], char palindromes[][MAX], int *occurrences);
int MaiorString(char mat[][MAX], int *l);
int TamIguaisString(char mat[][MAX], int *l);
int OcorrenciaDeStringEmSring (char string1[], char string2[]);

int main()
{
    char Matriz[MAX][MAX];
    int linha, coluna, eventos=0;
    int posicoes[MAX][4];
    char palindromos[MAX][MAX];

    ReadDimensions(&linha, &coluna);

    RecebeMatriz(Matriz, &linha, &coluna);

    VarreLinhas(Matriz, &linha, &coluna, &eventos,posicoes, palindromos);

    ExibirMatriz(Matriz, &linha, &coluna);

    printf("\nQuantidade de palindromos: %i\n", eventos);
    for (int i; i<eventos; i++)
        printf("%s   -   (%i,%i) - (%i,%i) \n", palindromos[i], posicoes[i][0], posicoes[i][1], posicoes[i][2], posicoes[i][3]); // Imprime as posições dos palindromos achados

    return 0;
}

/*LENDO AS DIMENSÕES DA MATRIZ*/
void ReadDimensions (int *L, int *C) {
    printf("********* Bem Vindo ao Ca%ca-Pal%cndromo *******\n", 135, 161);
    printf("\nDigite a dimens%co da linha, por favor:  ", 198);
    scanf("%i", &*L);
    while(*L<=0 || *L>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de linha inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*L);
    }
    printf("\nDigite a dimens%co da coluna, por favor:  ", 198);
    scanf(" %i", &*C);
    while(*C<=0 || *C>MAX) { //Caso a dimenção recebida esteja fora dos paramentros
        printf("\nDimens%co de coluna inv%clida, insira novamente:  ", 198, 160);
        scanf(" %i", &*C);
    }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*RECEBE A MATRIZ DO USUARIO*/
void RecebeMatriz (char mat[][MAX], int *L, int *C) { // Matriz recebida - numero de linha - numero de coluna
    int i,j;

	for (i=0; i<*L; i++) // Preenhe toda matriz com asteriscos
        for(j=0; j<*C; j++)
            mat[i][j] ='*';

    printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
	printf("\nPreencha a matriz com letras:", 163);
    ExibirMatriz(mat,L,C); // Exibe a matriz de asteriscos

	for(i=0; i<*L; i++)
        for(j=0; j<*C; j++) {
            printf("\nPosi%c%co [%i][%i]: ", 135,198, i, j); //Informa a posição a ser recebida a letra
            fflush(stdin);
            scanf(" %c", &mat[i][j]); //Chama a função que recebe apenas numeros inteiros positivos do usuario
            system("CLS"); //Limpa a tela para exibir tudo com o numero recebido acima

            printf("*********Bem Vindo ao Ca%ca-Palavras*******\n", 135);
            printf("\nPreencha os espacos com n%cmeros inteiros:", 163);
            ExibirMatriz(mat,L,C); // Exibe a matriz com o caractere recebido nessa interação
        }
    printf("\n\n");
    system("PAUSE"); //Pausa
    system("CLS"); //Limpa a tela
}

/*EXIBE A MATRIZ PARA O USUSARIO*/
void ExibirMatriz (char mat[][MAX], int *L, int *C) {
    putchar('\n');
	for (int i=0; i<*L; i++) {
		printf("-");
		for (int k=0; k<*C; k++)
			printf("--");
        printf("\n");
		for (int j=0; j<=*C; j++)
			(j==*C) ? printf("|") : printf("|%c", mat[i][j]);
		printf("\n");
	}
	printf("-");
	for (int k=0; k<*C; k++)
        printf("--");
    putchar('\n');
}

/*CAÇA PALINDROMO NAS LINHAS*/
void VarreLinhas(char mat[][MAX], int *L, int *C, int *casos, int vet[][4], char pal[][MAX]) {
    int i, j, k, m, n, confirma;
    int p[MAX][4];
    char aux[MAX][MAX];
    int a,b;

	for(i=0; i<*L; i++) { // Laço principal, controla a mudança das linhas da matriz
        a=0;
        b=0;
        for(j=0; j<*C; j++) // j define o ponto inicial da verificação do possivel palindromo (percorre toda linha)
            for(k=j+1; k<*C; k++) { // k define o ponto final da verificação do possivel palindromo (percorre toda linha)
                confirma=1;
                for(m=j,n=k;  m<n;  m++,n--) // Verifica se um palindromo é achado
                    if ( tolower(mat[i][m]) != tolower(mat[i][n]) ) { // Ignora case sensitive
                        confirma=0;
                        break;
                    }
                if (confirma && isalpha(mat[i][j]) && isalpha(mat[i][k])) { // Confirma se existe um palindromo na verificacao, evita ocorrencias com numeros e caracteres especiais
                    for (m=j+1; m<k; m++) // Verifica se todos os membros do palindromo são letras
                        if ( !(isalpha(mat[i][m])) ) {
                            confirma=0;
                            break;
                        }
                    if (confirma) {
                        for(m=j; m<=k; m++) { // Armazena todos os palindromos achados na linha
                            aux[a][b++]=mat[i][m];
                        }
                        aux[a][b]='\0';

                       p[a][0]=i;
                       p[a][1]=j;
                       p[a][2]=i;
                       p[a][3]=k;

                       a++;
                       b=0;
                    }
                }
            }
        for (b=0; b<a; b++)
            printf("%s   -   (%i,%i) - (%i,%i) \n", aux[b], p[b][0], p[b][1], p[b][2], p[b][3]); // Imprime as posições dos palindromos achados*/
            FiltroSubPalindromos(aux, p, &a, vet,pal, casos);
	}
 }

void FiltroSubPalindromos(char mat[][MAX], int vet[MAX][4], int *l,  int position[][4], char palindromes[][MAX], int *occurrences) {
    int i=0, k;
    if (*l==1) { // Se a linha tiver apenas 1 palindromo
        strcpy(palindromes[*occurrences],mat[0]);
        position[*occurrences][0]= vet[0][0];
        position[*occurrences][1]= vet[0][1];
        position[*occurrences][2]= vet[0][2];
        position[*occurrences][3]= vet[0][3];
        ++(*occurrences);

    } else if (*l>1) {  // Se a linha tiver mais de 1 palindromo
        if (TamIguaisString(mat, l)) // Se os palindromos da linha tiverem o mesmo tamanho
            for(i=0; i<*l; i++) {
                strcpy(palindromes[*occurrences],mat[i]);
                position[*occurrences][0]= vet[i][0];
                position[*occurrences][1]= vet[i][1];
                position[*occurrences][2]= vet[i][2];
                position[*occurrences][3]= vet[i][3];
                ++(*occurrences);
            }
        else {
            k=MaiorString(mat, l);  // Direciona o maior palindromo para matriz final

            strcpy(palindromes[*occurrences],mat[k]);
            position[*occurrences][0]= vet[k][0];
            position[*occurrences][1]= vet[k][1];
            position[*occurrences][2]= vet[k][2];
            position[*occurrences][3]= vet[k][3];
            ++(*occurrences);

            for (i=0; i<*l; i++)
                if (i!=k)
                    if (OcorrenciaDeStringEmSring(mat[k],mat[i])==0) { // Direciona os palindromos q não estao contidos no maior palindromo para matriz final
                        strcpy(palindromes[*occurrences],mat[i]);
                        position[*occurrences][0]= vet[i][0];
                        position[*occurrences][1]= vet[i][1];
                        position[*occurrences][2]= vet[i][2];
                        position[*occurrences][3]= vet[i][3];
                        ++(*occurrences);
                    }
        }
    }
}

int MaiorString(char mat[][MAX], int *l) {
    int i,j;
    int maior;
    int p_maior;
    maior = strlen(mat[0]); // Inicializa com a primeira posição
    p_maior=0;
    for (i=1; i<*l; i++) //Verifica o membro de maior tamanho
        if (maior<strlen(mat[i])) {
            maior = strlen(mat[i]); // Inicializa com a primeira posição
            p_maior=i;
        }
    return p_maior; // Retorna a posição de linha do maior membro
 }

int TamIguaisString(char mat[][MAX], int *l) {
    int i,tam;
    tam = strlen(mat[0]); // Inicializa com a primeira posição
    for (i=1; i<*l; i++) // Verifica se tem o mesmo tamanho todos
        if (tam!=strlen(mat[i]))
            return 0;
    return 1;
}

int OcorrenciaDeStringEmSring (char string1[], char string2[]) {
    int i, j, i_aux, confirma, ocorrencia=0;
    for(i=0; string1[i]!='\0'; i++) // Percorre toda string frase - laço principal
        if(string1[i]== string2[0]) { // Indica quando o primeiro caractere igual da palavra é encontrao
            confirma=1; // Diz se a uma str está contida na outra
            for(j=0, i_aux=i; string2[j]!='\0' && string1[i_aux]!='\0'; j++, i_aux++) // Confirma a str contida na outra
                if(string2[j]!=string1[i_aux]) {
                    confirma=0;
                    break;
                }
            if(confirma && string2[j]=='\0') //Se palavra for achada na frase
                ++ocorrencia;
        }
    return ocorrencia; // Devolve a quantidade de ocorrencias
}


