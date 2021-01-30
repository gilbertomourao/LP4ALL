//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 1
//     ANO: 2020

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/* Funções Usadas*/
    void ReadDimension (int *D);
    void AlocaString (char **str, int *D);
    void DesalocaString (char *str);
    void RecebeString(char *str); // Recebe string
    void ImprimirStrings(char *str1, char *str2); // Imprime as strings

    bool Igual_C (char *s); // Verifica se o primeiro caracter de uma string é igual ao ultimo caracter dela
    void Procurar(char*str1, char *str2, int *casos); // Procura ocorrencias da string2 na string1
    void Colocar (char*s1, char *s2, bool *achou, int p); // Preenche a string final

int main()
{
    char *string1, *string2;
    int tam1, tam2, eventos=0;

    printf("------ RECEBENDO STRING 1 ------");
    ReadDimension(&tam1);
    AlocaString(&string1, &tam1);
    RecebeString(string1);

    printf("------ RECEBENDO STRING 2 ------");
    ReadDimension(&tam2);
    AlocaString(&string2, &tam2);
    RecebeString(string2);

    system("pause");
    system("cls");

    if ( strlen(string2) > strlen(string1) ) {
        ImprimirStrings (string1, string2);
        printf("\n\nSitua%c%co inv%clida, pois a string2 %c maior que a string1\n\n", 135, 198, 160, 130);
    } else {
        ImprimirStrings (string1, string2);
        Procurar(string1,string2,&eventos); // Procura e substitui
        if (eventos>0) { // Se houver uma ocorrencia ou mais de String2 em String1
            printf("\n\n---------- RESPOSTA ----------");
            printf("\n%s\n\n", string1);
        } else // Caso não haja nenhuma ocorrenncia
            printf("\n\nN%co houve nenhuma ocorr%cncia da string2 na string1\n\n", 198,136);
    }
    DesalocaString(string1);
    DesalocaString(string2);

    return 0;
}

/*LENDO AS DIMENSÕES DAS STRINGS*/
void ReadDimension (int *D) {
    printf("\nDigite a dimens%co da string:  ", 198);
    scanf("%i", D);
    while(*D<=0) { // Caso a dimenção recebida esteja fora dos parametros
        printf("\nDimens%co inv%clida!\nInsira novamente:  ", 198, 160);
        scanf(" %i", D);
    }
}

/*ALOCA ESPAÇO DE MEMÓRIA PARA DA STRING*/
void AlocaString (char **str, int *D) {
    *str = (char *) malloc((*D)  * sizeof(char));
     if (str==NULL) {
        printf ("Erro: Em fun%cão 'AlocaString'.\nAloca%c%co de mem%cria falhou.\n", 135,135, 198, 162);
        exit(0);
    }
}

/*DESALOCA O ESPAÇO DE MEMÓRIA DA STRING*/
void DesalocaString (char *str) {
    free(str);
}

/*RECEBE AS STRINGS*/
void RecebeString (char *str) {
    printf("Insira a string: ");
    fflush(stdin);
    gets(str);
    putchar('\n');
}

/*IMPRIME AS STRINGS*/
void ImprimirStrings (char *str1, char *str2) {
    printf("String-1: %s\n", str1);
    printf("String-2: %s", str2);
}

/*PROCURA AS OCORRENCIAS DE STRING2 EM STRING1 E CHAMA FUNÇÃO DE SUBSTITUIÇÃO*/
void Procurar (char*str1, char *str2, int *casos) {
    int i, j, a, alarme=0;
    bool confirma; // Diz se String2 ocorre completamente em String1

        for (i=0; *(str1+i); i++) { // Percorre toda String1 - laço principal
            confirma=false; // String2 ainda não ocorreu
            if ( tolower(*(str1+i)) == tolower(*str2) ) { // Primeiro caractere igual nas duas strings
                confirma=true; // Verifica se String2 realmente ocorre em String1
                for (a=i, j=0; *(str1+a) && *(str2+j); a++, j++) // Vai confirmar a existência da String2 na String1
                    if ( tolower(*(str1+a)) != tolower(*(str2+j)) ) { // Quando ocorre a primeira desigualadade
                        confirma=false; // String2 não ocorreu
                        break; // Sai do laço
                    }
                if (confirma && !(*(str2+j))) { // Se String2 for achada em String1
                   ++(*casos); // Soma as ocorrencias de String2 em String1
                    Colocar(str1,str2,&confirma,i); // Passa string2 invertida para string1
                    if (Igual_C(str2)) { // Coloca a variavel i em posição de encontrar outras ocorrencias de String2
                        i = a - 2;
                        alarme=1; // Proteje contra casos em que anABananA
                    } else
                        i = a - 1;
                } else {
                    if(alarme && *(str2+j) ) { // Se ñ achou String2 (com primeiro e ultimo caracter iguais) e na última iteração ocorreu
                        if (*(str1+i+1) && *(str1+i+1) !=*str2) {  //Se proxima posição diferente do delimitador da String1 e diferente do primeiro caracter da String2
                            ++i; // Passa posição pra próxima
                            Colocar(str1,str2,&confirma,i); // Preenche com asterisco
                        } // Se proxima posição for delimitador da String1, não faz nada e espera fim do laço
                        alarme=0;
                    } else
                        Colocar(str1,str2,&confirma,i); // Preenche a posição com asteriscos
                }
            } else
                Colocar(str1,str2,&confirma,i); // Preenche a posição com asteriscos
        }
}

/*PREENCHE A STRIN1 CONFORME É PEDIDO - ASTERISCO - STRING2 INVERTIDA*/
void Colocar (char*s1, char *s2, bool *achou, int p) { // String1-String2-Ocorrencia(ou não) de String2 em String1-posição verificada
    int i;
    if (*achou) { // Se houver ocorrencia de String2 em String1
        strrev(s2); // Inverte String2 para atribuição
        for(i=0; *(s2+i); i++){ // Atribui string invertida
            *(s1+p) =*(s2+i);
            ++p;
        }
        strrev(s2); // Inverte String2 novamente para voltar ao estado inicial
    }
    else // Se não houver ocorrencia
        *(s1+p)='*'; // Coloca asterico
}

/*VERIFICA SE PRIMEIRO CARACTER É IGUAL AO ULTIMO NUMA STRING*/
bool Igual_C (char *s) {
    if (*s == *(s+(strlen(s)-1))) // Compara o primeiro caracter com o ultimo caracter de uma string
        return true;
    return false;
}
