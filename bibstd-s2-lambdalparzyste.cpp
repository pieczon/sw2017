#include <iostream>
#include <algorithm>
#include <vector>

//http://slides.com/uczelnia_bt_kw/stl-2/#/3/11

void print(const std::vector<int>& v)
{
    std::cout << "[";
    for(const auto& ele : v)
    {
        std::cout << ele << std::endl;
    }
    std::cout << "]";
}

void foo(const std::vector<int>& v)
{
    int liczba = 0;
    std::generate_n(std::back_inserter(v), 10, [&]() { return (liczba++)*2; });
}

int main()
{
    std::vector<int> b;
    b.reserve(10);
    foo(b);
    print(b);
}