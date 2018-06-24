#include <iostream>
#include <array>
#include <cstdlib>
#include <vector>
#include <cmath>

std::vector<int> foo(const std::vector<int> &v, int pow)
{
    std::vector<int> toRet;
    toRet.reserve(v.size());
    for(auto element: v)
    {
        if(element%2 == 0)
        {
            auto k = std::pow(element, pow);
            toRet.push_back(std::pow(element, pow));
        }
    }
    return toRet;
}

int main()
{
    auto g = foo({{1,2,3,4}}, 2);
    for(const auto& ele : g)
    {
        std::cout << ele << " " << std::endl;
    }

}
