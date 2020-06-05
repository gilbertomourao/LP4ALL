/*Caça-Palavras com Função*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 11

void limpaBuffer();
void dimensao(int *,int *);
void ler_matriz(char *,int *,int *);
void imprime(char *,int *,int *);
void ler_string(char *);
void get_auxstr(char *,char *);
void get_invstr(char *,char *);
void get_auxmat(char *,char *,int *,int *);
char *varre_linhas(char *,char *,char *,char *,int *,int *);
char *varre_colunas(char *,char *,char *,char *,int *,int *);
char *varre_diagonais(char *,char *,char *,char *,int *,int *);
char *cacapalavras(char *,char *,int *,int *);

int main(){
	
	char mat[MAX][MAX], pala[MAX];
	int L,C;
	
	dimensao(&L,&C);
	ler_matriz(mat[0],&L,&C);
	imprime(mat[0],&L,&C);
	putchar('\n');
	ler_string(pala);
	putchar('\n');
	imprime(cacapalavras(mat[0],pala,&L,&C),&L,&C);
	
	return 0;
}

/**************************************************
 *************		 Funções		  *************							
 **************************************************/
 
void limpaBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
 
void dimensao(int *L,int *C){

	int i = 0,j = 0;
	
	while (i <= 0 || j <= 0 || i >= MAX || j >= MAX){
		printf("Insira o numero de linhas: "); scanf("%d", &i); limpaBuffer();
		printf("Insira o numero de colunas: "); scanf("%d", &j); limpaBuffer();
	}
	
	*L = i; *C = j; 	
} 

void ler_matriz(char *mat,int *L,int *C){
	
	int i,j;
	
	for (i = 0;i<*L;i++)
		for (j = 0;j<*C;j++)
			*(mat+i*MAX+j) = '*';
		
	puts("*********Bem vindo ao CACA PALAVRAS*******");
	puts("Agora, preencha os espacos com caracteres.");
	putchar('\n');	
		
	for (i=0;i<=*L;i++)
		for (j=0;j<*C;j++){  
			   imprime(mat,L,C);
			   putchar('\n');		      	   	
			   if (i == *L) break;
			   printf("\nEspaco [%d][%d]: ",i+1,j+1);
			   *(mat+i*MAX+j) = getchar();
			   if (*(mat+i*MAX+j) == '\n')
			   	*(mat+i*MAX+j) = ' ';
			   else limpaBuffer();
			   putchar('\n');
		}
	
	system("cls");
}

void imprime(char *mat,int *L,int *C){

	int i,j,k;

	for (i = 0;i<*L;i++){
		printf("-");
		for (k = 0;k < *C;k++)
			printf("--");
		putchar('\n');
		for (j=0;j<=*C;j++)
			if (j == *C)
				printf("|");
			else 
	 	 	    printf("|%c",*(mat+i*MAX+j));
		putchar('\n');
	}
	printf("-");
	for (k = 0;k < *C;k++)
			printf("--");
		
}

void ler_string(char *pala){
	
	printf("Qual palavra deseja procurar? ");
	
	fgets(pala,MAX,stdin);
	char *p = pala;
	while(*p && *p != '\n') ++p;
	if (*p) *p = 0;
	else{
		scanf("%*[^\n]");
		scanf("%*c");
	}
}

void get_auxstr(char *pala,char *aux_pala){
	
	int i,j;
	
	for (i=0,j=0;*(pala+i)!='\0';i++,j++){
		while ((*(pala+i) < 'A' || *(pala+i) > 'Z') && (*(pala+i) < 'a' || *(pala+i) > 'z') && *(pala+i) != '\0')
			i++;
		if (*(pala+i) == '\0') break;
		*(aux_pala+j) = *(pala+i);
		if (*(aux_pala+j) >= 'A' && *(aux_pala+j) <= 'Z')
			*(aux_pala+j) = tolower(*(aux_pala+j));
	}
	*(aux_pala+j) = '\0';
}

void get_invstr(char *aux_pala,char *inv_pala){
	aux_pala = strrev(aux_pala);
	inv_pala = strcpy(inv_pala,aux_pala);
	aux_pala = strrev(aux_pala);
}

void get_auxmat(char *mat,char *aux_mat,int *L,int *C){
	int i, j;
	/*Obtém a auxiliar da matriz*/
	for (i=0;i<*L;i++)
		for (j=0;j<*C;j++){
			*(aux_mat+i*MAX+j) = *(mat+i*MAX+j);
			*(aux_mat+i*MAX+j) = tolower(*(aux_mat+i*MAX+j)); 
		}	
}

char *varre_linhas(char *mat,char *aux_mat,char *aux_pala,char *inv_pala,int *L,int *C){
	
	int i, j, k;
	unsigned int h, cont, cont_inv;
	
	/*Varredura das linhas*/
	
	for (i=0;i<*L;i++)
		for (j=0;j<*C;j++)
			if (*(aux_mat+i*MAX+j) == *aux_pala || *(aux_mat+i*MAX+j) == *inv_pala){
				cont = cont_inv = 0;
				for (h=0,k=j;h < strlen(aux_pala) && k < *C;h++,k++){
					while ((*(aux_mat+i*MAX+k) < 'a' || *(aux_mat+i*MAX+k) > 'z') && k < *C )
						k++;
					if (k == *C) break;
					if (*(aux_mat+i*MAX+k) == *(aux_pala+h))
						cont++;
					if (*(aux_mat+i*MAX+k) == *(inv_pala+h))
						cont_inv++;
				}
				if (cont == strlen(aux_pala) || cont_inv == strlen(aux_pala))
					for (h=0,k=j;h < strlen(aux_pala);h++,k++){        /*Faz a substituição*/
					   while (*(aux_mat+i*MAX+k) < 'a' || *(aux_mat+i*MAX+k) > 'z')
					   	 k++;
					   if (*(aux_mat+i*MAX+k) == *(aux_pala+h) || *(aux_mat+i*MAX+k) == *(inv_pala+h))
					   		*(mat+i*MAX+k) = '*';	
					}
			}	
			
	return mat;
}

char *varre_colunas(char *mat,char *aux_mat,char *aux_pala,char *inv_pala,int *L,int *C){
	
	int i, j, k;
	unsigned int h, cont, cont_inv;
	
	/*Varredura das colunas*/
	
	for (j=0;j<*C;j++)
		for (i=0;i<*L;i++)
			if (*(aux_mat+i*MAX+j) == *aux_pala || *(aux_mat+i*MAX+j) == *inv_pala){
				cont = cont_inv = 0;
				for (h=0,k=i;h < strlen(aux_pala) && k < *L;h++,k++){
					while ((*(aux_mat+k*MAX+j) < 'a' || *(aux_mat+k*MAX+j) > 'z') && k < *L)
						k++;
					if (k == *L) break;
					if (*(aux_mat+k*MAX+j) == *(aux_pala+h))
						cont++;
					if (*(aux_mat+k*MAX+j) == *(inv_pala+h))
						cont_inv++;
				}
				if (cont == strlen(aux_pala) || cont_inv == strlen(aux_pala))
					for (h=0,k=i;h < strlen(aux_pala);h++,k++){         /*Faz a substituição*/
						while (*(aux_mat+k*MAX+j) < 'a' || *(aux_mat+k*MAX+j) > 'z')
						  k++;
					   if (*(aux_mat+k*MAX+j) == *(aux_pala+h) || *(aux_mat+k*MAX+j) == *(inv_pala+h))
					   	   	*(mat+k*MAX+j) = '*';	
					}	
			}
			
	return mat;		
}

char *varre_diagonais(char *mat,char *aux_mat,char *aux_pala,char *inv_pala,int *L,int *C){
	
	int i,j,k,l,m,n;
	unsigned int h,cont,cont_inv;
	
	/*Varredura das diagonais*/
	
		/*Sentido da diagonal principal*/
		
		for (j=0;j<*C;j++)   
			for (i=*L-1;i>=0;i--){
				if (j>0) i = 0; /*evita repetições*/
				for (k = i,l = j; k < *L && l < *C; k++, l++)
					if (*(aux_mat+k*MAX+l) == *aux_pala || *(aux_mat+k*MAX+l) == *inv_pala){
						cont = cont_inv = 0;
						for (h=0,m=k,n=l;h < strlen(aux_pala) && n < *C && m < *L;h++,m++,n++){
							while ((*(aux_mat+m*MAX+n) < 'a' || *(aux_mat+m*MAX+n) > 'z')&& n < *C && m < *L){
								 m++; n++;  	
							}
							if (n == *C || m == *L) break;
							if (*(aux_mat+m*MAX+n) == *(aux_pala+h))
								cont++;
							if (*(aux_mat+m*MAX+n) == *(inv_pala+h))
								cont_inv++;
						}
						if (cont == strlen(aux_pala) || cont_inv == strlen(aux_pala))
							for (h=0,m=k,n=l;h < strlen(aux_pala);h++,m++,n++){  /*Faz a substituição*/
								while (*(aux_mat+m*MAX+n) < 'a' || *(aux_mat+m*MAX+n) > 'z'){
							   	   m++; n++;	
								}
						   	   if (*(aux_mat+m*MAX+n) == *(aux_pala+h) || *(aux_mat+m*MAX+n) == *(inv_pala+h))
						   			*(mat+m*MAX+n) = '*';
							}
					}
			}	
		
		/*Sentido da diagonal secundária*/
		
		for (i=0;i<*L;i++)   
			for (j=0;j<*C;j++){
				if (i>0) j = *C-1; /*evita repetições*/
				for (k = i,l = j; k < *L && l >= 0; k++, l--)
					if (*(aux_mat+k*MAX+l) == *aux_pala || *(aux_mat+k*MAX+l) == *inv_pala){
						cont = cont_inv = 0;
						for (h=0,m=k,n=l;h < strlen(aux_pala) && m < *L && n >= 0;h++,m++,n--){
							while ((*(aux_mat+m*MAX+n) < 'a' || *(aux_mat+m*MAX+n) > 'z') && m < *L && n >= 0){
								 m++; n--;  	
							}
							if (m == *L || n < 0) break;
							if (*(aux_mat+m*MAX+n) == *(aux_pala+h))
								cont++;
							if (*(aux_mat+m*MAX+n) == *(inv_pala+h))
								cont_inv++;
						}
						if (cont == strlen(aux_pala) || cont_inv == strlen(aux_pala))
							for (h=0,m=k,n=l;h < strlen(aux_pala);h++,m++,n--){  /*Faz a substituição*/
								while (*(aux_mat+m*MAX+n) < 'a' || *(aux_mat+m*MAX+n) > 'z'){
							   	   m++; n--;	
								}
						   	   if (*(aux_mat+m*MAX+n) == *(aux_pala+h) || *(aux_mat+m*MAX+n) == *(inv_pala+h))
						   			*(mat+m*MAX+n) = '*';
							}
					}
			}
	
	return mat;
}

char *cacapalavras(char *mat,char *pala,int *L,int *C){
	
	char aux_mat[MAX][MAX], aux_pala[MAX], inv_pala[MAX];
	
	get_auxstr(pala, aux_pala);	
	get_invstr(aux_pala, inv_pala);
	get_auxmat(mat, aux_mat[0], L, C);
		
	mat = varre_linhas(mat,aux_mat[0],aux_pala,inv_pala,L,C);
	mat = varre_colunas(mat,aux_mat[0],aux_pala,inv_pala,L,C);
	mat = varre_diagonais(mat,aux_mat[0],aux_pala,inv_pala,L,C);
			
	return mat;
}
