#include <iostream>
#include <algorithm>
#include <vector>

//http://slides.com/uczelnia_bt_kw/stl-2/#/3/11

void print(const std::vector<int>& v)
{
    std::cout << "[";
    for(const auto& ele : v)
    {

    }
}

void foo(const std::vector<int>& v)
{
    int counter = 0;
    std::generate_n(std::back_inserter(v), 10, [&]() { return counter++; }); //-> uzywana do wymuszenia typu zwracanego w funkcji lambda, wartosc zwracana przez strzalke tylko przy bardziej kompleksowych funkcjach
    //typ mozemy zachowac dla funkcji lambra tylko w auto
    //lambda nie widzi zmiennych okreslonych poza funkcją do przekazania wpisujemy w nawiasy [&] lub [&counter] lub [=] lub [counter], podanie przez kopie obiektow robi je stałe, to sa stale obiekty, zeby lambda mogla modyfikowac wartosci przekazywane przez kopie to dodajemy slowo mutable, czyli [&]() mutable
    //przekazywanie do funkcji, przechwytuje jeden argument przez wartosc
    //[counter = 0ul] tak tez mozna zapisac, ale typ zmiennej zalezy od tego czym inicjalizujemy
}

int main()
{
    std::vector<int> b;
    b.resize(10);
    foo(b);
    print(b);
}