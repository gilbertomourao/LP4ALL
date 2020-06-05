#include <stdio.h> 

#define MAX 50

int main()
{	
	int vet[MAX];
	int n,i,aux,num;
	
	printf("Digite o tamanho do vetor: "); scanf("%d", &n); fflush(stdin);
	
	for (i=0;i<n;i++){
		
		printf("Posicao %d: ",i);
		scanf("%d", &vet[i]);
		
	}	
	
	putchar('\n');
	
	for (i=n-1;i>=0;i--)
		printf("%d",vet[i]);
	
	num = 1;
	
	while (num){
		
		for(i=0;i<n-1;i++)
			if(vet[i] < vet[i+1]){
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
			
		for(i=n-1;i>0;i--)
			if(vet[i] > vet[i-1]){
				num = 1;
				break;
			}
			else
				num = 0;
			
	}
	
	putchar('\n');
	
	//ordem decrescente
	puts("---ORDEM DECRESCENTE---");
	for(i=0;i<n;i++)
		printf("%d",vet[i]);
	
	putchar('\n');
	
	//ordem crescente	
	puts("---ORDEM CRESCENTE---");
	for(i=n-1;i>=0;i--)
		printf("%d",vet[i]);	
	
	return 0;	
}