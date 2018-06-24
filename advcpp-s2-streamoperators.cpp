#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <cstring>


template<typename T>
class Vector3d 
{
public:

    Vector3d(T x, T y, T z) : x_(x), y_(y), z_(z) 
    {
        //
    }
    template<typename U>
    friend std::ostream& operator <<(std::ostream& os, const Vector3d<U>& v);

private:
    T x_;
    T y_;
    T z_;
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const Vector3d<T>& v) 
{
    os << "[" << v.x_ << " " << v.y_ << " " << v.z_ << "]";
    return os;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const std::list<T>& l) 
{
    os << "[";
    for (auto& el : l) 
    {
        os << " " << el;
    }
    os << " ]";
    return os;
}

int main(int argc, const char* argv[])
{
    Vector3d<int> jakis{5,4,3};
    std::cout << jakis << std::endl; 
    std::list<std::string> lista = {"dupa pieczona"};
    std::cout << lista << std::endl;
}