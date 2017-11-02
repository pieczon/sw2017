#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. definiuję strukturę, z dodaniem przykładowych rekordów do listy
struct studtoku
{
    int rokst, nralb;
    char *kierunek, *nazwisko;
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
        kolejny->adrnast = &sara;
        
    //char bufor[30 + 1];
        kolejny->rokst = 4;
        kolejny->nralb = 25555;
        kolejny->kierunek = (char*)malloc(sizeof(char) * (strlen("Lekarski") + 1));
        strcpy(kolejny->kierunek, "Lekarski");
        //strcpy(kierunek, bufor);     
        kolejny->nazwisko = (char*)malloc(sizeof(char) * (strlen("Pokora") + 1));
        strcpy(kolejny->nazwisko, "Pokora");
        //strcpy(nazwisko, bufor);
        sara.adrnast = &nadia;
        
//4. pokazywanie listy
    struct studtoku *tmp = NULL;
    tmp=kolejny;

    while(tmp != NULL)
    {
        printf("Dane studentów, rok studiów: %d, numer albumu: %d, nazwa kierunku: %s, nazwisko: %s \n", tmp->rokst, tmp->nralb, tmp->kierunek, tmp->nazwisko);
        tmp = tmp->adrnast;
    }

    printf("Nazwisko Pokora?: %s\n", kolejny->nazwisko);
    return 0;
}