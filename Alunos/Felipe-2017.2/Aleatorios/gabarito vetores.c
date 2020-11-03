#include <stdio.h>

int main(int argc, char** argv)
{
	int i,aluno;//Contadores i=gabarito,j=gabaritoaluno,aluno=aluno corrente
	int n,pontos;//n=total de alunos
	char gabarito[3],resposta[3];
	
	printf("Digite o numero de alunos:\n");
	scanf("%i",&n);
	/*Contador pra gabarito oficial
	*/
	printf("Digite o gabarito correto:\n");
	for (i=0; i<3; i++){
		scanf(" %c",&gabarito[i]);
	}
	/*Contador para o total de alunos e
	contador para as respostas dos alunos 
	*/
	for (aluno=1; aluno<=n; aluno++){
		pontos=0;
		printf("\nDigite as respostas do aluno:\n");
		for (i=0; i<3; i++){
			scanf(" %c",&resposta[i]);
			if(resposta[i] == gabarito[i]){
				pontos+=1;//Serve como operador soma pra pontuação
			}
		}
		printf("O aluno %i, fez %i pontos",aluno,pontos);
	}
	return 0;
}