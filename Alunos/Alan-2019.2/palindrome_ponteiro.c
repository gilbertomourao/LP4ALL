#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
void palindrome(char string[]);

int main(void) {
  char string[MAX];

  printf("Escreva sua string:\n");
  gets(string);

  palindrome(string);
}

void palindrome(char string[]){
	char *p;
	char *m;
	p = string;
	int cont=0;
	int total=0;


	while(*p){
		if(*p >= 'a' && *p <= 'z'){
			*p = *p - 32;
		}
		p++;
	}

	p = string;
	while(*p){
		if(*p >= 'A' && *p <= 'Z'){
			total++;
		}
		p++;
	}

	m = string;
	p--;
	while(*m){
		if(*p == ' '){
			p--;
		}

		if(*m == ' '){
			m++;
		}

		if(*p == *m){
			cont++;
		}
		m++;
		p--;
	}

	if(cont == total){
		printf("Eh palindrome!!");
	}else{
		printf("Nao eh palindrome!!!");
	}
}