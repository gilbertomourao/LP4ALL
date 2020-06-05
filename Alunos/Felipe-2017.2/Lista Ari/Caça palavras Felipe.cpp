/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Matriz caça palavras
Ano: 2017.2
*/
#include <stdio.h>
#include <stdlib.h>
//Funções auxiliares
void tela(char matriz[][100],int d);

//Funções comparativas
int strlen(char s[]);
char *strrev(char s[]);
int compara(char f[],char p[]);
int palindrome(char s[]);
int linha(char mat[][100],char s[],int dim);
int coluna(char mat[][100],char s[],int dim);

//main
int main(int argc, char** argv){
	int dim,i,j,qnt,valor;
	char mat[100][100],palavra[100];
	puts("Bem vindo jogador ao ");
	printf("Ca%ca palavras do FELIPE:\n\n",-121);
	printf("Digite a dimens%co pra come%car:\n",-58,-121);
	scanf("%d",&dim);
	puts("Preencha a matriz:");
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("Posicao [%d][%d]\n",i+1,j+1);
			scanf(" %c",&mat[i][j]);
		}
	}
	system("cls");
	puts("MATRIZ DIGITADA:");
	tela(mat,dim);
	fflush(stdin);
	puts("Digite a qnt de palavra a ser buscada:");
	scanf("%d",&qnt);
	while(qnt>0){
		printf("\n\nDigite a palavra a ser procurada:\n");
		fflush(stdin);
		gets(palavra);
		while(strlen(palavra)==1){
			puts("Nao e palavra");
			gets(palavra);
		}
		valor=linha(mat,palavra,dim)+coluna(mat,palavra,dim);
		printf("A palavara %s aparece %d vez(es)",palavra,valor);
		qnt--;	
	}
	return 0;
}

//Funções

int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void tela(char matriz[][100],int d){
	int i,j;
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			printf("%3c",matriz[i][j]);
		}
		printf("\n");
	}
}
int palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}

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

int compara(char f[],char p[]){
	int tf,tp,i,j,aux,cont=0,x;
	tf=strlen(f);
	tp=strlen(p);
	for(i=0;i<tf;i++){
		if(p[0]==f[i]){
			aux=i;
			x=0;//variavel q auciliará na contagem de palavras iguais
			for(j=0;j<tp;j++){
				if(p[j]==f[aux]){
					x++;
					aux++;
				}
				if(x==tp){
					cont++;
				}
			}
		}
	}
	//verificará a palavra de trás pra frente
	if(!palindrome(p)){
		strrev(p);
		for(i=0;i<tf;i++){
			if(p[0]==f[i]){
				x=0;//variavel q auciliará na contagem de palavras iguais
				aux=i;
				for(j=0;j<tp;j++){
					if(p[j]==f[aux]){
						x++;
						aux++;
					}
					if(x==tp){
						cont++;
					}
				}
			}
		}
	}
	return cont;
}
int linha(char mat[][100],char s[],int dim){
	int i,j,cont=0;
	char S[100];
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			S[j]=mat[i][j];
		}
		S[j]='\0';
		cont+=compara(S,s);
	}
	return cont;
}
int coluna(char mat[][100],char s[],int dim){
	int i,j,cont=0;
	char S[100];
	for(j=0;j<dim;j++){
		for(i=0;i<dim;i++){
			S[i]=mat[i][j];
		}
		S[i]='\0';
		cont+=compara(S,s);
	}
	return cont;
}









