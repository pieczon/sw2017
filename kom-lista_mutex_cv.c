#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t initmutex;
pthread_cond_t cvfull, cvempty;

unsigned int pojemnosc, ilosc, ik, ip = 0;

typedef struct student
{
    int nralb;
    struct student *next;
}stud;

struct student *head = NULL;

int dodajnaKon(stud **el, int nr)
{
    if(pojemnosc <= 5)
    {
        struct student *buf = malloc(sizeof(stud));
        struct student *pom = malloc(sizeof(stud));
        pom->next = NULL; //zapis równoważny (*pom).next = NULL;
        pom->nralb = nr;
        buf = *el;
        if(*el == NULL)
        {
            *el = pom;
            ilosc++;
        }
        else
        {
            while(buf->next)
            {
                buf = buf->next;
                ilosc++;
            }
            buf->next = pom;
        }
        return pom->nralb;
    }
    else
    {
        puts("Za dużo elementów\n");
        return -1;
    }
    
}

int usunPocz(stud **el)
{
    struct student *pom = malloc(sizeof(stud));
    pom = *el;
    if((**el).next)
    {
        int usuwany = pom->nralb;
        *el = (**el).next;
        free(pom);

        ilosc = 0;
        return usuwany;
    }
    else
    {
        puts("Lista nie ma elementów\n");
        return -1;
    }
}

void *prod(void *arg)
{
    while(ip <= 2)
    {
        pthread_mutex_lock(&initmutex);
        int element = dodajnaKon(&head, 25000+ip);
        if(element != -1)
        {
            printf("Numer wątku %ld, dodany element: %d\n", pthread_self(), element);
            pthread_cond_signal(&cvempty);
        }
        else
        {
            printf("Numer wąrku %ld, lista jest pełna\n", pthread_self());
            pthread_cond_wait(&cvfull, &initmutex);
        }
        pthread_mutex_unlock(&initmutex);
        ip++;
    }
    pthread_exit(NULL);
}

void *kons(void *arg)
{
    while(ik < 2)
    {
        pthread_mutex_lock(&initmutex);
        int element = usunPocz(&head);
        if(element != -1)
        {
            printf("Numer wątku %ld usunięto pierwszy element %d\n", pthread_self(), element);
            pthread_cond_signal(&cvfull);
        }
        else
        {
            printf("Numer wątku %ld lista nie zawiera elementów\n", pthread_self());
            pthread_cond_wait(&cvempty, &initmutex);
        }
        pthread_mutex_unlock(&initmutex);
        ik++;
    }
}


int main()
{
    pthread_t th_prod[5];
    pthread_t th_kons[5];

    if(pthread_mutex_init(&initmutex, 0) != 0)
    {
        perror("Błąd tworzenia initmutex");
        exit(0);
    }
    if(pthread_cond_init(&cvfull, 0) != 0)
    {
        perror("Błąd tworzenia cvfull");
        exit(0);
    }
    if(pthread_cond_init(&cvempty, 0) != 0)
    {
        perror("Błąd tworzenia cvempty");
        exit(0);
    }

    printf("\n--------------------\nWątki producentów\n");
    for(int i=0; i<5; i++)
    {
        if(pthread_create(&th_prod[i], NULL, prod, NULL) != 0)
        {
            perror("Błąd towrzenia producentów\n");
            exit(0);
        }
        else
        {
            printf("\nProducent %ld nr %lu, wątek %ld\n", i, pthread_self(), th_prod[i]);
        }
    }

    printf("\n--------------------\nWątki konsumentów\n");
    for(int i=0; i<5; i++)
    {
        if(pthread_create(&th_kons[i], NULL, kons, NULL) != 0)
        {
            perror("Błąd towrzenia konsumentów\n");
            exit(0);
        }
        else
        {
            printf("\nKonsument %ld nr %lu, wątek %ld\n", i, pthread_self(), th_kons[i]);
        }
    }
    puts("\n");
    
    for(int i=0; i<5; i++)
    {
        pthread_join(th_kons[i], NULL);
    }
    for(int i=0; i<5; i++)
    {
        pthread_join(th_prod[i], NULL);
    }

    pthread_cond_destroy(&cvfull);
    pthread_cond_destroy(&cvempty);
    pthread_mutex_destroy(&initmutex);

    return 0;
}
