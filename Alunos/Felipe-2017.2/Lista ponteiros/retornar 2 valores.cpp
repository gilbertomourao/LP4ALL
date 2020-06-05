#include <stdio.h>
int recebe(int x,int y,int *s);
int main(){
	int x,a,b;
	int *soma;
	scanf("%d %d",&a,&b);
	x=recebe(a,b,soma);
	printf("%d\n",x);
	printf("%d",*soma);
	return 0;
}

int recebe(int x,int y,int *s){
	*s=x+y;
	return 1;
}


