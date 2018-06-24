#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/4/3

template <typename ContainerType>
void print(const ContainerType& v)
{
    if (v.empty())
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    std::for_each(v.begin(), v.end()-1, [&](std::string r) { std::cout << r << ", ";});
    std::cout << *(v.end()-1);
    std::cout << "]" << std::endl;
}

template <typename TypKontenera>
void upper(TypKontenera& str)
{
    std::for_each(str.begin(), str.end(), [](char& c){c = std::toupper(c);})
    //std::transform(s.begin(), s.end(), [&](auto p) {std::toupper(p);});
}

int main()
{
    std::vector<std::string> w = {"a", "b", "c"};
    upper(w);
    print(w);
}