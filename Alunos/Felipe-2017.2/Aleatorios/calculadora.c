#include <stdio.h>
#include <stdlib.h>
main() {
 float x, y;
 char op;
 printf("\n Digite um numero depois a express�o depois o outro numero");
 scanf("%f %c %f", &x, &op, &y);
 switch( op ) {
 case '+': printf("\n valor = %.2f", x+y); break;
 case '-': printf("\n valor = %.2f", x-y); break;
 case '*': printf("\n valor = %.2f", x*y); break;
 case '/': printf("\n valor = %.2f", x/y);
 case ':': printf("\n valor = %.2f", x/y);
 default : printf("\n Operador inv�lido: %c",op);
 }
 system("pause");
} 