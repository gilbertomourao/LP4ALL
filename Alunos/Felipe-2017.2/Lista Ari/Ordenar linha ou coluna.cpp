#include <stdio.h>
#include <stdlib.h>
void tela(char m[][100],int d);
void linsel(char m[][100],int l,int d);
void colsel(char m[][100],int c,int d);
char *ordenar(char s[]);
int main(){
	int i,j,dim,esc,lin,col;
	char mat[100][100];
	puts("MATRIZ");
	puts("Digite a dimensao:");
	scanf("%d",&dim);
	fflush(stdin);
	puts("Preencha a matriz:");
	for(i=1;i<dim+1;i++){
		for(j=1;j<dim+1;j++){
			printf("[%d][%d]\n",i,j);
			scanf(" %c",&mat[i][j]);
			system("cls");
		}
	}
	tela(mat,dim);
	fflush(stdin);
	puts("Pra ordenar linha digite 1, coluna digite 0:");
	scanf("%d",&esc);
	while(esc<0||esc>1){
		printf("Invalido, tente novamente\n");
		scanf("%d",&esc);
	}
	if(esc==1){
		   puts("Digite a linha:");
		   scanf("%d",&lin);
		   	linsel(mat,lin,dim);
	}
	if(esc==0){
		   puts("Digite a coluna:");
		   scanf("%d",&col);
		   	colsel(mat,col,dim);
	}
	return 0;
}
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void tela(char m[][100],int d){
	int i,j;
	puts("Matriz:");
	for(i=1;i<d+1;i++){
		for(j=1;j<d+1;j++){
			printf("%2.5c",m[i][j]);
		}
		printf("\n");
	}
}
char *ordenar(char s[]){
	int i,j;
	char aux;
	for(i=1;i<strlen(s);i++){
		for(j=i+1;j<strlen(s);j++){
			if(s[i]>s[j]){
				aux=s[i];
				s[i]=s[j];
				s[j]=aux;
			}
		}
	}
	return s;
}
void linsel(char m[][100],int l,int d){
	int j;
	char str[100];
	for(j=1;j<d+1;j++){
		str[j]=m[l][j];
	}
	str[j]='\0';
	ordenar(str);
	for(j=1;j<d+1;j++){
		m[l][j]=str[j];
	}
	puts("Ordenada:");
	tela(m,d);
}
void colsel(char m[][100],int c,int d){
	int i;
	char str[100];
	for(i=1;i<d+1;i++){
		str[i]=m[i][c];
	}
	str[i]='\0';
	ordenar(str);
	for(i=1;i<d+1;i++){
		m[i][c]=str[i];
	}
	puts("Ordenada:");
	tela(m,d);
}
