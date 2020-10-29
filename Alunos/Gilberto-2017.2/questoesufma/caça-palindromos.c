/*Caça-Palíndromos*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 30

void dim (int *,int *);
int strpal (char *);
void leitura (char *,int *,int *);
void palihunt (char *,int *,int *);
void mostra (char *,int *,int *);

int main(){
	
	int L,C,i,j;
	char mat[MAX][MAX];   	

	dim (&L,&C);
	
	/*Matriz inicial*/
	
	for (i=0;i<L;i++)
		for (j=0;j<C;j++)
			mat[i][j] = '*';
	
	leitura (mat[0],&L,&C);
	system("cls");
	mostra(mat[0],&L,&C);
	palihunt (mat[0],&L,&C);
	putchar('\n');
	mostra (mat[0],&L,&C);
	
	return 0;
}

void dim (int *L,int *C){
	
	int i,j;
	
	printf("Insira o numero de linhas da matriz: "); scanf("%d", &i); fflush(stdin);
	printf("Insira o numero de colunas da matriz: "); scanf("%d", &j); fflush(stdin);
	
	*L = i; *C = j;
	
}

int strpal (char *string){
	
	int tamanho=0,i=0,j;
	
	while (*(string + i++))
		tamanho++;
	
	if (tamanho == 1)
		return 0;
	else for (i = 0,j=tamanho-1;i < j;i++,j--)
			if (tolower(*(string+i)) != tolower(*(string+j)))
				return 0;
	return 1;	
}

void leitura (char *mat,int *L,int *C){
	
	int i,j,k,l;
	
	for (i=0;i<=*L;i++)
		for (j=0;j<*C;j++){  
			   puts("*********Bem vindo ao CACA-PALINDROMOS*******");
	  	  	   puts("Agora, preencha os espacos com caracteres.");
			   putchar('\n');
	
			   for (k=0;k<*L;k++){
				   for (l=0;l<*C;l++)
					   printf("%c",*(mat + k*MAX + l));
                   putchar('\n');
			   }    	   	
			   if (i == *L) break;
			   
			   printf("\nEspaco [%d][%d]: ",i+1,j+1);
			   *(mat + i*MAX + j) = getchar();
			   if (*(mat + i*MAX + j) == '\n')
			   	*(mat + i*MAX + j) = ' ';
			   fflush(stdin);
		}

}

void mostra (char *mat,int *L,int *C){
	
	int i,j;
	
	for (i = 0;i < *L;i++){
		for (j = 0;j < *C;j++)
			printf("%c", *(mat+i*MAX+j));
		putchar('\n');
	}
	
}

void palihunt (char *mat,int *L,int *C){
	
	int i,j,k,l,m,n,o;
	int kaux, laux, maux; /*fixed*/
	char mat_aux[MAX][MAX], string[MAX];
	
	/*Matriz auxiliar*/
	
	for (i=0;i<=*L;i++)
		for (j=0;j<*C;j++)
			mat_aux[i][j] = *(mat + i*MAX + j);
	putchar('\n');	
	/*Contagem nas linhas*/	

	for (i=0;i<*L;i++)
		for (j=0;j<*C;j++){ l = 0;
			if (tolower(mat_aux[i][j]) >= 'a' && tolower(mat_aux[i][j]) <= 'z'){
				string[l++] = mat_aux[i][j];
				for (m = j+1;m < *C;m++){
					if (tolower(mat_aux[i][m]) >= 'a' && tolower(mat_aux[i][m]) <= 'z')
						string[l++] = mat_aux[i][m];
					string[l] = '\0';
					if (strpal(string)){
						if (tolower(mat_aux[i][m]) >= 'a' && tolower(mat_aux[i][m]) <= 'z')
							printf("O palindromo %s aparece na linha %d entre [%d][%d] e [%d][%d].\n",string,i+1,i+1,j+1,i+1,m+1);
						for (k = j,l = 0;k < *C;k++,l++)
							if (mat_aux[i][k] == string[l])
								*(mat + i*MAX + k) = '*';
							else l--;
					}
				}
			}
		}	
	putchar('\n');	
	/*Contagem nas colunas*/
	
	for (j=0;j<*C;j++)
		for (i=0;i<*L;i++){ l = 0;
			if (tolower(mat_aux[i][j]) >= 'a' && tolower(mat_aux[i][j]) <= 'z'){
				string[l++] = mat_aux[i][j];
				for (m = i+1;m < *L;m++){
					if (tolower(mat_aux[m][j]) >= 'a' && tolower(mat_aux[m][j]) <= 'z')
						string[l++] = mat_aux[m][j];
					string[l] = '\0';
					if (strpal(string)){
						if (tolower(mat_aux[m][j]) >= 'a' && tolower(mat_aux[m][j]) <= 'z')
							printf("O palindromo %s aparece na coluna %d entre [%d][%d] e [%d][%d].\n",string,j+1,i+1,j+1,m+1,j+1);
						for (k = i,l = 0;k < *L;k++,l++)
							if (mat_aux[k][j] == string[l])
								*(mat + k*MAX + j) = '*';
							else l--; 
					}	
				}
			}
		}
    putchar('\n');
	/*Contagem nas diagonais principais*/
	
	for (j=0;j<*C;j++)
		for (i=*L-1;i>=0;i--){
			if (j>0) i = 0; /*evita repetições*/
			for (k = i,l = j; k < *L && l < *C; k++, l++){ o = 0;
				if (tolower(mat_aux[k][l]) >= 'a' && tolower(mat_aux[k][l]) <= 'z'){
					string[o++] = mat_aux[k][l];
					for (m = k+1,n=l+1;m < *L && n < *C ;m++,n++){
						if (tolower(mat_aux[m][n]) >= 'a' && tolower(mat_aux[m][n]) <= 'z')
							string[o++] = mat_aux[m][n];
						string[o] = '\0';
						if (strpal(string)){
							if (tolower(mat_aux[m][n]) >= 'a' && tolower(mat_aux[m][n]) <= 'z')
								printf("O palindromo %s aparece na diagonal P entre [%d][%d] e [%d][%d].\n",string,k+1,l+1,m+1,n+1);
							for (kaux = k,laux = l,maux = 0; kaux < *L && laux < *C; kaux++, laux++, maux++)
								if (mat_aux[kaux][laux] == string[maux])
									*(mat + kaux*MAX + laux) = '*';
								else maux--; 	
						}
					}
				}
			}	
		}
	putchar('\n');
	/*Contagem nas diagonais secundárias*/
	
	for (i=0;i<*L;i++)
		for (j=0;j<*C;j++){
			if (i>0) j = *C-1; /*evita repetições*/
			for (k = i,l = j; k < *L && l >= 0; k++, l--){ o = 0;
				if (tolower(mat_aux[k][l]) >= 'a' && tolower(mat_aux[k][l]) <= 'z'){
					string[o++] = mat_aux[k][l];
					for (m = k+1,n=l-1;m < *L && n >= 0 ;m++,n--){
						if (tolower(mat_aux[m][n]) >= 'a' && tolower(mat_aux[m][n]) <= 'z')
							string[o++] = mat_aux[m][n];
						string[o] = '\0';
						if (strpal(string)){
							if (tolower(mat_aux[m][n]) >= 'a' && tolower(mat_aux[m][n]) <= 'z')
								printf("O palindromo %s aparece na diagonal S entre [%d][%d] e [%d][%d].\n",string,k+1,l+1,m+1,n+1);
							for (kaux = k,laux = l,maux = 0; kaux < *L && laux < *C; kaux++, laux--, maux++)
								if (mat_aux[kaux][laux] == string[maux])
									*(mat + kaux*MAX + laux) = '*';
								else maux--;
						}
					}	
				}
			}
		}
	putchar('\n');	
}