#include <iostream>
#include <algorithm>

//http://slides.com/uczelnia_bt_kw/stl-2/#/7/6
//jest ok

template <typename TypKontenera>
void print(const TypKontenera& v)
{
    if (v.empty())
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    std::for_each(v.begin(), v.end()-1, [&](auto r){ std::cout << r << ", ";});
    std::cout << *(v.end()-1);
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> w{1,2,3,4,5,6,7,8,20,-50};
    print(w);
    auto it = std::remove(w.begin(),w.end(), 5);
    print(w);
    w.erase(it, w.end());
    print(w);
}