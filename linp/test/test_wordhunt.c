#include <stdio.h>
#include <string.h>
#include <linp.h>

int main()
{
	Linp_Matrix grid;
	char word[LINP_SIZE];
	int n_words;

	/*2D array*/
	lp.readmat(&grid,"txt/camomile.txt");

	lp.dispmat(&grid,"Matriz Principal");

	lp.readstr(word);

	/*Testing wordhunt*/
	n_words = lp.wordhunt(&grid,word,'@');

	lp.dispmat(&grid,"Teste wordhunt");

	printf("\nQuantidade de palavras encontradas: %d\n", n_words);

	/*1D array*/
	lp.readstr(grid.mat[0]);
	lp.readstr(word);

	/*Force 1D*/

	printf("\n\n-----Testando array 1D:\n\n");
	grid.rows = 1;
	grid.cols = strlen(grid.mat[0]);

	n_words = lp.wordhunt(&grid,word,'*');

	lp.dispmat(&grid,"New string");

	printf("\nA string %s apareceu %d vez(es).\n", word, n_words);

	return 0;
}