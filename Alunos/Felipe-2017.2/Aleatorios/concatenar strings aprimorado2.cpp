#include <stdio.h>
//Função para concatenar strings
int concatenar(char string1[],int t1,char string2[],int t2,char string3[]){
	int i,j;
	for (i=0;i<t1;i++){
		string3[i]=string1[i];
	}
	for (j=0;j<t2;j++){
		string3[j+t1]=string2[j];
	}
}
int main(){
     int i,t1,t2,t3;
     printf("Digite a qnt de caracteres da primeira palavra,segunda e da resultante:\n");
	 scanf("%i",&t1);
	 scanf("%i",&t2);
	 scanf("%i",&t3);  
	 char p1[t1];
	 char p2[t2];
	 char p3[t3];
	 printf("Digite uma palavra:\n");
	 scanf("%s",&p1);
	 printf("Digite uma palavra:\n");
	 scanf("%s",&p2);
	 concatenar(p1,t1,p2,t2,p3);
	 printf("JUNTANDO:");
	 for (i=0;i<t3;i++){
		 printf("%c",p3[i]);
	 }
	return 0;
}
//pra colocar espaço entre as duas palavras temos q inserir um caractere a mais
// tipo 'o''i''_' na vez de dois caracteres, colocamos três