#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void dim(int *lin,int *col);
void ler(char m[][MAX],int lin,int col);
void palavra(char *s);
void tela(char m[][MAX],int lin,int col);

int palindrome(char s[]);
int strlen(char s[]);
char *strrev(char st[]);
void cacar(char m[][MAX],char p[MAX],int lin,int col);

int main(){
	char mat[MAX][MAX],pal[MAX];
	int l,c;
	dim(&l,&c);
	ler(mat,l,c);
	tela(mat,l,c);
	fflush(stdin);
	palavra(&pal[0]);
	cacar(mat,pal,l,c);
	tela(mat,l,c);
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

void palavra(char *s){
	printf("Digite a palavra a ser procurada:\n");
	gets(s++);
}
 
void tela(char m[][MAX],int lin,int col){
	int i,j;
	puts(" ");
	printf("MATRIZ:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%c",m[i][j]);
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


int palindrome(char s[]){
	int i,j;
	for(i=0,j=strlen(s)-1;s[i]!='\0';i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}

void cacar(char m[][MAX],char p[MAX],int lin,int col){
	int i,j,vdd,k,h;
	char aux_mat[MAX][MAX],pal_aux[MAX];
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			aux_mat[i][j]=m[i][j];
		}
	}
	for(i=0;p[i]!='\0';i++){
		pal_aux[i]=p[i];
	}
	pal_aux[i]='\0';
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			if(aux_mat[i][j]==p[0]){
				vdd=0;
				for(k=0;k<strlen(p);k++){
					if(aux_mat[i][j+k]==p[k]){
						vdd++;
						
					}
					if(vdd==strlen(p)){
						printf("A palavra %s apareceu na linha %d\n",pal_aux,i+1);
						for (h=0,k=j;h < strlen(p);h++,k++){      
					   	   if (aux_mat[i][k] == p[h])
					   		m[i][k] = '*';	
						}
						
					}
				}		
			}
		}
	}
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			if(aux_mat[i][j]==p[0]){
				vdd=0;
				for(k=0;k<strlen(p);k++){
					if(aux_mat[i+k][j]==p[k]){
						vdd++;
						
					}
					if(vdd==strlen(p)){
						printf("A palavra %s apareceu na coluna %d\n",pal_aux,j+1);
						for (h=0,k=i;h < strlen(p);h++,k++){       
					   	   if (aux_mat[k][j] == p[h])
					   		m[k][j] = '*';	
						}
						
					}
				}		
			}
		}
	}
	if(!palindrome(p)){
		strrev(p);
		for(i=0;i<lin;i++){
			for(j=0;j<col;j++){
				if(aux_mat[i][j]==p[0]){
					vdd=0;
					for(k=0;k<strlen(p);k++){
						if(aux_mat[i][j+k]==p[k]){
							vdd++;
						
						}
						if(vdd==strlen(p)){
							printf("A palavra %s apareceu na linha %d\n",pal_aux,i+1);
							for (h=0,k=j;h < strlen(p);h++,k++){        
					   	   	   if (aux_mat[i][k] == p[h])
					   			m[i][k] = '*';	
							}
						
						}
		 		    }		
				}
			}
		}
		for(i=0;i<lin;i++){
			for(j=0;j<col;j++){
				if(aux_mat[i][j]==p[0]){
					vdd=0;
					for(k=0;k<strlen(p);k++){
						if(aux_mat[i+k][j]==p[k]){
							vdd++;
						
						}
						if(vdd==strlen(p)){
							printf("A palavra %s apareceu na coluna %d\n",pal_aux,j+1);
							for (h=0,k=i;h < strlen(p);h++,k++){       
					   	   	   if (aux_mat[k][j] == p[h])
					   			m[k][j] = '*';	
							}
						
						}
		 		    }		
				}
			}
		}
	}
}