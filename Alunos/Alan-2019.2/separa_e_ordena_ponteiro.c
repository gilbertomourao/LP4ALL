#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separa(char string[]);

int main(void) {
	char string[30];

	printf("Digite sua string:\n");
	gets(string);

	separa(string);
}

void separa(char string[])
{
	char *p;
	char *L;
	char *l;
	char *n;
	char *m;
	char auxL[30];
	char auxl[30];
	char auxN[30];
	char ordenadaL;
	char ordenadal;
	char ordenadaN;
	char aux;

	L = auxL;
	l = auxl;
	n = auxN;
	p = string;
	while(*p){
		//Separa as maiusculas
		if(*p>='A' && *p<='Z'){
			*L = *p;
			L++;
		}

		//Separa as minusculas
		if(*p>='a' && *p<='z'){
			*l = *p;
			l++;
		}

		//separa os numeros
		if(*p>='0' && *p<='9'){
			*n = *p;
			n++;
		}
		p++;
	}
	//Poe '\0' no finla pra ser string
	*L = '\0';
	*n = '\0';
	*l = '\0';

	L = auxL;
	l = auxl;
	n = auxN;
	printf("\nminus: %s\nmaius: %s\nnum: %s\n",l,L,n);
	//os "/n" foram usados apenas para deixar organizado na tela
	
	//ordena maiusculas
	L = auxL;
	m = auxL;
	while(*L){
		m = L;
		while(*m){
			if(*m < *L){
				aux = *L;
				*L = *m;
				*m = aux;
			}
			m++;
		}
		L++;
	}
	L = auxL;
	printf("\nMaius ordenado: %s",L);

	//ordena minusculas
	l = auxl;
	m = auxl;
	while(*l){
		m = l;
		while(*m){
			if(*m < *l){
				aux = *l;
				*l = *m;
				*m = aux;
			}
			m++;
		}
		l++;
	}
	l = auxl;
	printf("\nMinus ordenado: %s",l);

	//ordena numeros
	n = auxN;
	m = auxN;
	while(*n){
		m = n;
		while(*m){
			if(*m < *n){
				aux = *n;
				*n = *m;
				*m = aux;
			}
			m++;
		}
		n++;
	}
	n = auxN;
	printf("\nNum ordenado: %s",n);
}