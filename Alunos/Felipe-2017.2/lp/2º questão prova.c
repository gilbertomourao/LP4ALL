#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(){
	char a[MAX],b[MAX],c[MAX],aux[MAX],auxb[MAX];
	int i,j,k,vdd,ta,tb,tc,cont=0,w;
	
	puts("Digite a frase:\n");
	gets(a);
	ta=strlen(a);
	puts("Digite a palavra a ser substituida:");
	gets(b);
	tb=strlen(b);
	puts("Digite a palavra a ser posta no lugar:");
	gets(c);
	tc=strlen(c);
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='!'&&a[i]<='@'){
			for(k=i,j=0;;j++,k++){
				a[k]=' ';
			}
			i+=strlen(c)-1;
		}
	}
	printf("%s\n",a);
	//case sensitive
	for(i=0,j=0;a[i]!='\0';i++,j++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-32;
		}
	}
	for(i=0,j=0;a[i]!='\0';i++,j++){
		while(b[i]==' '){
			i++;
		}
		if(b[i]>='a'&&b[i]<='z'){
			b[j]=b[i]-32;
		}
	}
	for(i=0,j=0;c[i]!='\0';i++,j++){
		while(c[i]==' '){
			i++;
		}
		if(c[i]>='a'&&c[i]<='z'){
			c[j]=c[i]-32;
		}
	}
	//fim do case sensitive
	for(i=0;i<ta;i++){
        if(b[0]==a[i]){
        	vdd=0;
            for(j=0;j<tb;j++){
                if(b[j]==a[i+j]){
                    vdd++;
                }
            }
            if(vdd==tb){
                for(j=j-1;j>=0;j--){
                    a[i+j]='*';//cria um marcador quando achar a palavra
                }
                cont++;
            }
        }
    }
    //percorre o marcador
	k=0;
	for(i=0;a[i]!='\0';i++){
		if(a[i]!='*'){
			aux[k]=a[i];
			k++;
		}
		else{
			for(j=0;j<tc;j++){
				aux[k]=c[j];
				k++;
			}
			i+=tb-1;//incrementa o a partir do tamanho de B
		}
	}
	aux[k]='\0';
	if((cont>0)&&(ta>1)){
		puts("---------------------");
		puts("NOVA PALAVRA:");
		printf("%s\n",aux);
		puts("---------------------");
	}
	else{
		puts("A palavra não foi encontrada na frase !");
	}
	if(ta==1){
		puts("A palavra não pode ser substituida devido ao tamanho da frase !");
	}
	system("pause");
}