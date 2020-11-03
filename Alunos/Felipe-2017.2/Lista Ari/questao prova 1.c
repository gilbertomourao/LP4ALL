#include <stdio.h>
#include <string.h>
#define MAX 300
int main(){
	
	char palavra[MAX],min[MAX],num[MAX],final[MAX],aux;
	int i,j,k,t1,t2;
	
	puts("Digite a string:");
	gets(palavra);
	for(i=0,k=0;palavra[i]!='\0';i++){
		if(palavra[i]>='A'&&palavra[i]<='Z'){
			final[k]=palavra[i];
			k++;
		}
	}
	t1=k;
	for(i=0,k=0;palavra[i]!='\0';i++){
		if(palavra[i]>='a'&&palavra[i]<='z'){
			min[k]=palavra[i];
			k++;
		}
	}
	min[k]='\0';
	for(i=0;min[i]!='\0';i++){
		for(j=i+1;min[j]!='\0';j++){
			if(min[i]>min[j]){
				aux=min[i];
				min[i]=min[j];
				min[j]=aux;
			}
		}
	}
	for(i=t1,j=0;min[j]!='\0';i++,j++){
		final[i]=min[j];
	}
	t2=i;
	for(i=0,k=0;palavra[i]!='\0';i++){
		if(palavra[i]>='1'&&palavra[i]<='9'){
			num[k]=palavra[i];
			k++;
		}
	}
	num[k]='\0';
	for(i=0;num[i]!='\0';i++){
		for(j=i+1;num[j]!='\0';j++){
			if(num[i]>num[j]){
				aux=num[i];
				num[i]=num[j];
				num[j]=aux;
			}
		}
	}
	for(i=t2,j=0;num[j]!='\0';i++,j++){
		final[i]=num[j];
	}
	final[i]='\0';
	printf("%s",final);
	return 0;
}