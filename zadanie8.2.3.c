#include <stdio.h>
#include <stdlib.h>

//8.2.3 (r,!) Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku tekstowego i wypisuje na standardowym wyjściu zawartość pliku z pominięciem białych znaków. Napisz dwie wersje funkcji dla znaków typów char i wchar_t.

int main()
{
    void wypisz(char *sciezka)
    {
        FILE *id = fopen(sciezka, "r");
        char c;
        while(fscanf(plik, "%c", &c)) ==1)
        {
            if (!isspace(c))
            {
                printf("%c", c);
            }
        }
        fclose(plik);
    }    
}
