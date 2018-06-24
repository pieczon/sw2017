#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/7/6
//erase ma kasowac stringi z jakas cyfra/liczba
//powinno byc ok, sprawdzic potem

template <typename ContainerType>
void print(const ContainerType& v)
{
    if (v.empty())
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    std::for_each(v.begin(), v.end()-1, [&](auto r) { std::cout << r << ", ";});
    std::cout << *(v.end()-1);
    std::cout << "]" << std::endl;
}

int main()
{
    auto has_number = [](const std::string& str) -> bool {std::any_of(str.begin(), str.end(), [](char c){return std::isdigit(c);});};

    std::vector<std::string> w{"s1, dupa , a3, afdaf"};
    auto it = std::remove(w.begin(),w.end(), has_number);
    print(w);
    w.erase(it, w.end());
    print(w);
}