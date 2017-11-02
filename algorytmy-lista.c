#include <stdio.h>
#include <stdlib.h>

//1. definiuję strukturę listy
struct studtoku
{
 int rokst, nralb;
 char kierunek[20], nazwisko[20];
 struct studtoku *adrnast;

}studtoku;

struct studtoku sara={3, 24658, "Kosmetologia", "Dawidziuk", NULL};
int t = 7;

int main()
{
//2. inicjalizacja listy, tworzenie obiektów po kolei: początek listy, element listy

struct studtoku *head;
struct studtoku *kolejny;
head = malloc(sizeof(studtoku));
kolejny = malloc(sizeof(studtoku));
head->adrnast = NULL;

//3. zapełnianie listy 

kolejny = kolejny->adrnast = malloc(sizeof(studtoku));
kolejny->adrnast = NULL;

//kolejny->rokst = 4;
//kolejny->nralb = 25555;
//kolejny->kierunek[] = "Lekarski";
//kolejny->nazwisko[] = "Pokora";
//kolejny-> struct studtoku aaa={4, 39727, "Stomatologia", "Przydrożna"};

//4. pokazywanie listy

while(kolejny != NULL)
{
printf("Dane studentów, rok studiów: %d, numer albumu: %d, nazwa kierunku: %s, nazwisko: %s \n", kolejny->rokst, kolejny->nralb, kolejny->kierunek, kolejny->nazwisko);
kolejny = kolejny->adrnast;
}

return 0;
}
