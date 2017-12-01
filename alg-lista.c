#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. definiuję strukturę, z dodaniem przykładowych rekordów do listy
struct studtoku
{
    int rokst, nralb;
    char *kierunek, *nazwisko;
    struct studtoku *adrnast;
    //struct studtoku *adrpopr;
}studtoku;

struct studtoku sara={3, 24658, "Kosmetologia", "Dawidziuk", NULL};
struct studtoku nadia={1, 56777, "Biotechnologia", "Zalewska", NULL};

int main()
{
//2. inicjalizacja listy, tworzenie nowych obiektów listy: początek listy, elementy listy
    struct studtoku *head;
    head = NULL;

    struct studtoku *kolejny;
    kolejny = malloc(sizeof(studtoku)); 

    kolejny->adrnast = NULL;
    kolejny->rokst = 4;
    kolejny->nralb = 25555;
    kolejny->kierunek = (char*)malloc(sizeof(char) * (strlen("Lekarski") + 1));
    strcpy(kolejny->kierunek, "Lekarski");
    //strcpy(kierunek, bufor);     
    kolejny->nazwisko = (char*)malloc(sizeof(char) * (strlen("Pokora") + 1));
    strcpy(kolejny->nazwisko, "Pokora");
    
    head = kolejny;

    kolejny->adrnast = &sara;
    sara.adrnast = &nadia;

    struct studtoku ania={5, 34899, "Zdrowie publiczne", "Kloczkowska", NULL};
    nadia.adrnast = &ania;

//3. pokazywanie listy
    struct studtoku *tmp = NULL;
    tmp = head;
    while(tmp != NULL)
    {
        printf("  %s, nr: %d, %s, rok: %d\n", tmp->nazwisko, tmp->nralb, tmp->kierunek, tmp->rokst);
        tmp = tmp->adrnast;
    }
    // printf("Pokora: %s\n", kolejny->nazwisko);
    // printf("Pokora: %d\n", kolejny->nralb);
    // printf("Pokora: %s\n", kolejny->kierunek);
    // printf("Pokora: %d\n", kolejny->rokst);

// 4. usuwanie danych z listy

    struct studtoku *usun = NULL;
    struct studtoku *przedos = NULL;
    usun = head;
    while(usun->adrnast != NULL)
    {
        przedos = usun;
        usun = usun->adrnast;    
    }
    przedos->adrnast = NULL;
    
    printf("Przedostatni: %s\n", przedos->nazwisko);
    printf("Ostatni: %s\n", usun->nazwisko);

    while(usun->adrnast != NULL)
    {
        if(usun->nralb == 25555)
        {
            free(usun);
        }
        //usun = usun->adrnast;    
    }
    tmp = head;
    while(tmp != NULL)
    {
        printf("Po skasowaniu %s, nr: %d, %s, rok: %d\n", tmp->nazwisko, tmp->nralb, tmp->kierunek, tmp->rokst);
        tmp = tmp->adrnast;
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
    return 0;
}
