#include <stdio.h>

#define MAX 50

int main()
{
	char mat[MAX][MAX],vet[MAX],vet_aux[MAX];
	int n,i,j,num=1;
	char aux;
	
	printf("Insira as dimensoes da matriz nxn: "); scanf("%d", &n); fflush(stdin);
	
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){
			
			printf("Posicao [%d][%d]: ",i,j);
			mat[i][j] = getchar();
			fflush(stdin);
			
		}
		
	//Mostra a matriz	
	
	putchar('\n');
	puts("Matriz Resultante: ");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
			printf("%c\t",mat[i][j]);
		putchar('\n');   	
	}
		
	//	
		
	for(i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (i==j)
				vet[i] = mat[i][j];       //Obtém a diagonal principal
			
	//Ignora case sensitive
	
	for(i=0;i<n;i++){
		
		vet_aux[i] = vet[i];
		if (vet_aux[i]<='Z' && vet_aux[i]>='A')
			vet_aux[i] += 'a'-'A';
		
	}	
			
	//Ordena a diagonal principal
	
	while (num){
		
		for(i=0;i<n-1;i++)
			if(vet_aux[i] < vet_aux[i+1]){
				
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				
				aux = vet_aux[i];
				vet_aux[i] = vet_aux[i+1];
				vet_aux[i+1] = aux;
				
			}
			
		for(i=n-1;i>0;i--)
			if(vet_aux[i] > vet_aux[i-1]){
				num = 1;
				break;
			}
			else
				num = 0;
			
	}			
	
	putchar('\n');
	
	//Mostra a diagonal principal ordenada
	
	    puts("DIAGONAL PRINCIPAL ORDENADA:");
		for(i=n-1;i>=0;i--)
		printf("%c",vet[i]);
	
	
	
	return 0;
}