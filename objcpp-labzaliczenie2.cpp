#include <iostream>
#include <istream>

using namespace std;

class Klasa
{
    private: 
    int a, b;
    public:

    Klasa(const int &a, const int &b);
    int suma(int a, int b)
    {
        a = x;
        b = y;
        int wynik = a*b;
        return wynik;
    }
};

int main()
{
    int x, y;
    cout << "Podaj a";
    cin >> x;
    cout << "Podaj b";
    cin >> y;
    Klasa k;
    k(x,y);

}