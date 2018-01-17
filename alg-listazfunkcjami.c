#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicja listy
// typedef struct osoba
// {
//     char *imie, *nazwisko;
//     int wiek;
// }osoba;

typedef struct student
{
    //struct osoba;
    int rokst;
    int nralb;
    char *kier;
    char *nazw;
    struct wsk *next;
    //struct wsk *prev;
}stud;

void dodajnapocz(stud **el, int rk, int nr, char *ki, char *na)
{
    struct student *pom = malloc(sizeof(stud));
    pom->next = NULL; //zapis równoważny (*pom).next = NULL;
    pom->rokst = rk;
    pom->nralb = nr;
    pom->kier = ki;
    pom->nazw = na;
    if(*el == NULL)
    {
        *el = pom;
    }
    else
    {
        pom->next = *el;
        *el = pom;
    }
}

void dodajnakon(stud **el, int rk, int nr, char* ki, char* na)
{
    struct student *buf = malloc(sizeof(stud));
    struct student *pom = malloc(sizeof(stud));
    pom->next = NULL; //zapis równoważny (*pom).next = NULL;
    pom->rokst = rk;
    pom->nralb = nr;
    pom->kier = ki;
    pom->nazw = na;
    buf = *el;
    if(*el == NULL)
    {
        *el = pom;
    }
    else
    {
        while(buf->next)
        {
            buf = buf->next;
        }
        buf->next = pom;
    }
}

int pokazlist(stud *el)
{
    if(el != NULL)
    {
        while(el)
        {
            printf("  %s, album: %d, %s, rok: %d\n", el->nazw, el->nralb, el->kier, el->rokst);
            el = el->next;
        }
    }
    return 0;
}

int main()
{
    struct student *head = NULL;
    puts("--------------------");
    puts("Lista studentów w C, z dodawaniem na początek: \n");
    dodajnapocz(&head, 5, 25000, "Kosma", "Przydrożna");
    dodajnapocz(&head, 1, 45334, "Dieta", "Karyna");
    dodajnapocz(&head, 3, 49658, "Lekarsko-dentystyczny", "Zielonka");
    dodajnapocz(&head, 2, 57800, "Lekarski", "Ogrodowa");
    pokazlist(head);

    puts("--------------------");
    puts("Lista studentów w C, z dodawaniem na koniec: \n");
    dodajnakon(&head, 1, 45678, "Farmacja", "Końcowa");
    dodajnakon(&head, 6, 39800, "Administracja w służbie zdrowia", "Paliwoda");
    pokazlist(head);
    
    puts("\nKoniec listy studentów.\n");
    return 0;
}