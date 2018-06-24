#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/5/4
//do dokonczenia, logika od bt przepisana powinna dzialac

int closestToZero(const std::vector<int>&v)
{
    const auto it = std::min_element(v.begin(), v.end(), [](const auto& current, const auto& min){return std::abd(current) > std::abs(min);});
    if(it==std::end(v)) throw std::logic_error(""); //to trzeba zawsze sprawdzic, bo iterator na koniec nie moze byc dereferencja
    std::cout << *it;
    return std::distance(v.begin(), it);
}

int main()
{
    std::vector<int> w = {-10,-1,0,22,14,3};
    closestToZero(w);
}

//find i find_it dzialaja w czasie liniowym, nie dzialaja tak szybko jak zwykle, nieposortowanych zbiorow tak nie przeszukujemy, lepiej binary search, dziala w czasie logarytmiczym