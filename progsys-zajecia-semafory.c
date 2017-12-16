#include <stdio.h>
#include <stdlib.h>  // EXIT_SUCCESS
#include <pthread.h> // pthread
#include <semaphore.h>
#include <unistd.h>

sem_t pingsem, pongsem;

void *ping(void *arg)
{
    for(;;)
    {
        sem_wait(&pingsem); //zjemij 1 z jednego semafora
        printf("ping\n");
        usleep(100000);
        sem_post(&pongsem); //dodaj 1 do tego semafora
    }
}
void *pong(void *arg)
{
    for(;;)
    {
        sem_wait(&pongsem);
        printf("-------pong\n");
        sem_post(&pingsem);
    }
}
int main(void)
{
    sem_init(&pingsem,0,1);
    sem_init(&pongsem,0,0);
    pthread_t ping_thread, pong_thread;
    pthread_create(&ping_thread, NULL, ping, NULL);
    pthread_create(&pong_thread, NULL, pong, NULL);
    pthread_join(ping_thread, NULL);
    pthread_join(pong_thread, NULL);
    return 0;
}