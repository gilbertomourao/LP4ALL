#include <stdio.h>
#define MAX 100

int main(int argc, char** argv)
{
	int n,i,face[MAX],a,b,c,d,e,f;
	a=0;
	b=0;
	c=0;
	d=0;
	e=0;
	f=0;
	printf("Digite o numero de lancamentos do dado:\n");
	scanf("%i",&n);
	
	printf("Digite as faces obtidas:\n");
	for (i=0; i<n; i++){
		scanf("%i",&face[i]);
		switch(face[i]){
		case 1:
			a+=1;
			break;
		case 2:
			b+=1;
			break;
		case 3:
			c+=1;
			break;
		case 4:
			d+=1;
			break;
		case 5:
			e+=1;
			break;
		case 6:
			f+=1;
			break;
		}
	}
	
	printf("A face 1 caiu %i vezes\n",a);
	printf("A face 2 caiu %i vezes\n",b);
	printf("A face 3 caiu %i vezes\n",c);
	printf("A face 4 caiu %i vezes\n",d);
	printf("A face 5 caiu %i vezes\n",e);
	printf("A face 6 caiu %i vezes\n",f);
	return 0;
}