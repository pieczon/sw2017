#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

double sum(std::istream & is)
{
    std::vector<double> w;
    // std::generate_n(std::back_inserter(w), 5, [](){
    // double number;
    // std::cin >> number;
    // return number;
    // });
    if(is.exceptions() & std::ios::failbit){
    }

    double d;
    std::cin >> d;
    w.push_back(d);

    return std::accumulate(w.begin(), w.end(), 0);
}

int main()
{
    // size_t n;
    // std::vector<double> w;
    // std::cout << "Podaj kolejne elementy: " << std::endl;
    // while((!std::ios::failbit) or (!std::ios::badbit))
    // {
    //     std::generate_n(std::back_inserter(w), n, [](){
    //     double number;
    //     std::cin >> number;
    //     return number;
    //     });
    // }
    // int sum = std::accumulate(w.begin(), w.end(), 0);
    // std::cout.exceptions(std::ios::failbit);


    // std::cin.exceptions(std::ios::badbit | std::ios::failbit);
    // try{
    //     double x;
    //     std::cin >> x;
    // }
    // catch(const std::exception& ex){
    // }

    std::cout << sum(std::cin) << std::endl;
    return 0;
}