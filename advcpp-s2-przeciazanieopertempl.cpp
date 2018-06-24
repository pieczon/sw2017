#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <cstring>

template <typename T> class C 
{
public:

    C(T* data, size_t size) 
    {
        table = new T[size];
        nsize = size;
    }

    ~C() 
    {
        delete [] table;
    }

    T* getTable() 
    {
        return table;
    }

    template<typename T> 
    C& operator=(const C& other)
    {
        if(this != other)
        {
            nsize = other.nsize;
            if(T[nsize] != T[size])
            {
                delete [] T;
                table = new T[nsize];
            }
            for(size_t i=0; i < nsize; ++i)
            {
                T[i] = other.T[i];
            }
            //zamiat petli for mozna uzyc funkcji std::copy(other.table, other.table+size; table);
        }
    return *this;
    }

    C& operator=(C&& other)
    {
        if(this != other)
        {
            delete [] table;
            table = std::exchange(other.table, nullptr);
            size = std::exchange(other.size,0);
        }
    }

private:
    T* table;
    size_t nsize;
};