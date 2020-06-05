#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM_F 1001
#define DIM_P 31

int main()
{
	int i,j,k,verdade,tam_f,tam_p,tam_t,tam_dif;
	char frase[DIM_F],aux_f[DIM_F],palavra[DIM_P],troca[DIM_P];
	
	puts("Digite a frase para analise:");
	gets(frase);
	puts("Digite a palavra a ser troca:");
	gets(palavra);
	puts("Digite a palavra que vc deseja incluir:");
	gets(troca);
	
	tam_f=strlen(frase);
	tam_p=strlen(palavra);
	tam_t=strlen(troca);
	
	tam_dif=tam_t-tam_p;
	
	for(i=0;frase[i]!='\0';i++){   //retirada de espaços e minusculas e atribuição a uma aux!//
		if(frase[i]>='a' && frase[i]<='z')  
		  aux_f[i]=frase[i]-32;
		else
		  aux_f[i]=frase[i];  
	}
	aux_f[i]= '\0'; //Coloquei para evitar bugs
	
	for(i=0,j=0;palavra[i]!='\0';i++,j++){   //retirada de espaços e minusculas na palavra//
    while(palavra[i]==' '){
    	i++;
		}
		if(palavra[i]>='a' && palavra[i]<='z')  
		  palavra[j]=palavra[i]-32;
		else
		  palavra[j]=palavra[i];    
	}
	palavra[j] = '\0'; //Coloquei para evitar bugs
	
	for(i=0,j=0;troca[i]!='\0';i++,j++){   //retirada de espaços e minusculas na troca//
		while(troca[i] ==' '){    //estava <= e não ==
    	i++;
		}
	 if(troca[i]>='a' && troca[i]<='z')  
		  troca[j]=troca[i]-32;
		else
		  troca[j]=troca[i];  
	}
	troca[j] = '\0';  //Coloquei para evitar bugs
	
  //analise da frase e busca de palavra//
  
  for(i=0;aux_f[i]!='\0';i++){

  	if(aux_f[i]==palavra[0]){
  		verdade=0;
  		for(j=i,k=0;palavra[k]!='\0';j++,k++){
  			if(aux_f[j]==palavra[k])
  			  verdade++; 
			}

			
			if(verdade==tam_p && tam_dif>0){
				
      	  	  for(j=tam_f;j>(i+tam_p-1);j--) //Note que aqui mudei o j>i para
	        	aux_f[j+tam_dif]=aux_f[j]; 			   //diminuir o trabalho da máquina
	        
			  for(k=i,j=0;troca[j]!='\0';k++,j++)
		      	  aux_f[k]=troca[j];	
		  
	       	 i+=tam_t-1;	  
			}
			
		  if(verdade==tam_p && tam_dif<0){
				
      	  for(j=i+tam_p;j <= tam_f;j++)          //Aqui mudei para <=, pois estava <
  				aux_f[j+tam_dif]=aux_f[j];
        
			for(k=i,j=0;troca[j]!='\0';k++,j++)
		      aux_f[k]=troca[j]; 	
		  
	      i+=tam_t-1;	  
			}  
		}	
	}
	printf("\n\n--------------------------------------------------\n"
	"A NOVA FRASE EH: \n\n");
	puts(aux_f);
 
   return 0;
}