/**
 * Algoritmo que recebe um arquivo texto e 
 * pergunta ao usuário que palavras ele deseja 
 * procurar. Depois, cria um arquivo texto 
 * com as palavras destacadas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strcmp */
#include <linp.h>

#define MAX_SIZE 100

void cacapalavras(char *, char *, char (*)[]);

int main(int argc, char **argv)
{
	/**
	 * Verifica se os parâmetros passados estão corretos. 
	 * Total de parâmetros permitidos: 3 (1 + 2)
	 * 1 = nome do executável
	 * 2 = argumentos (nomes dos arquivos texto)
	 *
	 * Ex:
	 *
	 * caca_palavras caca_palavras.txt gabarito.txt
	 */
	if (argc != 3)
	{
		printf("ERRO: Quantidade de argumentos invalida! Insira dois argumentos.\n");
		exit(EXIT_FAILURE);
	}

	char (*palavras)[MAX_SIZE]; /* array de strings */

	/* Interação com o usuário */
	int qtd; /* quantidade de palavras que serão procuradas */

	lp.input("Quantas palavras deseja procurar? ", "%d", &qtd, 1);

	/* Verifica se qtd é um valor aceitável */
	while (qtd < 0)
	{
		printf("VALOR INVALIDO: A quantidade de palavras deve ser 0" 
			   " ou um inteiro positivo.\n");
		lp.input("Tente novamente: ", "%d", &qtd, 1);
	}

	/* Aloca memória para palavras */
	palavras = malloc((qtd + 1) * sizeof(char [MAX_SIZE]));
	if (palavras == NULL)
	{
		printf("ERRO: Alocacao de memoria falhou! Ver variavel palavras.\n");
		exit(EXIT_FAILURE);
	}

	printf("\nInsira a string \"-1\" se deseja voltar uma palavra.\n\n");

	/* Armazena as strings recebidas via stdin em palavras */
	int i, j;
	for (i = 0; i < qtd; i++)
	{
		lp.input("Palavra: ", "%s", palavras[i], MAX_SIZE);
		if (!strcmp(palavras[i], "-1"))
		{
			i = (i > 0) ? i - 2 : i - 1; /* para fazer a releitura da palavra */
			putchar('\n');
			for (j = 0; j <= i; j++)
			{
				printf("Palavra inserida: %s\n", palavras[j]);
			}
			putchar('\n');
		} 
		else 
		{
			putchar('\n');
			for (j = 0; j <= i; j++)
			{
				printf("Palavra inserida: %s\n", palavras[j]);
			}
			putchar('\n');
		}
	}
	palavras[i][0] = '\0'; /* Indica o fim da lista de palavras */

	/* Cria o arquivo texto com as palavras destacadas */
	cacapalavras(argv[1], argv[2], palavras);

	/**
	 * Libera a memória previamente alocada
	 */
	free(palavras);

	return 0;
}

void cacapalavras(char *src_file, char *dst_file, char (*palavras)[MAX_SIZE])
{
	lp.start(); /* Inicia um bloco LINP */

	Linp_Mat *src = lp.criarmat(MAX_SIZE, MAX_SIZE);

	lp.lerarquivo(src, src_file);

	Linp_Mat *dst = lp.criarmat(src->rows, src->cols);
	Linp_Mat *temp_dst = lp.criarmat(src->rows, src->cols);

	/* Inicializa dst */
	unsigned i, j;

	for (i = 0; i < src->rows; i++)
		for (j = 0; j < src->cols; j++)
			dst->data[i][j] = ' ';

	unsigned it = 0; /* iterador */

	while(palavras[it][0] != '\0')
	{
		/**
		 * Busca pela i-esima palavra em todas as direções permitidas 
		 * por procstr. Não ignora nenhum caractere e ignora case 
		 * sensitive. 
		 */
		lp.procstr(src, temp_dst, NULL, palavras[it], "LCPS", "", true);

		/* Destaca as ocorrências em dst */
		for (i = 0; i < src->rows; i++)
			for (j = 0; j < src->cols; j++)
				if (temp_dst->data[i][j] != (char) 250)
					dst->data[i][j] = temp_dst->data[i][j];

		/* Avança para a próxima palavra */
		++it;
	}

	/* Cria o arquivo com a localização das palavras */
	lp.criararquivo(dst, dst_file);

	/**
	 * Encerra o bloco LINP atual
	 */
	lp.stop();
}