#include <stdio.h>
#define MAX 100
void tam(int *x);
void ler(char *m,int tam);
void tela(char *m,int tam);
void ordenar(char *m,int tam);
int main(){
	int dim;
	char mat[MAX][MAX];
	tam(&dim);
	ler(&mat[0][0],dim);
	tela(&mat[0][0],dim);
	ordenar(&mat[0][0],dim);
	tela(&mat[0][0],dim);
	return 0;
}

void tam(int *x){
	int a;
	printf("Digite a dimensao (quadrada):\n");
	scanf("%d",&a);
	*x=a;
}

void ler(char *m,int tam){
	int i;
	for(i=0;i<tam*tam;i++){
		printf("Digite a posicao %d\n",i+1);
		scanf(" %c",(m+i));
	}
}

void tela(char *m,int tam){
	int i,j=0;
	printf("MATRIZ:\n");
	for(i=0;i<tam*tam;i++){
		printf("%c",*(m+i));
		j++;
		if(j==tam){
			puts("");
			j=0;
		}
	}
}

void ordenar(char *m,int tam){
	int i,j;
	char aux;
	for(i=0;i<tam*tam;i+=(tam+1)){
		for(j=i+(tam+1);j<tam*tam;j+=(tam+1)){
			if(*(m+i)>*(m+j)){
				aux=*(m+i);
				*(m+i)=*(m+j);
				*(m+j)=aux;
			}
		}
	}	
}




























