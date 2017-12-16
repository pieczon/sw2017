#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;
pthread_cond_t condvar;
int threads_left = 0;

void *do_pingpong(void *arg) //argumenty zawsze musza wskazywac na void, potem przekazywane sa konkretne dane do obslugi wątku, my bedziemy przekazywac tekst czyli wskaznik na char
{
    char *myname = (char *)arg;
    int count = 0;
    fprintf(stdout, "\nThread %s has started\n", myname);
    threads_left++;
    if(pthread_mutex_lock(&mutex) != 0)
    {
        perror("mutex lock failed");
        exit(-1);
    }
    while(count++ < 5)
    {
        fprintf(stdout, "%s\n", myname);
        pthread_cond_signal(&condvar);
        pthread_cond_wait(&condvar, &mutex);
    }
    if(pthread_mutex_unlock(&mutex) != 0)
    {
        perror("mutex unlock failed\n");
        exit(-1);
    }
    fprintf(stdout, "Thread %s is ending\n", myname);
    threads_left--; //na koncu procedury obslugi watku mamy zmniejszenie jej wartosci
    pthread_cond_signal(&condvar);
    return NULL;
}

int main()
{
    char t1name[] = "ping";
    char t2name[] = "pong";
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condvar, NULL);

    if(pthread_create(&t1, NULL, do_pingpong, (void *)t1name) != 0)
    {
        perror("t1 create failed");
        exit(-1);
    }
    if(pthread_create(&t2, NULL, do_pingpong, (void *)t2name) != 0)
    {
        perror("t2 create failed");
        exit(-1);
    }
    pthread_detach(t1);//przy detachu nie mozemy pozwolic zeby program glowny sie skonczyl, bo nie zadziala
    pthread_detach(t2);//musimy dac glownego procesowi jakies zadanie
    //przy joinie ta czesc nie jest nam potrzebna, bo join zapewnia ze program glowny sie nie skonczy, dopoki watki nie zakoncza dzialania
    while(1)
    {
        sleep(2);
        if (threads_left == 0)
        {
            exit(0);
        }
    }
    return(0);
}