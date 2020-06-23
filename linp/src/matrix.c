#include <stdio.h>
#include <stdlib.h>

#include "../include/linp.h"

void linp__copymat(Linp_Matrix *src, Linp_Matrix *dst)
{
	int i, j;

	for (i = 0; i < src->rows; i++)
	{
		for (j = 0; j < src->cols; j++)
		{
			dst->mat[i][j] = src->mat[i][j];
		}
	}

	dst->rows = src->rows;
	dst->cols = src->cols;
}

void linp__tolowermat(Linp_Matrix *src)
{
	int i, j;

	for (i = 0; i < src->rows; i++)
	{
		for (j = 0; j < src->cols; j++)
		{
			if (src->mat[i][j] >= 'A' && src->mat[i][j] <= 'Z')
				src->mat[i][j] += 'a' - 'A';
		}
	}
}

void linp__touppermat(Linp_Matrix *src)
{
	int i,j;

	for (i = 0; i < src->rows; i++)
	{
		for (j = 0; j < src->cols; j++)
		{
			if (src->mat[i][j] >= 'a' && src->mat[i][j] <= 'z')
				src->mat[i][j] += 'A' - 'a';
		}
	}	
}

void linp__switchcols(Linp_Matrix *src, unsigned col_1, unsigned col_2)
{
	char aux;
	int i;

	/*Check if the arguments are ok*/
	if (col_1 >= src->cols || col_2 >= src->cols)
	{
		printf("WARNING: Wrong column indices specified. No operation will be executed.\n");
		return;
	}

	for (i = 0; i < src->rows; i++)
	{
		aux = src->mat[i][col_1];
		src->mat[i][col_1] = src->mat[i][col_2];
		src->mat[i][col_2] = aux;
	}
}

void linp__switchrows(Linp_Matrix *src, unsigned row_1, unsigned row_2)
{
	char aux;
	int j;

	/*Check if the arguments are ok*/
	if (row_1 >= src->rows || row_2 >= src->rows)
	{
		printf("WARNING: Wrong row indices specified. No operation will be executed.\n");
		return;
	}

	for (j = 0; j < src->cols; j++)
	{
		aux = src->mat[row_1][j];
		src->mat[row_1][j] = src->mat[row_2][j];
		src->mat[row_2][j] = aux;
	}
}