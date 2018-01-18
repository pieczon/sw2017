#include <stdlib.h>
#include <stdio.h>

int tab[10] = {12,3,1,55,34,78,66,90,11,8};
int temp[10];

void merge(int first, int mid, int last)
{
    //zmienne pomocnicze dla tablicy tymczasowej
    int i, j, k;
    for(i=first; i<=last; i++)
    {
        temp[i] = tab[i];
    }
    //ustawianie indeksów tablicy pomocniczej
    i=first;
    j=mid+1;
    k=first;
    //sortowanie w podzbiorach
    while(i<=mid && j<=last)
    {
        if(temp[i] < temp[j])
        {
            tab[k++]=temp[i++];
        }
        else
        {
            tab[k++]=temp[j++];
        }
    }
    while(i<=mid)
    {
        tab[k++]=temp[i++];
    }
}

void sortuj(int first, int last)
{
    int mid;
    if(first < last)
    {
        mid=(first+last)/2;
        sortuj(first, mid); //pierwsza połówka tablicy
        sortuj(mid+1, last); //druga połówka tablicy
        merge(first, mid, last); //na koniec łączenie połówek
    }
}

int main()
{
    int i;
    printf("Bez sortowania: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", tab[i]);
    }

    sortuj(0,9);

    printf("\nPo sortowaniu: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
