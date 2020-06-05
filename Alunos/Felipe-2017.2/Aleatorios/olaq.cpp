#include <stdio.h>
int main(int argc, char** argv)
{
	int i,nota[5];
	for(i=1; i<=4; i++){
		printf("Digite sua %i nota:\n",i);
		scanf("i%",&nota[i]);
	}
	return 0;
}
