#include <stdio.h>
#include <stdlib.h>

//2.2.1
// int wartbezwzgl(double a)
// {
//     if(a>0)
//     {
//         return a;
//     }
//     else
//     {
//         return a*(-1);
//     }
// }
// int main()
// {
//     double wb, liczba;
//     printf("wprowadz liczbe\n");
//     scanf("%lf", &liczba);
//     wb = wartbezwzgl(liczba);
//     printf("wartosc bezwzgledna: %.2f\n", wb);
// }

//2.2.2
// unsigned int silnia(unsigned int s)
// {
//     int wynik=1;
//     for(int i=1; i<=s; ++i)
//     {
//         wynik = wynik*i;
//     }
//     return wynik;
// }
// int main()
// {
//     unsigned int liczba;
//     printf("podaj liczbe: ");
//     scanf("%d", &liczba);
//     printf("silnia: %d\n", silnia(liczba));

//     return 0;
// }

//2.2.3
// int najwpodzielnik(int liczba)
// {
//     int wynik;
//     for(int i=1; i<liczba; i++)
//     {
//         if(liczba%i == 0)
//         {
//             wynik = i;
//         }
//     }
//     return wynik;
// }
// int main()
// {
//     int n;
//     printf("podaj liczbe n\n");
//     scanf("%d", &n);
//     if(n>2)
//     {
//         printf("najwiekszy dzielnik: %d\n", najwpodzielnik(n));
//     }
//     else
//     {
//         printf("podano liczbe mniejsza lub rowna 2\n");
//     }
// }

