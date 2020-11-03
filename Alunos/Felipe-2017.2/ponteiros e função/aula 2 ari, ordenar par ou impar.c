#include <stdio.h>
#define MAX 100
void ler(int v[],int tam);
void tam(int *dim);
void separar(int v[],int tam);
void ordenar(int v[],int tam);
void tela(int v[],int tam);
int main(){
	
	int vet[100],dim;
	tam(&dim);
	ler(vet,dim);
	separar(vet,dim);
	ordenar(vet,dim);
	tela(vet,dim);
	
	return 0;
}
void tam(int *dim){
	int a;
	printf("Digite a dimensao do vetor:\n");
	scanf("%d",&a);
	*dim=a;
}
void ler(int v[],int tam){
	int i,j;
	for(i=0;i<tam;i++){
		printf("Digite a posicao [%d]",i+1);
		scanf("%d",&v[i]);
	}
}
/*
Ao separar, os valores impares serão jogados nas primeiras posições 
*/
void separar(int v[],int tam){
	int i,j,aux;
	for(i=0;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(v[j]%2!=0){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
}
void ordenar(int v[],int tam){
	int i,j,aux,cont=0;\
	for(i=0;i<tam;i++){
		if(v[i]%2!=0){
			cont++;/*conta a qnt de impares pra ser usado na ordenação*/
		}
	}
	/*ordenação dos impares*/
	for(i=0;i<cont;i++){
		for(j=i+1;j<cont;j++){
			if(v[i]>v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;	
			}
		}
	}
	/*ordenação dos pares*/
	for(i=cont;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(v[i]>v[j]){
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;	
			}
		}
	}
}
void tela(int v[],int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%d",v[i]);
	}
}








