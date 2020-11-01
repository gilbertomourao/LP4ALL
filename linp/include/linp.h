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
 * If you decide to change LINP_SIZE, some input functions can
 * present bad behavior. In this case, it's better to not use 
 * then. The function wordhunt is independent of this macro, but 
 * be sure that all members of Linp_Matrix are correct.
 */

typedef struct matrix
{
	char mat[LINP_SIZE][LINP_SIZE];
	int rows;
	int cols;
} Linp_Matrix;

/*buffer related*/
typedef struct input_args
{
	const char *prompt;
	const char *str;
	void *arg; 
	unsigned buffer_size;
} input_args;

LINP_EXPORT void input(input_args);

#ifndef linp_EXPORTS
#define input(...) input((input_args){__VA_ARGS__});
#endif

/*matrix related*/
LINP_EXPORT void linp__readmat(Linp_Matrix *, char *);
LINP_EXPORT void linp__dispmat(Linp_Matrix *, char *);
LINP_EXPORT void linp__copymat(Linp_Matrix *, Linp_Matrix *);
LINP_EXPORT void linp__tolowermat(Linp_Matrix *);
LINP_EXPORT void linp__touppermat(Linp_Matrix *);
LINP_EXPORT void linp__switchcols(Linp_Matrix *, unsigned, unsigned);
LINP_EXPORT void linp__switchrows(Linp_Matrix *, unsigned, unsigned);

/*wordhunt related*/
LINP_EXPORT int linp__wordhunt(Linp_Matrix *, char *, const char);
LINP_EXPORT void linp__palihunt(Linp_Matrix *, char *, char *, const char);

/**
 * Implementation of namespace lp
 *
 * You still can call the functions using "linp__name", but
 * with this implementation you can call them by lp.name
 */
static const struct
{
	/*buffer related*/

	/*matrix related*/
	void (*readmat)(Linp_Matrix *, char *);
	void (*dispmat)(Linp_Matrix *, char *);
	void (*copymat)(Linp_Matrix *, Linp_Matrix *);
	void (*tolowermat)(Linp_Matrix *);
	void (*touppermat)(Linp_Matrix *);
	void (*switchcols)(Linp_Matrix *, unsigned, unsigned);
	void (*switchrows)(Linp_Matrix *, unsigned, unsigned);

	/*wordhunt related*/
	int (*wordhunt)(Linp_Matrix *, char *, const char);
	void (*palihunt)(Linp_Matrix *, char *, char *, const char);

} lp = {

	linp__readmat,
	linp__dispmat,
	linp__copymat,
	linp__tolowermat,
	linp__touppermat,
	linp__switchcols,
	linp__switchrows,

	linp__wordhunt,
	linp__palihunt

};

#endif