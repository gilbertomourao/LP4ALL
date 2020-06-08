#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/linp.h"

/*buffer related*/

void linp__readstr(char *str)
{
	char *ptr = str, c;

	printf("\n~$ string: ");

	fgets(str,LINP_SIZE,stdin);

	while (*ptr && *ptr != '\n')
		ptr++;

	if (*ptr) *ptr = 0;
	else while ((c = getchar()) != '\n' && c != EOF);
}

/*Linp_Matrix related*/

void linp__readmat(Linp_Matrix *array, char *text_file)
{
	int i, j, flag, cols = 0;
	bool eol = false;
	char ch; /*to consume characters*/
	FILE *file;

	file = fopen(text_file,"r");

	if (!file)
		exit(EXIT_FAILURE);

	for (i = 0;flag!=EOF && i < LINP_SIZE;i++)
	{
		eol = false;
		for (j = 0;!eol && j < LINP_SIZE;j++)
		{
			flag = fscanf(file,"%c",*(array->mat+i)+j);

			if (!flag || flag == EOF) 
			{
				eol = true;
				break;
			}

			if (*(*(array->mat+i)+j) == '\n')
			{
				eol = true;
				j--;
			}
		}

		if (j > cols) cols = j;

		while (!eol)
		{
			fscanf(file,"%c",&ch);
			if (ch == '\n') eol = true;
		}
	}

	array->cols = cols;
	array->rows = i;

	fclose(file);

	/*some warnings*/
	if (i == LINP_SIZE || j == LINP_SIZE)
	{
		printf("\nWARNING: Reached the limit of LINP Linp_Matrix read function. ");
		printf("The Linp_Matrix on the text file may not have been properly read.\n");
	}
}

void linp__dispmat(Linp_Matrix *array, char *str)
{
	int i, j;

	printf("\n~$ %s\n\n",str);

	for (i = 0;i < array->rows;i++)
	{
		for (j = 0;j < array->cols;j++)
			printf("%c ", *(*(array->mat+i)+j));

		putchar('\n');
	}
}