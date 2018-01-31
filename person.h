#include <iostream>

class Person
{
    public:
    Person(const int &w, const int &t, const std::string &i, const std::string &n): wiek(w), nrtel(t), imie(i), nazwisko(n) {std::cout << "Imie: " << i << "Nazwisko: " << n << "Wiek: " << w << std::endl;};
    Person(const Person& rhs);
    Person &operator=(const Person& rhs);
    ~Person() {};

    private:
    int wiek, nrtel;
    std::string imie, nazwisko;
};