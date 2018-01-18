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
    //struct wsk *prev;
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

void usunWybr(stud **el, int nr)
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

struct student *SortedMerge(stud *a, stud *b)
{
    struct student *result = malloc(sizeof(stud));
    result->next = NULL;
    
    /* Base cases */
    if(a == NULL) return(b);
    else if(b==NULL) return(a);
    
    /* Pick either a or b, and recur */
    if(strcmp(a->nazw, b->nazw)<0)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void MergeSort(stud **el)
{
    struct student *pom = malloc(sizeof(stud));
    struct stud *first = malloc(sizeof(stud));
    struct stud *last = malloc(sizeof(stud));
    pom = *el;
    
    /* Base case -- length 0 or 1 */
    if((pom == NULL) || (pom->next == NULL))
    {
        //puts("Nic tu nie ma");
        return;
    }
    
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(pom, &first, &last); 
    
    /* Recursively sort the sublists */
    MergeSort(&first);
    MergeSort(&last);
    
    /* answer = merge the two sorted lists together */
    *el = SortedMerge(first, last);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves, and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list. Uses the fast/slow pointer strategy.  */
void FrontBackSplit(stud *source, stud **frontRef, stud **backRef)
{
    struct student *fast = malloc(sizeof(stud));
    struct student *slow = malloc(sizeof(stud));
    if(source==NULL || source->next==NULL)
    {
        /* length < 2 cases */
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
    
        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
    
        /* 'slow' is before the midpoint in the list, so split it in two at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
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
    
    puts("--------------------");
    puts("Wyświetlanie zmienionej listy: \n");
    pokazList(head);
    puts("\n");
    dodajnaKon(&head, 1, 45678, "Farmacja", "Paliwoda");
    dodajnaKon(&head, 6, 39800, "Administracja w służbie zdrowia", "Końcowa");
    
    puts("--------------------");
    puts("Wyświetlanie zmienionej listy: \n");
    pokazList(head);

    puts("--------------------");
    puts("Wyświetlanie posortowanej listy: \n");
    MergeSort(&head);
    pokazList(head);

    usunWybr(&head, 77900);
    pokazList(head);

    usunKon(&head);
    pokazList(head);

    usunPocz(&head);
    pokazList(head);
    
    puts("\nKoniec listy studentów.\n");
    return 0;
}
