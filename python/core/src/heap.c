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

/**
 * Pilha (Heap) com "objetos" de LINP criados durante 
 * um bloco LINP.
 */
typedef struct arrays
{
	Linp_Mat *arr_add; /* endereço do array */
	struct arrays *next; 
} Arrays;
typedef struct words
{
	Linp_Word **word_add; /* endereço do array de words */
	struct words *next;
} Words;
typedef struct linp_heap
{
	Arrays *arr;
	Words *w;
	struct linp_heap *next;
} Heap;

static Heap *heap = NULL;
static unsigned heap_count = 0;

/**
 * Todas as variáveis do tipo Linp_Mat e Linp_Word são 
 * criadas com alocação dinâmica dentro de um bloco LINP. 
 * Decidimos então criar um heap que guarda os endereços 
 * de cada região alocada dinamicamente durante um bloco. 
 * Ao invés de chamar várias funções do tipo destruir, 
 * agora é possível apenas utilizar lp.stop() para encerrar 
 * um bloco LINP. A função stop() irá liberar toda a memória 
 * alocada por funções de LINP dentro de um bloco LINP. 
 * Para iniciar um bloco LINP, basta chamar a função start(), 
 * como no exemplo abaixo.
 *
 * lp.start();
 *
 * Linp_Mat *mat = lp.criarmat(100, 100);
 *
 * lp.lerarquivo(mat, "arquivo.txt");
 * lp.dispmat(mat, "Matriz");
 *
 * lp.stop();
 *
 * É possível criar um bloco LINP dentro de outro. Ao finalizar 
 * o bloco interno, apenas a memória alocada por funções de LINP 
 * dentro dele será liberada. 
 *
 * Exemplo:
 *
 * lp.start();
 *
 * Linp_Mat *mat = lp.criarmat(100, 100);
 *
 * lp.start();
 *
 * Linp_Mat *mat2 = lp.criarmat(100, 100);
 *
 * lp.lerarquivo(mat, "arquivo.txt");
 * lp.dispmat(mat, "Matriz");
 * lp.lerarquivo(mat2, "arquivo2.txt");
 * lp.dispmat(mat2, "Matriz 2");
 *
 * lp.stop(); --> Encerra o bloco interno, liberando mat2
 *
 * lp.stop(); --> Encerra o bloco externo, liberando mat
 */

/**
 * Funções para liberar memória dinamicamente alocada
 */

/**
 * destruirmat 
 *
 * Destrói uma matriz previamente criada, liberando 
 * a memória alocada no endereço correspondente.
 */
static void linp__destruirmat(Linp_Mat *mat)
{
	unsigned i;

	for (i = 0; i < mat->rows; i++)
		free(mat->data[i]);

	free(mat->data);
	free(mat);

	mat = NULL;
}

/**
 * Destrói a lista encadeada de palavras L.
 */
static void linp__destruirlista(Linp_Word *L)
{
	Linp_Word *temp;

	while (L)
	{
		temp = L;
		L = L->next;
		free(temp->word);
		free(temp);
	}
}

/**
 * Destrói o array de listas encadeadas de palavras L.
 */
static void linp__destruirword(Linp_Word **L)
{
	unsigned i;

	for (i = 0; L[i] != NULL; i++)
	{
		linp__destruirlista(L[i]);
	}

	free(L);
	L = NULL;
}

/**
 * Inicializa um bloco LINP
 */
static void linp__start()
{
	heap_count++;

	Heap *new = malloc(sizeof(Heap));

	if (new == NULL)
	{
		printf("ERRO: Em start. Falha ao inicializar um bloco LINP. Nao foi possivel "
			   "alocar memoria para o heap.\n");
		exit(EXIT_FAILURE);
	}

	new->arr = NULL; /* Inicializa o heap arr */
	new->w = NULL; /* Inicializa o heap w */
	new->next = heap;
	heap = new;
}

/**
 * Finaliza um bloco LINP
 */
static void linp__stop()
{
	if (heap_count == 0)
	{
		printf("ERRO: Em stop. Nao e possivel parar um bloco LINP inexistente.\n");
		exit(EXIT_FAILURE);
	}

	heap_count--; /* Diminui o contador */

	/**
	 * Libera toda a memória alocada durante a execução do bloco atual
	 */
	/* arrays */
	Arrays *tempr = heap->arr;
	while (tempr && tempr->arr_add)
	{
		linp__destruirmat(tempr->arr_add);
		heap->arr = heap->arr->next;
		tempr = heap->arr;
	}
	/* words */
	Words *tempw = heap->w;
	while (tempw && tempw->word_add)
	{
		linp__destruirword(tempw->word_add);
		heap->w = heap->w->next;
		tempw = heap->w;
	}
	/**
	 * Destrói o heap atual e aponta para o próximo.
	 */
	Heap *temp = heap;
	if (temp)
	{
		heap = heap->next;
		free(temp);
	}
}