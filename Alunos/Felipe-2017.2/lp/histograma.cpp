#include <stdio.h>
#include <string.h>

void conta_letras(char str[]);

main()
{
    char s[50];

    printf(":: Insira Uma String:\n");
    gets(s);

    conta_letras(s);

}

void conta_letras(char str[])
{
    int ascii[255],i=0,j=0,k=0;

    while(i<256){
        *(ascii+i)=0;
        ++i;
    }
    while(*(str+j)){
        if(*(str+j)!=' ')
            ascii[*(str+j)]++; 
        ++j;
    }
    while(k<255){
        if(*(ascii+k)>0)
            printf("\n~ '%c' = %d",k,*(ascii+k));
        ++k;
    }
}


