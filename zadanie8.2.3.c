#include <stdio.h>
#include <stdlib.h>

//8.2.3 (r,!) Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku tekstowego i wypisuje na standardowym wyjściu zawartość pliku z pominięciem białych znaków. Napisz dwie wersje funkcji dla znaków typów char i wchar_t.

void wypisz(char *sciezka)
{
    FILE *id = fopen(sciezka, "r");
    char c;
    printf("\n----------------------------------------------------------------\n");
    printf("Deskryptor: %p\nNazwa: %s\n", id, sciezka);
    printf("Zawartość bez spacji: \n");
    printf("----------------------------------------------------------------\n");
    while(fscanf(id,"%c", &c) == 1)
    {
        if(!isspace(c))
        {
            printf("%c", c);
        }
    }
    printf("\n");
    fclose(id);
}
int main()
{
    wypisz("liczba.c");
    wypisz("/home/pieczon/PzESW/sw2017/coldwind-przyklady_na_pointerach.c");
    return 0;
}
