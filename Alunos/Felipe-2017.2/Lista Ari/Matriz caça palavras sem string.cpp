/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Matriz caça palavras sem usar string
Ano: 2017.2
*/
#include <stdio.h>
int main(){
	char mat[3][3],vet,pal[0][3];//pal= uma palavra de tamanho três
	int i,j,cont,resp;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("[%d][%d]",i+1,j+1);
			scanf(" %c",&mat[i][j]);
		}
	}
	puts("");
	puts("Matriz:");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c",mat[i][j]);
		}
		puts(" ");
	}
	printf("digite 1 pra linha e 0 pra coluna");
	scanf("%d",&resp);
	while(resp<0||resp>1){
		printf("Valor invalido tente novamente:");
		scanf("%d",&resp);
	}
	printf("Digite a palavra:");
	for(i=0;i<3;i++){
		scanf(" %c",pal[i]);
	}
	cont=0;
	if(resp==1){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				   	if(mat[i][j]==pal[0][j]){cont++;}
			}
		}
	}
	else if(resp==0){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(mat[i][j]==pal[0][i]){cont++;}
			}
		}
	}
	printf("Total de vezes:\n%d",cont);
	return 0;
}