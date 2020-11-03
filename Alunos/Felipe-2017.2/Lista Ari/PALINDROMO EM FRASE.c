#include <stdio.h>
#include <string.h>

int main(){
	
	char string[100];
	int i,j,k,w,vdd,cont=0;
	
	puts("Digite a string:");
	gets(string);
	//ignora os espaços
	for (i=0,j=0;string[i]!='\0';i++,j++) {
		if (string[j]==' ')
			j++;	
		string[i]=string[j];
	}
	//ignora o case sensitive
	for(i=0;string[i]!='\0';i++){
		if(string[i]>='a'&&string[i]<='z'){
			string[i]-=32;
		}
	}
	//logica de busca dos palindromos
	for(i=0;string[i]!='\0';i++){
		for(j=i+1;string[j]!='\0';j++){
			for(k=i,w=j;k<w;k++,w--){
				if(string[k]==string[w]){
					vdd=1;
				}
				else{
					vdd=0;
					break;
				}
			}
			if(vdd==1){
				cont++;
			}
		}
	}
	printf("%d\n",cont);
	return 0;
}