#include <stdio.h>
#define MAX 100 //quantidade máxima de elementos do vetor
int main(){
	int q,i,n,k,numeros[MAX];
	//Inicio da sequencia 
	printf("Digite o tamanho do vetor:\n");
	scanf("%i",&n);
	for (i=0;i<n;i++){
		printf("Digite o %i termo sequencia:\n",i+1);
		scanf("%i",&numeros[i]);
	}
	//Final do codigo pra sequencia 
	//Pegunta ao usuario o numero q será buscado na sequencia 
	printf("Digite um numero pra saber se esta na sequencia:\n");
	scanf("%i",&k);
	q=0;//Contador para a quantidade de chaves 
	for (i=0;i<=n;i++){
		if (k==numeros[i]){
			q+=1;//somatório do total de chaves 
			printf("A chave %i esta na posicao: %i\n",k,i+1);
		}
	}
	//Estruturas condicionais para a totalização de chaves
	if (q>0){
		printf("O total de chaves e': %i\n\a",q);
	}
	else{
	
		printf("Nao existe esse numero na sequencia\n\a");		
	}
	return 0;
}

