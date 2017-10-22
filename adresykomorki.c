#include <stdio.h>
#define MAX 10

int x = 100, y = 200;
char napis[] = "programowanie \n";
int tab[MAX]={100,102,104,106,108};
int *wsk1, *wsk2;
char *wskc;

int dodaj(int cel, int v)
{
cel += v;
return cel;
}

int main()
{
 wsk1 = &x;
 wsk2 = &y;
 //printf("wsk = &x | x = %d | wsk = %p | *wsk = %d \n", x, wsk1, *wsk1);
 //y = dodaj(x,2);
 //printf("y = %d | x = %d \n", y, x);
 
 //printf("adres x: &x = %p | wsk1 = %p \n", &x, wsk1);
 //*wsk1 = 5;
 //printf("x = %d | wsk1 = %p | *wsk1 = %d \n", x, wsk1, *wsk1);
 //wsk2 = wsk1;
 //printf("tymczasem *wsk2 = %d bo wsk2 = %p \n", *wsk2, wsk2);
 
 //++x;
 //printf("x=%d wsk1=%p *wsk1=%d wsk2=%p *wsk2=%d \n", ++x, wsk1, *wsk1, wsk2, *wsk2);
 //printf("x=%d\n",x);
 //printf("x=%d\n",++x);
 //printf("x=%d\n",x);
 //printf("x=%d\n",x++);
 //printf("x=%d\n",x); 
 //printf("Ile wyniesie x: %d %d %d\n", x=2, x=3, x=4);

 //printf("Tablice i wsaźniki ");
 //wsk2=tab;

 // for(int i=0;i<MAX;i++)
 // {
 //  printf(" %5d", tab[i]);
 //  printf("\n");
 //  printf("Elementy tablicy ze wskaźnika: *(wsk2+%d)=%d\n", i, *(wsk2+i));
 // }

 //wsk1=&tab[0];
 //wsk2=tab;
 //printf("*wsk1=%d *wsk2=%d\n", *wsk1, *wsk2); 
 //printf("++*wsk1=%d *(wsk2+3)=%d *wsk2-10=%d *++wsk1=%d\n", ++*wsk1, *(wsk2+3), *wsk2-10, *++wsk1);
 //printf("wsk2=%p (wsk2+3)=%p\n", wsk2, wsk2+3);

 //printf("Rozmiar int=%lu \n", sizeof(int));
 //printf("Rozmair pamięci wskazanej przez wsk2=%lu \n", sizeof(*wsk2));
 
 printf("napis=%p napis=%s", napis, napis);
 wskc=napis+3;
 printf("wskc=%p wskc=%s", wskc, wskc);
 
 *wskc='p';
 printf("napis=%p napis=%s", napis, napis);
 (*wskc)++;
 printf("napis=%p napis=%s", napis, napis);
return x;
}

