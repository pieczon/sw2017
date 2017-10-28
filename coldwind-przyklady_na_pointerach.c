#include <stdio.h>

int a=8;

int
main(void)
{
//int b=10;
int *p=&a;

printf("%i %i %i\n",&p,p,*p);

}
