#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

struct Employee{
    // std::string str() const;
    // void str(const std::string&);

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);

    private:
    int wiek;
    std::string nazwisko;
};

std::ostream& operator<<(std::ostream& os, const Employee& e){
    os << e.nazwisko;
    return e.nazwisko;
}

int main()
{
    Employee emp{19, "Kazik"};
    std::stringstream ss;
    ss << emp;
}