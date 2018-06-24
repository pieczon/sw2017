#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/5/9
//to jest dobrze od bt, do dokonczenia print tego
//to byla grupa niemodyfikujacych algorytmow

template<class InputIt1, class InputIt2>
std::pair<InputIt1, InputIt2>
mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
    while ((first1 != last1) && (*first1 == *first2))
    {
        ++first1, ++first2;
    }
    return std::make_pair(first1, first2);
}

int main()
{
    std::vector<int> w1 = {-10,-1,0,22,14,3};
    std::vector<int> w2 = {10,-1,0,22,14,3};

    if(sizeof(w1) != sizeof(w2))
    {
        std::cout << "kontenery sa rozne" << std::endl;
    }
    else if(std::equal(w1.begin(), w1.end(), w2))
    {
        std::cout << "kontenery sa rozne" << std::endl;
    }    
}