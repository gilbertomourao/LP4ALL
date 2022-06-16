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

#include "pylinp.h"

/**
 * C-function: cacapalavras
 */
static void cacapalavras(char *src_file, char *dst_file, char **palavras, 
                         char *dir, char *ignch, bool igncs, char subs_ch)
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
            dst->data[i][j] = subs_ch;

    unsigned it = 0; /* iterador */

    while(palavras[it])
    {
        /**
         * Busca pela i-esima palavra.
         */
        lp.procstr(src, temp_dst, NULL, palavras[it], dir, ignch, igncs);

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

/**
 * Função que verifica se palavras é uma lista 
 * de strings.
 */
static int ArgCheck_Palavras(PyObject *lista)
{
    /* Verifica se o ponteiro é válido */
    if (lista == NULL)
        return 0;

    /* Verifica se o objeto é uma lista */
    if (!PyList_CheckExact(lista))
        return 0;

    /* Verifica se todos os itens da lista são strings */
    Py_ssize_t list_size = PyList_Size(lista); /* tamanho da lista */
    Py_ssize_t i; /* iterador */

    /* Verifica se é uma lista vazia */
    if (list_size < 1)
        return 0;

    for (i = 0; i < list_size; i++)
    {
        PyObject *temp = PyList_GetItem(lista, i); /*borrowed reference to returned value*/
        
        if (strcmp(temp->ob_type->tp_name, "str"))
        {
            return 0;
        }

        /*just to guarantee*/
        if (PyErr_Occurred())
            return 0;
    }

    return 1;
}

/**
 * Função que cria o vetor de strings com base
 * na lista de strings passada para o argumento 
 * palavras.
 */
static char **palavras_as_strings(PyObject *lista_de_palavras)
{
    /* Obtém o tamanho da lista de palavras */
    Py_ssize_t list_size = PyList_Size(lista_de_palavras);

    /* Aloca memória para palavras */
    char **palavras = malloc(list_size*sizeof(char *) + 1); /* +1 representa o NULL */

    if (palavras == NULL)
    {
        return NULL;
    }

    Py_ssize_t i; /* iterador */

    /* Aponta para a string correspondente */
    for (i = 0; i < list_size; i++)
    {
        PyObject *temp = PyList_GetItem(lista_de_palavras, i); /*borrowed reference to returned value*/

        PyObject *encodedString = PyUnicode_AsEncodedString(temp, "UTF-8", "strict");
        /* retorna NULL em caso de falha */

        if (encodedString)
        {
            char *str_from_python = PyBytes_AsString(encodedString); /*  The pointer refers to the internal buffer of temp */
            
            /* gets the string len */
            unsigned pystr_len = strlen(str_from_python);

            palavras[i] = malloc(pystr_len * sizeof(char));

            if (palavras[i] == NULL)
            {
                Py_DECREF(encodedString); /* DECREF before living */
                return NULL;
            }

            strcpy(palavras[i], str_from_python);
            Py_DECREF(encodedString);
        }
    }

    palavras[list_size] = NULL; /* Encerra a lista de palavras */

    return palavras;
}

/*****************************************************************************
 * 
 *                          Top level function
 * 
 *****************************************************************************
 */
PyObject *PyLinp_cacapalavras(PyObject *self, PyObject *args, PyObject *kwargs)
{
    /* Argumentos esperados */
    char *src_file = NULL;
    char *dst_file = NULL;
    PyObject *lista_de_palavras = NULL; /* Lista de palavras */
    char *mode = "LCPS"; /* modo de busca. Ex: LCPS */
    char *ign_chars = ""; /* caracteres a serem ignorados */
    PyObject *py_ign_cs;
    bool ign_cs = false; /* flag para ignorar case sensitive */
    char *subs_ch_str = " ";

    /* Valores a serem retornados */
    /* Não retorna valor algum. */

    static char *kwlist[] = {"src", "dst", "palavras", "dir", "ignch", "igncs", "ch", NULL};

    /* $ : indica que todos os argumentos depois dele são keyword only */
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|$ssOssO!s", kwlist, &src_file, &dst_file, &lista_de_palavras, &mode, &ign_chars, &PyBool_Type, &py_ign_cs, &subs_ch_str))
    {
        char *error = "cacapalavras: falha na analise dos argumentos.\n"
                      "A função aceita somente argumentos com a keyword especificada.\n"
                      "Argumentos da função:\n"
                      "\n"
                      "src: string contendo o caminho para o arquivo texto de referência.\n"
                      "dst: string contendo o caminho para o arquivo texto de destino.\n"
                      "palavras: lista de palavras que serão procuradas em src.\n"
                      "dir: direção da procura. Ver o atributo __doc__ para mais informações.\n"
                      "\tvalor padrão: LCPS\n"
                      "ignch: string contendo os caracteres a serem ignorados.\n"
                      "\tvalor padrão: \"\"\n"
                      "igncs: True ou False. Indica se cacapalavras deve considerar letras maiúsculas e minúsculas como iguais ou diferentes.\n"
                      "\tvalor padrão: False\n"
                      "ch: Caractere que substitui todos os outros que não aparecem nas correspondências.\n"
                      "\tvalor padrão: ' '\n"
                      "\n";
        PyErr_SetString(PyExc_TypeError, error);
        return NULL;
    }

    if (py_ign_cs)
    {
        ign_cs = PyObject_IsTrue(py_ign_cs);
    }

    /* Verifica se os argumentos src e dst foram passados */
    if (src_file == NULL || dst_file == NULL)
    {
        PyErr_SetString(PyExc_TypeError, "Os argumentos src e dst devem ser strings e são obrigatórios.");
        return NULL;
    }

    /* Verifica se o argumento palavras está correto */
    /* palavras deve ser uma lista de strings */
    if (!ArgCheck_Palavras(lista_de_palavras))
    {
        PyErr_SetString(PyExc_TypeError, "O argumento palavras deve ser uma lista de strings.");
        return NULL;
    }

    /* Verifica se subs_ch é um caractere (string de 1 char no python) */
    if (strlen(subs_ch_str) != 1)
    {
        PyErr_SetString(PyExc_TypeError, "O argumento ch deve ser um caractere.");
        return NULL;
    }

    /* Armazena o caractere em uma variável char para interagir com cacapalavras */
    char subs_ch = subs_ch_str[0];

    /* Tudo ok, cria o vetor de strings */
    char **palavras = palavras_as_strings(lista_de_palavras);

    if (palavras == NULL)
    {
        PyErr_SetString(PyExc_TypeError, "Erro inesperado na construção do argumento char **palavras.");
        return NULL;
    }

    /* Chama a função original em C */
    cacapalavras(src_file, dst_file, palavras, mode, ign_chars, ign_cs, subs_ch);

    /* Limpa a memória previamente alocada */
    int i = 0;
    while (palavras[i])
    {
        free(palavras[i]);
        i++;
    }
    free(palavras);

    /* A função retorna None */
    Py_RETURN_NONE;
}