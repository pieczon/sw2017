#include <stdio.h>
#include <stdlib.h>

//8.2.4 (r) Napisz funkcję, która dostaje jako argumenty ścieżkę dostępu do pliku tekstowego oraz znak c i zwraca jako wartość liczbę wystąpień znaku c w podanym w argumencie pliku. Napisz dwie wersje funkcji dla znaków typów char i wchar_t.

int lwystapien(char *sciezka, char c)
{
    FILE *fd = fopen(sciezka, "r");
    int licznik = 0;
    char znak;
    if(fd == NULL)
    {
        printf("Nie da się otworzyć pliku\n");
    }
    while(fscanf(fd, "%c", &znak) == 1)
    {
        if(c == znak)
        {
            licznik++;
        }
    }
    fclose(fd);
    return licznik;
}
int main()
{
    printf("Liczba wystąpień: %d\n", lwystapien("liczba.c", 'p'));
}
