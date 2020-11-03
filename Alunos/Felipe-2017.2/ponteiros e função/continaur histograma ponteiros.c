#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void dim(int *lin,int *col);
void ler(char m[][MAX],int lin,int col);
void tela(char m[][MAX],int lin,int col);
int strlen(char s[]);
void frequencia(char m[][MAX],int lin,int col);
int main(){
	char mat[MAX][MAX];
	int l,c;
	dim(&l,&c);
	ler(mat,l,c);
	tela(mat,l,c);
	frequencia(mat,l,c);
	return 0;
}
void dim(int *lin,int *col){
	int a,b;
	puts("Digite a qnt de linha e colunas:");
	scanf("%d %d",&a,&b);
	*lin=a;
	*col=b;
}

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

void tela(char m[][MAX],int lin,int col){
	int i,j;
	printf("MATRIZ:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%3c",m[i][j]);
		}
		puts("");
	}
}
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void frequencia(char m[][MAX],int lin,int col){
	int i,j,k,cont;
	char S[MAX];
	k=0;
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			S[k]=m[i][j];	
			k++;
		}
	}
	S[k]='\0';
	for(i=0;S[i]!='\0';i++){
		cont=0;
		for(j=0;S[j]!='\0';j++){
			if(S[i]==S[j]){
				cont++;
				for(k=j;k<strlen(S);j++){
					S[k]=S[k+1];
				}
			}
		}
		printf("%c--------->%d\n",S[i],cont);
	}
}



