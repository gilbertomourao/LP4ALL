#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/linp.h"

/**
 * Function to get lowcase string
 */

static void get_lowstr(char *source, char *dest)
{
	int i, j;

	for (i = 0,j = 0;*(source+i);i++,j++)
	{
		while ( (*(source+i) < 'A' || *(source+i) > 'Z') &&
				(*(source+i) < 'a' || *(source+i) > 'z') &&
				*(source+i)) 
			{i++;}

		if (!*(source+i))
			break;

		*(dest+j) = tolower(*(source+i));
	}

	*(dest+j) = '\0';
}

/**
 * Function to get lowcase matrix
 */

static void get_lowmat(Linp_Matrix *source, char **dest)
{
	int i, j;

	for (i = 0;i < source->rows;i++)
	{
		for (j = 0;j < source->cols;j++)
		{
			dest[i][j] = tolower(source->mat[i][j]);
		}
	}
}

/**
 * Wordhunt
 */

static int huntrow(Linp_Matrix *array, char **aux_array, char *aux_word, 
				   unsigned size, const char c, int i, int j)
{
	int k;

	/*some flags to optimize the code*/
	int flag = (j+1) < array->cols;
	int flag_aux = 1, flag_inv = 1;

	/*string related*/
	int h; 
	unsigned counter = 1, inv_counter = 1;

	for (h = 1,k = j+1; aux_word[h] &&
					   (flag_aux || flag_inv) &&
					    flag;
		h++, k++)
	{
		while ((aux_array[i][k] < 'a' || aux_array[i][k] > 'z') && flag)
		{
			k++;
			flag = k < array->cols;
		}

		flag_aux = aux_array[i][k] == aux_word[h] && flag;
		flag_inv = aux_array[i][k] == aux_word[size-1-h] && flag;

		counter += flag_aux;
		inv_counter += flag_inv;

		flag = (k+1) < array->cols;
	}

	flag = !(aux_word[counter] && (inv_counter < size));

	for (h = 0,k = j;aux_word[h] && flag;h++,k++)
	{
		while (aux_array[i][k] < 'a' || aux_array[i][k] > 'z') 
			k++;

		array->mat[i][k] = c;
	}
		
	return flag;
}

static int huntcol(Linp_Matrix *array, char **aux_array, char *aux_word,
				   unsigned size, const char c, int i, int j)
{
	int k;

	/*some flags to optimize the code*/
	int flag = (i+1) < array->rows;
	int flag_aux = 1, flag_inv = 1;

	/*string related*/
	int h; 
	unsigned counter = 1, inv_counter = 1;

	for (h = 1,k = i+1; aux_word[h] &&
					   (flag_aux || flag_inv) && 
					    flag;
		h++,k++)
	{
		while ((aux_array[k][j] < 'a' || aux_array[k][j] > 'z') && flag)
		{
			k++;
			flag = k < array->rows;
		}

		flag_aux = aux_array[k][j] == aux_word[h] && flag;
		flag_inv = aux_array[k][j] == aux_word[size-1-h] && flag;

		counter += flag_aux;
		inv_counter += flag_inv;

		flag = (k+1) < array->rows;
	}

	flag = !(aux_word[counter] && (inv_counter < size));

	for (h = 0,k = i;aux_word[h] && flag;h++,k++)
	{
		while (aux_array[k][j] < 'a' || aux_array[k][j] > 'z') 
			k++;

		array->mat[k][j] = c; 
	}

	return flag;
}

static int huntdiP(Linp_Matrix *array, char **aux_array, char *aux_word,
				   unsigned size, const char c, int i, int j)
{
	int k,l;

	/*some flags to optimize the code*/
	int flag = (i+1) < array->rows && (j+1) < array->cols;
	int flag_aux = 1, flag_inv = 1;

	/*string related*/
	int h; 
	unsigned counter = 1, inv_counter = 1;

	for (h = 1,k = i+1,l = j+1; aux_word[h] && 
						       (flag_aux || flag_inv) && 
						        flag;
		h++,k++,l++)
	{
		while((aux_array[k][l] < 'a' || aux_array[k][l] > 'z') && flag)
		{
			k++; 
			l++;
			flag = k < array->rows && l < array->cols;
		}

		flag_aux = aux_array[k][l] == aux_word[h] && flag;
		flag_inv = aux_array[k][l] == aux_word[size-1-h] && flag;

		counter += flag_aux;
		inv_counter += flag_inv;

		flag = (k+1) < array->rows && (l+1) < array->cols;
	}

	flag = !(aux_word[counter] && (inv_counter < size));

	for (h=0,k=i,l=j;aux_word[h] && flag;h++,k++,l++)
	{
		while (aux_array[k][l] < 'a' || aux_array[k][l] > 'z')
		{
		   	   k++; 
		   	   l++;
		}

	   	array->mat[k][l] = c;
	}

	return flag;
}

static int huntdiS(Linp_Matrix *array, char **aux_array, char *aux_word,
				   unsigned size, const char c, int i, int j)
{ 
	int k,l;

	/*some flags to optimize the code*/
	int flag = (i+1) < array->rows && (j-1) >= 0;
	int flag_aux = 1, flag_inv = 1;

	/*string related*/
	int h; 
	unsigned counter = 1, inv_counter = 1;

	for (h = 1,k = i+1,l = j-1; aux_word[h] &&
						       (flag_aux || flag_inv) && 
						        flag;
		h++,k++,l--)
	{
		while((aux_array[k][l] < 'a' || aux_array[k][l] > 'z') && flag)
		{
			k++; 
			l--;
			flag = k < array->rows && l >= 0;
		}

		flag_aux = aux_array[k][l] == aux_word[h] && flag;
		flag_inv = aux_array[k][l] == aux_word[size-1-h] && flag;

		counter += flag_aux;
		inv_counter += flag_inv;

		flag = (k+1) < array->rows && (l-1) >= 0;
	}

	flag = !(aux_word[counter] && (inv_counter < size));

	for (h=0,k=i,l=j;aux_word[h] && flag;h++,k++,l--)
	{
		while (aux_array[k][l] < 'a' || aux_array[k][l] > 'z')
		{
		   	   k++;
		   	   l--;
		}

	   	array->mat[k][l] = c;
	}

	return flag;
}

/**
 * Top level function
 *
 * Performs the wordhunt operation on the array
 */

int wordhunt(Linp_Matrix *array, char *word, const char c)
{
	char **aux_array;
	int i, j, word_counter = 0;
	unsigned size;
	char *aux_word;

	/**
	 * Memory allocation
	 */
	
	/* 2d array */
	aux_array = malloc(array->rows * sizeof(char *));

	if (aux_array == NULL)
	{
		printf("Memory allocation failed.\n Variable: aux_array\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < array->rows; i++)
	{
		aux_array[i] = malloc(array->cols * sizeof(char));
		if (aux_array[i] == NULL)
		{
			printf("Memory allocation failed.\n Variable: aux_array[i]");
			exit(EXIT_FAILURE);
		}
	}

	/* string */
	aux_word = malloc(strlen(word) * sizeof(char));

	if (aux_word == NULL)
	{
		printf("Memory allocation failed.\n Variable: aux_word\n");
		exit(EXIT_FAILURE);
	}

	/**
	 * Main
	 */
	
	get_lowstr(word, aux_word);
	size = strlen(aux_word);
	get_lowmat(array, aux_array);

	for (i = 0;i < array->rows;i++)
	{
		for (j = 0;j < array->cols;j++)
		{
			if (aux_array[i][j] == aux_word[0] || aux_array[i][j] == aux_word[size-1])
				word_counter += huntrow(array,aux_array,aux_word,size,c,i,j) + 
								huntcol(array,aux_array,aux_word,size,c,i,j) + 
								huntdiP(array,aux_array,aux_word,size,c,i,j) +
								huntdiS(array,aux_array,aux_word,size,c,i,j);
		}
	}

	/*Free memory*/

	free(aux_word);

	for (i = 0; i < array->rows; i++)
	{
		free(aux_array[i]);
	}

	free(aux_array);

	return word_counter;
}