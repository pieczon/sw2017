#include <iostream>
#include <array>
#include <cstdlib>
// #include <fstream>

using namespace std;

int main()
{
    array<int, 100> tab;

    for(int& value: tab)
    {
        value = rand()%100;
        cout<<value<<endl;
    }
    
    int maks=0;

    for(const int& value: tab)
    {
        if(value>maks)
        {
            maks = value;
        }
    }
    cout<<"Największa wartość: "<<maks<<endl;
}