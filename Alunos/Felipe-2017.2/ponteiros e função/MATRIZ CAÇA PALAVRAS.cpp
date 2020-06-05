#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*operacinonais*/
void dim(int *lin,int *col);
void ler(char m[][MAX],int lin,int col);
void tela(char m[][MAX],int lin,int col);
/*funcionais*/
int palindrome(char s[]);
char tolower(char c);
int strlen(char s[]);
char *strrev(char st[]);
void cacar(char m[][MAX],char p[MAX],int lin,int col);
/*incio da main*/
int main(){
	char mat[MAX][MAX],pal[MAX];
	int l,c;
	dim(&l,&c);
	ler(mat,l,c);
	tela(mat,l,c);
	printf("digite a palavra;\n");
	fflush(stdin);
	gets(pal);
	cacar(mat,pal,l,c);
	tela(mat,l,c);
	return 0;
}
/*pega a dimensão da matriz */
void dim(int *lin,int *col){
	int a,b;
	puts("Digite a qnt de linha e colunas:");
	scanf("%d %d",&a,&b);
	*lin=a;
	*col=b;
}
/*case sensitive nas comparações*/
char tolower(char c){
	if (c >= 'A' && c <= 'Z'){
		return (c + 'a' - 'A');
	}	
	else{
		return c;
	}
}
/*ler os valores pra matriz*/
void ler(char m[][MAX],int lin,int col){
	int i,j;
	printf("Preencha a matriz:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("[%d][%d]",i+1,j+1);
			scanf(" %c",&m[i][j]);
			system("cls");
		}
	}
}
/*exibe os valores digitados pelo usuário*/
void tela(char m[][MAX],int lin,int col){
	int i,j;
	printf("MATRIZ:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%c",m[i][j]);
		}
		puts("");
	}
}
/*retorna o tamanho de uma string*/
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
/*retorna uma string invertida*/
char *strrev(char s[]){
	int i,j;
	char aux;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		aux=s[i];
		s[i]=s[j];
		s[j]=aux;
	}
	return s;
}
/*reconhece se uma string é ou não é palindromo*/
int palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}
/*função que busca a palavra na matriz e a substitui por '*'*/
void cacar(char m[][MAX],char p[MAX],int lin,int col){
	int i,j,vdd,k,h;
	char paux[MAX];
	/*coloca a palavra numa auxiliar pra não ser modificada*/
	for(i=0;p[i]!='\0';i++){
		paux[i]=p[i];
	}
	paux[i]='\0';
	/*procura nas linhas*/
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			if(tolower(m[i][j])==tolower(p[0])){
				vdd=0;
				for(k=0;k<strlen(p);k++){
					if(tolower(m[i][j+k])==tolower(p[k])){
						vdd++;
						
					}
					if(vdd==strlen(p)){
						for (h=0,k=j;h < strlen(p);h++,k++){        //Faz a substituição//
					   	   if (tolower(m[i][k]) == tolower(p[h]))
					   		m[i][k] = '*';	
						}
						
					}
				}		
			}
		}
	}
	/*procura nas colunas*/
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			if(tolower(m[i][j])==tolower(p[0])){
				vdd=0;
				for(k=0;k<strlen(p);k++){
					if(tolower(m[i+k][j])==tolower(p[k])){
						vdd++;
						
					}
					if(vdd==strlen(p)){
						for (h=0,k=i;h < strlen(p);h++,k++){        //Faz a substituição//
					   	   if (tolower(m[k][j]) == tolower(p[h]))
					   		m[k][j] = '*';	
						}
						
					}
				}		
			}
		}
	}
	/*se não for palindromo a palavra, então deve fazer isso uma  única vez */
	if(!palindrome(p)){
		strrev(p);/*inverte a palavra*/
		/*procura nas linhas*/
		for(i=0;i<lin;i++){
			for(j=0;j<col;j++){
				if(tolower(m[i][j])==tolower(p[0])){
					vdd=0;
					for(k=0;k<strlen(p);k++){
						if(tolower(m[i][j+k])==tolower(p[k])){
							vdd++;
						
						}
						if(vdd==strlen(p)){
							for (h=0,k=j;h < strlen(p);h++,k++){        //Faz a substituição//
					   	   	   if (tolower(m[i][k]) == tolower(p[h]))
					   			m[i][k] = '*';	
							}
						
						}
		 		    }		
				}
			}
		}
		/*procura nas colunas*/
		for(i=0;i<lin;i++){
			for(j=0;j<col;j++){
				if(tolower(m[i][j])==tolower(p[0])){
					vdd=0;
					for(k=0;k<strlen(p);k++){
						if(tolower(m[i+k][j])==tolower(p[k])){
							vdd++;
						
						}
						if(vdd==strlen(p)){
							for (h=0,k=i;h < strlen(p);h++,k++){        //Faz a substituição//
					   	   	   if (tolower(m[k][j]) == tolower(p[h]))
					   			m[k][j] = '*';	
							}
						
						}
		 		    }		
				}
			}
		}
	}
}






















