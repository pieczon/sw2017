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

void UsunWybr(stud **el, int nr)
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

//void SortujScal(stud **el)
//{
    /* sorts the linked list by changing next pointers (not data) */
    void MergeSort(stud **el)
    {
        struct student *pom = malloc(sizeof(stud));
        struct stud *first = malloc(sizeof(stud));
        struct stud *last = malloc(sizeof(stud));
        pom = *el;
        
        /* Base case -- length 0 or 1 */
        if ((pom == NULL) || (pom->next == NULL))
        {
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
        if (source==NULL || source->next==NULL)
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
            while (fast != NULL)
            {
                fast = fast->next;
                if (fast != NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        
            /* 'slow' is before the midpoint in the list, so split it in two
            at that point. */
            *frontRef = source;
            *backRef = slow->next;
            slow->next = NULL;
        }
    }

    /* See https://www.geeksforgeeks.org/?p=3622 for details of this 
   function */
    struct stud *SortedMerge(stud *a, stud *b)
    {
        struct student *result = malloc(sizeof(stud));
        result->next = NULL;
        
        /* Base cases */
        if (a == NULL) return(b);
        else if (b==NULL) return(a);
        
        /* Pick either a or b, and recur */
        if (a->nazw <= b->nazw)
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
//}

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

    puts("--------------------");
    puts("Wyświetlanie posortowanej listy: \n");
    MergeSort(&head);
    pokazlist(head);

    UsunWybr(&head, 49658);
    pokazlist(head);

    usunkon(&head);
    pokazlist(head);

    usunpocz(&head);
    pokazlist(head);
    
    puts("\nKoniec listy studentów.\n");
    return 0;
}
