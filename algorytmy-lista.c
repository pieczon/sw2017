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
//2. inicjalizacja listy, tworzenie nowych obiektów listy: początek listy i kolejne elementy listy
    struct studtoku *head;
        head = malloc(sizeof(studtoku));
        head->adrnast = NULL;

    struct studtoku *kolejny;
        kolejny = malloc(sizeof(studtoku)); 
        kolejny = kolejny->adrnast = malloc(sizeof(studtoku));
        kolejny->adrnast = &sara;
        
        kolejny->rokst = 4;
        kolejny->nralb = 25555;
        kolejny->kierunek = (char*)malloc(sizeof(char) * (strlen("Lekarski") + 1));
        strcpy(kolejny->kierunek, "Lekarski");     
        kolejny->nazwisko = (char*)malloc(sizeof(char) * (strlen("Pokora") + 1));
        strcpy(kolejny->nazwisko, "Pokora");

        sara.adrnast = &nadia;

    struct studtoku ania={5, 34899, "Zdrowie publiczne", "Kloczkowska", NULL};
    nadia.adrnast = &ania;
        
//4. wyświetlanie listy
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

/*
Do zrobienia jeszcze w programie:
1. rozbicie kodu programu na funkcje i wykorzystanie ich w main()
2. możliwość wpisywania własnych pozycji listy z klawiatury, funkcja gets() albo scanf()
3. sortowanie bąbelkowe utworzonej listy
4. obsługa drzewa do tej listy
5. obsługa stosu na tej liście
6. implementacja kolejki?
7. 

*/

int dodajstud()
{
gets()

}
