#include <iostream>
#include <vector>
#include <algorithm>

void ForEach(const std::vector<int>& w, void(*func)(int))
{
    for(int wartosc : w)
    {
        func(wartosc);
    }
}

int main()
{
    std::vector<int> wektor = {1,5,4,2,3};
    auto it = std::find_if(wektor.begin(), wektor.end(), [](int value){ return value > 2;});
    std::cout << *it << std::endl;
    auto lambda = [](int dupa){ std::cout << "Wartość: " << dupa << std::endl; };
    ForEach(wektor, lambda);
}