/*2ª Questão*/

#include <stdio.h>

#define MAX 50

int main(){
	
	char str_1[MAX],str_2[MAX],mostra[MAX];
	int i,j=0,k=0,tamanho=0;
	
	printf("Insira a primeira string: "); gets(str_1);
	printf("Insira a segunda string: "); gets(str_2);
	
	for (i=0;str_2[i]!= '\0';i++)
		tamanho++;	
	
	/*Análise da primeira string
	*/
		for (i=0;str_1[i]!='\0';i++){
			while (str_1[i] == ' '){
				mostra[j] = str_1[i]; 
				i++;
				j++;
			}
			mostra[j] = str_1[i];
			if (str_1[i-1] == ' ' && str_1[i+1] == '\0'){
				mostra[j+1] = '\0';
				break;
			}
			if (str_2[k] == '\0'){
				for (i = i,j=j;str_1[i] != '\0';i++,j++)
					mostra[j] = str_1[i];
				mostra[j] = '\0';
				break;
			}
			if ((i > 0 && str_1[i-1] == ' ' && str_1[i+1] != ' ' && str_1[i+1] != '\0') || (i == 0 && str_1[i+1]!=' ' && str_1[i+1]!='\0')){
				if (k == 0 && str_2[k] == ' ')
					while(str_2[k] == ' ')
						k++;
				for (j=j+1,k=k;str_2[k] != ' ' && str_2[k] != '\0';j++,k++)
						mostra[j] = str_2[k];		
				while (str_2[k] == ' ')
					k++;
			}
			while (str_1[i]!=' ' && str_1[i]!='\0')
				i++;
			mostra[j] = str_1[i-1];
			i--; j++;
			if (str_1[i+1] == '\0'){
				mostra[j] = '\0';
				break;
			}
		}	
			puts(mostra);
	
	return 0;
		
}