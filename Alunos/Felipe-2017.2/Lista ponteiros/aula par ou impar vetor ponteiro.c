#include <stdio.h>
#define MAX 100

void tam(int *dim);
void ler(int *v,int tam);
void separar(int *v,int tam);
void ordenar(int *v,int tam);
void tela(int *v,int tam);

int main(){
	int vet[MAX],dim;
	tam(&dim);
	ler(&vet[0],dim);
	separar(&vet[0],dim);
	ordenar(&vet[0],dim);
	tela(&vet[0],dim);
	return 0;
}

void tam(int *t){
	int a;
	printf("Digite o tamanho do vetor:\n");
	scanf("%d",&a);
	*t=a;
}

void ler(int *v,int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("Digite o elemento %d:\n",i+1);
		scanf("%d",(v+i));
	}
}

void separar(int *v,int tam){ //joga os impares pra frente do vetor;
	int i,j,aux;
	for(i=0;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(*(v+j)%2!=0){
				aux=*(v+i);
				*(v+i)=*(v+j);
				*(v+j)=aux;   	   	
			}
		}
	}
}

void ordenar(int *v,int tam){
	int i,j,aux,cont=0;
	for(i=0;i<tam;i++){
		if(*(v+i)%2!=0){
			cont++;//qnt de impares
		}
	}
	//ordenação dos imapres
	for(i=0;i<cont;i++){
		for(j=i+1;j<cont;j++){
			if(*(v+i) > *(v+j)){
				aux=*(v+i);
				*(v+i)=*(v+j);
				*(v+j)=aux;
			}
		}
	}
	//ordenação dos pares
	for(i=cont;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(*(v+i) > *(v+j)){
				aux=*(v+i);
				*(v+i)=*(v+j);
				*(v+j)=aux;
			}
		}
	}	
	
}

void tela(int *v,int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%d\n",*(v+i));
	}
}