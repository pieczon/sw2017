#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <chrono>
#include <algorithm>
#include <list>

// http://slides.com/uczelnia_bt_kw/stl-2/#/3/5
// excercise
// Implement a function that inserts values from 1 to 10 to a list 
// use function object
// use std::generate

struct Predicate 
{
    int operator()()
    {
        return counter++;
    }
    int counter = 0;
};
//funkcje lambda 
void foo(std::list<int>& v)
{
    Predicate p;
    std::generate_n(std::back_inserter(v), 10, p);
    //generator jest podany przez warotsc, to zawsze sie wywola dla kopii tego obiektu
    //w kazdym algorytmie STL obiekty sa brane przez wartosc, nigdy nie przez referencje, wiec pracujemy na kopii
    //jak chcemy przez referencje, trzeba wywolywac algorytmy 
    std::cout << p.counter << std::endl;
};

void print(const std::list<int>& v)
{
    auto itBegin = v.begin();
    for(int i=0; i< v.size(); ++i)
    {
        std::cout << *(itBegin + 4) << std::endl;
    }
};

int main()
{
    auto v = std::list<int>{1,2,3,4,5};
    foo(v);
    print(v);
}