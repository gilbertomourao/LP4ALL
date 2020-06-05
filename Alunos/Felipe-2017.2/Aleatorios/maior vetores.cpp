#include <stdio.h>

int main(){
	int i,vet[5],maior,menor,q,k;//onde k e q são contadores pra posição dos elementos 
	printf("Digite o valor na posicao 1:\n");
	scanf("%d",&vet[0]);
	maior=vet[0];
	menor=vet[0];
	q=1;
	k=1;
	for (i=1;i<5;i++){
		printf("Digite o valor na posicao %d:\n",i+1);
		scanf("%d",&vet[i]);
		if (maior<vet[i]){
			maior=vet[i];
			q=i+1;
		}
		if (menor>vet[i]){
			menor=vet[i];
			k=i+1;
		}
	}
	printf("O maior e: %d na posicao:%d\n",maior,q);
	printf("O menor e: %d na posicao:%d\n",menor,k);
	return 0;
}
