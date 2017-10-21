#include <stdio.h>
#define MAX 10

int x = 100, y;
char napis[] = "programowanie \n";
int tab[MAX];
int *wsk1, *wks2;
char *wksc;

int dodaj(int cel, int v)
{
cel += v;
return cel;
}


int main()
{
 wsk1 = &x;
 printf("wsk = &x | x = %d | wsk = %p | *wsk = %d \n", x, wsk1, *wsk1);
 y = dodaj(x,2);
 printf("y = %d | x = %d \n", y, x);
 return x;
}

