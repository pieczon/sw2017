#include <stdio.h>
#include <stdlib.h>

// 8.2.1 (r,róż) Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku, otwiera plik do tekstowego czytania i zwraca jako wartość deskryptor świeżo otwartego pliku.

FILE *otwieraj(char *sciezka)
{
    FILE *fd;
    fd = fopen(sciezka, "r");
    if(fd == NULL)
    {
        printf("*otwieraj błąd dostępu do pliku\n");
        exit(1);
    }
    printf("Deskryptor fd: %p\n", fd);
    fclose(fd);
    return fd;
}
int main()
{
    FILE *fp; //identyfikatorem pliku jest wskaźnik na strukturę typu FILE - to pewna grupa zmiennych, która przechowuje dane o pliku (np. aktualną pozycję w nim). 
    char tekst[] = "Bardzo ważne informacje zapisane w pliku";
    if((fp = fopen("argument2", "r")) == NULL) //fopen() zwraca NULL dla błędu otwierania pliku lub wskaźnik gdy się powiedzie
    //*fp - deskryptor pliku, jest podstawowym identyfikatorem pliku z zapisaną informacją czy jest tylko do odczytu czy zapisu. Nie można wykorzystać jednego deskryptora do obydwu operacji odczytu i zapisu, tworzy się niezależne deskryptory w tym celu przy pomocy funkcji fopen() z właściwym parametrem "r" lub "w", itp.
    {
        printf("Nie ma bata na ten plik, nie idzie Andrzeju\n");
        exit(1);
    }
    printf("Deskryptor fp: %p\n", fp);
    //fprintf(fp, "%s", tekst);
    fclose(fp);
    otwieraj("liczba.c");
    otwieraj("liczba.c");
    otwieraj("zadanie3.sh");
    return 0;  
}
