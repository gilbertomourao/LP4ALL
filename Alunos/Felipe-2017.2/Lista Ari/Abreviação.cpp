/*
UFMA-ENGENHARIA ELÉTRICA
Professor: Ari
Aluno: Felipe Alencar Araujo
Programa: Mostrar a abreviação do nome digitado sem contar de,da,do,das,dos,e...
Ano: 2017.2
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	int i,j;
	char nome[50],ab[50];
	puts("Digite o nome completo");
	gets(nome);
	//coloca td em minuscula
	for(i=0;nome[i]!='\0';i++){
		if(nome[i]>='A' && nome[i]<='Z'){
			nome[i]+=32;
		}
	}
	ab[0]=toupper(nome[0]);
	ab[1]='.';
	j=2;//contador começa em dois devido a posição do vetor abreviação
	for(i=0;nome[i]!='\0';i++){
		if(nome[i]==' ' && nome[i+1]!='d'&&nome[i+1]!='e'){
			ab[j]=toupper(nome[i+1]);
			ab[j+1]='.';
			j+=2;//ajuda a pular as posições após a abreviação
		}
		else{
			if((nome[i]==' ')&&(nome[i+1]=='e')&&(nome[i+2]!=' ')){
				ab[j]=toupper(nome[i+1]);
				ab[j+1]='.';
				j+=2;	
			}
			else if((nome[i]==' ')&&(nome[i+1])=='d'&&((nome[i+2]!='a')||(nome[i+2]!='o')||(nome[i+2]!='e'))&&(nome[i+3]!=' '&&(nome[i+3]!='s'&& nome[i+4]!=' '))){
				ab[j]=toupper(nome[i+1]);
				ab[j+1]='.';
				j+=2;	
			}
			else if((nome[i]==' ')&&(nome[i+1])=='d'&&((nome[i+2]=='a')||(nome[i+2]=='o')||(nome[i+2]=='e'))&&(nome[i+3]!=' '&&(nome[i+3]=='s'&& nome[i+4]!=' '))){
				ab[j]=toupper(nome[i+1]);
				ab[j+1]='.';
				j+=2;
			}
		}
	}
	ab[j]='\0';
	puts(" ");
	puts("Abreviando:");
	printf("%s",ab);
	
	return 0;
}