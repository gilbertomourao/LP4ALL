//1ª questão

#include <stdio.h>

#define MAX 50

int main(){
	
	char str[MAX], aux;
	int i,j,inicio;
	
	printf("Insira uma string: "); gets(str);
	
	//String organizada	
	
	for (i=0;str[i]!='\0';i++){
		for (j=i+1;str[j]!='\0';j++)
				if ((str[j] >= 'A' && str[j] <= 'Z') && (str[i] < 'A' || str[i] > 'Z' )){
					aux = str[j];
					str[j] = str[i];
					str[i] = aux;
				}
	}		
	
	for (i = 0; str[i]!='\0';i++)
		if (str[i] < 'A' || str[i] > 'Z')
			break;
		
	inicio = i;	
	
	for (i=inicio;str[i]!='\0';i++){        /*Ordena as letras*/
	        while (str[i] >= '0' && str[i] <= '9' && str[i] !='\0')
				i++;
			if (str[i] == '\0') break;
			for (j = i+1; str[j]!='\0';j++){
				while (str[j] >= '0' && str[j] <= '9' && str[j] !='\0')
					j++;
				if (str[j] == '\0') break;
					if (str[i] > str[j]){
						aux = str[i];
						str[i] = str[j];
						str[j] = aux;
					}
			}
	}		
					
	//Organiza a string final
	
	for (i=inicio;str[i]!='\0';i++){
		for (j=i+1;str[j]!='\0';j++)
				if ((str[j] >= 'a' && str[j] <= 'z') && (str[i] < 'a' || str[i] > 'z' )){
					aux = str[j];
					str[j] = str[i];
					str[i] = aux;
				}
	}		
	
	for (i = 0; str[i]!='\0';i++)
		if (str[i] >= '0' && str[i] <= '9')
			break;	
		
	inicio = i;
	
	for (i = inicio;str[i]!='\0';i++)
		for (j = i+1;str[j]!='\0';j++)
			if (str[i] > str[j]){
				aux = str[i];
				str[i] = str[j];
				str[j] = aux;
			}		
			
	for (i=0;str[i]!='\0';i++)
		for (j = i+1;str[j]!='\0';j++)
			if (str[i] == ' '){
				aux = str[i];
				str[i] = str[j];
				str[j] = aux;
			}	
	
	for (i=0;str[i]!='\0';i++)
		if (str[i] == ' '){
			str[i] = '\0';
			break;
		} 		
			
	printf("\nString ordenada: %s\n",str);	
			
	return 0;
}