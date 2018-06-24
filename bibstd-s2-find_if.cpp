#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/5/6
//znalezc wystapienia, f zwraca wektor indeksow
//to jest dobrze od bt, do dokonczenia print tego
//uzywamy binary_search na kazdym posortowanym kontenerze, bo jest logarytmicznie szybszy
//jak mamy nieposortowane to bez wyboru find czy tam find/if

std::vector<std::size_t> wystapienia(const std::vector<int>&v, int N)
{
    std::vector<std::size_t> indeces;
    auto it = v.begin();
    while (it != std::end(v))
    {
        it = std::find(it, v.end(), N);
        if(it != std::end(v))
        {
            indeces.push_back(std::distance(std::begin(v), it));
            it++;
        }
    }
    return indeces;
}

int main()
{
    std::vector<int> w = {-10,-1,0,22,14,3};

    wystapienia({1,22,1,3,4,5,7,8,1,5}, 1);
}