#include <stdio.h>
#include <stdlib.h>

//Funções para substring

char tolower(char c);
int strlen(const char *s);
void tolowers(char *s);
int strpal(char *s);
char *strrev(char *s);
int substr(char *S,char *s);
void nospace(char *s);
void mostra(char s[][50],int DIM);

//Funções para contagem na matriz

int checalinha(char mat[][50],char s[],int DIM);
int checacoluna(char mat[][50],char s[],int DIM);
int checadiag(char mat[][50],char s[],int DIM);

//Programa

int main()
{
	int i,j,n,res;
	char ch;
	char mat[50][50],palavra[50];
	
	puts("****Bem vindo ao CACA PALAVRAS**");
	printf("Escolha a dimensao do jogo: "); scanf("%d", &n);
	puts("Agora, preencha os espacos com caracteres.");
	
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			mat[i][j] = ' ';
	
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){
			printf("\nEspaco [%d][%d]: ",i+1,j+1);
			scanf(" %c", &ch);	
			if (mat[i][j] == ' ')
				mat[i][j] = ch;
			system("cls");
			mostra(mat,n);
		}
	
	fflush(stdin);
	
	printf("\nEscolha uma palavra para procurar: "); fgets(palavra,50,stdin);	
	
	for (i=0;i<strlen(palavra);i++)	
		if (palavra[i] == '\n')
			palavra[i] = '\0';
	
	if (strlen(palavra) == 1)
		res = checalinha(mat,palavra,n);
	else	
		res = checalinha(mat,palavra,n) + checacoluna(mat,palavra,n) + checadiag(mat,palavra,n);
	
	putchar('\n');
	printf("A palavra %s aparece %d vezes.",palavra,res);
	
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
	
	for (i=0,j=strlen(s)-1;i<j;i++,j--)
		if (s[i]!=s[j])
			return 0;
		
	return 1;	
}

char *strrev(char *s)
{
	int i,len;
	char aux;
	
	for (i=0,len=strlen(s)-1;i<len;i++,len--)
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
	char saux[50];
	
	for (i=0;i<strlen(s);i++)
		saux[i]=s[i];
	
	for (i=0;i<strlen(S);i++) {
		if (S[i] == s[j]) {soma++;j++;}
			else
				if (S[i]==s[0]) {soma=j=0;i--;}
					else {soma = j = 0;}
		if (soma == strlen(s) && strlen(s)!=1) {soma=j=0;num_sub++;i--;}
		if (soma == 1 && strlen(s)==1) {num_sub++;}	
		if (i == strlen(S)-1) {soma = j = 0;}	
	}

	if (!strpal(s)) {
		strrev(s);
		for (i=0;i<strlen(S);i++) {
		if (S[i] == s[j]) {soma++;j++;}
			else
				if (S[i]==s[0]) {soma=j=0;i--;}
					else {soma = j = 0;}
		if (soma == strlen(s) && strlen(s)!=1) {soma=j=0;num_sub++;i--;}
		if (soma == 1 && strlen(s)==1) {num_sub++;}	
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

int checalinha(char mat[][50],char s[],int DIM)
{
	int i,j,aux=0;
	char S[50];
	
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++)
			S[j] = mat[i][j];
		S[j] = '\0';
		nospace(S); nospace(s);
		tolowers(S); tolowers(s);
		aux += substr(S,s);
	}
	return aux;		
}

int checacoluna(char mat[][50],char s[],int DIM)
{
	int i,j,aux=0;
	char S[50];
	
	for (j=0;j<DIM;j++){
		for (i=0;i<DIM;i++)
			S[i] = mat[i][j];
		S[i] = '\0';
		nospace(S); nospace(s);
		tolowers(S); tolowers(s);
		aux += substr(S,s);
	}
	
	return aux;
}

int checadiag(char mat[][50],char s[],int DIM)
{
	int i,j,k,aux=0;
	char S_1[50],S_2[50];
	
	//Direção da diagonal principal
	
	for (k=0;k<DIM;k++) {
        for (i=k,j=0;i<DIM;i++,j++){
			S_1[j] = mat[i][j];
			if (i!=j){S_2[j] = mat[j][i];}
			else {S_2[0] = '\0';}
		}
		S_1[j] = S_2[j] = '\0';
		nospace(S_1); nospace(S_2); nospace(s);
		tolowers(S_1); tolowers(S_2); tolowers(s);
		aux += substr(S_1,s)+substr(S_2,s);
	}
	
	//Direção da diagonal secundária
	
	for (k=0;k<DIM;k++) {
		for (i=k,j=(DIM-1);i<DIM;i++,j--){
			S_1[i-k] = mat[i][j];
			if (k>0) {S_2[i-k] = mat[i-k][j-k];}
			else {S_2[0] = '\0';}	
		}
		S_1[i-k] = S_2[i-k] = '\0';
		nospace(S_1); nospace(S_2); nospace(s);
		tolowers(S_1); tolowers(S_2); tolowers(s);
		aux += substr(S_1,s)+substr(S_2,s);
	}
	
	return aux;
}

void mostra(char s[][50],int DIM)
{
	int i,j;
	
	puts("****Bem vindo ao CACA PALAVRAS**");
	puts("Agora, preencha os espacos com caracteres.");
	putchar('\n');
	
	for (i=0;i<DIM;i++){
		for (j=0;j<DIM;j++)
			printf(" %c",s[i][j]);
		putchar('\n');
	}
}