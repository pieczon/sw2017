/*
STL3
http://slides.com/uczelnia_bt_kw/stl-3-14#/1/1
std::pair przydatne kiedy chcemy zworic z funkcji wiecej niz jedna wartosc
w range for uzywamy tak na prawde std::pair
std::make_pair(s,d) kompilator sam domysli sie typow, tworzac recznie trzeba podac samemu typy

std::tuple, krotka - wiecej niz dwa elementy, std::get<index> po tym wyciagamy wartosc krotki
mozna tez z krotki wyciagnac info po typie od c++14
std::tuple bardzo dobrze sie optymalizuje..

std::make_tuple nie musimy powtarzac typow, typem zwracanym jest stala referencja

wskazniki static_cast posiada pusty stan nullptr, przydatne wtedy kiedy mamy doczynienia z polimorfizmem

delete zwalnia tylko odwolanie pointera, ale dalej posiada wartosc sprzed delete

bss - zmienne globalne oraz sterta jedyne obszary dostepne dla wszystkich watkow w programie, stos jest jeden na watek

std::unique_ptr - przechowuje wskaznik na obiekt typu T, raz stworzony uptr

std::move nietrafiona nazwa, niekondycyjne konwertowanie do rwatosci, to konwertuje podana obiekt na referencje do obiektu tymczasowego rhs

&& g

lhs mozna skastowac do rhs

referencja do rhs nie binduje sie do rhs

przy konstrukotrze przesuwajacym, std::move moze zalatwic problem jak sie nie kompiluje/jest blad

reference collapsing,

w kontenerach mozemy uzywac uptr np. std::vector<std::unique_ptr<int>>

w funkcjach lambda []() -> typ zwracany wypisyjemy tylko jak jest kilka returnow, lub kilka typow zwaracanych {}

customowe deletery, np dla sytuacji gdy uptr zostal stworzony przez przypisanie zwracanego inta z funkcji otwarcia pliku k{::open("tt")}

 <int,decltype(deleter)>

tylko kompilator zna typ funkcji lamnda

uptr mozna uzywac wszedzie do zarzadzania zasobami, np. otwarcie pliku, tylko wtedy customowy deleter, bo przy pliku nie chcemy wywolac delete na pliku, tylko np. close

uptr niekopiowalny, przesuwalny, mozemy ukrasc z niego zasoby
*/
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
auto konwertuj(std::vector<T>& v)
{
    std::vector<std::unique_ptr<int>> uv;
    std::transform(v.begin(), v.end(), std::back_inserter(uv), [](const auto& v)
    { return std::make_unique<int>(v); });
    return uv;
}

double mean(const std::vector<std::unique_ptr<int>>& v)
{
    double sum = 0;
    std::accumulate(v.begin(), v.end(), 0.0, [](double p, const auto& part){ return p + *part; });
}

int main()
{

}