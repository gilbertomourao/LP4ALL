//Caça-Palavras com substituição e dentro da main

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
	char mat[MAX][MAX],aux_mat[MAX][MAX],pala[MAX],aux_pala[MAX],mostra[MAX][MAX];
	int i,j,k,o,m,h,n,L,C,aux_i,aux_j,cont,qtd_L=0,qtd_C=0,qtd_D = 0,total,pali;
	
	printf("Insira o numero de linhas da matriz: "); scanf("%d", &L); 
	fflush(stdin); 
	printf("Insira o numero de colunas da matriz: "); scanf("%d", &C); 
	fflush(stdin);
	
	//Inicia o preenchimento do caça-palavras
	
	for (i=0;i<L;i++)
		for (j=0;j<C;j++)
			mat[i][j] = ' ';
		
	for (i=0;i<L;i++){
		aux_i = i;
		for (j=0;j<C;j++){
			   
			   aux_j = j;
			   
			   printf("\nEspaco [%d][%d]: ",i+1,j+1);
			   mat[i][j] = getchar();
			   fflush(stdin);
			   system("cls");
			   
			   puts("*********Bem vindo ao CACA PALAVRAS*******");
	  	  	   puts("Agora, preencha os espacos com caracteres.");
			   putchar('\n');
	
			   for (i=0;i<L;i++){
				   for (j=0;j<C;j++)
					   printf("%c",mat[i][j]);
                   putchar('\n');
			   }
			
               j = aux_j;
			   i = aux_i;      	
		}
	}
	
	for (i = 0;i < L;i++)
		for (j = 0; j < C; j++)
			mostra[i][j] = mat[i][j];
	
	printf("\nQual a palavra que deseja procurar? "); fgets(pala,MAX,stdin);
	
	//Elimina o \n do fgets
	
	for(i=0;pala[i]!='\0';i++)
		if (pala[i] == '\n')
			pala[i] = '\0';
		
    //Ignora case sensitive
    
    for(i=0,j=0;pala[i]!='\0';i++,j++){
		while (pala[i] == ' ')
			i++;
		aux_pala[j] = pala[i];
		if (aux_pala[j] >= 'A' && aux_pala[j] <= 'Z')
			aux_pala[j] += 'a'-'A';
	}
	
	n = j; //Número de letras da palavra que está sendo procurada
	
	for (i=0;i<L;i++)
		for (j=0;j<C;j++){
			   aux_mat[i][j] = mat[i][j];
			   if (aux_mat[i][j] >= 'A' && aux_mat[i][j] <= 'Z')
			   	aux_mat[i][j] += 'a'-'A';	
		}
		
	//Contagem nas linhas
	
	for (i=0;i<L;i++)
		for (j=0;j<C;j++){
			if (aux_mat[i][j] == aux_pala[0]){
			
				cont = 1;
				for (h=1,k=j+1;h < n && k < C;h++,k++){
					   while (aux_mat[i][k] == ' ')
					   	 k++;
					   if (aux_mat[i][k] == aux_pala[h])
					   	cont++;	
				}
				if(cont == n){
					qtd_L++;	
					for (h=0,k=j;h < n;h++,k++){    //Faz a substituição
					   while (aux_mat[i][k] == ' ')
					   	 k++;
					   if (aux_mat[i][k] == aux_pala[h])
					   	mostra[i][k] = 'X';	
					}
				}
			}
			
			if (aux_mat[i][j] == aux_pala[n-1]){  //Contagem inversa
			
				cont = 1;
				for (h=n-2,k=j+1;h >= 0 && k < C;h--,k++){
					   while (aux_mat[i][k] == ' ')
					   	 k++;
					   if (aux_mat[i][k] == aux_pala[h])
					   	cont++;	
				}
				if(cont == n){
					qtd_L++;
					for (h=n-1,k=j;h >= 0;h--,k++){ //Faz a substituição
					   while (aux_mat[i][k] == ' ')
					   	 k++;
					   if (aux_mat[i][k] == aux_pala[h])
					   	mostra[i][k] = 'X';	
					}
				}
			}
			
		}
		
	 //Contagem nas colunas
	 
	 for (j=0;j<C;j++)
	 	for (i=0;i<L;i++){
		 	if (aux_mat[i][j] == aux_pala[0]){
			
				cont = 1;
				for (h=1,k=i+1;h < n && k < L;h++,k++){
					while (aux_mat[k][j] == ' ')
						 k++;
					   if (aux_mat[k][j] == aux_pala[h])
					   	cont++;	
				}
				if(cont == n){
					qtd_C++;
					for (h=0,k=i;h < n;h++,k++){  //Faz a substituição
						while (aux_mat[k][j] == ' ')
						  k++;
					   if (aux_mat[k][j] == aux_pala[h])
					   	mostra[k][j] = 'X';	
					}	
				}
			}
			
			if (aux_mat[i][j] == aux_pala[n-1]){  //Contagem inversa
			
				cont = 1;
				for (h=n-2,k=i+1;h >= 0 && k < L;h--,k++){
					while (aux_mat[k][j] == ' ')
						 k++;
					   if (aux_mat[k][j] == aux_pala[h])
					   	cont++;	
				}
				if(cont == n){
					qtd_C++;
					for (h=n-1,k=i;h >= 0;h--,k++){  //Faz a substituição
					   while (aux_mat[k][j] == ' ')
						 k++;
  	   	   	   	   	   if (aux_mat[k][j] == aux_pala[h])
			   			 mostra[k][j] = 'X';	
					}
				}
			}

		 }
		 
	//Contagem nas diagonais
	
		//Sentido da diagonal principal
			
	for (m = 0;m < L;m++)
		for (i=m ,j=0; i<L ;i++,j++){
			if (aux_mat[i][j] == aux_pala[0]){
			
				cont = 1;
				for (h=1,k=j+1,o=i+1;h < n && k < C;h++,k++,o++){
					while (aux_mat[o][k] == ' '){
						   o++; k++;	
					}
					   if (aux_mat[o][k] == aux_pala[h])
					   	cont++;
				}
				if(cont == n){
					qtd_D++;
					for (h=0,k=j,o=i;h < n;h++,k++,o++){  //Faz a substituição
						while (aux_mat[o][k] == ' '){
						   o++; k++;	
						}
					   if (aux_mat[o][k] == aux_pala[h])
					   	mostra[o][k] = 'X';
					}
				}
			}
			
			if (aux_mat[i][j] == aux_pala[n-1]){     //Contagem Inversa
			
				cont = 1;
				for (h=n-2,k=j+1,o=i+1;h >= 0 && k < C;h--,k++,o++){
					while (aux_mat[o][k] == ' '){
						   o++; k++;	
					}
					   if (aux_mat[o][k] == aux_pala[h])
					   	cont++;
				}
				if(cont == n){
					qtd_D++;
					for (h=n-1,k=j,o=i;h >= 0;h--,k++,o++){  //Faz a substituição
						while (aux_mat[o][k] == ' '){
						   o++; k++;	
						}
					   if (aux_mat[o][k] == aux_pala[h])
					   	mostra[o][k] = 'X';
					}   	
				}
			}
			
			if (i != j && aux_mat[j][i] == aux_pala[0]){
					
						cont = 1;
						for (h=1,k=j+1,o=i+1;h < n && k < C;h++,k++,o++){
							while (aux_mat[k][o] == ' '){
								k++; o++;
							}
							if (aux_mat[k][o] == aux_pala[h])
								cont++;
						}
						if (cont == n){
							qtd_D++;
							for (h=0,k=j,o=i;h < n;h++,k++,o++){  //Faz a substituição
								while (aux_mat[k][o] == ' '){
									k++; o++;
								}
								if (aux_mat[k][o] == aux_pala[h])
									mostra[k][o] = 'X';
							}	
						}
			}
			
			if (i != j && aux_mat[j][i] == aux_pala[n-1]){   //Contagem Inversa
					
						cont = 1;
						for (h=n-2,k=j+1,o=i+1;h >= 0 && k < C;h--,k++,o++){
							while (aux_mat[k][o] == ' '){
								k++; o++;
							}
							if (aux_mat[k][o] == aux_pala[h])
								cont++;
						}
						if (cont == n){
							qtd_D++;
							for (h=n-1,k=j,o=i;h >= 0;h--,k++,o++){  //Faz a substituição
								while (aux_mat[k][o] == ' '){
									k++; o++;
								}
								if (aux_mat[k][o] == aux_pala[h])
									mostra[k][o] = 'X';
							}
						}
			}
			
		}
					
					
		//Sentido da diagonal secundária
		
	for (m = 0;m < L;m++)
		for (i=m ,j=C-1; i<L ;i++,j--){
			if (aux_mat[i][j] == aux_pala[0]){
			
				cont = 1;
				for (h=1,k=j-1,o=i+1;h < n && k < C;h++,k--,o++){
					while (aux_mat[o][k] == ' '){
						k--; o++;
					}
					   if (aux_mat[o][k] == aux_pala[h])
					   	cont++;
				}
				if(cont == n){
					qtd_D++;
					for (h=0,k=j,o=i;h < n;h++,k--,o++){  //Faz a substituição
						while (aux_mat[o][k] == ' '){
							k--; o++;
						}
					   if (aux_mat[o][k] == aux_pala[h])
					   	mostra[o][k] = 'X';
					}
				}	
				
			}
			
			if (aux_mat[i][j] == aux_pala[n-1]){       //Contagem Inversa
			
				cont = 1;
				for (h=n-2,k=j-1,o=i+1;h >= 0 && k < C;h--,k--,o++){
					while (aux_mat[o][k] == ' '){
						k--; o++;
					}
					   if (aux_mat[o][k] == aux_pala[h])
					   	cont++;
				}
				if(cont == n){
					qtd_D++;
					for (h=n-2,k=j,o=i;h >= 0;h--,k--,o++){ //Faz a substituição
						while (aux_mat[o][k] == ' '){
							k--; o++;
						}
					   if (aux_mat[o][k] == aux_pala[h])
					   	mostra[o][k] = 'X';
					}	
				}
			}
			
			if(i+j != C-1 && aux_mat[i-m][j-m] == aux_pala[0]){
					
				cont = 1;
				for (h=1,k=j-1,o=i+1;h < n && k < C;h++,k--,o++){
					while (aux_mat[o-m][k-m] == ' '){
				   		k--; o++;
					}
					if (aux_mat[o-m][k-m] == aux_pala[h])
						cont++;
				}
				if (cont == n){
					qtd_D++;
					for (h=0,k=j,o=i;h < n;h++,k--,o++){   //Faz a substituição
						while (aux_mat[o-m][k-m] == ' '){
				   			k--; o++;
						}
						if (aux_mat[o-m][k-m] == aux_pala[h])
							mostra[o-m][k-m] = 'X';
					}
				}	
			}
			
			if(i+j != C-1 && aux_mat[i-m][j-m] == aux_pala[n-1]){ //Contagem Inversa
					
				cont = 1;
				for (h=n-2,k=j-1,o=i+1;h >= 0 && k < C;h--,k--,o++){
					while (aux_mat[o-m][k-m] == ' '){
				   		k--; o++;
					}
					if (aux_mat[o-m][k-m] == aux_pala[h])
						cont++;
				}
				if (cont == n){	
					qtd_D++;
					for (h=n-1,k=j,o=i;h >= 0;h--,k--,o++){   //Faz a substituição
						while (aux_mat[o-m][k-m] == ' '){
				   			k--; o++;
						}
						if (aux_mat[o-m][k-m] == aux_pala[h])
							mostra[o-m][k-m] = 'X';
					}
				}	
			}
			
		}
		
		total = qtd_L+qtd_C+qtd_D; //Total de vezes que a palavra foi encontrada
		
		if (n == 1)
			total = qtd_L; //Caso a palavra seja na verdade uma letra
		
		//Verifica se a palavra procurada é um palíndromo
		
		for (i=0,j=n-1;i<j;i++,j--)
			if (aux_pala[i] != aux_pala[j]){
				pali = 0;
				break;
			}
			else
				pali = 1;
			
		if (pali == 1 || n == 1)
			total /= 2;
	
		printf("\nA palavra %s aparece %d vez(es).\n",pala,total);
		
		putchar('\n');
		
		for (i=0;i<L;i++){
			for (j=0;j<C;j++)
				printf("%c",mostra[i][j]);
			putchar('\n');
		}	
	
	return 0;
}