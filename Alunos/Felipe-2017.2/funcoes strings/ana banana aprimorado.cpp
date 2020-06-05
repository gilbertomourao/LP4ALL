#include <stdio.h>
//Protótipos
int compara(char st1[],char st2[]);
int strlen(char s[]);
char toupper(char c);
void touppers(char s[]);
//Função principal
int main(){
	
	char palavra[100],frase[100];
	
	printf("\nDigite uma frase:\n");
	gets(frase);
	
	printf("Digite uma palavra:\n");
	gets(palavra);
	
	touppers(frase);touppers(palavra);
	
	printf("Aparece %d vez(es)",compara(frase,palavra));
	
	
	return 0;
}

//Funções
 
int strlen(char s[]){
	
	int i=0;
	
	while(s[i]!='\0'){i++;}
		
	return i;

}

char toupper(char c){
	
	if(c>='a'&&c<='z'){
		
		return (c-=32);
		
	}
	else{
		
		return c;
		
	}
}

void touppers(char s[]){
	
	int i;
	
	char c;
	
	for(i=0;i<strlen(s);i++){
		
		c=s[i];
		
		s[i]=toupper(c);
		
	}
}

int compara(char st1[],char st2[]){

	int i=0,cont=0,j=0;
	
	while(st1[i]!='\0'){
		
		while(st1[j]!='\0'&&st2[j]!='\0'&&st1[i+j]==st2[j]){j++;}
			
		if(st2[j]=='\0'){cont+=1;}
			
		j=0;
	
		i++;
	}
	
	return cont;
}













