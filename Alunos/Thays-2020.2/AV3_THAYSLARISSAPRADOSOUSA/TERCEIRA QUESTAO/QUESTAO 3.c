/*  TERCEIRA AVALIA��O DE LP
    ALUNA: THAYS LARISSA PRADO SOUSA
    QUEST�O 3 */

/* BIBLIOTECAS */
#include <stdio.h>
#include <ctype.h>
/* MACROS */
#define MAX 200
#define LETRA(ch) ((ch>= 'A' && ch <= 'Z') ||(ch >= 'a' && ch <= 'z')) // MACRO CRIADA PARA VERIFICAR SE � LETRA

// PROTOTIPOS
void Ler_Str(char[]); // FUN��O PARA LER AS STRINGS INSERIDAS PELO USUARIO
void Ler_Elem(char[]); // FUN��O PARA LER O ELEMENTO
void Procura_Subs(char [], char[], char[], char[]); // FUN��O PARA PROCURAR E SUBSTITUIR
void Imprime_string(char[]); // FUN��O PARA IMPRIMIR RESULTADO

void main()
{
    char str1[MAX],str2[MAX]; // STRINGS INSERIDAS PELO USUARIO
    char elem[MAX]; // ELEMENTO INSERIDO PELO USUARIO
    char str_aux[MAX]; // STRING AUX PARA CASE SENSITIVE
    int i,j; // ITERADORES
    char str_resp[MAX]; // STRING RESPOSTA COM SUBSTITUI�AO FEITA

    printf("Informe a frase:");
    Ler_Str(str1);
    printf("Informe a palavra:");
    Ler_Str(str2);
    Ler_Elem(elem);

// TRABALHANDO O CASE SENSITIVE USANDO UMA STRING AUXILIAR
    for (i=0, j=0; str2[i]!= '\0'; i++) // VARRE A STRING 2 PARA OBTER A STRING AUX
    {
        if (LETRA(str2[i])) // VERIFICA SE � UMA LETRA USANDO A MACRO
        {
             str_aux[j] = tolower(str2[i]); // STRING AUXILIAR RECEBE A PALAVRA TODA MINUSCULA
             j++;
        }

    }
    str_aux[j]='\0'; // FINALIZO A STRING AUXILIAR

    Procura_Subs(str1, str_aux, elem, str_resp);
    Imprime_string(str_resp);

}

void Ler_Str(char string[]) // LER FRASE E PALAVRA
{
    printf(" ");
    fflush(stdin);
    gets(string);
}

void Ler_Elem(char elemento[]) // LER ELEMENTO
{
    printf("Informe o elemento que ira substituir a palavra:");
    fflush(stdin);
    gets(elemento);
}

void Procura_Subs(char str1[], char str_aux[], char elem[], char str_resp[]) // PROCURA A PALAVRA NA FRASE E SUBSTITUI PELO ELEMENTO
{
    int i, j, k; // ITERADORES UTILIZADOS PARA PROCURAR OCORRENCIAS
    int posicoes[MAX][2]; // MATRIZ QUE ARMAZENA AS POSI��ES 2 COLUNAS PQ ARMAZENA i E j-1 (INICIO E FIM)
    int it_pos = 0; // ITERADOR PARA POSICAO DA PALAVRA
    int it = 0, r = 0; // ITERADORES UTILIZADOS PARA SUBSTITUI�AO

// PRIMEIRO, EU PROCURO A PALAVRA DENTRO DA FRASE E ARMAZENO A POSI�AO DA PALAVRA ENCONTRADA EM UMA MATRIZ POSI�OES
    for (i=0; str1[i]!= '\0'; i++) // VARRE A STRING PRINCIPAL PARA CHECAR AS OCORRENCIAS
    {
        if (LETRA(str1[i])) // VERIFICA SE � LETRA USANDO A MACRO PARA IGNORAR ESPA�OS E OUTROS CARACTERES
        {
            if (tolower(str1[i]) == str_aux[0]) // VERIFICA SE O CARACTER NA POSI��O i DA STRING 1 � IGUAL AO PRIMEIRO CARACTER DA STRING AUXILIAR
            {
                for (j = i+1, k = 1; str1[j] != '\0' && str_aux[k] != '\0'; j++, k++) // COMPARA AS OUTRAS LETRAS DA STRING 1 COM AS LETRAS DA STRING AUXILIAR COME�A COM i+1 PORQUE � A POSI��O SEGUINTE
                {
                    if (LETRA(str1[j]))
                    {
                        if (tolower(str1[j]) != str_aux[k])
                        {
                            break; // SE O CARACTER DA STRING 1 NA POSI��O j FOR DIFERENTE DA POSI��O k NA STRING AUXILIAR, SIGNIFICA QUE A SEMELHAN�A ACABOU E EU SAIO DO LA�O
                        }
                    }
                    else
                        k--; // PARA O CASO DO CARACTER NAO SER UMA LETRA NAO PULAR UMA POSI��O
                }

                if (str_aux[k] == '\0') // VERIFICO SE TODA A STRING AUXILIAR FOI VARRIDA
                {
                    posicoes[it_pos][0] = i; // COM A STRING VARRIDA, ARMAZENO AS POSI��ES DE INICIO E FIM DA STRING EM UMA MATRIZ
                    posicoes[it_pos][1] = j-1; // j-1 DEVIDO AO INCREMENTO j++ DO FOR
                    it_pos++; // INCREMENTO A LINHA DA MATRIZ
                }

            }
        }
    }

// APOS ENCONTRAR, FA�O A SUBSTITUI�AO
    for (i = 0; str1[i] != '\0' && r < MAX-1; i++) // LA�O PARA VARRER A STRING PRINCIPAL
    {
        if (i == posicoes[it][0])// OBSERVA SE O ITERADOR i � IGUAL A POSI��O DE INICIO DA STRING 2
        {
            for (j = i; elem[j-i] != '\0' && r < MAX-1; j++) // SE FOR, PERCORRO A STRING 3 E VOU COLOCANDO OS CARACTERES NA STRING RESPOSTA
            {
                str_resp[r] = elem[j-i];
                r++;
            }

            it++; // INCREMENTA PARA SABER QUE ACHOU A PALAVRA
        }
        else
        {
            if (it == 0) // NAO ENCONTROU A PALAVRA
            {
                str_resp[r] = str1[i]; // STRING RESPOSTA RECEBE A STRING ORIGINAL MESMO
                r++;
            } else
            {
                if (i > posicoes[it-1][1]) // OBSERVA SE O ITERADOR i � MAIOR QUE A POSI��O DO FIM DA STRING 2
                {
                    str_resp[r] = str1[i];
                    r++;
                }

            }
        }
    }

    str_resp[r] = '\0'; //  FINALIZANDO A STRING RESPOSTA

}

void Imprime_string(char str_resp[]) // IMPRIMIR O RESULTADO
{
    printf("String resposta: %s\n", str_resp);
}
