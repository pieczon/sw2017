#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/4/3
//nie dziala pirnt, do dokonczneia

std::string print(std::string& str)
{
    std::string newS;
    newS.resize(str.size());
    std::transform(str.begin(), str.end(), std::back_inserter(newS), [](auto c){return std::toupper(c); std::cout << c << std::endl;});
    return newS;
}

int main()
{
    std::string a{"asdASD"};
    print(a);
}