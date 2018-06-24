#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<std::uint8_t> w {0,1,2,3};
    auto flags = std::cout.flags();
    for(auto el : w)
    {
        std::cout << std::showbase << std::uppercase << std::hex << static_cast<int>(el) << std::endl;
    }
    std::cout.setf(flags);
    std::cout << 3 << std::endl;
}