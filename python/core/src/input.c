/**
 * LINP - Biblioteca da disciplina Linguagem de Programação - EE, UFMA
 *
 * Autor: Gilberto José Guimarães de Sousa Mourão
 *
 * A biblioteca LINP tem como objetivo principal ajudar os alunos que 
 * estão cursando ou irão cursar a disciplina linguagem de programação. 
 * Aqui estão algumas funções cobradas ao longo dos anos em provas 
 * e em atividades. Sugiro que, caso não consiga desenvolver a sua 
 * própria função, utilize LINP como referência para estudar um determinado 
 * algoritmo. 
 *
 * Outra utilidade de LINP está no fato dela poder ser utilizada como 
 * comparação. As funções aqui presentes foram testadas em diversos 
 * casos e são confiáveis. É interessante ler a documentação de cada 
 * função para ter mais detalhes.
 *
 * A distribuição desta biblioteca é livre, podendo ser utilizada por 
 * qualquer pessoa, desde que seja citado o nome do autor e dos seus 
 * colaboradores. Os alunos que estão cursando a disciplina linguagem 
 * de programação e os que já foram aprovados podem contribuir com LINP 
 * desenvolvendo novas funções e/ou otimizando as já existentes. Para tal, 
 * siga as regras do github ou envie mensagem para um dos colaboradores 
 * do repositório.
 */

#include "../include/linp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#endif

/**
 * input
 *
 * Recebe dados de stdin e armazena em uma variável 
 * passada como parâmetro. Limpa o buffer em seguida. 
 */
static void linp__input(const char *prompt, const char *str, void *arg, unsigned buffer_size)
{
	/*
	A linha while( (ch = fgetc(stdin)) != EOF && ch != '\n' );
	é utilizada para limpar o buffer. 
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

	/*prompt*/
	if (!prompt)
	{
		printf("ERRO: Em input. O primeiro argumento deve ser uma string para interagir com o usuário.\n");
		exit(EXIT_FAILURE);
	}
	/*Passou na primeira verificação*/

	/*Verifica se str é uma string válida*/
	if (str && str[0] == '%' && arg)
	{
		/*É válida, então continua e imprime prompt*/
		printf("%s", prompt);
		switch (str[1])
		{
			case 'u':
			{
				flag += fscanf(stdin, "%u", (unsigned int*)arg);
				while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
				break;
			}
			case 'd':
			{
				flag += fscanf(stdin, "%d", (int *)arg);
				while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
				break;
			}
			case 'c':
			{
				flag += fscanf(stdin, "%c", (char *)arg);
				while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
				break;
			}
			case 'f':
			{
				flag += fscanf(stdin, "%f", (float *)arg);
				while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
				break;
			}
			case 'h':
			{
				switch (str[2])
				{
					case 'd':
					{
						flag += fscanf(stdin, "%hd", (short int*)arg);
						while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );	
						break;
					}
					case 'u':
					{
						flag += fscanf(stdin, "%hu", (unsigned short int*)arg);
						while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
						break;
					}
					default:
					{
						printf("\nERRO: Em input. Falha ao tentar ler stdin. Verifique se o tipo indicado esta correto.\n");
						exit(EXIT_FAILURE); /*error*/
					}
				} /*str[2]*/

				flag++;	
				break;	
			}
			case 'l':
			{
				switch (str[2])
				{
					case 'd':
					{
						flag += fscanf(stdin, "%ld", (long int*)arg);
						while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
						break;
					}
					case 'u':
					{
						flag += fscanf(stdin, "%lu", (unsigned long int*)arg);
						while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
						break;
					}
					case 'f':
					{
						flag += fscanf(stdin, "%lf", (double*)arg);
						while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
						break;
					}
					#if __STDC_VERSION__ >= 199901L
					case 'l':
					{
						switch (str[3])
						{
							case 'd':
							{
								flag += fscanf(stdin, PRId64, (long long int*)arg);
								while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
								break;
							}
							case 'u':
							{
								flag += fscanf(stdin, PRIu64, (unsigned long long int*)arg);
								while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
								break;
							}
							default:
							{
								printf("\nERRO: Em input. Falha ao tentar ler stdin. Verifique se o tipo indicado esta correto.\n");
								exit(EXIT_FAILURE); /*error*/
							}
						} /*str[3]*/

						flag++;
						break;	
					}
					#endif
					default:
					{
						printf("\nERRO: Em input. Falha ao tentar ler stdin. Verifique se o tipo indicado esta correto.\n");
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
				flag += fscanf(stdin, "%Lf", (long double*)arg);
				while( flag > 1 && (ch = fgetc(stdin)) != EOF && ch != '\n' );
				break;
			}
			#endif
			#endif
			case 's':
			{
				/*Read characters from stdin*/
				if (!fgets(string,buffer_size,stdin))
				{
					break;
				}

				while(*(string+i) && *(string+i) != '\n'){
					i++;
				}

				if (*(string+i))
					*(string+i) = '\0';
				else
					while( (ch = fgetc(stdin)) != EOF && ch != '\n' );

				flag++;
				break;
			}
			default:
			{
				printf("\nERRO: Em input. Falha ao tentar ler stdin. Verifique se o tipo indicado esta correto.\n");
				exit(EXIT_FAILURE); /*error*/
			}
		} /*str[1]*/
	}
	else 
	{
		printf("\nERRO: Em input. Argumentos invalidos. Por favor, verifique a documentacao.\n");
		exit(EXIT_FAILURE); /*error*/
	}

	/*Check if the string type is terminated*/
	if (str[flag])
	{
		printf("\nERRO: Em input. A string que indica o tipo da variavel e muito longa! Por favor, verifique a documentacao.\n");
		exit(EXIT_FAILURE); /*error*/
	}
}
