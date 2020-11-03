#include <stdio.h>
#define MAX 100
int main(){
	char nome[MAX][MAX];
	int i,n;
	printf("Digite quantos sobrenomes vc tem:\n");
	scanf("%i",&n);
	printf("Digite seu nome e sobrenome:\n");
	for (i=0;i<=n;i++){
		scanf("%s",&nome[i]);
	}
	for (i=0;i<=n;i++){
		printf("%s ",nome[i]);
	}
	return 0;
}