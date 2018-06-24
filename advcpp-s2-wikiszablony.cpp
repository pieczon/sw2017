#include <iostream>

template <typename TTT> class Punkt
{
    public:
        TTT x, y, z;
        Punkt(TTT argX, TTT argY, TTT argZ): x(argX), y(argY), z(argZ) {}
};

//typedef Punkt<int> PunktInt;
//typedef Punkt<unsigned> PunktUInt;
//typedef Punkt<float> PunktFloat;
template <typename T, typename Y> class Pieczon
{
    public:
        T nazwa;
        Y ilosc;
        Pieczon(T a, Y b): nazwa(a), ilosc(b) {}
};

int main(void)
{
    Punkt<int> A(0,-10,0);
    Punkt<unsigned int> B(0,10,5);

    std::cout << "A(" << A.x << "," << A.y << "," << A.z << ")" << std::endl;
    std::cout << "B(" << B.x << "," << B.y << "," << B.z << ")" << std::endl;

    Pieczon<std::string, int> pit("Jestem potężnym programistą!", 646);
    std::cout << pit.nazwa << " " << pit.ilosc << std::endl;
}