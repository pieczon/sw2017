#include <stdio.h>
#include <stdlib.h>

//1. definiuję strukturę, z dodaniem przykładowych rekordów do listy
struct studtoku
{
    int rokst, nralb;
    char *kierunek, *nazwisko
    struct studtoku *adrnast;
}studtoku;

struct studtoku sara={3, 24658, "Kosmetologia", "Dawidziuk", NULL};
struct studtoku nadia={1, 56777, "Biotechnologia", "Zalewska", NULL};

int main()
{
//2. inicjalizacja listy, tworzenie nowych obiektów listy: początek listy, elementy listy
    struct studtoku *head;
        head = malloc(sizeof(studtoku));
        head->adrnast = NULL;
    struct studtoku *kolejny;
        kolejny = malloc(sizeof(studtoku)); 
        kolejny = kolejny->adrnast = malloc(sizeof(studtoku));
        kolejny->adrnast = NULL;
        
    char bufor[30 + 1];
        kolejny->rokst = 4;
        kolejny->nralb = 25555;
        kierunek = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
        strcpy(kierunek, bufor);
    kolejny->kierunek = "Lekarski";
    nazwisko = (char*)malloc(sizeof(char)* (strlen(bufor) + 1));
    strcpy(nazwisko, bufor);
    kolejny->nazwisko = "Pokora";
//kolejny-> {4, 39727, "Stomatologia", "Przydrożna"};

//4. pokazywanie listy
    while(kolejny != NULL)
    {
        printf("Dane studentów, rok studiów: %d, numer albumu: %d, nazwa kierunku: %c, nazwisko: %c \n", kolejny->rokst, kolejny->nralb, kolejny->kierunek, kolejny->nazwisko);
        kolejny = kolejny->adrnast;
    }

    return 0;
}
