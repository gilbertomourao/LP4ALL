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

static PyMethodDef pylinp_methods[] = 
{
    {"cacapalavras", (PyCFunction) PyLinp_cacapalavras, METH_VARARGS | METH_KEYWORDS, cacapalavras_doc},
    
    {NULL, NULL, 0, NULL} /*Sentinel*/
};

static struct PyModuleDef pylinp_module = 
{
    PyModuleDef_HEAD_INIT,
    "pylinp", /*name of the module*/
    NULL, /*module documentation*/
    -1, /*still can't understand this*/

    pylinp_methods
};

PyMODINIT_FUNC PyInit_pylinp(void)
{
    PyObject *m;

    m = PyModule_Create(&pylinp_module);

    if (m == NULL)
        return NULL;

    PyObject *max_size = Py_BuildValue("I", MAX_SIZE);

    if (PyModule_AddObject(m, "max_size", max_size))
    {
        Py_DECREF(max_size);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}