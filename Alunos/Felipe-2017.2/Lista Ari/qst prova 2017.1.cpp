#include <stdio.h>
#include <string.h>
#define MAX 100
void tela(char m[][MAX],int d);
char *ordenacao(char s[MAX],int d);
int main(){
	int i,j,dim,k,w,cont=0;
	char mat[MAX][MAX],ch,x[MAX],y[MAX],vet1[MAX],vet2[MAX];
	puts("vai comecar !");
	puts("DIGITE A DIMENSAO:");
	scanf("%d",&dim);
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("[%d][%d]\n",i+1,j+1);
			scanf(" %c",&mat[i][j]);
		}
	}
	tela(mat,dim);
	puts("Digite o caractere a ser procurado:");
	scanf(" %c",&ch);
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if(mat[i][j]==ch){
				x[i]=i;
				y[i]=j;
				cont++;	
			}
		}
	}
	for(i=0,j=0;i<=cont;i++,j++){
		for(w=0;w<dim;w++){
		vet1[w]=mat[x[i]][w];
		}
		for(k=0;k<dim;k++){
		vet2[k]=mat[k][y[i]];
		}
		vet1[w]='\0';
		vet2[k]='\0';
		ordenacao(vet1,dim);
		ordenacao(vet2,dim);
		for(w=0;w<dim;w++){
			mat[x[i]][w]=vet1[w];
		}
		for(k=0;k<dim;k++){
			mat[k][y[i]]=vet2[k];
		}
	}
	tela(mat,dim);
	return 0;
}

char *ordenacao(char s[MAX],int d){
	int i,j;
	char aux;
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			if(s[i]<s[j]){
				aux=s[i];
				s[i]=s[j];
				s[j]=aux;   	
			}
		}
	}
	return s;
}
void tela(char m[][MAX],int d){
	int i,j;
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			printf("%c",m[i][j]);	  		
		}
		puts(" ");
	}
}