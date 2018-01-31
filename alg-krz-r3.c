#include <stdio.h>
#include <stdlib.h>

//3.2.1
// int najmniejsza(int *a, int *b)
// {
//     return (*a<*b) ? *a:*b;
// }
// int main()
// {
//     int a, b;
//     printf("podaj dwie liczby \n");
//     scanf("%d %d", &a, &b);
//     printf("najmniejsza liczba: %d\n", najmniejsza(a,b));
// }

//3.2.2
// int *najmniejsza(int *a, int *b)
// {
//     if(*a<*b)
//     {
//         return a;
//     }
//     else
//     {
//         return b;
//     }
// }
// int main()
// {
//     int x, y;
//     printf("podaj dwie liczby \n");
//     scanf("%d %d", &x, &y);
//     printf("mniejsza liczba: %d\n", *najmniejsza(&x,&y));
// }

//3.2.3
// void zamien(int *a, int *b)
// {
//     int pom;
//     pom = *a;
//     *a = *b;
//     *b = pom;
// }
// int main()
// {
//     int x, y;
//     printf("podaj dwie liczby\n");
//     scanf("%d %d", &x, &y);
//     zamien(&x,&y);
//     printf("zamienione liczby: %d i %d\n", x, y);
// }

