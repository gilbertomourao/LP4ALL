//     UFMA-ENGENHARIA ELÉTRICA
//     ALUNA: Jéssica Sabrina de Jesus Sousa
//     PROFESSOR: Ari
//     PROGRAMA: Questão 1
//     ANO:2020

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

/* Funções Usadas*/
void ReceberStrings(char *str1, char *str2); // Recebe as strings
void ImprimirStrings(char *str1, char *str2); //Imprime as strings
bool Igual_Caracter (char *s); // Verifica se o primeiro caracter de uma string é igual ao ultimo caracter dela
void String_Inverte (char *s); // Inverte uma string
void Procurar(char*str1, char *str2, int *casos); // Procura ocorrencias da string2 na string1
void Colocar (char*str1, char *str2, bool *achou, int p); // Preenche a string final

int main()
{
    char string1[MAX], string2[MAX];
    int eventos=0;

    ReceberStrings(string1, string2);

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
    return 0;
}

/*RECEBE AS STRINGS*/
void ReceberStrings(char *str1, char *str2) {
    printf("Insira uma string: ");
    fflush(stdin);
    gets(str1);
    putchar('\n');
    printf("Insira outra string: ");
    fflush(stdin);
    gets(str2);
    putchar('\n');
    system("Pause");
    system("cls");
}

/*IMPRIME AS STRINGS*/
void ImprimirStrings(char *str1, char *str2) {
    printf("String-1: %s\n", str1);
    printf("String-2: %s", str2);
}

/*PROCURA AS OCORRENCIAS DE STRING2 EM STRING1 E CHAMA FUNÇÃO DE SUBSTITUIÇÃO*/
void Procurar (char*str1, char *str2, int *casos) {
    int i, j, a, alarme=0;
    bool confirma; // Diz se String2 ocorre completamente em String1

        for (i=0; str1[i]!='\0'; i++) { // Percorre toda String1 - laço principal
            confirma=false; // String2 ainda não ocorreu
            if ( tolower(str1[i]) == tolower(str2[0]) ) { // Primeiro caractere igual nas duas strings
                confirma=true; // Verifica se String2 realmente ocorre em String1
                for (j=0, a=i; str1[a]!='\0' && str2[j]!='\0'; j++, a++) // Vai confirmar a existência da String2 na String1
                    if ( tolower(str1[a]) != tolower(str2[j]) ) { // Quando ocorre a primeira desigualadade
                        confirma=false; // String2 não ocorreu
                        break; // Sai do laço
                    }
                if (confirma && str2[j]=='\0') { // Se String2 for achada em String1
                   ++(*casos); // Soma as ocorrencias de String2 em String1
                    Colocar(str1,str2,&confirma,i); // Passa string2 invertida para string1
                    if (Igual_Caracter(str2)) { // Coloca a variavel i em posição de encontrar outras ocorrencias de String2
                        i = a - 2;
                        alarme=1; // Proteje contra casos em que anABananA
                    } else
                        i = a - 1;
                } else {
                    if(alarme && (str2[j]!='\0') ) { // Se ñ achou String2 (com primeiro e ultimo caracter iguais) e na última iteração ocorreu
                        if (str1[i+1]!='\0' && str1[i+1]!=str2[0]) {  //Se proxima posição diferente do delimitador da String1 e diferente do primeiro caracter da String2
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
    int i, j;
    if (*achou) { // Se houver ocorrencia de String2 em String1
        String_Inverte(s2); //Inverte String2 para atribuição
        for(i=0; s2[i]!='\0'; i++)  // Atribui string invertida
            s1[p++]=s2[i];
        String_Inverte(s2); // Inverte String2 novamente para voltar ao estado inicial
    }
    else // Se não houver ocorrencia
        s1[p]='*'; // Coloca asterico
}

/*VERIFICA SE PRIMEIRO CARACTER É IGUAL AO ULTIMO NUMA STRING*/
bool Igual_Caracter (char *s) {
    if (s[0]==s[strlen(s)-1]) // Compara o primeiro caracter com o ultimo caracter de uma string
        return true;
    return false;
}

/*RETORNA UMA STRING INVERTIDA*/
void String_Inverte (char *s) {
	int i,j;
	char aux;
	for(i=0,j=strlen(s)-1; i<j ;i++,j--) { // Inverte cada caracter da string
		aux=s[i];
		s[i]=s[j];
		s[j]=aux;
	}
}
