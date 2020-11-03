#include <stdio.h>

//Menu de Funções

char tolower(char c);
int strlen(const char *s);
void tolowers(char *s);
int strpal(char *s);
char *strrev(char *s);
int substr(char *S,char *s);
void nospace(char *s);

//Programa

int main(void)
{
	
	char string[50], substring[50];
	
	while (1)
	{
		printf("Insira uma string principal: "); fgets(string,50,stdin);
		printf("Insira uma string secundaria: "); fgets(substring,50,stdin);
		nospace(string); nospace(substring);
		tolowers(string); tolowers(substring);
		printf("%d\n",substr(string,substring));
	}
	
	return 0;
}

//Funções

char tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	else
	{
		return c;
	}
}

int strlen(const char *s)
{
	int i =0;
	
	while (s[i]!='\0')
		i++;
	
	return i;
}

void tolowers(char *s)
{
	int i;
	char ch;
	
	   for (i=0;i<strlen(s);i++) {ch = s[i];s[i] = tolower(ch);}	   	
}

int strpal(char *s)
{
	
	int i,j;
	
	for (i=0,j=strlen(s)-2;i<j;i++,j--)
		if (s[i]!=s[j])
			return 0;
		
	return 1;	
}

char *strrev(char *s)
{
	int i,len;
	char aux;
	
	for (i=0,len=strlen(s)-2;i<len;i++,len--)
	{
		aux = s[i];
		s[i] = s[len];
		s[len] = aux;
	}
	
	return s;
}

int substr(char *S,char *s)
{
	int i,j=0,soma=0,num_sub=0;
	
	for (i=0;i<strlen(S);i++) {
		if (S[i] == s[j]) {soma++;j++;}
			else
				if (S[i]==s[0]) {soma=j=0;i--;}
					else {soma = j = 0;}
		if (soma == strlen(s)-1 && strlen(s)!=2) {soma=j=0;num_sub++;i--;}
		if (soma == 1 && strlen(s)==2) {num_sub++;}	
		if (i == strlen(S)-1) {soma = j = 0;}	
	}

	if (!strpal(s)) {
		strrev(s);
		for (i=0;i<strlen(S);i++) {
		if (S[i] == s[j]) {soma++;j++;}
			else
				if (S[i]==s[0]) {soma=j=0;i--;}
					else {soma = j = 0;}
		if (soma == strlen(s)-1 && strlen(s)!=2) {soma=j=0;num_sub++;i--;}
		if (soma == 1 && strlen(s)==2) {num_sub++;}	
		if (i == strlen(S)-1) {soma = j = 0;}	
		}
	}
			
	return num_sub;
}

void nospace(char *s)
{
	int i,j;
	
	for (i=0,j=0;i<strlen(s);i++,j++) {
		if (s[j]==' ')
			j++;	
		s[i] = s[j];
	}	
}