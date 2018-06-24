#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

//
//musimy zagwarantowac 
//inwalidowanie iteratorow, czyli po dodaniu np. 1 elem. do wektora, ale jak bedzie relokacja, iteratory wektora moga wskazywac na poprzednie miejsce w pamieci, wiec lepiej wywolywac funkcje nie na tym samym kontenerze

void copy_only(const std::vector<int>& v, std::list<int>& l)
{
    std::copy_if(v.begin(), v.end(), std::back_inserter(v), [](int e){return e%2 == 0;});
}

int main()
{
    std::vector<int> w = {1,2,3,4,5,6,7};
    std::list<int> li = {0,1,2,3,4,5,6,7};
    copy_only(w,li);
}