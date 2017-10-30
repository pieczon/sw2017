#include <stdio.h>

int a=8;

int main(void)
{
//int b=10;
int *p=NULL;
p=&a;

printf("%p %p %p\n",&p,p,*p);

}
