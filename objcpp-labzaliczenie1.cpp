#include <iostream>

using namespace std;


class Prostokat
{
    private:
    int x, y;

    public:
    int pole(int a, int b)
    {
        a = x;
        b = y;
        int wynik = a*b;
        return wynik;
    }
    Prostokat(): x(5), y(10) {};
};


int main()
{
    Prostokat z;
    int p = z.pole(10,5);
    cout << p << endl;
}