#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#endif

#include "../include/linp.h"

/*buffer related*/

/*========================================================================*/

static int kernelInput(const char *prompt, const char *str, void *arg, unsigned buffer_size){
	/*Read user buffered/file input and stores it in a variable*/
	
	/*
	The line while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
	is used to clean the buffer. 
	*/

	/*
	Acceptable str input types:

	%u: unsigned int
	%d: int
	%c: char
	%f: float
	%hd: short int
	%hu: unsigned short int
	%ld: long int
	%lu: unsigned long int
	%lf: double
	%lld: long long int (only for C99 or later)
	%llu: unsigned long long int (only for C99 or later)
	%Lf: long double (only for C99 or later)
	%s: string

	*/

	int ch, i = 0, flag = 1;
	char *string = (char *)arg;
	int retval = 0;

	/*prompt*/
	if (!prompt)
	{
		printf("You must provide a string as the first argument to interact with the user!\n");
		exit(EXIT_FAILURE);
	}
	/*Passed first check*/

	/*Verifies if str is a valid input type string*/
	if (str && str[0] == '%' && arg){
		/*It's valid, then continue and print prompt*/
		printf("%s", prompt);
		switch (str[1]){
			case 'u':
			{
				retval = fscanf(stdin, "%u", (unsigned int*)arg);
				while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
				flag++;
				break;
			}
			case 'd':
			{
				retval = fscanf(stdin, "%d", (int *)arg);
				while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
				flag++;	
				break;
			}
			case 'c':
			{
				retval = fscanf(stdin, "%c", (char *)arg);
				while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
				flag++;	
				break;
			}
			case 'f':
			{
				retval = fscanf(stdin, "%f", (float *)arg);
				while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
				flag++;
				break;
			}
			case 'h':
			{
				switch (str[2]){
					case 'd':
					{
						retval = fscanf(stdin, "%hd", (short int*)arg);
						while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
						flag++;	
						break;
					}
					case 'u':
					{
						retval = fscanf(stdin, "%hu", (unsigned short int*)arg);
						while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
						flag++;
						break;
					}
					default:
					{
						printf("\nFailed to read from input.\n");
						exit(EXIT_FAILURE); /*error*/
					}
				} /*str[2]*/
				flag++;	
				break;	
			}
			case 'l':
			{
				switch (str[2]){
					case 'd':
					{
						retval = fscanf(stdin, "%ld", (long int*)arg);
						while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
						flag++;
						break;
					}
					case 'u':
					{
						retval = fscanf(stdin, "%lu", (unsigned long int*)arg);
						while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
						flag++;
						break;
					}
					case 'f':
					{
						retval = fscanf(stdin, "%lf", (double*)arg);
						while( (ch = fgetc(stdin)) != EOF && ch != '\n' );	
						flag++;
						break;
					}
					#if __STDC_VERSION__ >= 199901L
					case 'l':
					{
						switch (str[3]){
							case 'd':
							{
								retval = fscanf(stdin, PRId64, (long long int*)arg);
								while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
								flag++;
								break;
							}
							case 'u':
							{
								retval = fscanf(stdin, PRIu64, (unsigned long long int*)arg);
								while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
								flag++;
								break;
							}
							default:
							{
								printf("\nFailed to read from input.\n");
								exit(EXIT_FAILURE); /*error*/
							}
						} /*str[3]*/
						flag++;
						break;	
					}
					#endif
					default:
					{
						printf("\nFailed to read from input.\n");
						exit(EXIT_FAILURE);
					}
				} /*str[2]*/
				flag++;
				break;	
			}
			#if __STDC_VERSION__ >= 199901L
			#ifndef _WIN32
			case 'L':
			{
				retval = fscanf(stdin, "%Lf", (long double*)arg);
				while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
				flag++;	
				break;
			}
			#endif
			#endif
			case 's':
			{
				/*Read characters from stdin*/
				fgets(string,buffer_size,stdin);

				while(*(string+i) && *(string+i) != '\n'){
					i++;
				}

				if (*(string+i))
					*(string+i) = '\0';
				else
					while( (ch = fgetc(stdin)) != EOF && ch != '\n' );

				flag++;
				retval = 1;
				break;
			}
			default:
			{
				printf("\nFailed to read from input.\n");
				exit(EXIT_FAILURE); /*error*/
			}
		} /*str[1]*/
	} else {
		printf("\nFailed to read from input.\n");
		exit(EXIT_FAILURE); /*error*/
	}
	/*Check if the string type is terminated*/
	if (str[flag]){
		printf("\nFailed to read from input.\n");
		exit(EXIT_FAILURE); /*error*/
	}

	return retval;
}

/*
typedef struct input_args
{
	const char *prompt;
	const char *str;
	void *arg; 
	unsigned buffer_size;
} input_args;
 */

int input(input_args args)
{
	const char *prompt = args.prompt ? args.prompt : NULL;
	const char *str = args.str ? args.str : NULL;
	void *arg = args.arg ? args.arg : NULL;
	unsigned buffer_size = args.buffer_size ? args.buffer_size : 100;

	return kernelInput(prompt, str, arg, buffer_size);
}

/*Linp_Matrix related*/

/*========================================================================*/

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