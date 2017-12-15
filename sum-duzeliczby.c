#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 250

int main(int argc, char* argv[])
{
    unsigned char lpierwsza[L] = {'0'};
    unsigned char ldruga[L] = {'0'};
    unsigned char suma[L+1] = {0};
    int dodaj = 0;
    int wstawzero = 0;
    int i = 0;
    int n = 0;
    int jestcyfra = 1;
    int dziesiatki = 0;

    printf("\nSumowanie 2 liczb maksymalnie %d-cyfrowych\n", L);
    printf("Wpisz 1 liczbę: ");
    scanf("%s", lpierwsza);
    printf("Wpisz 2 liczbę: ");
    scanf("%s", ldruga);

    while(jestcyfra == 1)
    {
        if(lpierwsza[i] != 0)
        {
            i++;
        }
        else
        {
            jestcyfra--;
        }
    }
    wstawzero = L-i;
    memmove(lpierwsza+wstawzero, lpierwsza, i);
    memset(lpierwsza, 0, wstawzero);   
    
    jestcyfra = 1;
    i = 0;
    wstawzero = 0;
    while(jestcyfra == 1)
    {
        if(ldruga[i] != 0)
        {
            i++;
        }
        else
        {
            jestcyfra--;
        }
    }
    wstawzero = L-i;
    memmove(ldruga+wstawzero, ldruga, i);
    memset(ldruga, 0, wstawzero); 

    for(n=L-1; n>=0; n--)
    {
        if((lpierwsza[n]!=0) || (ldruga[n]!=0))
        {
            if((lpierwsza[n]!=0) && (ldruga[n]!=0))
            {
                dodaj = 0;
                dodaj = dodaj + dziesiatki;
                dodaj += (lpierwsza[n] - '0') + (ldruga[n] - '0');
                dziesiatki = dodaj/10;
                suma[n+1] = dodaj%10 + '0';
            }
            else
            {
                dodaj = 0;
                dodaj = dodaj + dziesiatki;
                dodaj += (lpierwsza[n] - '0') + ldruga[n];
                dziesiatki = dodaj/10;
                suma[n+1] = dodaj%10 + '0';
            }
        }
        if ((lpierwsza[n] == 0) && (ldruga[n] == 0) && (dziesiatki == 1))
        {
            suma[n+1] = 1 + '0';
            dziesiatki = 0;
        }
    }

    jestcyfra = 1;
    i = L-1;
    while(jestcyfra == 1)
    {
          if(suma[i] != 0)
        {
            i--;
        }
        else
        {
            jestcyfra--;
        }
    }
    memmove(suma, suma+i+1, L-i);
    memset(suma+(L-i), 0, i+1);

    printf("Suma: %s\n", suma);
    return 0;
}
