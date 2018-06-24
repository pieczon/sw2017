#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <chrono>
#include <algorithm>

void print(const std::vector<int>& v)
{
    auto itBegin = v.begin();
    for(int i=0; i< v.size(); ++i)
    {
        std::cout << *(itBegin + 4) << std::endl;
    }
};

int foo(std::vector<int>& v, int searched)
{
    // for(auto itB = v.begin(); itB < v.end(); std::advance(itB, 1))
    // {
    //     if(*itB == searched) return std::distance(v.begin(), itB);
    // }
    // return -1;

    //zapis tozsamy ponizej kompilator go wygeneruje
    auto it = std::find(v.begin(), v.end(), searched);
    if(it != v.end())
    {
        return std::distance(v.begin(), it);
        return -1;
    }

    auto bInserter = std::back_inserter(v);
    bInserter = 10;
    bInserter = 11;

    auto fInserter = std::front_inserter(v); 
    //tylko na listach, wektor nie ma metod dodawania na poczatek,trzeba przyjac jako parametr np. referencje na obiekt listy
    fInserter = 5;
};

int main()
{
    auto v = std::vector<int>{1,2,3,4,5,6};
    foo(v,3);
    print(v); 
};