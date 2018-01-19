#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    struct student *next;
    //struct student *prev;
}stud;

void dodajnaPocz(stud **el, int rk, int nr, char *ki, char *na)
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

void dodajnaKon(stud **el, int rk, int nr, char *ki, char *na)
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

void pokazList(stud *el)
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

void usunPocz(stud **el)
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

void usunKon(stud **el)
{
    struct student *ost = malloc(sizeof(stud));;
    struct student *przedos = malloc(sizeof(stud));;
    ost = *el;
    while(ost->next)
    {
        przedos = ost;
        ost = ost->next;    
    }
    puts("--------------------");
    printf("Po usunięciu ostatniego rekordu: %s\n\n", ost->nazw);
    przedos->next = NULL;
    free(ost);
}

void usunWybr(stud **el, int nr)
{
    struct student *wyb = malloc(sizeof(stud));
    struct student *poprz = malloc(sizeof(stud));
    wyb = *el;
    while(wyb->next)
    {
        poprz = wyb;
        wyb = (*wyb).next;
        if(wyb->nralb == nr)
        {
            puts("--------------------");
            printf("Po usunięciu wybranego rekordu: %s\n\n", wyb->nazw);
            poprz->next = wyb->next;
            wyb->next = NULL;
            free(wyb);
        }
    }
}

void usunList(stud **el)
{
    struct student *pom = malloc(sizeof(stud));
    struct student *usun = NULL;
    pom = *el;
    while(pom)
    {
        usun = pom;
        pom = pom->next;
        usun->nazw = NULL;
        usun->kier = NULL;
        usun->next = NULL;
        free(usun);
    }
    puts("--------------------\nPo usunięciu całej listy: \n");
}

struct student *scalPosortowane(stud *pierwsza, stud *druga)
{
    struct student *posortowana = malloc(sizeof(stud));
    posortowana->next = NULL;

    if(pierwsza == NULL) 
    {
        return(druga);
    }
    else if(druga == NULL)
    {
        return(pierwsza);
    } 

    if(strcmp(pierwsza->nazw, druga->nazw) < 0)
    {
        posortowana = pierwsza;
        posortowana->next = scalPosortowane(pierwsza->next, druga);
    }
    else
    {
        posortowana = druga;
        posortowana->next = scalPosortowane(pierwsza, druga->next);
    }
    return(posortowana);
}

void mergeSort(stud **el)
{
    struct student *cala = malloc(sizeof(stud));
    struct stud *pierwsza = malloc(sizeof(stud));
    struct stud *druga = malloc(sizeof(stud));
    cala = *el;
    
    if((cala == NULL) || (cala->next == NULL))
    {
        //puts("Nic tu nie ma");
        return;
    }

    dajSublisty(cala, &pierwsza, &druga); 
    mergeSort(&pierwsza);
    mergeSort(&druga);
    *el = scalPosortowane(pierwsza, druga);
}

void dajSublisty(stud *cala, stud **pierwsza, stud **druga)
{
    struct student *fastptr = malloc(sizeof(stud));
    struct student *slowptr = malloc(sizeof(stud));
    if((cala == NULL) || (cala->next == NULL))
    {
        *pierwsza = cala;
        *druga = NULL;
    }
    else
    {
        slowptr = cala;
        fastptr = cala->next; //przemieszczanie się po liście o dwa węzły na raz, czyli cala->next->next

        while(fastptr)
        {
            fastptr = fastptr->next;
            if(fastptr != NULL)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
        }
        //w tym miejscu fastptr dotarł do ostatniego węzła, a slowptr jest na węźle przed środkiem
        *pierwsza = cala;
        *druga = slowptr->next; //wystarczy wyznaczyć drugą sublistę od tego węzła
        slowptr->next = NULL; //potem usunąć dowiązanie do drugiej sublisty i mamy 2 niezależne listy 
    }
}

int main()
{
    struct student *head = NULL;

    puts("\n");
    dodajnaPocz(&head, 5, 25000, "Kosma", "Przydrożna");
    dodajnaPocz(&head, 1, 45334, "Dieta", "Karyna");
    dodajnaPocz(&head, 3, 49658, "Lekarsko-dentystyczny", "Zielonka");
    dodajnaPocz(&head, 2, 57800, "Lekarski", "Ogrodowa");
    dodajnaPocz(&head, 2, 77900, "Analityka medyczna", "Wypadek");
    puts("--------------------\nWyświetlanie zmienionej listy:\n");
    pokazList(head);
    
    puts("\n");
    dodajnaKon(&head, 1, 45678, "Farmacja", "Paliwoda");
    dodajnaKon(&head, 6, 39800, "Administracja w służbie zdrowia", "Końcowa");
    puts("--------------------\nWyświetlanie zmienionej listy:\n");
    pokazList(head);

    puts("\n--------------------\nWyświetlanie posortowanej alfabetycznie listy:\n");
    mergeSort(&head);
    pokazList(head);

    usunWybr(&head, 77900);
    pokazList(head);

    usunKon(&head);
    pokazList(head);

    usunPocz(&head);
    pokazList(head);

    usunList(&head);
    pokazList(head);

    puts("\nKoniec listy studentów.\n");
    return 0;
}
