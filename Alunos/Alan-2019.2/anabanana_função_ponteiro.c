#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void anabanana(char *string, char *procurada);

int main(void) {
  char string[MAX];
  char procurada[MAX];

  printf("Digite sua string:\n");
  gets(string);

  printf("\nDigite a string que deseja procurar:\n");
  gets(procurada);

  anabanana(string, procurada);

}

void anabanana(char *string, char *procurada)
{
  	char *p;
  	char *m;
  	char *t;
  	int tam1,tam2;
  	int cont=0;
 	int contE;

	//Pegando o tamanho de cada string
  	tam1 = strlen(string);
  	tam2 = strlen(procurada);

	//Verificando se a string 2 está dentro da string 1
  	p = string;

  	for(int i=0;i<tam1;i++){
    	m = p;
    	t = procurada;
    	contE=0;
    	for(int j=0;j<tam2;j++){
      		if(*m == *t){
        		m++;
        		t++;
        		contE++;
				if(contE == tam2){
        			cont++;
      			}
      		}
    	}
    	p++;
  	}
  printf("\nO numero de vezes que -%s- aparece em -%s- eh: %d",procurada,string,cont);
}