#include <linp.h>

int main()
{
	Linp_Matrix test;

	lp.readmat(&test, "txt/matrix.txt");
	lp.dispmat(&test, "~Matrix: ");

	return 0;
}