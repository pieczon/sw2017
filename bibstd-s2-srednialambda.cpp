#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/4/4
//do dokonczenia

template <typename T>
T print(T& str)
{
    std::string newS;
    newS.resize(str.size());
    std::transform(str.begin(), str.end(), std::back_inserter(newS), [](auto c){return std::toupper(c); std::cout << c << std::endl;});
    return newS;
}

int mean(const std::vector<int>& v)
{
    int acc = 0;
    std::for_each(v.begin(), v.end(), [&acc](auto num){acc += num;});
}

int main()
{
    std::vector<int> i{1,23,4,5,5,6};
    print(a);
}