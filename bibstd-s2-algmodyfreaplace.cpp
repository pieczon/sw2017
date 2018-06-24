#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

//http://slides.com/uczelnia_bt_kw/stl-2/#/6/15


std::vector<std::string> replace(const std::vector<std::string>& v)
{
    bool is_lower = true;
    std::replace_if(v.begin(), v.end(), std::back_inserter(v), [&] (char c) {std::toupper(c) == c;
    is_lower = false;});
    return v;
}

int main()
{
    std::vector<std::string> w = {"a,B,c,D"};
    replace(w);
}