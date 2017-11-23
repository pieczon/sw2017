#include <stdio.h>
#include <stdlib.h>

// 8.2.2 (r,!) Napisz funkcję, która dostaje jako argument deskryptor do pliku tekstowego otwartego do czytania, wypisuje zawartość pliku na standardowe wyjście i zamyka plik.

FILE *otwieraj(char *sciezka)
{
    FILE *fd;
    fd = fopen(sciezka, "r");
    if(fd == NULL)
    {
        printf("*otwieraj błąd dostępu do pliku\n");
        exit(1);
    }
    printf("\n----------------------------------------------------------------\n");
    printf("Deskryptor: %p\nNazwa: %s\n", fd, sciezka);
    return fd;
}
void wypisz(FILE *id)
{
    char c;
    printf("Zawartość: \n");
    printf("----------------------------------------------------------------\n");
    while(fscanf(id,"%c", &c) == 1)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(id);
}
int main()
{
    wypisz(otwieraj("liczba.c"));
    wypisz(otwieraj("/home/pieczon/PzESW/sw2017/coldwind-przyklady_na_pointerach.c"));
    return 0;
}
