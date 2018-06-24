#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <math.h>

float funkcja(const std::vector<float>& w, bool isSorted)
{
    return std::accumulate(w.begin(), w.end(), isSorted ? 0.0f : 1.0f, [&isSorted](auto l, auto r) //accumulate zwroci nam int w tym przypadku, bo zwraca typ T, a tu mamy dwa inty 0 i 1, dopisanie 0.0f itp. rozwiązuje problem
    {
        if(isSorted){
            return l + r;
        }
        else{
            return l * r;
        }
    });
    //operator tenarny, krotsza wersja if-else
}

int main()
{
    std::size_t ile = 0;
    std::vector<float> w;

    std::cout << "Podaj liczbe elementów: " << std::endl;
    std::cin >> ile;
    w.reserve(ile);
    //po generate mamy juz utworzony wektor z elementami wedlug prototypu w funkcji lambda
    std::generate_n(std::back_inserter(w), ile, [](){
        float number;
        std::cin >> number;
        return number;
    });
    std::cout << funkcja(w, std::is_sorted(w.begin(), w.end())) << std::endl;

    //dodalem do tego kodu analogicznie generator dla tablicy, z zastosowaniem funkcji mat. pow() do jej elementow
    int mojatablica[ile];
    int a = 1;
    //tak samo elementy tworze generate_n w lambdzie
    std::generate_n(mojatablica, ile, [&a](){ return a += pow(a,a); });
    std::cout << "wygenerowana tablica: " << std::endl;
    for(int i=0; i<sizeof(mojatablica)/sizeof(mojatablica[0]); ++i){
        std::cout << mojatablica[i] << " " << std::endl;
    } 

    return 0;
}