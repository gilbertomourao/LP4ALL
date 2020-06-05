#include <stdio.h>

#define MAX 50

int main()
{
	char vet[MAX],aux[MAX];
	int i,n;
	
	printf("Insira o tamanho do vetor: "); scanf("%d", &n);
	
	for (i=0;i<n;i++){
		   
		   fflush(stdin);
		   printf("Elemento %d do vetor: ",i);
		   vet[i] = getchar();
		   
	}
	
	//Ignora case sensitive
	
	for(i=0;i<n;i++){
		aux[i] = vet[i];
		   if (aux[i] >= 'A' && aux[i] <= 'Z')
		   	aux[i] = aux[i] + 'a' - 'A'; 	
	}
	
	//
	
	for (i=0;i<n;i++)
		if (aux[i]=='a'||aux[i]=='e'||aux[i]=='i'||aux[i]=='o'||aux[i]=='u')
			vet[i] = '*';
		
	putchar('\n');	
		
	for (i=0;i<n;i++)
		printf("%c",vet[i]);	
	
	return 0;
}