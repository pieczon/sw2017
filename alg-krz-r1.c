#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //1.2.2
    //printf("Bardzo\ndługi\nnapis\n");
    
    //1.2.3
    //printf("Napis zawierający różne dziwne znaczki // \\ \\ $ & %\n");
    
    //1.2.4
    //int liczba;
    //scanf("%d",&liczba);
    //printf("Wpisana liczba: %d\n",liczba);
    
    //1.2.5
    //double wymierna;
    //scanf("%lf",&wymierna);
    //printf("Liczba wymierna: %f\n",wymierna);

    //1.2.6
    //int pierwsza, druga, trzecia;
    //scanf("%d %d %d", &pierwsza, &druga, &trzecia);
    //printf("pierwsza: %d\ndruga: %d\ntrzecia: %d\n", pierwsza, druga, trzecia);

    //1.2.7
    //int liczba;
    //scanf("%d", &liczba);
    //printf("%d\n", liczba+1);

    //1.2.8
    // int a, b, c;
    // double sr;
    // scanf("%d %d %d", &a, &b, &c);
    // sr = (double)(a+b+c)/3;
    // printf("%f\n", sr);

    //1.2.9
    // double x, y;
    // scanf("%lf", &x);
    // while(x <= 0)
    // {
    //     printf("Wpisz nieujemną liczbę: \n");
    //     scanf("%lf", &x);
    // }
    // y = sqrt(x);
    // printf("%f\n", y);

    //1.2.10
    // double x;
    // scanf("%lf", &x);
    // printf("%d\n", (int)x);

    //1.2.11
    // double x;
    // scanf("%lf", &x);
    // printf("%.2f\n", x);

    //1.2.12
    // double x;
    // scanf("%le", &x);
    // printf("%e\n", (double)x);

    //1.3.1
    // int n;
    // scanf("%d", &n);
    // if(n < 0)
    // {
    //     n = n*(-1);
    // }
    // printf("%d\n", n);

    //1.3.2
    // int a, b;
    // scanf("%d %d", &a, &b);
    // if(a >= b) 
    // {
    //     printf("%d\n", a);
    // }   
    // else
    // {
    //     printf("%d\n", b);
    // }

    //1.3.3
    // int a, b, c;
    // scanf("%d %d %d", &a, &b, &c);
    // if((a >= b)&&(a >= c)) 
    // {
    //     printf("%d\n", a);
    // }   
    // else if(b >= c)
    // {
    //     printf("%d\n", b);
    // }
    // else 
    // {
    //     printf("%d\n", c);
    // }

    //1.3.4
    // int a, b;
    // scanf("%d %d", &a, &b);
    // if(a < 0)
    // {
    //     a *= -1;
    // }
    // if(b < 0)
    // {
    //     b *= -1;
    // }
    // if(a > b)
    // {
    //     printf("%d\n", a);
    // }
    // else
    // {
    //     printf("%d\n", b);
    // }
    
    //1.3.5
    // double a, b, c, h;
    // int wybor;
    // printf("1. podaj podstawe i wysokosc\n2. podaj boki trojkata\n");
    // scanf("%d", &wybor);
    // if(wybor == 1)
    // {
    //     printf("podaj a i h\n");
    //     scanf("%lf %lf", &a, &h);
    //     printf("%f\n", (a*h)/2);
    // }
    // else 
    // {
    //     printf("podaj boki a, b, c\n");
    //     scanf("%lf %lf %lf", &a, &b, &c);
    //     double p = (a+b+c)/2;
    //     printf("%f\n", sqrt(p*(p-a)*(p-b)*(p-c)));
    // }

    //1.3.8
//     double a, b, c, p, s;
//     int wybor;

//     printf("Obliczanie pola\n1. trojkata\n2. kwadratu\n3. prostokata\n");
//     scanf("%d", &wybor);
//     switch (wybor)
//     {
// case 1: printf("podaj boki trojkata a, b, c\n");
//         scanf("%lf %lf %lf", &a, &b, &c);
//         s = (a+b+c)/2;
//         p = sqrt(s*(s-a)*(s-b)*(s-c));
//         break;
    
// case 2: printf("podaj boki kwadratu a, b\n");
//         scanf("%lf %lf", &a, &b);
//         p = a*b;
//         break;

// case 3: printf("podaj boki prostokata a, b\n");
//         scanf("%lf %lf", &a, &b);
//         p = a*b;
//     }
//     printf("Pole figury: %f\n", p);

    //1.3.9
    // double a, b, wynik;
    // int wybor;

    // printf("wybor operacji:\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n4. dzielenie\n5. pierwiastek\n");
    // scanf("%d", &wybor);

    // switch (wybor)
    // {
    //     case 1: printf("wprowadz dodawane liczby\n");
    //     scanf("%lf %lf", &a, &b);
    //     printf("wynik %f\n", wynik=a+b);
    //     break;

    //     case 2: printf("wprowadz odejmowane liczby\n");
    //     scanf("%lf %lf", &a, &b);
    //     printf("wynik %f\n", wynik=a-b);
    //     break;
        
    //     case 3: printf("wprowadz mnozone liczby\n");
    //     scanf("%lf %lf", &a, &b);
    //     printf("wynik %f\n", wynik=a*b);
    //     break;
        
    //     case 4: printf("wprowadz dzielone liczby\n");
    //     scanf("%lf %lf", &a, &b);
    //     printf("wynik %f\n", wynik=a/b);
    //     break;
        
    //     case 5: printf("wprowadz liczby do spierwiastkowania\n");
    //     scanf("%lf %lf", &a, &b);
    //     printf("wynik %f\n", wynik=a*sqrt(b));
    // }

    //1.4.1
    // int n, m;
    // scanf("%d %d", &n, &m);
    // for(int i=0; i<m; i++)
    // {
    //     printf("%d\n", n*i);
    // }

    //1.4.2
    // int n, m;
    // scanf("%d %d", &n, &m);
    // for(int i=0; i<m; i++)
    // {
    //     printf("wielokrotonosc %d\n", n*i);
    // }

    //1.4.3
    // int n, m, k;
    // scanf("%d %d %d", &n, &m, &k);
    // for(int i=m; (i>=m && i<k); i++)
    // {
    //     printf("wielokrotonosc %d\n", n*i);
    // }

    //1.4.4
    // unsigned int n, silnia=1;
    
    // scanf("%d", &n);

    // for(int i=1; i<n; ++i)
    // {
    //     silnia = (n-1)*n;
    // }
    // printf("silnia: %d\n", silnia);
    
    //1.4.5
    // unsigned int n;
    // scanf("%d", &n);
    // for(int i=0; i<=n; i++)
    // {
    //     printf("%d\n", i*i);
    // }

    //1.4.6
    // unsigned int n, parzysta, iloczyn=1;

    // printf("podaj liczbe calkowita wieksza lub rowna 4\n");
    // scanf("%d", &n);
    // if((n>2) && (n%2==0))
    // {
    //     parzysta = n;
    //     for(int i=4; i<=parzysta; i+=2)
    //     {
    //         iloczyn = iloczyn*i;
    //         printf("wynik: %d\n", iloczyn);
    //     }
    // }
    // else
    // {
    //     printf("to nie jst liczba parzysta wieksza od 2\n");
    // }

    
    



























    return 0;
}