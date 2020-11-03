#include <stdio.h>
#define MAX 100

void dim(int *l,int *c);
void ler(char *m,int l,int c);
void tela(char *m,int l,int c);
int selecione(int *x);
void ordenar(char *m,int l,int c);

int main(){
	char mat[MAX][MAX];
	int lin,col,sel,esc;
	dim(&lin,&col);
	ler(&mat[0][0],lin,col);
	tela(&mat[0][0],lin,col);
	if(1==selecione(&sel)){
		printf("Digite a linha que deseja ordenar:\n");
		ordenar(&mat[0][0],lin,col);
	}
	else{
		printf("Digite a coluna que deseja ordenar:\n");
	}
	tela(&mat[0][0],lin,col);
	return 0;
}

void dim(int *l,int *c){
	int a,b;
	printf("Digite a qnd de linhas e colunas, respectivamente:\n");
	scanf("%d %d",&a,&b);
	*l=a;
	*c=b;
}

void ler(char *m,int l,int c){
	int i;
	for(i=0;i<l*c;i++){
		printf("Digite a posicao %d posicao\n",i+1);
		scanf(" %c",(m+i));
	}
}

void tela(char *m,int l,int c){
	int i,j=0;
	for(i=0;i<l*c;i++){
		printf("%c",*(m+i));
		j++;
		if(j==l){
			puts(" ");//salta a posição da linha
			j=0;
		}
	}
}

int selecione(int *x){
	int a;
	printf("Digite se deseja selecionar linha[1] ou coluna[2]:");
	scanf("%d",&a);
	*x=a;
	while(*x<1 || *x>2){
		printf("tente novamente: \n");
		scanf("%d",&a);
		*x=a;
	}	
	if(*x=='1'){
		return 1;
	}
	else if(*x=='2'){
		return 0;
	}
}

void ordenar(char *m,int l,int c){
	int esc,i,j;
	char aux[MAX],aux_2;
	scanf("%d",&esc);
	for(j=0;j<l*c;j++){
		aux[i]=*(m+esc+j);
	}
	for(i=0;i<l*c;i++){
		for(j=i+1;j<l*c;j++){
			if(aux[i]>aux[j]){
				aux_2=aux[i];
				aux[i]=aux[j];
				aux[j]=aux_2;
			}
		}
	}
	for(j=0;j<l*c;j++){
		*(m+esc+j)=aux[i];
	}
}

