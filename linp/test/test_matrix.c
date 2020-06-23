#include <linp.h>
#include <stdio.h>

int main()
{
	Linp_Matrix test, test_lower, test_upper;

	lp.readmat(&test, "txt/somematrix.txt");

	lp.dispmat(&test, "Test Matrix");

	lp.copymat(&test, &test_lower);

	lp.copymat(&test, &test_upper);

	lp.tolowermat(&test_lower);

	lp.dispmat(&test_lower, "Lower Matrix");

	lp.touppermat(&test_upper);

	lp.dispmat(&test_upper, "Upper Matrix");

	printf("Now testing switch functions...\n");

	lp.switchcols(&test_lower, 0, 2);

	lp.dispmat(&test_lower, "After switch (cols 0 and 2)");

	lp.switchrows(&test_upper, 1, test_upper.rows-1);

	lp.dispmat(&test_upper, "After switch (rows 1 and last)");

	return 0;
}