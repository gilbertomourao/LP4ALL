/*
 __                  
|  |	          ___            
|  |  *          |   \
|  |  _   _ __   |    |
|  | | | | '_ \  |___/ 
|  | | | | | | | |
|__| |_| |_| |_| |

 */

#ifndef __LINP__H__
#define __LINP__H__

#include "linp_EXPORTS.h"

#define LINP_SIZE 100 /*Please, don't change this*/
/**
 * If you decide to change LINP_SIZE, the console functions can
 * present bad behavior. In this case, it's better to not use 
 * then. The function wordhunt is independent of this macro, but 
 * be sure that all members of Linp_Matrix are correct.
 */

LINP_EXPORT typedef struct matrix
{
	char mat[LINP_SIZE][LINP_SIZE];
	int rows;
	int cols;
} Linp_Matrix;

/*buffer related*/
LINP_EXPORT void readstr(char *);

/*matrix related*/
LINP_EXPORT void readmat(Linp_Matrix *, char *);
LINP_EXPORT void dispmat(Linp_Matrix *, char *);

/*wordhunt related*/
LINP_EXPORT int wordhunt(Linp_Matrix *, char *, const char);

#endif