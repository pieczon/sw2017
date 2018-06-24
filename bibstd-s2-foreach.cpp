#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

//http://slides.com/uczelnia_bt_kw/stl-2/#/4/2

template <typename ContainerrType>
void print(const ContainerrType& v)
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

int main()
{
    std::vector<std::string> w = {"a", "b", "c"};
    print(w);

    std::list<std::string> g;
}