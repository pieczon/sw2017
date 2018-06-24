#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

//http://slides.com/uczelnia_bt_kw/stl-2/#/4/2
//to jest niedokonczone

template <typename ContainerType>
void print(const ContainerType& v)
{
    if (std::begin(v) == std::end(v)) 
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    std::for_each(std::begin(v), std::end(v)-1, [&](std::string r) { std::cout << r << ", ";});
    std::cout << *(v.end()-1);
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<std::string> w = {"a", "b", "c"};
    print(w);

    std::list<std::string> g;
}