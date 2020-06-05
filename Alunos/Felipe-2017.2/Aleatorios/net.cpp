#include <stdio.h>

int main()
{
	char v[5][10];
	int i;
	for(i = 0; i < 5; i++){
		scanf("%s",&v[i]);
		printf("%s\n", v[i]);
	}
	return 0;
}
