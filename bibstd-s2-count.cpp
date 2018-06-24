#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/5/2
//nie dziala pirnt, do dokonczneia

template<class InputIt, class UnaryPredicate> typename iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate p)
{
    typename iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) 
    {
        if (p(*first)) 
        {
            ret++;
        }
    }
    return ret;
}

int numofelem(const std::vector<int>&v)
{
    return std::count_if(v.begin(), v.begin(), )
}

int main()
{
    std::vector<std::string> w = {"a", "b", "C"};
    count_if(w.begin(), w.end(), [&](){};)
}

