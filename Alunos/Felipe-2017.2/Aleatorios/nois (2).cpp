#include <stdio.h>
#define MAX 3
void incic(int s[]){
	int i;
	for (i=0;i<MAX;i++){
		s[i]=0;
	}
}
int main(){
	
	int v[MAX],i;
	incic(v);
	for(i=0;i<MAX;i++){
		v[i]=i;
	}
	for (i=0;i<MAX;i++){
		printf("%d\n",v[i]);
	}
	
	return 0;
}