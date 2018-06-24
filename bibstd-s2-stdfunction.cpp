#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <functional>

/*
roznica std::shared_ptr to ze jest kopiowalny i ma licznik referencji, jak spadnie do 0 to jest kasowanie obiektu

uzyteczny do przechowywania/przekazywania danych miedzy watkami
sam ptr jest zaaloowany na stosie, ale to na co wskazuje jest na stercie, jak normalnie we wskaznikach

gdy faktycznie mamy koniecznosc przechowania i kopiowania danych miedzy watkami
w programowaniu jednowatkowym nie ma potrzeby uzywac

std::weak_ptr odwolania cykliczne

std::function obiekt przechowuje wskazniki na funckcje, to jest zwykly obiekt, do callbackow
taka func jest wywolywana za nas kiedy cos sie stanie..
jak sie sygnatury funkcji zgadzaja czyli typ zwracany i przyjmowane parametry, to mozna fo std::function uzyc dalej lambdy

*/

auto callback(const std::vector<int>&v, int N)
{
    std::vector<std::size_t> indeces;
    auto it = v.begin();
    while (it != std::end(v))
    {
        it = std::find(it, v.end(), N);
        if(it != std::end(v))
        {
            std::function<void(int)> func;
            //indeces.push_back(std::distance(std::begin(v), it));
            //it++;
        }
    }
    return indeces;
}

void fbt(const std::vector<int>& v, int N, const std::function<void(unsigned int)>& fn)
{
    auto lmd = [&N](int val){ return val > N; };
    auto it = ;
}

int main()
{
    //std::vector<int> w = {-10,-1,0,22,14,3};
    callback({1,22,1,3,4,5,7,8,1,5}, 10);
}

/*
chrono bibl silnie typowalna, specjalne operatory castowania chr::duration_cast, 

std::thread typ, niekopiowalny, nieprzypisywalny, przesuwalny, ma konstr domyslny
joinable czy stan watku umozliwia poczekanie na niego, czy std::thread przechowuje jakas konkretna func do wykonania, czy nasz obiekt ma sens

std::thread moze byc przechowywany w kontenerach, bo jest domyslnie konstruktowalny ma thread() = default;

join() nie jest wywolywana w destr, zanim join(), sprawdzenie joinable() i dopiero mozna join()

detach() rzuic wyjatek jestli func nie jest w trybie joinable(), a tak to odlaczamygo od watku rodzica i bedzie sie wykonywac az do konca dizalania programu

std::thread two = std::move(t) - po wykonaniu t nie posiada zasobow, np. przestaje byc joinable(), ale two jest joinable()

std::mutex obiekty synchronizacyjne std::lock_guard to jest unique_ptr dla watkow
synchronizacja jest na poziomie dostepu do danych, nie kolejnosci wykonywania linijek kodu
niskopoziomowe operowanie na watkach

wysokopoziomowe operowanie jest na std::future i std::async async/deferred
duzo latwiejsza implementacja, duzo roboty juz zrobione za nas w tym zwracanie wartosci po zakonczeniu watku get()

niskopozoiomowe daje natomiast wieksza elastycznosc w operowaniu watkami, ale jest trudniejsze

*/