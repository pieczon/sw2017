#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicja listy dwukierunkowej z zestawem danych studentów
typedef struct student
{
    int rokst, nralb;
    char *kier, *nazw;
    struct student *next;
    struct student *prev;
}student;
//utworzenie 2 rekrodów listy
struct student sara={3, 24658, "Kosmetologia", "Dawidziuk", NULL};
struct student nadia={1, 56777, "Biotechnologia", "Zalewska", NULL};
struct student ania={5, 34899, "Zdrowie publiczne", "Kloczkowska", NULL};

int main()
{
    puts("\nLista studentów:\n");
//inicjalizacja listy, utworzenie początku listy
    student *head;
    head = &sara;
    sara.next = &nadia;
//tworzenie elementów listy
    student *kolejny;
    kolejny = malloc(sizeof(student)); 
//różne sposoby implementacji
    kolejny->rokst = 4;
    kolejny->nralb = 25555;
    kolejny->kier = (char*)malloc(sizeof(char) * (strlen("Lekarski") + 1));
    strcpy(kolejny->kier, "Lekarski");
    kolejny->nazw = (char*)malloc(sizeof(char) * (strlen("Pokora") + 1));
    strcpy(kolejny->nazw, "Pokora");
    kolejny->next = &sara;
    head = kolejny;
 //kolejny rekord
    nadia.next = &ania;
//wyświetlanie listy, struktura pomocnicza
    student *tmp = NULL;
    tmp = head;
    while(tmp != NULL)
    {
        printf("  %s, nr: %d, %s, rok: %d\n", tmp->nazw, tmp->nralb, tmp->kier, tmp->rokst);
        tmp = tmp->next;
    }

//usuwanie danych z listy, tworzenie węzłów pomocniczych
    struct student *usun = NULL;
    struct student *przedos = NULL;
    usun = head;
    while(usun->next != NULL)
    {
        przedos = usun;
        usun = usun->next;    
    }
    printf("\nPrzedostatni: %s", przedos->nazw);
    printf("\nOstatni: %s\n", usun->nazw);
    puts("Kasownie ostatniego elementu listy\n");
    przedos->next = NULL;
    
    // while(usun->next != NULL)
    // {
    //     if(usun->nralb != 0)
    //     {
    //         free(usun);
    //     }
    //     //usun = usun->next;    
    // }

    tmp = head;
    while(tmp != NULL)
    {
        printf("  %s, nr: %d, %s, rok: %d\n", tmp->nazw, tmp->nralb, tmp->kier, tmp->rokst);
        tmp = tmp->next;
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
    
    puts("\nKoniec listy studentów.\n");
    return 0;
}
