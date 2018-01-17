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
    printf("Dodawanie na początek: %s, album: %d, %s, rok: %d\n", pom->nazw, pom->nralb, pom->kier, pom->rokst);
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
    printf("Dodawanie na koniec: %s, album: %d, %s, rok: %d\n", pom->nazw, pom->nralb, pom->kier, pom->rokst);
}

void pokazlist(stud *el)
{
    if(el != NULL)
    {
        while(el)
        {
            printf("  %s, album: %d, %s, rok: %d\n", el->nazw, el->nralb, el->kier, el->rokst);
            el = el->next;
        }
    }
}

void usunpocz(stud **el)
{
    struct student *pom = malloc(sizeof(stud));
    pom = *el;
    if((**el).next)
    {
        puts("--------------------");
    printf("Po usunięciu pierwszego rekordu: %s\n\n", pom->nazw);
        *el = (**el).next;
        free(pom);
    }
    else
    {
        puts("Lista nie ma elementów\n");
    }
}

void usunkon(stud **el)
{
    struct student *pom = malloc(sizeof(stud));;
    struct student *przedos = malloc(sizeof(stud));;
    pom = *el;
    while(pom->next)
    {
        przedos = pom;
        pom = pom->next;    
    }
    puts("--------------------");
    printf("Po usunięciu ostatniego rekordu: %s\n\n", pom->nazw);
    przedos->next = NULL;
    free(pom);
}

void usunwybr(stud **el, int nr)
{
    struct student *pom = malloc(sizeof(stud));
    struct student *przedos = malloc(sizeof(stud));
    pom = *el;
    while(pom->next)
    {
        przedos = pom;
        pom = (*pom).next;
        if(pom->nralb == nr)
        {
            puts("--------------------");
            printf("Po usunięciu wybranego rekordu: %s\n\n", pom->nazw);
            przedos->next = pom->next;
            pom->next = NULL;
            free(pom);
        }
    }
}

void sortscal(stud **el)
{

}

int main()
{
    struct student *head = NULL;
    puts("\n");
    dodajnapocz(&head, 5, 25000, "Kosma", "Przydrożna");
    dodajnapocz(&head, 1, 45334, "Dieta", "Karyna");
    dodajnapocz(&head, 3, 49658, "Lekarsko-dentystyczny", "Zielonka");
    dodajnapocz(&head, 2, 57800, "Lekarski", "Ogrodowa");
    
    puts("--------------------");
    puts("Wyświetlanie zmienionej listy: \n");
    pokazlist(head);
    puts("\n");
    dodajnakon(&head, 1, 45678, "Farmacja", "Paliwoda");
    dodajnakon(&head, 6, 39800, "Administracja w służbie zdrowia", "Końcowa");
    
    puts("--------------------");
    puts("Wyświetlanie zmienionej listy: \n");
    pokazlist(head);



    usunwybr(&head, 49658);
    pokazlist(head);

    usunkon(&head);
    pokazlist(head);

    usunpocz(&head);
    pokazlist(head);
    
    puts("\nKoniec listy studentów.\n");
    return 0;
}
