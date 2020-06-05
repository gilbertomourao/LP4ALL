#include <stdio.h>
int exercicio(int v[],int n,int *x);
int main(){
	
	int vector[50],num,x=0,*p=&x;
	printf("Digite um numero:\n");
	scanf("%d",&num);
	printf("%d",exercicio(vector,num,p));
	return 0;
}

int exercicio(int v[],int n,int *x){
	int i=0,fator=2,tamv;
	
	while (n>1) 
	{
      while (n%fator==0)
	  {	  	  	
	  	  v[i]=n;
          n = n / fator; 
          i++;   
	  }
      fator++; 
    }
	tamv=i;
	*x=tamv;
	if(*x>10){
		return 1;
	}
	else
	{
		return 0;
	}
}