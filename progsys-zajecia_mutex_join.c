#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <string.h>

static int global_counter;
char shared_buffer[50];
pthread_mutex_t global_mtx = PTHREAD_MUTEX_INITIALIZER;

pid_t my_gettid()
{
	pid_t tid;
	tid = syscall(SYS_gettid);
	return tid;
}

//deklaracja makra ponizej, trzy kropki sa agrumentem, znaczy to ze dowolna liczba parametrow moze zostac przekazana do funkcji
//poprzez makro VA_ARGS rozwijany jest do formatu widocznego jako lista parametrow
#define LOG_DBG(fmt, ...)						\
	do {								\
		fprintf(stderr, __FILE__ "%d:%s PID=%d TID=%d DBG: " fmt, \
			__LINE__, __func__,				\
			getpid(), my_gettid(), ##__VA_ARGS__);	\
	}while (0)
//powyższa petla ma specyficzny zapis na koncu while(0), ogolnie petla wykona sie oczywiscie raz, ale jezyk C ma pewne niedomaganie, przed ktorym ten zapis zabezpiecza, to jest roznica w traktowaniu funkcji i makra

#define LOG_ERR(fmt, ...)						\
	do {								\
		fprintf(stderr, __FILE__ "%d:%s ERR: " fmt, __LINE__, __func__,	\
			##__VA_ARGS__);					\
	}while (0)

#define SET_BUFFER(B, fmt, ...)						\
	do {								\
		int s = snprintf(B, ARRAY_SIZE(B), "%10s: " fmt,	\
				 __func__, ##__VA_ARGS__);		\
		if (s == ARRAY_SIZE(B)) {				\
			B[ARRAY_SIZE(B)] = '\0';			\
		}							\
	} while(0)

#define ARRAY_SIZE(a) sizeof(a)/sizeof((a)[0])

typedef int (*th_f)(int th, int id, int i); //wskaznik do funkcji, adres funkcji ktora zwraca int, a przyjmuje parametry, kazdy wskaznik do funkcji ma taki element do funkcji void (*nazwa)(), w algorytmie w dzialaniu programu podmieniamy funkcję, tylko lista argumentów i typ zwracany mają się zgadzać, sama nazwa funkcji tez jest w rzeczywistosci wskaznikem na ta funkcje
//typedef pozwala potem na skracanie zapisu czyli: th_f f1 = fa; 
//a wywolanie funkcji przez wskaźnik: f1(1, 0, 10); f1 = fb;

int s_print_id(int th, int id, int i)
{
	pthread_mutex_lock(&global_mtx);
	global_counter++;
	fprintf(stdout, "%11s: E: th=%0#10x id=%d print_id: %3d gc=%-4d sb=%s\n",
		__func__, th, id, i, global_counter, shared_buffer);
	global_counter--;
	pthread_mutex_unlock(&global_mtx);
}

int m_print_id(int th, int id, int i)
{
	pthread_mutex_lock(&global_mtx);
	global_counter++;
	fprintf(stdout, "%11s: E: th=%-10x id=%d print_id: %3d gc=%-4d sb=%s\n",
		__func__, th, id, i, global_counter, shared_buffer);
	SET_BUFFER(shared_buffer, "th=%-10x id=%d i=%d", th, id, i); //shared_buffer przechwytuje tekst, dwa wątki z dostepem do wspoldizelonej pamieci
	usleep(10);
	global_counter--;
	fprintf(stdout, "%11s: X: th=%-10x id=%d print_id: %3d gc=%-4d sb=%s\n",
		__func__, th, id, i, global_counter, shared_buffer);
	pthread_mutex_unlock(&global_mtx);
}

typedef struct th_args_s {
	int id;
	pthread_t thid;
	int count;
	th_f fn;
} th_args_t;

void *thread_fn(void *arg) //funkcja obslugujaca watek, to jest main dla watkow, ta funkcja wywoluje jeszcez jedna przez element  struktury
{
	th_args_t *args  = (th_args_t*)arg;
	int i;
	int count = 5; /* default count */

	if (!args) {
		LOG_ERR("arg=NULL\n");
	}

	count = (args->count > 0) ? args->count : 5;

	for(i = 0; i < count; i++) {
		if (args->fn) {//wywolanie funkcji przez wskaznik, gdzie fn jest wskaznikiem
			args->fn(args->thid, args->id, i);
		}
		else
		{
			LOG_DBG("thread=%0#10lx id=%d function missing cnt=%d sb=%s\n",
				args->thid, args->id, i, shared_buffer);
		}
	}
}

th_args_t thread_args[] = {
/*	{0, 0, 10, NULL}, */
/*	{0, 0, 10, s_print_id}, */
/*	{0, 0, 10, s_print_id}, */
	{0, 0, 10, m_print_id}, //inicjacja elementow stuktury
	{0, 0, 10, m_print_id}, //wskaznik na funkcje, w watku w jego obrebie, 5 razy jest przekazywana przez sturcta
};

int main(int argc, char **argv)
{
	int i = 0;
	int res;

	memset(shared_buffer, '\0', ARRAY_SIZE(shared_buffer));

	pthread_mutex_lock(&global_mtx); //do tej pamieci ma dostep tylko funkcja ktora go zaalokowala, zabezpieczyla, inny thread nie dostanie sie tutaj
	SET_BUFFER(shared_buffer, "main"); //wrzucamy poczatkowy tekst do tego bufora
	pthread_mutex_unlock(&global_mtx);//zwalniamy blokade, inne procedy moga tu zapisywac

	for (i = 0; i < ARRAY_SIZE(thread_args); i++) {
		LOG_DBG("starting thread %d sb=%s\n", i, shared_buffer); 
		thread_args[i].id = i;
		res = pthread_create(&thread_args[i].thid, NULL, thread_fn, &thread_args[i]); //tworzymy nowy wątek: miejsce w ktore wpisujemy liczbe, ktora pthread utworzy; nastepny argument priorytet wątku; funkcja realizowana przez wątek; do tej funkcji przekazujemy również argumenty, lista argumentow przekazywana jako odpowiednia tablica argumentow;  
		if (res != 0) {//pthread_create zwraca 0 jak jest ok, inna od 0 mamy błąd
			LOG_ERR("Thread id=%d create failed res=%d sb=%s\n", i, res, shared_buffer);//tu powinno byc exit(0)
		}
		LOG_DBG("thread=%lx id=%d created sb=%s\n", thread_args[i].thid, i, shared_buffer);
	}

	for (i = 0; i < 20; i++) {
		s_print_id(getpid(), 0, i);
	}

	LOG_DBG("Waiting for threads to finish sb=%s\n", shared_buffer);
	for (i = 0; i < ARRAY_SIZE(thread_args); i++) {
		pthread_join(thread_args[i].thid, NULL);//join zeby program glowny nie skonczyl sie wczesniej niz skoncza sie watki
		//pracujemy z watkiem glownym, bez tego proba dostepu do pamieci ktora jest zwolniona moze skonczyc sie bledem
	}

	LOG_DBG("all threads finished sb=%s\n", shared_buffer);
	return 0;
}
